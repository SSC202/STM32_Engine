#include "foc_motor.h"

/**
 * @brief   三相电压设置函数
 * @note    AntiPark 变换 + SVPWM 七段发波算法
 * @param   u_q             q 轴电压
 * @param   u_d             d 轴电压
 * @param   electric_angle  电角度，需要归一化
 */
void set_phase_voltage(float u_q, float u_d, float electric_angle)
{
    // AntiPark 变换
    static float u_alpha;
    static float u_beta;

    u_alpha = u_d * _cos(electric_angle) - u_q * _sin(electric_angle);
    u_beta  = u_d * _sin(electric_angle) + u_q * _cos(electric_angle);

    // SVPWM
    // 1. 扇区判断
    static uint8_t sector;
    static uint8_t A, B, C, N;
    static float __u1, __u2, __u3;
    __u1 = u_beta;
    __u2 = (_SQRT3 * u_alpha - u_beta) / 2.0f;
    __u3 = (-_SQRT3 * u_alpha - u_beta) / 2.0f;
    if (__u1 > 0) {
        A = 1;
    } else {
        A = 0;
    }
    if (__u2 > 0) {
        B = 1;
    } else {
        B = 0;
    }
    if (__u3 > 0) {
        C = 1;
    } else {
        C = 0;
    }
    N = 4 * C + 2 * B + A;
    switch (N) {
        case 3:
            sector = 1;
            break;
        case 1:
            sector = 2;
            break;
        case 5:
            sector = 3;
            break;
        case 4:
            sector = 4;
            break;
        case 6:
            sector = 5;
            break;
        case 2:
            sector = 6;
            break;
        default:
            break;
    }
    // 2. 计算中间变量X,Y,Z
    static float X, Y, Z;
    X = (_SQRT3 * Ts * u_beta) / U_dc;
    Y = (_SQRT3 * Ts * (_SQRT3 * u_alpha + u_beta)) / (U_dc * 2);
    Z = (_SQRT3 * Ts * (-_SQRT3 * u_alpha + u_beta)) / (U_dc * 2);
    // printf("%d, %.3f,%.3f,%.3f\r\n", sector, X, Y, Z);
    // 3. 计算T4，T6
    static float T_4, T_6;
    switch (sector) {
        case 1:
            T_4 = -Z;
            T_6 = X;
            break;
        case 2:
            T_4 = Z;
            T_6 = Y;
            break;
        case 3:
            T_4 = X;
            T_6 = -Y;
            break;
        case 4:
            T_4 = -X;
            T_6 = Z;
            break;
        case 5:
            T_4 = -Y;
            T_6 = -Z;
            break;
        case 6:
            T_4 = Y;
            T_6 = -X;
            break;
        default:
            break;
    }
    // printf("%.3f,%.3f\r\n", T_4, T_6);
    if (T_4 + T_6 - Ts > 0) {
        T_4 = T_4 * Ts / (T_4 + T_6);
        T_6 = T_6 * Ts / (T_4 + T_6);
    }
    // 4. 计算占空比
    static float T_a, T_b, T_c;
    static float __T1, __T2, __T3;
    __T1 = (Ts - T_4 - T_6) / 4;
    __T2 = (Ts + T_4 - T_6) / 4;
    __T3 = (Ts + T_4 + T_6) / 4;
    switch (sector) {
        case 1:
            T_a = __T1;
            T_b = __T2;
            T_c = __T3;
            break;
        case 2:
            T_a = __T2;
            T_b = __T1;
            T_c = __T3;
            break;
        case 3:
            T_a = __T3;
            T_b = __T1;
            T_c = __T2;
            break;
        case 4:
            T_a = __T3;
            T_b = __T2;
            T_c = __T1;
            break;
        case 5:
            T_a = __T2;
            T_b = __T3;
            T_c = __T1;
            break;
        case 6:
            T_a = __T1;
            T_b = __T3;
            T_c = __T2;
            break;
        default:
            break;
    }
    static float duty_a, duty_b, duty_c;
    duty_a = T_a / Ts;
    duty_b = T_b / Ts;
    duty_c = T_c / Ts;
    // 设置 PWM 输出
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, (int)((1 - duty_a) * (TIM1->ARR)));
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, (int)((1 - duty_b) * (TIM1->ARR)));
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, (int)((1 - duty_c) * (TIM1->ARR)));
    // printf("%.3f,%.3f,%.3f\r\n", duty_a, duty_b, duty_c);
}
