#include "odrive.h"

CAN_TX_Typedef TX;
CAN_RX_Typedef RX;

axis_t odrive_axis[2];

/************************************************************************************************************ */

/**
 * @brief   CAN 数据包发送函数
 */
static void CAN_Send_Packet(CAN_HandleTypeDef *init, CAN_TX_Typedef *tx)
{
    init->Instance->sTxMailBox[0].TDHR &= ~0xFFFFFFFF;
    init->Instance->sTxMailBox[0].TDLR &= ~0xFFFFFFFF;
    init->Instance->sTxMailBox[0].TDTR &= ~0xFFFFFFFF;
    init->Instance->sTxMailBox[0].TIR &= ~0xFFFFFFFF;
    //---------------------------------------------------------------------------------------------------------------------
    switch (tx->id_type)
    {
    case CAN_ID_Standard:
    {
        init->Instance->sTxMailBox[0].TIR = tx->ID << 21;
        init->Instance->sTxMailBox[0].TIR &= ~1 << 2;
    }
    break;
    case CAN_ID_Extended:
    {
        init->Instance->sTxMailBox[0].TIR = tx->ID << 3;
        init->Instance->sTxMailBox[0].TIR |= 1 << 2;
    }
    break;
    }
    //---------------------------------------------------------------------------------------------------------------------
    switch (tx->frame_type)
    {
    case CAN_Frame_Data:
    {
        init->Instance->sTxMailBox[0].TIR &= ~(1 << 1);
    }
    break;
    case CAN_Frame_Remote:
    {
        init->Instance->sTxMailBox[0].TIR |= (1 << 1);
    }
    break;
    }
    //---------------------------------------------------------------------------------------------------------------------
    init->Instance->sTxMailBox[0].TDTR = tx->data_length;
    init->Instance->sTxMailBox[0].TDTR &= ~CAN_TDT0R_TGT;
    init->Instance->sTxMailBox[0].TDHR = tx->data[7] << 24 | tx->data[6] << 16 | tx->data[5] << 8 | tx->data[4] << 0;
    init->Instance->sTxMailBox[0].TDLR = tx->data[3] << 24 | tx->data[2] << 16 | tx->data[1] << 8 | tx->data[0] << 0;
    init->Instance->sTxMailBox[0].TIR |= (1 << 0);
    while (init->Instance->sTxMailBox[0].TIR & (1 << 0))
    {
    }
}

/**
 * @brief   CAN 数据包接收函数
 */
static void CAN_Get_Packet(CAN_HandleTypeDef *init, CAN_RX_Typedef *rx)
{

    int frame_type = 0;
    int id_type = 0;

    id_type = (CAN1->sFIFOMailBox[0].RIR & CAN_RI0R_IDE_Msk) >> CAN_RI0R_IDE_Pos;
    frame_type = (CAN1->sFIFOMailBox[0].RIR & CAN_RI0R_RTR_Msk) >> CAN_RI0R_RTR_Pos;

    if (id_type)
    {
        // Extended ID
        rx->id_type = CAN_ID_Extended;
        rx->ID = (init->Instance->sFIFOMailBox[0].RIR & CAN_RI0R_EXID_Msk) >> CAN_RI0R_EXID_Pos;
    }
    else
    {
        // Standard ID
        rx->id_type = CAN_ID_Standard;
        rx->ID = (init->Instance->sFIFOMailBox[0].RIR & CAN_RI0R_STID_Msk) >> CAN_RI0R_STID_Pos;
    }

    if (frame_type)
    {
        // RTR Frame
        rx->frame_type = CAN_Frame_Remote;
        rx->data_length = (init->Instance->sFIFOMailBox[0].RDTR & CAN_RDT0R_DLC_Msk) >> CAN_RDT0R_DLC_Pos;
        init->Instance->RF0R |= CAN_RF0R_RFOM0;
        while ((init->Instance->RF0R & CAN_RF0R_RFOM0))
        {
        }
    }
    else
    {
        // Data Frame
        rx->frame_type = CAN_Frame_Data;
        rx->data_length = (init->Instance->sFIFOMailBox[0].RDTR & CAN_RDT0R_DLC_Msk) >> CAN_RDT0R_DLC_Pos;
        for (int i = 0; i < rx->data_length; i++)
        {
            if (i < 4)
            {
                rx->data[i] = (init->Instance->sFIFOMailBox[0].RDLR & (0xFF << (8 * i))) >> (8 * i);
            }
            else
            {
                rx->data[i] = (init->Instance->sFIFOMailBox[0].RDHR & (0xFF << (8 * (i - 4)))) >> (8 * (i - 4));
            }
        }

        init->Instance->RF0R |= CAN_RF0R_RFOM0;
    }
}

