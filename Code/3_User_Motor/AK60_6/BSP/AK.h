/**
 * @brief   CubeMars AK电机驱动程序
 * @author  SSC
 * @attention   AK电机为关节电机，非常珍贵，谨慎使用
 * 官网地址：
 *      https://www.cubemars.com/
 * 上位机使用地址：
 *      https://www.bilibili.com/video/BV1Ge4y1F7zS/?spm_id_from=333.788&vd_source=2d2507d13250e2545de99f3c552af296
 * 1. 接线：
 *  使用24V进行供电，串口用于和上位机通讯（调试使用），注意：串口可以直连USB转TTL模块，连接后，上位机右下角会间断性的闪烁绿色方框。CAN接口用于和下位机通讯。
 *
 *  上电正常标志为蓝灯常亮（红灯有微弱亮光为正常现象），未连接CAN时绿灯可以不亮。
 * 2. CAN波特率为1Mbps，和DJI电机进行相同配置，建议使用CAN2接口以避免和DJI电机混用时混淆。
 * 3. 使用前调整34,36,37,52行的宏定义，34行用于电机选型，36，37行用于选择模式（模式应提前在上位机指定），MIT模式类似于Unitree，Servo模式类似于FEETECH，52行指定CAN接口。
 * 4. 使用MIT模式应使用以下初始化顺序：
 *      CAN初始化;
 *      AK_Motor_Init();
 *      AK_Motor_Set_Origin();
 *      随后使用AK_Motor_Send_Msg();发送数据;
 *      提供ak_data结构体接收电机回传的CAN报文。
 * 5. 使用Servo模式应使用以下初始化顺序：（未测试）
 *      CAN初始化；
 *      comm_can_set_origin();
 *      随后发送数据；
 *      提供ak_data结构体接收电机回传的CAN报文。
 * @attention   未进行STM32H7相关测试，未进行CAN2相关测试，未进行Servo_Mode测试；
 * @attention   配合wtr_can.c和wtr_can.h进行使用
 * @date    2024.1.26
 */

#ifndef __AK_H
#define __AK_H

#include "wtr_can.h"
/**************************电机旋择***************************/
#define AK60_6 1 // AK60_6电机
/**************************模式旋择***************************/
#define MIT_Mode   1 // MIT模式
#define Servo_Mode 0 // 伺服模式
/************************************************************/
typedef struct {
#if (MIT_Mode == 1)
    int motor_id; // 电机ID（伺服模式无此选项）
#endif
    float motor_spd; // 电机速度
    float motor_pos; // 电机位置
    float motor_cur; // 电机电流
    int motor_tmp;   // 电机温度
    int motor_error; // 电机错误码，0表示无故障，1表示电机过温度故障，2表示过电流故障，3表示过压故障，4表示欠压故障，5表示编码器故障，6表示mos管过温度故障，7表示电机堵转
} AK_DATA;

#if (STM32F427xx)
/*********************用户宏定义**************************/
#define AK_CAN 1 // AK60_6 使用的CAN设置，设置为x即为CANx，取值为1，2

/***********************类型定义*************************/
#if (Servo_Mode == 1)
typedef enum {
    CAN_PACKET_SET_DUTY = 0,      // 占空比模式
    CAN_PACKET_SET_CURRENT,       // 电流环模式
    CAN_PACKET_SET_CURRENT_BRAKE, // 电流刹车模式
    CAN_PACKET_SET_RPM,           // 转速模式
    CAN_PACKET_SET_POS,           // 位置模式
    CAN_PACKET_SET_ORIGIN_HERE,   // 设置原点模式
    CAN_PACKET_SET_POS_SPD,       // 位置速度环模式
} CAN_PACKET_ID;                  // 控制模式定义

// Servo 模式指令
void comm_can_set_duty(uint8_t controller_id, float duty);
void comm_can_set_current(uint8_t controller_id, float current);
void comm_can_set_cb(uint8_t controller_id, float current);
void comm_can_set_rpm(uint8_t controller_id, float rpm);
void comm_can_set_pos(uint8_t controller_id, float pos);
void comm_can_set_origin(uint8_t controller_id, uint8_t set_origin_mode);
void comm_can_set_pos_spd(uint8_t controller_id, float pos, int16_t spd, int16_t RPA);
#endif
#if (MIT_Mode == 1)
#if (AK60_6)
#define P_MIN  (-12.5f)
#define P_MAX  (12.5f)
#define V_MIN  (-45.0f)
#define V_MAX  (45.0f)
#define T_MIN  (-15.0f)
#define T_MAX  (15.0f)
#define KP_MIN (0.0f)
#define KP_MAX (500.0f)
#define KD_MIN (0.0f)
#define KD_MAX (5.0f)
#endif

// MIT模式指令
void AK_Motor_Init(uint8_t controller_id);
void AK_Motor_DeInit(uint8_t controller_id);
void AK_Motor_Set_Origin(uint8_t controller_id);
void AK_Motor_Send_Msg(uint8_t controller_id, float p_des, float v_des, float kp, float kd, float t_ff);
#endif
#endif

extern AK_DATA ak_data;

#endif
/******************************************************/