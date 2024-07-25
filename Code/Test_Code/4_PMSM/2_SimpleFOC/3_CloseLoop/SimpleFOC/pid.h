#ifndef __PID_H
#define __PID_H

#include "usermain.h"

typedef struct PID_t {
    __IO float SetPoint;    /* PID目标值 */
    __IO float ActualValue; /* PID输出值 */
    __IO float SumError;    /* PID误差 */
    __IO float Proportion;  /* P */
    __IO float Integral;    /* I */
    __IO float Derivative;  /* D */
    __IO float Error;       /* Error[1] */
    __IO float LastError;   /* Error[-1] */
    __IO float PrevError;   /* Error[-2] */
} PID_t;

void pid_init(PID_t *upid, float KP, float KI, float KD);
float pid_calc(PID_t *upid, float Feedback_value);

#endif