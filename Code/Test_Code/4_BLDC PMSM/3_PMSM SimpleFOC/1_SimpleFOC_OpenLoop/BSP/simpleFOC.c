#include "simpleFOC.h"
#include "math.h"
#include <stdio.h>

float zero_angle_el = 0.0f; // 电角度零点
float shaft_angle   = 0.0f; // 机械角度
uint32_t time_stamp = 0;    // 时间戳

#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))
#define round(x)                  ((x) >= 0 ? (long)((x) + 0.5) : (long)((x)-0.5))

/*********************************基础驱动函数*********************************/
const int sine_array[200] = {0, 79, 158, 237, 316, 395, 473, 552, 631, 710, 789, 867, 946, 1024, 1103, 1181, 1260, 1338, 1416, 1494, 1572, 1650, 1728, 1806, 1883, 1961, 2038, 2115, 2192, 2269, 2346, 2423, 2499, 2575, 2652, 2728, 2804, 2879, 2955, 3030, 3105, 3180, 3255, 3329, 3404, 3478, 3552, 3625, 3699, 3772, 3845, 3918, 3990, 4063, 4135, 4206, 4278, 4349, 4420, 4491, 4561, 4631, 4701, 4770, 4840, 4909, 4977, 5046, 5113, 5181, 5249, 5316, 5382, 5449, 5515, 5580, 5646, 5711, 5775, 5839, 5903, 5967, 6030, 6093, 6155, 6217, 6279, 6340, 6401, 6461, 6521, 6581, 6640, 6699, 6758, 6815, 6873, 6930, 6987, 7043, 7099, 7154, 7209, 7264, 7318, 7371, 7424, 7477, 7529, 7581, 7632, 7683, 7733, 7783, 7832, 7881, 7930, 7977, 8025, 8072, 8118, 8164, 8209, 8254, 8298, 8342, 8385, 8428, 8470, 8512, 8553, 8594, 8634, 8673, 8712, 8751, 8789, 8826, 8863, 8899, 8935, 8970, 9005, 9039, 9072, 9105, 9138, 9169, 9201, 9231, 9261, 9291, 9320, 9348, 9376, 9403, 9429, 9455, 9481, 9506, 9530, 9554, 9577, 9599, 9621, 9642, 9663, 9683, 9702, 9721, 9739, 9757, 9774, 9790, 9806, 9821, 9836, 9850, 9863, 9876, 9888, 9899, 9910, 9920, 9930, 9939, 9947, 9955, 9962, 9969, 9975, 9980, 9985, 9989, 9992, 9995, 9997, 9999, 10000, 10000};

/**
 * @brief   查表sin函数
 */
float _sin(float a)
{
    if (a < (PI / 2)) {
        return 0.0001 * sine_array[round(126.6873 * a)];
    } else if (a < PI) {
        return 0.0001 * sine_array[398 - round(126.6873 * a)];
    } else if (a < (3 * (PI / 2))) {
        return -0.0001 * sine_array[-398 + round(126.6873 * a)];
    } else {
        return -0.0001 * sine_array[796 - round(126.6873 * a)];
    }
}

/**
 * @brief   查表cos函数
 */
float _cos(float a)
{
    float a_sin = a + (PI / 2);
    a_sin       = a_sin > (2 * PI) ? a_sin - (2 * PI) : a_sin;
    return _sin(a_sin);
}

/**
 * @brief   PWM设置函数
 */
void Set_PWM(float ua, float ub, float uc)
{
    // voltage limit
    ua = constrain(ua, 0.0f, V_Limit);
    ub = constrain(ub, 0.0f, V_Limit);
    uc = constrain(uc, 0.0f, V_Limit);
    // Calculate PWM
    float dc_a = 0, dc_b = 0, dc_c = 0;
    dc_a = constrain(ua / V_dc, 0.0f, 1.0f);
    dc_b = constrain(ub / V_dc, 0.0f, 1.0f);
    dc_c = constrain(uc / V_dc, 0.0f, 1.0f);
    // Set PWM
    __HAL_TIM_SetCompare(PWM_1_TIMER_HANDDLE, PWM_1_CHANNEL, dc_a * 20000);
    __HAL_TIM_SetCompare(PWM_2_TIMER_HANDDLE, PWM_2_CHANNEL, dc_b * 20000);
    __HAL_TIM_SetCompare(PWM_3_TIMER_HANDDLE, PWM_3_CHANNEL, dc_c * 20000);
}

