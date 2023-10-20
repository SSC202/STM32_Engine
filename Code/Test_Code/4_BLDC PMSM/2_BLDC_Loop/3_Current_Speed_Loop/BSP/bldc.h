#ifndef _BLDC_H
#define _BLDC_H

#include "stm32g4xx.h"
#include "tim.h"
#include "pid.h"

/***************************************** 霍尔传感器接口 ***********************************************/

#define HALL_A_GPIO_Port GPIOB
#define HALL_A_GPIO_Pin  GPIO_PIN_6

#define HALL_B_GPIO_Port GPIOB
#define HALL_B_GPIO_Pin  GPIO_PIN_7

#define HALL_C_GPIO_Port GPIOB
#define HALL_C_GPIO_Pin  GPIO_PIN_8

/****************************************** 电机接口 ****************************************************/
/* 上桥臂定义 */
#define MOTOR_HIGH_SIDE_TIMER        TIM1
#define MOTOR_HIGH_SIDE_TIMER_HANDLE &htim1

#define MOTOR_HIGH_SIDE_U_PORT       GPIOA
#define MOTOR_HIGH_SIDE_U_PIN        GPIO_PIN_8
#define MOTOR_HIGH_SIDE_U_CHANNEL    TIM_CHANNEL_1

#define MOTOR_HIGH_SIDE_V_PORT       GPIOA
#define MOTOR_HIGH_SIDE_V_PIN        GPIO_PIN_9
#define MOTOR_HIGH_SIDE_V_CHANNEL    TIM_CHANNEL_2

#define MOTOR_HIGH_SIDE_W_PORT       GPIOA
#define MOTOR_HIGH_SIDE_W_PIN        GPIO_PIN_10
#define MOTOR_HIGH_SIDE_W_CHANNEL    TIM_CHANNEL_3

/* 下桥臂定义 */
#define MOTOR_LOW_SIDE_U_PORT GPIOB
#define MOTOR_LOW_SIDE_U_PIN  GPIO_PIN_13

#define MOTOR_LOW_SIDE_V_PORT GPIOB
#define MOTOR_LOW_SIDE_V_PIN  GPIO_PIN_14

#define MOTOR_LOW_SIDE_W_PORT GPIOB
#define MOTOR_LOW_SIDE_W_PIN  GPIO_PIN_15

#define SAMPLE_TIMER          TIM6
#define SAMPLE_TIMER_HANDLE   &htim6

/* 极对数 */
#define POLE_PAIRS 4
/***************************************** 电机状态结构体 ***********************************************/
#define CCW        (1) /* 逆时针 */
#define CW         (2) /* 顺时针 */

#define HALL_ERROR (0xF0) /* 霍尔错误标志 */
#define RUN        (1)    /* 电机运动标志 */
#define STOP       (0)    /* 电机停机标志 */

typedef struct BLDC_Motor {
    __IO uint8_t run_flag;        /* 运行标志 */
    __IO uint8_t locked_rotor;    /* 堵转标记 */
    __IO uint8_t step_sta;        /* 本次霍尔状态 */
    __IO uint8_t hall_single_sta; /* 单个霍尔状态 */
    __IO uint8_t hall_sta_edge;   /* 单个霍尔状态跳变 */
    __IO uint8_t step_last;       /* 上次霍尔状态 */
    __IO uint8_t dir;             /* 电机旋转方向 */
    __IO int32_t pos;             /* 电机位置 */
    __IO int32_t speed;           /* 电机速度 */
    __IO int16_t current;         /* 电机速度 */
    __IO uint16_t pwm_duty;       /* 电机占空比 */
    __IO uint32_t hall_keep_t;    /* 霍尔保持时间 */
    __IO uint32_t hall_pul_num;   /* 霍尔传感器脉冲数 */
    __IO uint32_t lock_time;      /* 电机堵转时间 */
    __IO float current_u;         /* U相电流 */
    __IO float current_v;         /* V相电流 */
    __IO float current_w;         /* W相电流 */
    __IO float current_s;           /* 母线 */
    __IO uint32_t no_single;
    __IO uint32_t count_j;
} BLDC_Motor;

extern BLDC_Motor motor;
extern PID speed_pid;
/********************************************** 用户函数 ************************************************/
void BLDC_Motor_Stop(void);
void BLDC_Motor_Start(void);
void BLDC_Motor_Speed_Set(int32_t speed);
void BLDC_Motor_Init(void);
void BLDC_Motor_Current_Read(void);

#endif