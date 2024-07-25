#include "usermain.h"

float shaft_vel;    // 机械速度
float shaft_theta;  // 机械角度
PID_t velocity_pid; // 速度pid

void usermain(void)
{
    RetargetInit(&huart2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
    pid_init(&velocity_pid, 0.1, 0.001, 0.00);

    HAL_Delay(2000);

    // 编码器校准
    align_sensor();

    HAL_Delay(1000);

    HAL_TIM_Base_Start_IT(&htim2);
    HAL_TIM_Base_Start_IT(&htim3);
    velocity_pid.SetPoint = 12;

    while (1) {
        shaft_theta = AS5600_Read_Angle();
        printf("%.4f,%.4f\r\n", shaft_vel, shaft_theta);
        HAL_Delay(1);
    }
}

/**
 * @brief   定时中断函数
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    static float angle_now, angle_prev;
    static float vel_now, vel_prev;
    static float shaft_angle, el_angle;
    static float velocity_pid_output;
    // 中断周期10ms(100Hz)
    if (htim->Instance == htim2.Instance) {
        // Caculate
        angle_now = sensor_direction * shaft_theta;
        vel_now   = (angle_now - angle_prev) / 0.01;
        // LPF
        shaft_vel = 0.3 * vel_now + 0.7 * vel_prev;
        // Update
        vel_prev   = shaft_vel;
        angle_prev = angle_now;
    }
    // 中断周期10ms(100Hz)
    if (htim->Instance == htim3.Instance) {
        // Update
        shaft_angle         = sensor_direction * shaft_theta;
        el_angle            = _normalizeAngle(shaft_angle * POLE_PAIRS - zero_electric_angle);
        velocity_pid_output = pid_calc(&velocity_pid, shaft_vel);
        if (velocity_pid_output >= 5) {
            velocity_pid_output = 5;
        } else if (velocity_pid_output <= -5) {
            velocity_pid_output = -5;
        }
        set_phase_voltage(velocity_pid_output, 0, el_angle);
    }
}