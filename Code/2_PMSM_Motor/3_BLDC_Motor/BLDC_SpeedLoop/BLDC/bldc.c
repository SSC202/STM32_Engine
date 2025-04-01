#include "bldc.h"

/**
 * @brief   BLDC 六步实现,H_PWM_L_ON 模式
 * @param   step    扇区
 * @param   duty    PWM 占空比
 */
void bldc_pwm(uint8_t step, float duty)
{
    switch (step) {
        case 1: // U_PWM_V_ON
            TIM1->CCR1 = duty * TIM1->ARR;
            TIM1->CCR2 = 0;
            TIM1->CCR3 = 0;
            HAL_GPIO_WritePin(UL_Port, UL_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(VL_Port, VL_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(WL_Port, WL_Pin, GPIO_PIN_RESET);
            break;
        case 2: // U_PWM_W_ON
            TIM1->CCR1 = duty * TIM1->ARR;
            TIM1->CCR2 = 0;
            TIM1->CCR3 = 0;
            HAL_GPIO_WritePin(UL_Port, UL_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(VL_Port, VL_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(WL_Port, WL_Pin, GPIO_PIN_SET);
            break;
        case 3: // V_PWM_W_ON
            TIM1->CCR1 = 0;
            TIM1->CCR2 = duty * TIM1->ARR;
            TIM1->CCR3 = 0;
            HAL_GPIO_WritePin(UL_Port, UL_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(VL_Port, VL_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(WL_Port, WL_Pin, GPIO_PIN_SET);
            break;
        case 4: // V_PWM_U_ON
            TIM1->CCR1 = 0;
            TIM1->CCR2 = duty * TIM1->ARR;
            TIM1->CCR3 = 0;
            HAL_GPIO_WritePin(UL_Port, UL_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(VL_Port, VL_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(WL_Port, WL_Pin, GPIO_PIN_RESET);
            break;
        case 5: // W_PWM_U_ON
            TIM1->CCR1 = 0;
            TIM1->CCR2 = 0;
            TIM1->CCR3 = duty * TIM1->ARR;
            HAL_GPIO_WritePin(UL_Port, UL_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(VL_Port, VL_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(WL_Port, WL_Pin, GPIO_PIN_RESET);
            break;
        case 6: // W_PWM_V_ON
            TIM1->CCR1 = 0;
            TIM1->CCR2 = 0;
            TIM1->CCR3 = duty * TIM1->ARR;
            HAL_GPIO_WritePin(UL_Port, UL_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(VL_Port, VL_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(WL_Port, WL_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

/**
 * @brief       检测 HALL 单相输入信号是否发生变化
 * @param       val 输入信号
 * @retval      0：高电平时间; 1：低电平时间; 2：信号未改变
 */
uint8_t hall_edge_read(uint8_t val)
{
    static uint8_t oldval = 0;
    if (oldval != val) {
        oldval = val;
        if (val == 0)
            return 0;
        else
            return 1;
    }
    return 2;
}

/**
 * @brief   HALL 传感器读取
 * @param[out]   hall_value 输出 HALL 值
 * @param[out]   hall_statu u 相 HALL 状态
 */
void hall_read(uint8_t *hall_value, uint8_t *hall_statu)
{
    uint8_t u, v, w;
    u           = HAL_GPIO_ReadPin(HALL_U_Port, HALL_U_Pin);
    v           = HAL_GPIO_ReadPin(HALL_V_Port, HALL_V_Pin);
    w           = HAL_GPIO_ReadPin(HALL_W_Port, HALL_W_Pin);
    *hall_value = ((w << 2) | (v << 1) | u);
    *hall_statu = u;
}