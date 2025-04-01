#include "usermain.h"

uint8_t direct; // rotate direct
float duty;   // pwm duty

static void init()
{
    direct = 0;
	  duty = 0;
    TIM1->CCR1 = 0;
    TIM1->CCR2 = 0;
    TIM1->CCR3 = 0;
    HAL_GPIO_WritePin(UL_Port, UL_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(VL_Port, VL_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(WL_Port, WL_Pin, GPIO_PIN_RESET);
    HAL_TIM_Base_Start_IT(&htim1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
}

void usermain()
{
    init();
    while (1) {
        ;
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    uint8_t hall; // HALL value
    // 10kHz High frequency --- HALL read and pwm generate
    if (htim == &htim1) {
        // Read HALL Sensor
        hall = hall_read();
        // pwm generate
        switch (direct) {
            case 0: // CW
                switch (hall) {
                    case 5:
                        bldc_pwm(1, duty);
                        break;
                    case 1:
                        bldc_pwm(2, duty);
                        break;
                    case 3:
                        bldc_pwm(3, duty);
                        break;
                    case 2:
                        bldc_pwm(4, duty);
                        break;
                    case 6:
                        bldc_pwm(5, duty);
                        break;
                    case 4:
                        bldc_pwm(6, duty);
                        break;
                    default:
                        bldc_pwm(1, duty);
                        break;
                }
                break;
            case 1: // CCW
                switch (hall) {
                    case 2:
                        bldc_pwm(1, duty);
                        break;
                    case 6:
                        bldc_pwm(2, duty);
                        break;
                    case 4:
                        bldc_pwm(3, duty);
                        break;
                    case 5:
                        bldc_pwm(4, duty);
                        break;
                    case 1:
                        bldc_pwm(5, duty);
                        break;
                    case 3:
                        bldc_pwm(6, duty);
                        break;
                    default:
                        bldc_pwm(1, duty);
                        break;
                }
                break;
            default:
                break;
        }
    }
}