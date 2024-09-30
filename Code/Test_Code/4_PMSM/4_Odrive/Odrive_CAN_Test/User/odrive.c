#include "odrive.h"

OdirveTypeDef odrive;

/**
 * @brief   Odrive 初始化
 */
void odrive_init(void)
{
    odrive.pos0     = 0;
    odrive.pos1     = 0;
    odrive.set_pos0 = 0;
    odrive.set_pos1 = 0;
    odrive_canfilter_init();
}

/**
 * @brief   Odrive 通讯消息过滤器初始化
 */
void odrive_canfilter_init(void)
{

    CAN_FilterTypeDef filter;
    filter.FilterActivation     = ENABLE;
    filter.FilterBank           = 0;
    filter.FilterFIFOAssignment = CAN_RX_FIFO0;
    filter.FilterIdHigh         = 0x0000;
    filter.FilterIdLow          = 0x0000;
    filter.FilterMaskIdHigh     = 0x0000;
    filter.FilterMaskIdLow      = 0x0000;
    filter.FilterMode           = CAN_FILTERMODE_IDMASK;
    filter.FilterScale          = CAN_FILTERSCALE_32BIT;

    HAL_CAN_ConfigFilter(&hcan, &filter);
    HAL_CAN_Start(&hcan);
    HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
}

/**
 * @brief   Odrive 位置控制
 */
void odrive_pos_ctrl(unsigned char num, float pos)
{
    CAN_TxHeaderTypeDef header;
    uint8_t data[8];
    header.RTR      = CAN_RTR_DATA;
    header.IDE      = CAN_ID_STD;
    header.DLC      = 8;
    header.StdId    = ((NODE_ID(num) << 5) | MSG_SET_INPUT_POS);
    header.ExtId    = 0;
    uint8_t *ptrPos = (uint8_t *)&pos;
    data[0]         = ptrPos[0];
    data[1]         = ptrPos[1];
    data[2]         = ptrPos[2];
    data[3]         = ptrPos[3];
    data[4]         = 0;
    data[5]         = 0;
    data[6]         = 0;
    data[7]         = 0;
    uint32_t ret;
    HAL_CAN_AddTxMessage(&hcan, &header, data, &ret);
}

/**
 * @brief   Odrive 位置反馈
 */
void odrive_pos_callback(unsigned char num)
{
    CAN_TxHeaderTypeDef header;
    uint8_t data[8];
    header.RTR   = CAN_RTR_REMOTE;
    header.IDE   = CAN_ID_STD;
    header.DLC   = 0;
    header.StdId = ((NODE_ID(num) << 5) | MSG_GET_ENCODER_COUNT);
    header.ExtId = 0;
    uint32_t ret;
    HAL_CAN_AddTxMessage(&hcan, &header, data, &ret);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *can)
{
    CAN_RxHeaderTypeDef header;
    uint8_t buf[8];
    if (can == &hcan) {
        HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &header, buf);
        if ((header.StdId >> 5) == AXIS0_CAN_NODE_ID) {

        } else if ((header.StdId >> 5) == AXIS1_CAN_NODE_ID) {
        }
    }
}