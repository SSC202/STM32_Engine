#include "usermain.h"

float shaft_angle = 0;
float open_velocity;
float uq;

void usermain(void)
{
    RetargetInit(&huart2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIM_Base_Start_IT(&htim2);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);

    uq            = 2.5;
    open_velocity = 2;
    while (1) {

        HAL_Delay(1);
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    static float el_angle;
    if (htim->Instance == htim2.Instance) {
        shaft_angle += open_velocity * 0.0001;
        el_angle = _normalizeAngle(_electricalAngle(shaft_angle, POLE_PAIRS));
        set_phase_voltage(uq, 0, el_angle);
    }
}