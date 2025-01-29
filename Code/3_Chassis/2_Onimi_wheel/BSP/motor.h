#ifndef __MOTOR_H
#define __MOTOR_H

#include "main.h"
#include "tim.h"
#include "pid.h"

/****************************用户定义段*******************************/
#define USE_FREERTOS
#define AT8236
/**********************电机参数定义**********************/
#define ROTO_RATIO      52  /* 倍频数×线数 */
#define REDUCTION_RATIO 30  /* 减速比为 30:1 */
#define MAX_Speed       366 /* 最大转速(rpm) */
/**********************电机引脚定义**********************/
#ifdef TB6612

#define Motor1_IN1_Pin       GPIO_PIN_3
#define Motor1_IN1_GPIO_Port GPIOA
#define Motor1_IN2_Pin       GPIO_PIN_2
#define Motor1_IN2_GPIO_Port GPIOA

#define Motor2_IN1_Pin       GPIO_PIN_4
#define Motor2_IN1_GPIO_Port GPIOA
#define Motor2_IN2_Pin       GPIO_PIN_5
#define Motor2_IN2_GPIO_Port GPIOA

#define Motor3_IN1_Pin       GPIO_PIN_12
#define Motor3_IN1_GPIO_Port GPIOE
#define Motor3_IN2_Pin       GPIO_PIN_5
#define Motor3_IN2_GPIO_Port GPIOC

#define Motor4_IN1_Pin       GPIO_PIN_11
#define Motor4_IN1_GPIO_Port GPIOB
#define Motor4_IN2_Pin       GPIO_PIN_15
#define Motor4_IN2_GPIO_Port GPIOB

/********************电机定时器定义**********************/
#define Motor1_PWM_Timer_Handle     &htim8        // PWM产生定时器
#define Motor1_PWM_Timer_Channel    TIM_CHANNEL_1 // PWM输出通道
#define Motor1_Encoder_Timer_Handle &htim2        // 编码器定时器
#define Motor1_Encoder_Timer        TIM2          // 编码器定时器

#define Motor2_PWM_Timer_Handle     &htim8        // PWM产生定时器
#define Motor2_PWM_Timer_Channel    TIM_CHANNEL_2 // PWM输出通道
#define Motor2_Encoder_Timer_Handle &htim3        // 编码器定时器
#define Motor2_Encoder_Timer        TIM3          // 编码器定时器

#define Motor3_PWM_Timer_Handle     &htim8        // PWM产生定时器
#define Motor3_PWM_Timer_Channel    TIM_CHANNEL_3 // PWM输出通道
#define Motor3_Encoder_Timer_Handle &htim4        // 编码器定时器
#define Motor3_Encoder_Timer        TIM4          // 编码器定时器

#define Motor4_PWM_Timer_Handle     &htim8        // PWM产生定时器
#define Motor4_PWM_Timer_Channel    TIM_CHANNEL_4 // PWM输出通道
#define Motor4_Encoder_Timer_Handle &htim5        // 编码器定时器
#define Motor4_Encoder_Timer        TIM5          // 编码器定时器

#endif
#ifdef AT8236

#define Motor1_IN1_PWM_Timer         &htim11       // IN1端输入PWM
#define Motor1_IN1_PWM_Timer_Handle  TIM11         // IN1端定时器句柄
#define Motor1_IN1_PWM_Timer_Channel TIM_CHANNEL_1 // IN1端输入通道
#define Motor1_IN1_GPIO_Port         GPIOB         // IN1端端口
#define Motor1_IN1_GPIO_Pin          GPIO_PIN_9    // IN1端端子
#define Motor1_IN2_PWM_Timer         &htim10       // IN2端输入PWM
#define Motor1_IN2_PWM_Timer_Handle  TIM10         // IN2端定时器句柄
#define Motor1_IN2_PWM_Timer_Channel TIM_CHANNEL_1 // IN2端输入通道
#define Motor1_IN2_GPIO_Port         GPIOB         // IN2端端口
#define Motor1_IN2_GPIO_Pin          GPIO_PIN_8    // IN2端端子
#define Motor1_Encoder_Timer_Handle  &htim2        // 编码器定时器
#define Motor1_Encoder_Timer         TIM2          // 编码器定时器

