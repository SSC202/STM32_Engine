#include "DJI.h"
#include "wtr_can.h"

#define LAST 0
#define NOW  1

#if (STM32F427xx)
DJI_t hDJI[8][2];
#endif
#if (STM32H723xx)
DJI_t hDJI[8][3];
#endif
/**
 * @brief	DJI电机初始化函数
 * @note    使用前应对全局变量hDJI进行类型初始化
 */
void DJI_Init()
{
#if (STM32F427xx)
    for (int i = 0; i < 8; i++) {
        // 速度环PID
        hDJI[i][0].speedPID.KP        = 12;
        hDJI[i][0].speedPID.KI        = 0.2;
        hDJI[i][0].speedPID.KD        = 5;
        hDJI[i][0].speedPID.outputMax = 8000;

        // 位置环PID
        hDJI[i][0].posPID.KP        = 80.0f;
        hDJI[i][0].posPID.KI        = 1.0f;
        hDJI[i][0].posPID.KD        = 0.0f;
        hDJI[i][0].posPID.outputMax = 5000;
        // hDJI[i].posPID.outputMin = 1500;

        if (hDJI[i][0].motorType == M3508) {
            hDJI[i][0].reductionRate = 3591.0f / 187.0f; // 2006减速比为36 3508减速比约为19
        } else if (hDJI[i][0].motorType == M2006) {
            hDJI[i][0].reductionRate = 36.0f;
        }

        hDJI[i][0].encoder_resolution = 8192.0f;
    }
#if(USE_CAN2 == 1)
    for (int i = 0; i < 8; i++) {
        // 速度环PID
        hDJI[i][1].speedPID.KP        = 12;
        hDJI[i][1].speedPID.KI        = 0.2;
        hDJI[i][1].speedPID.KD        = 5;
        hDJI[i][1].speedPID.outputMax = 8000;

        // 位置环PID
        hDJI[i][1].posPID.KP        = 80.0f;
        hDJI[i][1].posPID.KI        = 1.0f;
        hDJI[i][1].posPID.KD        = 0.0f;
        hDJI[i][1].posPID.outputMax = 5000;
        // hDJI[i].posPID.outputMin = 1500;

        if (hDJI[i][1].motorType == M3508) {
            hDJI[i][1].reductionRate = 3591.0f / 187.0f; // 2006减速比为36 3508减速比约为19
        } else if (hDJI[i][1].motorType == M2006) {
            hDJI[i][1].reductionRate = 36.0f;
        }

        hDJI[i][1].encoder_resolution = 8192.0f;
    }
#endif
#endif
#if (STM32H723xx)
#if (USE_FDCAN1 == 1)
    for (int i = 0; i < 8; i++) {
        // 速度环PID
        hDJI[i][0].speedPID.KP        = 12;
        hDJI[i][0].speedPID.KI        = 0.2;
        hDJI[i][0].speedPID.KD        = 5;
        hDJI[i][0].speedPID.outputMax = 8000;

        // 位置环PID
        hDJI[i][0].posPID.KP        = 80.0f;
        hDJI[i][0].posPID.KI        = 1.0f;
        hDJI[i][0].posPID.KD        = 0.0f;
        hDJI[i][0].posPID.outputMax = 5000;
        // hDJI[i].posPID.outputMin = 1500;

        if (hDJI[i][0].motorType == M3508) {
            hDJI[i][0].reductionRate = 3591.0f / 187.0f; // 2006减速比为36 3508减速比约为19
        } else if (hDJI[i][0].motorType == M2006) {
            hDJI[i][0].reductionRate = 36.0f;
        }

        hDJI[i][0].encoder_resolution = 8192.0f;
    }
#endif
#if (USE_FDCAN2 == 1)
    for (int i = 0; i < 8; i++) {
        // 速度环PID
        hDJI[i][1].speedPID.KP        = 12;
        hDJI[i][1].speedPID.KI        = 0.2;
        hDJI[i][1].speedPID.KD        = 5;
        hDJI[i][1].speedPID.outputMax = 8000;

        // 位置环PID
        hDJI[i][1].posPID.KP        = 80.0f;
        hDJI[i][1].posPID.KI        = 1.0f;
        hDJI[i][1].posPID.KD        = 0.0f;
        hDJI[i][1].posPID.outputMax = 5000;
        // hDJI[i].posPID.outputMin = 1500;

        if (hDJI[i][1].motorType == M3508) {
            hDJI[i][1].reductionRate = 3591.0f / 187.0f; // 2006减速比为36 3508减速比约为19
        } else if (hDJI[i][1].motorType == M2006) {
            hDJI[i][1].reductionRate = 36.0f;
        }

        hDJI[i][1].encoder_resolution = 8192.0f;
    }
#endif
#if (USE_FDCAN3 == 1)
    for (int i = 0; i < 8; i++) {
        // 速度环PID
        hDJI[i][2].speedPID.KP        = 12;
        hDJI[i][2].speedPID.KI        = 0.2;
        hDJI[i][2].speedPID.KD        = 5;
        hDJI[i][2].speedPID.outputMax = 8000;

        // 位置环PID
        hDJI[i][2].posPID.KP        = 80.0f;
        hDJI[i][2].posPID.KI        = 1.0f;
        hDJI[i][2].posPID.KD        = 0.0f;
        hDJI[i][2].posPID.outputMax = 5000;
        // hDJI[i].posPID.outputMin = 1500;

        if (hDJI[i][2].motorType == M3508) {
            hDJI[i][2].reductionRate = 3591.0f / 187.0f; // 2006减速比为36 3508减速比约为19
        } else if (hDJI[i][2].motorType == M2006) {
            hDJI[i][2].reductionRate = 36.0f;
        }

        hDJI[i][2].encoder_resolution = 8192.0f;
    }
#endif
#endif
}

