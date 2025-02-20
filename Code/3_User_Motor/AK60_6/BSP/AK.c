#include "AK.h"
#include "string.h"
#include "math.h"

AK_DATA ak_data;

/*****************************STM32F4xx******************************/
#if (STM32F427xx)
#if (AK_CAN == 1)
#define AK_USE_CAN          can1
#define AK_USE_CAN_HANDLE   hcan1
#define AK_USE_CAN_TXHANDLE hcan1_tx
#define AK_USE_CAN_RXHANDLE hcan1_rx
#define AK_USE_CAN_RXBUFFER can1_rxdata
#elif (AK_CAN == 2)
#define AK_USE_CAN          can2
#define AK_USE_CAN_HANDLE   hcan2
#define AK_USE_CAN_TXHANDLE hcan2_tx
#define AK_USE_CAN_RXHANDLE hcan2_rx
#define AK_USE_CAN_RXBUFFER can2_rxdata
#endif

/**********************************************************************/
#if (MIT_Mode == 1)
/**
 * @brief   float转uint函数
 */
static int float_to_uint(float x, float x_min, float x_max, unsigned int bits)
{
    /// Converts a float to an unsigned int, given range and number of bits ///
    float span = x_max - x_min;
    if (x < x_min)
        x = x_min;
    else if (x > x_max)
        x = x_max;
    return (int)((x - x_min) * ((float)((1 << bits) / span)));
}

/**
 * @brief   uint转float函数
 */
static float uint_to_float(int x_int, float x_min, float x_max, int bits)
{
    /// converts unsigned int to float, given range and number of bits ///
    float span   = x_max - x_min;
    float offset = x_min;
    return ((float)x_int) * span / ((float)((1 << bits) - 1)) + offset;
}

/**
 * @brief   电机初始化函数，注意同时上电情况下需要延迟一定时间使用
 * @param   controller_id   电机ID
 * @attention   初始化后进入运控模式
 */
void AK_Motor_Init(uint8_t controller_id)
{
    CAN_MSG umsg;
    umsg.id  = controller_id;
    umsg.ide = CAN_ID_STD;
    umsg.rtr = CAN_RTR_DATA;
    umsg.len = 8;
    for (int i = 0; i < 7; i++) {
        umsg.buffer[i] = 0xFF;
    }
    umsg.buffer[7] = 0xFC;
    AK_USE_CAN.CAN_Send_MSG(&umsg);
}

/**
 * @brief   电机去初始化函数
 * @param   controller_id   电机ID
 */
void AK_Motor_DeInit(uint8_t controller_id)
{
    CAN_MSG umsg;
    umsg.id  = controller_id;
    umsg.ide = CAN_ID_STD;
    umsg.rtr = CAN_RTR_DATA;
    umsg.len = 8;
    for (int i = 0; i < 7; i++) {
        umsg.buffer[i] = 0xFF;
    }
    umsg.buffer[7] = 0xFD;
    AK_USE_CAN.CAN_Send_MSG(&umsg);
}

/**
 * @brief   电机设置原点函数
 * @param   controller_id   电机ID
 */
void AK_Motor_Set_Origin(uint8_t controller_id)
{
    CAN_MSG umsg;
    umsg.id  = controller_id;
    umsg.ide = CAN_ID_STD;
    umsg.rtr = CAN_RTR_DATA;
    umsg.len = 8;
    for (int i = 0; i < 7; i++) {
        umsg.buffer[i] = 0xFF;
    }
    umsg.buffer[7] = 0xFE;
    AK_USE_CAN.CAN_Send_MSG(&umsg);
}

/**
 * @brief   MIT模式消息发送函数
 * @param   controller_id   电机ID
 * @param   p_des   期望位置（rad）
 * @param   v_des   期望速度（rpm）
 * @param   t_ff    期望力矩
 * @param   kp      阻尼系数
 * @param   kd      刚度系数
 */
