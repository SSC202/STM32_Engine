#include "step_motor.h"

/********************* 宏定义段 *****************************/

#define MOTOR_ENA(x) HAL_GPIO_WritePin(Motor_ENA_Port, Motor_ENA_Pin, x)
#define MOTOR_DIR(x) HAL_GPIO_WritePin(Motor_DIR_Port, Motor_DIR_Pin, x)

#define MOTOR_STEP_ANGLE    1.8     // 步进电机步距角，1.8°

/******************* 驱动函数定义 ***************************/

/**
 * @brief 电机旋转方向设置
 * @param dir   方向，CW正转，CCW反转
 */
static void Motor_Dir_Set(dir_t dir)
{
    if (dir) {
        MOTOR_DIR(1);
    } else {
        MOTOR_DIR(0);
    }
}

/**
 * @brief   电机启动函数
 */
static void Motor_Start(void)
{
    MOTOR_ENA(0);
    HAL_TIM_PWM_Start(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);
}

/**
 * @brief   电机停止函数
 */
static void Motor_Stop(void)
{
    MOTOR_ENA(1);
    HAL_TIM_PWM_Stop(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);
}

/**
 * @brief 电机PWM设置函数
 * @param   us   PWM周期，单位为us
 */
void Motor_PWM_Set(float us)
{
    uint16_t para = 0;
    if (us > 20000) {
        us = 20000;
    } else if (us < -20000) {
        us = -20000;
    }
    HAL_TIM_PWM_Stop(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);
    if (us > 0) {
        para = (uint16_t)us;
        __HAL_TIM_SET_AUTORELOAD(Motor_PWM_Timer_Handle, para);
        __HAL_TIM_SET_COMPARE(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel, (uint16_t)(para / 2)); // 占空比默认为50%
        Motor_Dir_Set(1);                                                                             // 正转
        HAL_TIM_PWM_Start(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);
    } else if (us == 0) {
        __HAL_TIM_SET_AUTORELOAD(Motor_PWM_Timer_Handle, 20000);
        __HAL_TIM_SET_COMPARE(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel, 0); // 停止输出
    } else if (us < 0) {
        para = (uint16_t)(-us);
        __HAL_TIM_SET_AUTORELOAD(Motor_PWM_Timer_Handle, para);
        __HAL_TIM_SET_COMPARE(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel, (uint16_t)(para / 2)); // 占空比默认为50%
        Motor_Dir_Set(0);                                                                             // 反转
        HAL_TIM_PWM_Start(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);
    }
}
/******************* 用户函数定义 ***************************/

/**
 * @brief 电机初始化
 */
void Motor_Init(void)
{
    __HAL_TIM_SET_AUTORELOAD(Motor_PWM_Timer_Handle, 20000);
    __HAL_TIM_SET_COMPARE(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel, 0); // 停止输出
    Motor_Start();
    Motor_Dir_Set(1); // 正转
}

/**
 * @brief   开环速度控制函数
 * @param   speed:速度(rpm)
 */
void Motor_Speed_Set(float speed)
{
    float us = (MOTOR_STEP_ANGLE * 60.0f * 1000000.0f)/(speed * 360.0f * MICRO_STEP);
    Motor_PWM_Set(us);
}
