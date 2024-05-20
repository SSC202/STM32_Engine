#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H

#include "stm32f1xx.h"
#include "tim.h"

/*************************用户定义段******************************/
#define MICRO_STEP              8       // 细分数
#define T1_FREQ                 1000000 // 时钟分频后频率
#define T_Accel                 0       // 梯形加减速
#define S_Accel                 1       // S形加减速

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

#if (S_Accel == 1)

#endif

typedef struct
{
#if (T_Accel == 1)
    uint8_t run_state; /* 当前电机状态 */
    dir_t dir;         /* 旋转方向 */
    int step_delay;    /* 脉冲间隔 */
    int decel_start;   /* 减速位置 */
    int decel_val;     /* 减速步数 */
    int min_delay;     /* 最小间隔 */
    int accel_count;   /* 加速步数 */
#endif
#if (S_Accel == 1)
    __IO uint8_t status;             /* 状态 */
    __IO dir_t dir;                  /* 方向 */
    __IO uint32_t pos;               /* 位置 */
    __IO uint16_t pluse_time;        /* 脉冲时间 */
    __IO int32_t Vo;                 /* 初始速度 */
    __IO int32_t Vt;                 /* 末速度 */
    __IO int32_t AccelTotalStep;     /* 加速总步数 */
    __IO int32_t DecPoint;           /* 开始减速的步数 */
    __IO int32_t TotalStep;          /* 完整曲线总步数 */
    __IO int32_t INC_AccelTotalStep; /* 加加速度步数 */
    __IO int32_t Dec_AccelTotalStep; /* 减加速度步数 */
#endif
} AccelData; // 梯形加减速变量

/**************************用户函数*******************************/

void Motor_Init(void);
#if (T_Accel == 1)
void Motor_Move(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);
#endif

#if (S_Accel == 1)
uint8_t Motor_Move(int16_t start_speed, int16_t end_speed, float acc_time, int32_t step);
#endif
#endif