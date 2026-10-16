#include "usermain.h"

PID_t speed_pid;
float speed_ref;

static void init()
{
    PID_init(&speed_pid, 0.0001, 0.001, 0, 1);

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
    static uint8_t hall_value;      // HALL value
    static uint8_t hall_statu;      // HALL statu
    static uint8_t hall_edge_statu; // HALL edge statu
    static uint16_t hall_no_single;
    static uint16_t count; // Counter

    static float speed;
    static float duty;
    static uint8_t direct;
    // 10kHz High frequency --- HALL read and pwm generate
    if (htim == &htim1) {
        // Read HALL Sensor
        hall_read(&hall_value, &hall_statu);
        // speed caculate
        count++;
        hall_edge_statu = hall_edge_read(hall_statu);
        switch (hall_edge_statu) {
            case 0:
                if (direct == 0) {
                    speed = (60 * 10000) / (2 * 4 * count);
                } else if (direct == 1) {
                    speed = -(60 * 10000) / (2 * 4 * count); // Caculate u phase High-level time,use high frequency counter. pole pairs is 4. 10000 is sample frequent.
                }
                hall_no_single = 0;
                count          = 0;
                break;
            case 1:
                hall_no_single = 0;
                count          = 0;
                break;
            case 2:
                hall_no_single++;
                if (hall_no_single > 15000) {
                    hall_no_single = 0;
                    speed          = 0;
                }
                break;
            default:
                break;
        }
        // PID caculate
        speed_pid.fdb = speed;
        speed_pid.ref = speed_ref;
        PID_Calc(&speed_pid, 1, 1e-4);
        duty = speed_pid.output;
        // pwm generate
        if (duty < 0) {
            duty   = -duty;
            direct = 1;
        } else {
            duty   = duty;
            direct = 0;
        }
        switch (direct) {
            case 0: // CW
                switch (hall_value) {
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
                switch (hall_value) {
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