#ifndef __MOTOR_H
#define __MOTOR_H

#include "main.h"
#include "tim.h"

/****************************用户定义段*******************************/

/**********************电机参数定义**********************/
#define ROTO_RATIO      52  /* 倍频数×线数 */
#define REDUCTION_RATIO 30  /* 减速比为 30:1 */
#define MAX_Speed       366 /* 最大转速(rpm) */
/**********************电机引脚定义**********************/
#define IN1_Pin       GPIO_PIN_10
#define IN1_GPIO_Port GPIOE

#define IN2_Pin       GPIO_PIN_12
#define IN2_GPIO_Port GPIOE
/********************电机定时器定义**********************/
#define PWM_Timer_Handle     &htim2        // PWM产生定时器
#define PWM_Timer_Channel    TIM_CHANNEL_1 // PWM输出通道
#define Encoder_Timer_Handle &htim1        // 编码器定时器
#define Encoder_Timer        TIM1          // 编码器定时器
/********************采样定时器定义**********************/
#define Sample_Timer_Handle &htim4 // 采样定时器
#define Sample_Timer        TIM4   // 采样定时器

/****************************变量定义段*******************************/
/********************电机变量定义************************/

typedef enum Motor_State {
    Motor_STOP,
    Motor_RUN
} Motor_State; // 电机运行状态

typedef struct
{
    Motor_State state; /* 电机状态 */
    float speed;       /* 电机速度 */
    int32_t pwm;       /* 电机PWM值 */
} Motor;
/*********************用户变量**************************/
extern Motor motor;
/******************************************************/
void Motor_Speed_Set(float speed);
void Motor_Init(void);
#endif