#define Motor2_IN1_PWM_Timer         &htim9        // IN1端输入PWM
#define Motor2_IN1_PWM_Timer_Handle  TIM9          // IN1端定时器句柄
#define Motor2_IN1_PWM_Timer_Channel TIM_CHANNEL_1 // IN1端输入通道
#define Motor2_IN1_GPIO_Port         GPIOE         // IN1端端口
#define Motor2_IN1_GPIO_Pin          GPIO_PIN_5    // IN1端端子
#define Motor2_IN2_PWM_Timer         &htim9        // IN2端输入PWM
#define Motor2_IN2_PWM_Timer_Handle  TIM9          // IN2端定时器句柄
#define Motor2_IN2_PWM_Timer_Channel TIM_CHANNEL_2 // IN2端输入通道
#define Motor2_IN2_GPIO_Port         GPIOE         // IN2端端口
#define Motor2_IN2_GPIO_Pin          GPIO_PIN_6    // IN2端端子
#define Motor2_Encoder_Timer_Handle  &htim3        // 编码器定时器
#define Motor2_Encoder_Timer         TIM3          // 编码器定时器

#define Motor3_IN1_PWM_Timer         &htim1        // IN1端输入PWM
#define Motor3_IN1_PWM_Timer_Handle  TIM1          // IN1端定时器句柄
#define Motor3_IN1_PWM_Timer_Channel TIM_CHANNEL_1 // IN1端输入通道
#define Motor3_IN1_GPIO_Port         GPIOE         // IN1端端口
#define Motor3_IN1_GPIO_Pin          GPIO_PIN_9   // IN1端端子
#define Motor3_IN2_PWM_Timer         &htim1        // IN2端输入PWM
#define Motor3_IN2_PWM_Timer_Handle  TIM1          // IN2端定时器句柄
#define Motor3_IN2_PWM_Timer_Channel TIM_CHANNEL_2 // IN2端输入通道
#define Motor3_IN2_GPIO_Port         GPIOE         // IN2端端口
#define Motor3_IN2_GPIO_Pin          GPIO_PIN_11    // IN2端端子
#define Motor3_Encoder_Timer_Handle  &htim4        // 编码器定时器
#define Motor3_Encoder_Timer         TIM4          // 编码器定时器

#define Motor4_IN1_PWM_Timer         &htim1        // IN1端输入PWM
#define Motor4_IN1_PWM_Timer_Handle  TIM1          // IN1端定时器句柄
#define Motor4_IN1_PWM_Timer_Channel TIM_CHANNEL_4 // IN1端输入通道
#define Motor4_IN1_GPIO_Port         GPIOE         // IN1端端口
#define Motor4_IN1_GPIO_Pin          GPIO_PIN_14   // IN1端端子
#define Motor4_IN2_PWM_Timer         &htim1        // IN2端输入PWM
#define Motor4_IN2_PWM_Timer_Handle  TIM1          // IN2端定时器句柄
#define Motor4_IN2_PWM_Timer_Channel TIM_CHANNEL_3 // IN2端输入通道
#define Motor4_IN2_GPIO_Port         GPIOE         // IN2端端口
#define Motor4_IN2_GPIO_Pin          GPIO_PIN_13   // IN2端端子
#define Motor4_Encoder_Timer_Handle  &htim5        // 编码器定时器
#define Motor4_Encoder_Timer         TIM5          // 编码器定时器

#endif
/********************采样定时器定义**********************/
#define Sample_Timer_Handle &htim6 // 采样定时器
#define Sample_Timer        TIM6   // 采样定时器

/****************************变量定义段*******************************/
/********************电机变量定义************************/

typedef enum Motor_State {
    Motor_STOP,
    Motor_RUN
} Motor_State; // 电机运行状态

typedef struct
{
    int encode_old;
    int encode_now;
    float speed;
} ENCODER; // 编码器结构体

typedef struct
{
    uint8_t id;        /* 电机ID */
    Motor_State state; /* 电机状态 */
    float speed;       /* 电机速度 */
    ENCODER encoder;   /* 编码器 */
    int32_t pwm;       /* 电机PWM值 */
    PID pid;
} Motor; // 电机结构体
/*********************用户变量**************************/

extern Motor motor1;
extern Motor motor2;
extern Motor motor3;
extern Motor motor4;
/*********************用户函数**************************/

void Motor_Init(Motor *umotor, uint8_t ID, float KP, float KI, float KD);
void Motor_Speed_Set(Motor *umotor, float speed);
void Motor_Start(Motor *umotor);
#endif