void AK_Motor_Send_Msg(uint8_t controller_id, float p_des, float v_des, float kp, float kd, float t_ff)
{
    CAN_MSG umsg;
    umsg.id  = controller_id;
    umsg.ide = CAN_ID_STD;
    umsg.rtr = CAN_RTR_DATA;
    umsg.len = 8;

    p_des = fminf(fmaxf(P_MIN, p_des), P_MAX);
    v_des = fminf(fmaxf(V_MIN, v_des), V_MAX);
    kp    = fminf(fmaxf(KP_MIN, kp), KP_MAX);
    kd    = fminf(fmaxf(KD_MIN, kd), KD_MAX);
    t_ff  = fminf(fmaxf(T_MIN, t_ff), T_MAX);

    int p_int  = float_to_uint(p_des, P_MIN, P_MAX, 16);
    int v_int  = float_to_uint(v_des, V_MIN, V_MAX, 12);
    int kp_int = float_to_uint(kp, KP_MIN, KP_MAX, 12);
    int kd_int = float_to_uint(kd, KD_MIN, KD_MAX, 12);
    int t_int  = float_to_uint(t_ff, T_MIN, T_MAX, 12);

    umsg.buffer[0] = p_int >> 8;                           // 位置高 8
    umsg.buffer[1] = p_int & 0xFF;                         // 位置低 8
    umsg.buffer[2] = v_int >> 4;                           // 速度高 8 位
    umsg.buffer[3] = ((v_int & 0xF) << 4) | (kp_int >> 8); // 速度低 4 位 KP 高 4 位
    umsg.buffer[4] = kp_int & 0xFF;                        // KP 低 8 位
    umsg.buffer[5] = kd_int >> 4;                          // Kd 高 8 位
    umsg.buffer[6] = ((kd_int & 0xF) << 4) | (t_int >> 8); // KP 低 4 位扭矩高 4 位
    umsg.buffer[7] = t_int & 0xff;                         // 扭矩低 8 位

    AK_USE_CAN.CAN_Send_MSG(&umsg);
}

/**
 * @brief   MIT模式消息解码函数
 * @param   msg_data        CAN消息数组
 */
void AK_Motor_Msg_Decode(uint8_t *msg_data)
{

    int id    = msg_data[0];                              // 驱动 ID 号
    int p_int = (msg_data[1] << 8) | msg_data[2];         // 电机位置数据
    int v_int = (msg_data[3] << 4) | (msg_data[4] >> 4);  // 电机速度数据
    int i_int = ((msg_data[4] & 0xF) << 8) | msg_data[5]; // 电机扭矩数据
    int T_int = msg_data[6];

    float p = uint_to_float(p_int, P_MIN, P_MAX, 16);
    float v = uint_to_float(v_int, V_MIN, V_MAX, 12);
    float i = uint_to_float(i_int, -60, 60, 12);
    float T = T_int;

        ak_data.motor_cur   = i;
        ak_data.motor_pos   = p;
        ak_data.motor_spd   = v;
        ak_data.motor_tmp   = T;
        ak_data.motor_error = msg_data[7];
}

/**
 * @brief   CAN RX0中断回调函数
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan->Instance == AK_USE_CAN_HANDLE.Instance) {
        if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &AK_USE_CAN_RXHANDLE, AK_USE_CAN_RXBUFFER) != HAL_OK) {
            Error_Handler();
        }
        memcpy((uint8_t *)AK_USE_CAN.rx_MSG.buffer, AK_USE_CAN_RXBUFFER, 8); // 保存CAN报文的内容
        AK_USE_CAN.rx_MSG.id  = AK_USE_CAN_RXHANDLE.StdId;                   // 保存CAN报文的ID
        AK_USE_CAN.rx_MSG.len = AK_USE_CAN_RXHANDLE.DLC;                     // 保存CAN报文的内容长度
        /* Can message Decode */
        if (AK_USE_CAN_RXHANDLE.IDE == CAN_ID_STD) {
            AK_Motor_Msg_Decode((uint8_t *)AK_USE_CAN.rx_MSG.buffer);
        }
        if (AK_USE_CAN_RXHANDLE.IDE == CAN_ID_EXT) {
            ;
        }
    }
}