static void Set_TX_Param(int AXIS_ID, int COMMAND_ID, int id_type, int frame_type, int data_length)
{
    TX.ID = (AXIS_ID << 5) | COMMAND_ID;
    TX.id_type = id_type;
    TX.frame_type = frame_type;
    TX.data_length = data_length;
}

/************************************************************************************************************ */

/**
 * @brief   Odrive 初始化
 */
void odrive_init(void)
{
    odrive_canfilter_init();
}

/**
 * @brief   Odrive 通讯消息过滤器初始化
 */
void odrive_canfilter_init(void)
{

    CAN_FilterTypeDef filter;
    filter.FilterActivation = ENABLE;
    filter.FilterBank = 0;
    filter.FilterFIFOAssignment = CAN_RX_FIFO0;
    filter.FilterIdHigh = 0x0000;
    filter.FilterIdLow = 0x0000;
    filter.FilterMaskIdHigh = 0x0000;
    filter.FilterMaskIdLow = 0x0000;
    filter.FilterMode = CAN_FILTERMODE_IDMASK;
    filter.FilterScale = CAN_FILTERSCALE_32BIT;

    HAL_CAN_ConfigFilter(&hcan1, &filter);
    HAL_CAN_Start(&hcan1);
    HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
}

/**
 * @brief   Odrive 设置轴状态
 */