/**
 * @brief   电角度求解
 */
float electrical_angle(float shaftangle)
{
    return (shaftangle * Pole_Pair);
}

/**
 * @brief   角度归一化
 */
float normalize_angle(float angle)
{
    float a = fmod(angle, 2 * PI);
    return a >= 0 ? a : (a + 2 * PI);
}

/**
 * @brief   电机电压驱动函数
 * @param   uq  Uq
 * @param   ud  Ud
 * @param   angle_el    电角度
 */
void Set_Voltage(float uq, float ud, float angle_el)
{
    angle_el = normalize_angle(angle_el + zero_angle_el);
    // Anti_Park
    float u_alpha, u_beta;
    u_alpha = -uq * _sin(angle_el);
    u_beta  = uq * _cos(angle_el);

    // Anti_Clark
    float ua, ub, uc;
    ua = u_alpha + V_dc / 2;
    ub = (SQRT_3 * u_beta - u_alpha) / 2 + V_dc / 2;
    uc = (-u_alpha - SQRT_3 * u_beta) / 2 + V_dc / 2;

    // Debug print
    printf("%.2f,%.2f,%.2f\r\n", ua, ub, uc);

    // PWM Set
    Set_PWM(ua, ub, uc);
}

/**
 * @brief   读取系统运行时间函数
 */
__STATIC_INLINE uint32_t GXT_SYSTICK_IsActiveCounterFlag(void)
{
    return ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == (SysTick_CTRL_COUNTFLAG_Msk));
}

/**
 * @brief   读取系统运行时间函数
 */
static uint32_t getCurrentMicros(void)
{
    /* Ensure COUNTFLAG is reset by reading SysTick control and status register */
    GXT_SYSTICK_IsActiveCounterFlag();
    uint32_t m         = HAL_GetTick();
    const uint32_t tms = SysTick->LOAD + 1;
    __IO uint32_t u    = tms - SysTick->VAL;
    if (GXT_SYSTICK_IsActiveCounterFlag()) {
        m = HAL_GetTick();
        u = tms - SysTick->VAL;
    }
    return (m * 1000 + (u * 1000) / tms);
}

/*********************************电机运行函数*********************************/
/**
 * @brief   SimpleFOC 运行函数
 * @param   mode    运行模式
 *
 * @param   target  1. 如果为Open_Loop,为目标速度
 */
void SimpleFOC_RUN(int mode, float target)
{
    uint32_t now_us;
    double ts;
    // Get Time
    now_us = getCurrentMicros();
    ts     = (now_us - time_stamp) * (0.000001);

    // Debug print
    // printf("%.6f\r\n", ts);
    switch (mode) {
        case Open_Loop:
            // Calculate Shaft angle
            shaft_angle = normalize_angle(shaft_angle + target * ts);

            // Debug print
            // printf("%.6f\r\n", shaft_angle);

            Set_Voltage(V_Limit, 0, electrical_angle(shaft_angle));
            time_stamp = now_us;
            HAL_Delay(1);
            break;
        default:
            break;
    }
}

/**
 * @brief   SimpleFOC 初始化函数
 */
void SimpleFOC_Init(void)
{
    HAL_TIM_PWM_Start(PWM_1_TIMER_HANDDLE, PWM_1_CHANNEL);
    HAL_TIM_PWM_Start(PWM_2_TIMER_HANDDLE, PWM_2_CHANNEL);
    HAL_TIM_PWM_Start(PWM_3_TIMER_HANDDLE, PWM_3_CHANNEL);
    HAL_GPIO_WritePin(Motor_Enable_Port, Motor_Enable_Pin, GPIO_PIN_SET);
    HAL_Delay(100);
}