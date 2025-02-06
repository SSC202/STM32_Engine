#ifndef __STEER_H
#define __STEER_H

#include "stm32f4xx.h"
#include "tim.h"

/***********************用户定义段*************************/
#define PWM_Timer_Handle    &htim2
#define PWM_Timer_Channel_2 TIM_CHANNEL_2
/***********************用户函数***************************/
void Servo_Control(uint16_t angle);
void Servo_Init(void);

#endif