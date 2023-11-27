#ifndef _DJI_CAN_H
#define _DJI_CAN_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "DJI_can.h"
#include "DJI.h"
#include "can.h"

    HAL_StatusTypeDef CANFilterInit(CAN_HandleTypeDef *hcan);

#ifdef __cplusplus
}
#endif

#endif
