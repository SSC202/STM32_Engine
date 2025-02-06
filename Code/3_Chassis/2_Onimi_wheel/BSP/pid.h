#ifndef __PID_H
#define __PID_H

#include "stm32f4xx.h"

/******************用户选择段********************/
//#define INCREMINENT_PID // 增量式PID
#define LOCATION_PID     // 全量式PID

/* PID结构体 */
typedef struct
{
    __IO float SetPoint;    /* PID目标值 */
    __IO float ActualValue; /* PID输出值 */
    __IO float SumError;    /* PID误差 */
    __IO float Proportion;  /* P */
    __IO float Integral;    /* I */
    __IO float Derivative;  /* D */
    __IO float Error;       /* Error[1] */
    __IO float LastError;   /* Error[-1] */
    __IO float PrevError;   /* Error[-2] */
} PID;
/*******************用户函数********************/

int32_t PID_Cal(PID *upid, float Feedback_value);
void PID_Init(PID *upid, float KP, float KI, float KD);
#endif