/**
 * @brief	DJI电机数据更新函数
 * @param	motor	电机句柄
 * @param	fdbData	反馈值
 */
void DJI_Update(DJI_t *motor, uint8_t *fdbData)
{
    /* 反馈信息计算 */
    motor->FdbData.RotorAngle_0_360 = (fdbData[0] << 8 | fdbData[1]) * 360.0f / motor->encoder_resolution; /* unit:degree*/
    motor->FdbData.rpm              = (int16_t)(fdbData[2] << 8 | fdbData[3]);                             /* unit:rpm   */
    motor->FdbData.current          = (int16_t)(fdbData[4] << 8 | fdbData[5]);
    /* 计算数据处理 */
    /* 更新反馈速度/位置 */
    motor->Calculate.RotorAngle_0_360_Log[LAST] = motor->Calculate.RotorAngle_0_360_Log[NOW];
    motor->Calculate.RotorAngle_0_360_Log[NOW]  = motor->FdbData.RotorAngle_0_360;
    /* 电机圈数更新 */
    if (motor->Calculate.RotorAngle_0_360_Log[NOW] - motor->Calculate.RotorAngle_0_360_Log[LAST] > (180.0f))
        motor->Calculate.RotorRound--;
    else if (motor->Calculate.RotorAngle_0_360_Log[NOW] - motor->Calculate.RotorAngle_0_360_Log[LAST] < -(180.0f))
        motor->Calculate.RotorRound++;
    /* 电机输出轴角度 */
    motor->AxisData.AxisAngle_inDegree = motor->Calculate.RotorRound * 360.0f;
    motor->AxisData.AxisAngle_inDegree += motor->Calculate.RotorAngle_0_360_Log[NOW] - motor->Calculate.RotorAngle_0_360_OffSet;
    motor->AxisData.AxisAngle_inDegree /= motor->reductionRate;

    motor->AxisData.AxisVelocity    = motor->FdbData.rpm / motor->reductionRate;
    motor->Calculate.RotorAngle_all = motor->Calculate.RotorRound * 360 + motor->Calculate.RotorAngle_0_360_Log[NOW] - motor->Calculate.RotorAngle_0_360_OffSet;
}