#endif
/**********************************************************************/
#if (Servo_Mode == 1)
/**
 * @brief   数组转int32函数
 */
static void buffer_append_int32(uint8_t *buffer, int32_t number, int32_t *index)
{
    buffer[(*index)++] = number >> 24;
    buffer[(*index)++] = number >> 16;
    buffer[(*index)++] = number >> 8;
    buffer[(*index)++] = number;
}

/**
 * @brief   数组转int16函数
 */
static void buffer_append_int16(uint8_t *buffer, int16_t number, int16_t *index)
{
    buffer[(*index)++] = number >> 8;
    buffer[(*index)++] = number;
}

/**
 * @brief   通用指令发送函数（伺服模式）
 * @param   id      ID
 * @param   data    发送数据
 * @param   len     数据长度
 */
static void comm_can_transmit_eid(uint32_t id, const uint8_t *data, uint8_t len)
{
    uint8_t i = 0;
    if (len > 8) {
        len = 8;
    }
    CAN_MSG umsg;
    umsg.id  = id;
    umsg.ide = CAN_ID_EXT;
    umsg.rtr = CAN_RTR_DATA;
    umsg.len = len;
    for (i = 0; i < len; i++)
        umsg.buffer[i] = data[i];
    AK_USE_CAN.CAN_Send_MSG(&umsg);
}

/**
 * @brief   占空比模式（伺服模式）
 * @param   controller_id   电机的CAN ID
 * @param   duty            占空比
 */
void comm_can_set_duty(uint8_t controller_id, float duty)
{
    int32_t send_index = 0;
    uint8_t buffer[4];
    buffer_append_int32(buffer, (int32_t)(duty * 100000.0), &send_index);
    comm_can_transmit_eid(controller_id |
                              ((uint32_t)CAN_PACKET_SET_DUTY << 8),
                          buffer, send_index);
}

/**
 * @brief   电流环模式（伺服模式）
 * @param   controller_id   电机的CAN ID
 * @param   duty            电流数值，-60000-60000为-60A到60A
 */
void comm_can_set_current(uint8_t controller_id, float current)
{
    int32_t send_index = 0;
    uint8_t buffer[4];
    buffer_append_int32(buffer, (int32_t)(current * 1000.0), &send_index);
    comm_can_transmit_eid(controller_id |
                              ((uint32_t)CAN_PACKET_SET_CURRENT << 8),
                          buffer, send_index);
}

/**
 * @brief   电流刹车模式（伺服模式）
 * @param   controller_id   电机的CAN ID
 * @param   duty            电流数值，0-60000为0到60A
 */
void comm_can_set_cb(uint8_t controller_id, float current)
{
    int32_t send_index = 0;
    uint8_t buffer[4];
    buffer_append_int32(buffer, (int32_t)(current * 1000.0), &send_index);
    comm_can_transmit_eid(controller_id |
                              ((uint32_t)CAN_PACKET_SET_CURRENT_BRAKE << 8),
                          buffer, send_index);
}

/**
 * @brief   速度环模式（伺服模式）
 * @param   controller_id   电机的CAN ID
 * @param   rpm             转速（rpm）数值，-100000-100000
 */
void comm_can_set_rpm(uint8_t controller_id, float rpm)
{
    int32_t send_index = 0;
    uint8_t buffer[4];
    buffer_append_int32(buffer, (int32_t)rpm, &send_index);
    comm_can_transmit_eid(controller_id |
                              ((uint32_t)CAN_PACKET_SET_RPM << 8),
                          buffer, send_index);
}

/**
 * @brief   位置环模式（伺服模式）
 * @param   controller_id   电机的CAN ID
 * @param   pos             位置（角度）数值，-360000000-360000000为-36000°~36000°;
 */
