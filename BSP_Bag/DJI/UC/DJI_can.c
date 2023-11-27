#include "DJI_can.h"

uint8_t CanReceiveData[8];

/**
 * @brief CAN接受过滤器配置函数
 */
HAL_StatusTypeDef CANFilterInit(CAN_HandleTypeDef *hcan)
{
  CAN_FilterTypeDef sFilterConfig;

  sFilterConfig.FilterBank = 0;
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  sFilterConfig.FilterIdHigh = 0x0000;
  sFilterConfig.FilterIdLow = 0x0000;
  sFilterConfig.FilterMaskIdHigh = 0x0000;
  sFilterConfig.FilterMaskIdLow = 0x0000;
  sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
  sFilterConfig.FilterActivation = ENABLE;
  sFilterConfig.SlaveStartFilterBank = 14;

  if (HAL_CAN_ConfigFilter(hcan, &sFilterConfig) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_CAN_Start(hcan) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
  {
    Error_Handler();
  }

  return HAL_OK;
}

/**
 * @brief CAN消息解码函数
 */
void CanDataDecode(CAN_RxHeaderTypeDef RxHeader)
{
  /* Can message Decode */
  if (RxHeader.IDE == CAN_ID_STD)
  {
    DJI_CanMsgDecode(RxHeader.StdId, CanReceiveData);
  }
  if (RxHeader.IDE == CAN_ID_EXT)
  {
    // vesc反馈关掉这里就不会有消息
    ;
    ;
  }
}

/**
 * @brief CAN RX0接受中断回调函数
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  CAN_RxHeaderTypeDef RxHeader;
  if (hcan->Instance == hcan1.Instance)
  {
    if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, CanReceiveData) != HAL_OK)
    {

      Error_Handler();
    }
    CanDataDecode(RxHeader);
  }
}