/**
 * @brief	DJI储存偏差函数
 * @param	motor	电机句柄
 * @param	fdbData	反馈值
 */
void get_dji_offset(DJI_t *motor, uint8_t *fdbData)
{
    motor->FdbData.RotorAngle_0_360             = (fdbData[0] << 8 | fdbData[1]) * 360.0f / motor->encoder_resolution;
    motor->Calculate.RotorAngle_0_360_Log[LAST] = motor->FdbData.RotorAngle_0_360;
    motor->Calculate.RotorAngle_0_360_Log[NOW]  = motor->Calculate.RotorAngle_0_360_Log[LAST];

    motor->Calculate.RotorAngle_0_360_OffSet = motor->FdbData.RotorAngle_0_360;
}

#if (STM32F427xx)
/**
 * @brief	DJI电调数据解码函数
 * @param	Stdid	CAN数据帧ID
 * @param	fdbData	反馈值
 */
HAL_StatusTypeDef DJI_CanMsgDecode(uint8_t can_code, uint32_t Stdid, uint8_t *fdbData)
{
    int i = Stdid - 0x201;
    if (can_code == 1) {
        if (i >= 0 && i < 8) {
            // 上电后进行反馈数据计数，计数到第50次时设置为当前偏差
            if (hDJI[i].FdbData.msg_cnt < 50) {
                get_dji_offset(&hDJI[i][0], fdbData);
                hDJI[i].FdbData.msg_cnt++;
            } else {
                DJI_Update(&hDJI[i][0], fdbData);
            }
            return HAL_OK;
        }
    }
#if (USE_CAN2 == 1)
    if (can_code == 2) {
        if (i >= 0 && i < 8) {
            // 上电后进行反馈数据计数，计数到第50次时设置为当前偏差
            if (hDJI[i].FdbData.msg_cnt < 50) {
                get_dji_offset(&hDJI[i][1], fdbData);
                hDJI[i].FdbData.msg_cnt++;
            } else {
                DJI_Update(&hDJI[i][1], fdbData);
            }
            return HAL_OK;
        }
    }
#endif
}

/**
 * @brief	DJI电机CAN发送函数，电机ID 1/2/3/4
 * @param	can	    CAN句柄(canx)
 * @param	cmx_iq	发送值，通常为最内环控制的输出值
 */
void CanTransmit_DJI_1234(CAN_HANDLER can, int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq)
{
    CAN_MSG umsg;

    umsg.id  = 0x200;
    umsg.len = 0x08;
    umsg.rtr = DATA_FRAME;

    umsg.buffer[0] = (uint8_t)(cm1_iq >> 8);
    umsg.buffer[1] = (uint8_t)cm1_iq;
    umsg.buffer[2] = (uint8_t)(cm2_iq >> 8);
    umsg.buffer[3] = (uint8_t)cm2_iq;
    umsg.buffer[4] = (uint8_t)(cm3_iq >> 8);
    umsg.buffer[5] = (uint8_t)cm3_iq;
    umsg.buffer[6] = (uint8_t)(cm4_iq >> 8);
    umsg.buffer[7] = (uint8_t)cm4_iq;

    can1.CAN_Send_MSG(&umsg);
}

/**
 * @brief	DJI电机CAN发送函数，电机ID 5/6/7/8
 * @param	can	    CAN句柄(canx)
 * @param	cmx_iq	发送值，通常为最内环控制的输出值
 */