void Set_Axis_Requested_State(axis_t Axis, Axis_State state)
{
    Set_TX_Param(Axis.AXIS_ID, SET_AXIS_REQUESTED_STATE, CAN_ID_Standard, CAN_Frame_Data, 4);
    unsigned int Requested_State = state;
    uint8_t *ptrToFloat;
    ptrToFloat = (uint8_t *)&Requested_State;
    TX.data[0] = ptrToFloat[0];
    TX.data[1] = ptrToFloat[1];
    TX.data[2] = ptrToFloat[2];
    TX.data[3] = ptrToFloat[3];
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 设置速度值
 */
void Set_Input_Vel(axis_t Axis, float vel, float torqueff)
{
    Set_TX_Param(Axis.AXIS_ID, SET_INPUT_VEL, CAN_ID_Standard, CAN_Frame_Data, 8);
    uint8_t *ptrVel;
    ptrVel = (uint8_t *)&vel;
    uint8_t *ptrTor;
    ptrTor = (uint8_t *)&torqueff;
    TX.data[0] = ptrVel[0];
    TX.data[1] = ptrVel[1];
    TX.data[2] = ptrVel[2];
    TX.data[3] = ptrVel[3];
    TX.data[4] = ptrTor[0];
    TX.data[5] = ptrTor[1];
    TX.data[6] = ptrTor[2];
    TX.data[7] = ptrTor[3];
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 清除错误指令
 */
void Clear_Errors(axis_t Axis)
{
    Set_TX_Param(Axis.AXIS_ID, CLEAR_ERRORS, CAN_ID_Standard, CAN_Frame_Data, 0);
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 重启
 */
void Reboot_ODrive(axis_t Axis)
{
    Set_TX_Param(Axis.AXIS_ID, REBOOT_ODRIVE, CAN_ID_Standard, CAN_Frame_Data, 0);
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 设置控制状态
 */
void Set_Controller_Modes(axis_t Axis, Control_Mode ControlMode, Input_Mode InputMode)
{
    Set_TX_Param(Axis.AXIS_ID, SET_CONTROLLER_MODES, CAN_ID_Standard, CAN_Frame_Data, 8);
    int Control = ControlMode;
    int Input = InputMode;
    uint8_t *ptrControl;
    ptrControl = (uint8_t *)&Control;
    uint8_t *ptrInput;
    ptrInput = (uint8_t *)&Input;
    TX.data[0] = ptrControl[0];
    TX.data[1] = ptrControl[1];
    TX.data[2] = ptrControl[2];
    TX.data[3] = ptrControl[3];
    TX.data[4] = ptrInput[0];
    TX.data[5] = ptrInput[1];
    TX.data[6] = ptrInput[2];
    TX.data[7] = ptrInput[3];
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 设置目标位置
 */
void Set_Input_Pos(axis_t Axis, float Input_Pos, int Vel_FF, int Torque_FF)
{
    Set_TX_Param(Axis.AXIS_ID, SET_INPUT_POS, CAN_ID_Standard, CAN_Frame_Data, 8);
    uint8_t *ptrPos;
    ptrPos = (uint8_t *)&Input_Pos;
    uint8_t *ptrVel;
    ptrVel = (uint8_t *)&Vel_FF;
    uint8_t *ptrTor;
    ptrTor = (uint8_t *)&Torque_FF;
    TX.data[0] = ptrPos[0];
    TX.data[1] = ptrPos[1];
    TX.data[2] = ptrPos[2];
    TX.data[3] = ptrPos[3];
    TX.data[4] = ptrVel[0];
    TX.data[5] = ptrVel[1];
    TX.data[6] = ptrTor[0];
    TX.data[7] = ptrTor[1];
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 读取编码器值
 */
void Get_Encoder_Count(axis_t Axis)
{
    Set_TX_Param(Axis.AXIS_ID, GET_ENCODER_COUNT, CAN_ID_Standard, CAN_Frame_Remote, 0);
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 设置目标力矩
 */
void Set_Input_Torque(axis_t Axis, float torque)
{
    Set_TX_Param(Axis.AXIS_ID, SET_INPUT_TORQUE, CAN_ID_Standard, CAN_Frame_Data, 4);
    uint8_t *ptrTor;
    ptrTor = (uint8_t *)&torque;
    TX.data[0] = ptrTor[0];
    TX.data[1] = ptrTor[1];
    TX.data[2] = ptrTor[2];
    TX.data[3] = ptrTor[3];
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 得到母线电压电流数据
 */
void Get_Bus_Voltage_Current(axis_t Axis)
{
    Set_TX_Param(Axis.AXIS_ID, GET_BUS_VOLTAGE_CURRENT, CAN_ID_Standard, CAN_Frame_Remote, 0);
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 得到 iq 值
 */
void Get_IQ(axis_t Axis)
{
    Set_TX_Param(Axis.AXIS_ID, GET_IQ, CAN_ID_Standard, CAN_Frame_Remote, 0);
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 设置位置增益
 */
void Set_Position_Gain(axis_t Axis, float pos_gain)
{
    Set_TX_Param(Axis.AXIS_ID, SET_POSITION_GAIN, CAN_ID_Standard, CAN_Frame_Data, 4);
    uint8_t *ptrPos;
    ptrPos = (uint8_t *)&pos_gain;
    TX.data[0] = ptrPos[0];
    TX.data[1] = ptrPos[1];
    TX.data[2] = ptrPos[2];
    TX.data[3] = ptrPos[3];
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 设置速度增益
 */
void Set_Vel_Gains(axis_t Axis, float Vel_Gain, float Vel_Int_Gain)
{
    Set_TX_Param(Axis.AXIS_ID, SET_VEL_GAINS, CAN_ID_Standard, CAN_Frame_Data, 8);
    uint8_t *ptrVelGain;
    ptrVelGain = (uint8_t *)&Vel_Gain;
    uint8_t *ptrVelIntGain;
    ptrVelIntGain = (uint8_t *)&Vel_Int_Gain;
    TX.data[0] = ptrVelGain[0];
    TX.data[1] = ptrVelGain[1];
    TX.data[2] = ptrVelGain[2];
    TX.data[3] = ptrVelGain[3];
    TX.data[4] = ptrVelIntGain[0];
    TX.data[5] = ptrVelIntGain[1];
    TX.data[6] = ptrVelIntGain[2];
    TX.data[7] = ptrVelIntGain[3];
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 设置轴的 CAN_ID
 */
void Set_Axis_Node_ID(axis_t Axis, uint32_t node_id)
{
    Set_TX_Param(Axis.AXIS_ID, SET_AXIS_NODE_ID, CAN_ID_Standard, CAN_Frame_Data, 4);
    uint8_t *ptrNodeId;
    ptrNodeId = (uint8_t *)&node_id;
    TX.data[0] = ptrNodeId[0];
    TX.data[1] = ptrNodeId[1];
    TX.data[2] = ptrNodeId[2];
    TX.data[3] = ptrNodeId[3];
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 设置轴的速度/位置限幅
 */
void Set_Limits(axis_t Axis, float vel_lim, float curr_lim)
{
    Set_TX_Param(Axis.AXIS_ID, SET_LIMITS, CAN_ID_Standard, CAN_Frame_Data, 8);
    uint8_t *ptrVelLim;
    ptrVelLim = (uint8_t *)&vel_lim;
    uint8_t *ptrCurrLim;
    ptrCurrLim = (uint8_t *)&curr_lim;
    TX.data[0] = ptrVelLim[0];
    TX.data[1] = ptrVelLim[1];
    TX.data[2] = ptrVelLim[2];
    TX.data[3] = ptrVelLim[3];
    TX.data[4] = ptrCurrLim[0];
    TX.data[5] = ptrCurrLim[1];
    TX.data[6] = ptrCurrLim[2];
    TX.data[7] = ptrCurrLim[3];
    CAN_Send_Packet(&hcan1, &TX);
}

/**
 * @brief   Odrive 读取轴状态
 */
void get_axis_status(axis_t *AXIS, int32_t CMD_ID)
{

    switch (CMD_ID)
    {

    case ODRIVE_HEARTBEAT_MESSAGE:
        AXIS->AXIS_Error = (RX.data[0] | RX.data[1] << 8 | RX.data[2] << 16 | RX.data[3] << 24);
        AXIS->AXIS_Current_State = RX.data[4];
        AXIS->Controller_Status = RX.data[5];
        break;

    case ENCODER_ESTIMATES:;

        uint32_t *ptrEncPos;
        ptrEncPos = (uint32_t *)&(AXIS->AXIS_Encoder_Pos);
        *ptrEncPos = (RX.data[0] + (RX.data[1] << 8) + (RX.data[2] << 16) + (RX.data[3] << 24));
        uint32_t *ptrEncVel;
        ptrEncVel = (uint32_t *)&(AXIS->AXIS_Encoder_Vel);
        *ptrEncVel = (RX.data[4] + (RX.data[5] << 8) + (RX.data[6] << 16) + (RX.data[7] << 24));
        break;

    case GET_ENCODER_COUNT:
        AXIS->AXIS_Encoder_Shadow = (RX.data[0] | RX.data[1] << 8 | RX.data[2] << 16 | RX.data[3] << 24);
        AXIS->AXIS_Encoder_CPR = (RX.data[4] | RX.data[5] << 8 | RX.data[6] << 16 | RX.data[7] << 24);
        break;

    case GET_BUS_VOLTAGE_CURRENT:;

        uint32_t *ptrBusV;
        ptrBusV = (uint32_t *)&(AXIS->AXIS_Bus_Voltage);
        *ptrBusV = (RX.data[0] + (RX.data[1] << 8) + (RX.data[2] << 16) + (RX.data[3] << 24));
        uint32_t *ptrBusI;
        ptrBusI = (uint32_t *)&(AXIS->AXIS_Bus_Current);
        *ptrBusI = (RX.data[4] + (RX.data[5] << 8) + (RX.data[6] << 16) + (RX.data[7] << 24));
        break;

    case GET_IQ:;

        uint32_t *ptrIqSet;
        ptrIqSet = (uint32_t *)&(AXIS->AXIS_Iq_Setpoint);
        *ptrIqSet = (RX.data[0] + (RX.data[1] << 8) + (RX.data[2] << 16) + (RX.data[3] << 24));
        uint32_t *ptrIqMsr;
        ptrIqMsr = (uint32_t *)&(AXIS->AXIS_Iq_Measured);
        *ptrIqMsr = (RX.data[4] + (RX.data[5] << 8) + (RX.data[6] << 16) + (RX.data[7] << 24));
        break;
    }
}