void comm_can_set_pos(uint8_t controller_id, float pos)
{
    int32_t send_index = 0;
    uint8_t buffer[4];
    buffer_append_int32(buffer, (int32_t)(pos * 10000.0), &send_index);
    comm_can_transmit_eid(controller_id |
                              ((uint32_t)CAN_PACKET_SET_POS << 8),
                          buffer, send_index);
}

/**
 * @brief   原点设置模式（伺服模式）
 * @param   controller_id               电机的CAN ID
 * @param   set_origin_mode             原点类型，0为上电原点，1为永久原点
 */
void comm_can_set_origin(uint8_t controller_id, uint8_t set_origin_mode)
{
    int32_t send_index = 0;
    uint8_t buffer;
    buffer = set_origin_mode;
    comm_can_transmit_eid(controller_id |
                              ((uint32_t)CAN_PACKET_SET_ORIGIN_HERE << 8),
                          &buffer, send_index);
}

/**
 * @brief   速度位置双环模式（伺服模式）
 * @param   controller_id               电机的CAN ID
 * @param   pos                         位置(角度)，-360000000-360000000为-36000°~36000°;
 * @param   spd                         速度(rpm)，-32768~32767;
 * @param   RPA                         加速度(rpm/s)，0~32767;
 */
void comm_can_set_pos_spd(uint8_t controller_id, float pos, int16_t spd, int16_t RPA)
{
    int32_t send_index  = 0;
    int16_t send_index1 = 4;
    uint8_t buffer[8];
    buffer_append_int32(buffer, (int32_t)(pos * 10000.0), &send_index);
    buffer_append_int16(buffer, spd / 10.0, &send_index1);
    buffer_append_int16(buffer, RPA / 10.0, &send_index1);
    comm_can_transmit_eid(controller_id |
                              ((uint32_t)CAN_PACKET_SET_POS_SPD << 8),
                          buffer, send_index1);
}

/**
 * @brief   数据接收解码函数（伺服模式）
 * @param   rx_message  接收数据
 */
void motor_receive_decode(uint8_t *rx_message)
{
    int16_t pos_int     = rx_message[0] << 8 | rx_message[1];
    int16_t spd_int     = rx_message[2] << 8 | rx_message[3];
    int16_t cur_int     = rx_message[4] << 8 | rx_message[5];
    ak_data.motor_pos   = (float)(pos_int * 0.1f);  // 电机位置
    ak_data.motor_spd   = (float)(spd_int * 10.0f); // 电机速度
    ak_data.motor_cur   = (float)(cur_int * 0.01f); // 电机电流
    ak_data.motor_tmp   = rx_message[6];            // 电机温度
    ak_data.motor_error = rx_message[7];            // 电机故障码
}

/**
 * @brief   CAN RX0中断回调函数
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan->Instance == AK_USE_CAN_HANDLE.Instance) {
        if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &AK_USE_CAN_RXHANDLE, AK_USE_CAN_RXBUFFER) != HAL_OK) {
            Error_Handler();
        }
        memcpy((uint8_t *)AK_USE_CAN.rx_MSG.buffer, AK_USE_CAN_RXBUFFER, 8); // 保存CAN报文的内容
        AK_USE_CAN.rx_MSG.id  = AK_USE_CAN_RXHANDLE.StdId;                   // 保存CAN报文的ID
        AK_USE_CAN.rx_MSG.len = AK_USE_CAN_RXHANDLE.DLC;                     // 保存CAN报文的内容长度
        /* Can message Decode */
        if (AK_USE_CAN_RXHANDLE.IDE == CAN_ID_STD) {
            ;
        }
        if (AK_USE_CAN_RXHANDLE.IDE == CAN_ID_EXT) {
            motor_receive_decode((uint8_t *)AK_USE_CAN.rx_MSG.buffer);
        }
    }
}
#endif

#endif