void CanTransmit_DJI_5678(CAN_HANDLER can, int16_t cm5_iq, int16_t cm6_iq, int16_t cm7_iq, int16_t cm8_iq)
{
    CAN_MSG umsg;

    umsg.len = 0x08;
    umsg.id  = 0x1FF;
    umsg.rtr = DATA_FRAME;

    umsg.buffer[0] = (uint8_t)(cm5_iq >> 8);
    umsg.buffer[1] = (uint8_t)cm5_iq;
    umsg.buffer[2] = (uint8_t)(cm6_iq >> 8);
    umsg.buffer[3] = (uint8_t)cm6_iq;
    umsg.buffer[4] = (uint8_t)(cm7_iq >> 8);
    umsg.buffer[5] = (uint8_t)cm7_iq;
    umsg.buffer[6] = (uint8_t)(cm8_iq >> 8);
    umsg.buffer[7] = (uint8_t)cm8_iq;

    can.CAN_Send_MSG(&umsg);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan->Instance == hcan1.Instance) {
        if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &hcan1_rx, can1_rxdata) != HAL_OK) {
            Error_Handler();
        }
        memcpy((uint8_t *)can1.rx_MSG.buffer, can1_rxdata, 8); // 保存CAN报文的内容
        can1.rx_MSG.id  = hcan1_rx.StdId;                      // 保存CAN报文的ID
        can1.rx_MSG.len = hcan1_rx.DLC;                        // 保存CAN报文的内容长度
        /* Can message Decode */
        if (hcan1_rx.IDE == CAN_ID_STD) {
            DJI_CanMsgDecode(1, can1.rx_MSG.id, (uint8_t *)can1.rx_MSG.buffer);
        }
        if (hcan1_rx.IDE == CAN_ID_EXT) {
            // vesc反馈关掉这里就不会有消息
            ;
            ;
        }
    }
#if (USE_CAN2 == 1)
    else if (hcan->Instance == hcan2.Instance) {
        if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &hcan2_rx, can2_rxdata) != HAL_OK) {
            Error_Handler();
        }
        memcpy((uint8_t *)can2.rx_MSG.buffer, can2_rxdata, 8); // 保存CAN报文的内容
        can2.rx_MSG.id  = hcan2_rx.StdId;                      // 保存CAN报文的ID
        can2.rx_MSG.len = hcan2_rx.DLC;                        // 保存CAN报文的内容长度
        /* Can message Decode */
        if (hcan2_rx.IDE == CAN_ID_STD) {
            DJI_CanMsgDecode(2, can2.rx_MSG.id, (uint8_t *)can2.rx_MSG.buffer);
        }
        if (hcan2_rx.IDE == CAN_ID_EXT) {
            // vesc反馈关掉这里就不会有消息
            ;
            ;
        }
    }
#endif
}

#endif
#if (STM32H723xx)
#include <string.h>
/**
 * @brief	DJI电机CAN发送函数，电机ID 1/2/3/4
 * @param   fdcan   fdcan 句柄(fdcanx)
 * @param	cmx_iq	发送值，通常为最内环控制的输出值
 */
void CanTransmit_DJI_1234(FDCAN_HANDLER fdcan, int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq)
{
    CAN_MSG umsg;

    umsg.id  = 0x200;
    umsg.len = 0x08;
    umsg.rtr = DATA_FRAME;

    umsg.buffer[0] = (uint8_t)(cm1_iq >> 8);
    umsg.buffer[1] = (uint8_t)cm1_iq;
    umsg.buffer[2] = (uint8_t)(cm2_iq >> 8);
    umsg.buffer[3] = (uint8_t)cm2_iq;
    umsg.buffer[4] = (uint8_t)(cm3_iq >> 8);
    umsg.buffer[5] = (uint8_t)cm3_iq;
    umsg.buffer[6] = (uint8_t)(cm4_iq >> 8);
    umsg.buffer[7] = (uint8_t)cm4_iq;

    fdcan.FDCAN_Send_MSG(&umsg);
}

