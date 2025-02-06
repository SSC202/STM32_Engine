#include "steer.h"

/**
 * @brief   舵机初始化函数
 */
void Servo_Init(void)
{
    Servo_Control(0);
}

/**
 * @brief   舵机控制函数
 * @param   angle 舵机旋转角度
*/
void Servo_Control(uint16_t angle)
{
    float temp;
    temp = angle * 5 / 9 + 25;
    __HAL_TIM_SET_COMPARE(PWM_Timer_Handle, PWM_Timer_Channel_2, (uint16_t)temp);
}
