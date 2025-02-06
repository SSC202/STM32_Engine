#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H

#include "stm32f1xx.h"
#include "tim.h"

/*************************用户定义段******************************/
#define MICRO_STEP              8 // 细分数

#define Motor_PWM_Timer_Handle  &htim2
#define Motor_PWM_Timer         TIM2
#define Motor_PWM_Timer_Channel TIM_CHANNEL_2

#define Motor_DIR_Port          GPIOA // 方向使能引脚
#define Motor_DIR_Pin           GPIO_PIN_2

#define Motor_ENA_Port          GPIOA // 脱机使能引脚
#define Motor_ENA_Pin           GPIO_PIN_3

/*************************结构体定义段*****************************/

typedef enum dir_t {
    CCW = 0, // 反转
    CW  = 1  // 正转
} dir_t;     // 电机旋转方向定义

/**************************用户函数*******************************/

void Motor_Init(void);
void Motor_Speed_Set(float speed);

#endif