/**
 * @brief	DJI电机CAN发送函数，电机ID 5/6/7/8
 * @param   fdcan   fdcan 句柄(fdcanx)
 * @param	cmx_iq	发送值，通常为最内环控制的输出值
 */
void CanTransmit_DJI_5678(FDCAN_HANDLER fdcan, int16_t cm5_iq, int16_t cm6_iq, int16_t cm7_iq, int16_t cm8_iq)
{
    CAN_MSG umsg;

    umsg.len = 0x08;
    umsg.id  = 0x1FF;
    umsg.rtr = DATA_FRAME;

    umsg.buffer[0] = (uint8_t)(cm5_iq >> 8);
    umsg.buffer[1] = (uint8_t)cm5_iq;
    umsg.buffer[2] = (uint8_t)(cm6_iq >> 8);
    umsg.buffer[3] = (uint8_t)cm6_iq;
    umsg.buffer[4] = (uint8_t)(cm7_iq >> 8);
    umsg.buffer[5] = (uint8_t)cm7_iq;
    umsg.buffer[6] = (uint8_t)(cm8_iq >> 8);
    umsg.buffer[7] = (uint8_t)cm8_iq;

    fdcan.FDCAN_Send_MSG(&umsg);
}

/**
 * @brief FIFO0接收中断回调函数
 */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
#if (USE_FDCAN1 == 1)
    fdcan1.RXFIFO_Inter_Type = RxFifo0ITs; /* 看看中断的类型 */
#endif
    // FIFO 中断类型
    if (FDCAN_IT_RX_FIFO0_WATERMARK == RxFifo0ITs ||
        FDCAN_IT_RX_FIFO0_NEW_MESSAGE == RxFifo0ITs ||
        FDCAN_IT_RX_FIFO0_FULL == RxFifo0ITs) {
#if (USE_FDCAN1 == 1)
        if (hfdcan->Instance == FDCAN1) {
            do {
                HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &hfdcan1_rx, fdcan1_rxdata); // 提取FIFO0中接收到的数据
                memcpy((uint8_t *)fdcan1.rx_MSG.buffer, fdcan1_rxdata, 8);                  // 保存CAN报文的内容
                fdcan1.rx_MSG.id  = hfdcan1_rx.Identifier;                                  // 保存CAN报文的ID
                fdcan1.rx_MSG.len = hfdcan1_rx.DataLength >> 16;                            // 保存CAN报文的内容长度

                // 判断远程帧或者数据帧
                if (hfdcan1_rx.RxFrameType == FDCAN_REMOTE_FRAME) {
                    fdcan1.rx_MSG.rtr = REMOTE_FRAME;
                } else {
                    fdcan1.rx_MSG.rtr = DATA_FRAME;
                }
                fdcan1.FDCAN_Update_RXFIFO_Status(hfdcan, &fdcan1); // 更新RXFIFO的状态（了解FIFO是否有剩余报文）
                DJI_CanMsgDecode(1, fdcan1.rx_MSG.id, (uint8_t *)fdcan1.rx_MSG.buffer);
            } while (fdcan1.FxFL > 0);
            // 循环直到FxFL等于0
        }
#endif
#if (USE_FDCAN2 == 1)
        if (hfdcan->Instance == FDCAN2) {
            do {
                HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &hfdcan2_rx, fdcan2_rxdata); // 提取FIFO0中接收到的数据
                memcpy((uint8_t *)fdcan2.rx_MSG.buffer, fdcan2_rxdata, 8);                  // 保存CAN报文的内容
                fdcan2.rx_MSG.id  = hfdcan2_rx.Identifier;                                  // 保存CAN报文的ID
                fdcan2.rx_MSG.len = hfdcan2_rx.DataLength >> 16;                            // 保存CAN报文的内容长度

                // 判断远程帧或者数据帧
                if (hfdcan2_rx.RxFrameType == FDCAN_REMOTE_FRAME) {
                    fdcan2.rx_MSG.rtr = REMOTE_FRAME;
                } else {
                    fdcan2.rx_MSG.rtr = DATA_FRAME;
                }
                fdcan2.FDCAN_Update_RXFIFO_Status(hfdcan, &fdcan2); // 更新RXFIFO的状态（了解FIFO是否有剩余报文）
                DJI_CanMsgDecode(2, fdcan2.rx_MSG.id, (uint8_t *)fdcan2.rx_MSG.buffer);
            } while (fdcan2.FxFL > 0);
            // 循环直到FxFL等于0
        }
#endif
#if (USE_FDCAN3 == 1)
        if (hfdcan->Instance == FDCAN3) {
            do {
                HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &hfdcan3_rx, fdcan3_rxdata); // 提取FIFO0中接收到的数据
                memcpy((uint8_t *)fdcan3.rx_MSG.buffer, fdcan3_rxdata, 8);                  // 保存CAN报文的内容
                fdcan3.rx_MSG.id  = hfdcan3_rx.Identifier;                                  // 保存CAN报文的ID
                fdcan3.rx_MSG.len = hfdcan3_rx.DataLength >> 16;                            // 保存CAN报文的内容长度

                // 判断远程帧或者数据帧
                if (hfdcan3_rx.RxFrameType == FDCAN_REMOTE_FRAME) {
                    fdcan3.rx_MSG.rtr = REMOTE_FRAME;
                } else {
                    fdcan3.rx_MSG.rtr = DATA_FRAME;
                }
                fdcan3.FDCAN_Update_RXFIFO_Status(hfdcan, &fdcan3); // 更新RXFIFO的状态（了解FIFO是否有剩余报文）
                DJI_CanMsgDecode(3, fdcan3.rx_MSG.id, (uint8_t *)fdcan3.rx_MSG.buffer);
            } while (fdcan3.FxFL > 0);
            // 循环直到FxFL等于0
        }
#endif
    }
}

/**
 * @brief	DJI电调数据解码函数
 * @param	Stdid	CAN数据帧ID
 * @param	fdbData	反馈值
 */
HAL_StatusTypeDef DJI_CanMsgDecode(uint8_t fdcan_code, uint32_t Stdid, uint8_t *fdbData)
{
    int i = Stdid - 0x201;
#if (USE_FDCAN1 == 1)
    if (fdcan_code == 1) {
        if (i >= 0 && i < 8) {
            // 上电后进行反馈数据计数，计数到第50次时设置为当前偏差
            if (hDJI[i][0].FdbData.msg_cnt < 50) {
                get_dji_offset(&hDJI[i][0], fdbData);
                hDJI[i][0].FdbData.msg_cnt++;
            } else {
                DJI_Update(&hDJI[i][0], fdbData);
            }
            return HAL_OK;
        }
    }
#endif
#if (USE_FDCAN2 == 1)
    if (fdcan_code == 2) {
        if (i >= 0 && i < 8) {
            // 上电后进行反馈数据计数，计数到第50次时设置为当前偏差
            if (hDJI[i][1].FdbData.msg_cnt < 50) {
                get_dji_offset(&hDJI[i][1], fdbData);
                hDJI[i][1].FdbData.msg_cnt++;
            } else {
                DJI_Update(&hDJI[i][1], fdbData);
            }
            return HAL_OK;
        }
    }
#endif
#if (USE_FDCAN3 == 1)
    if (fdcan_code == 3) {
        if (i >= 0 && i < 8) {
            // 上电后进行反馈数据计数，计数到第50次时设置为当前偏差
            if (hDJI[i][2].FdbData.msg_cnt < 50) {
                get_dji_offset(&hDJI[i][2], fdbData);
                hDJI[i][2].FdbData.msg_cnt++;
            } else {
                DJI_Update(&hDJI[i][2], fdbData);
            }
            return HAL_OK;
        }
    }
#endif
    return HAL_ERROR;
}
#endif