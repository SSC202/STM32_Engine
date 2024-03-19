/**
 * @file    SimpleFOC 自建简化驱动库(有感FOC)
 */

#if (STM32F103xE)
#include "stm32f1xx.h"
#include "tim.h"

#define PI     3.1415926
#define SQRT_3 1.73205080756895286528

/**
 * @brief   PWM 通道定义
 */
#define PWM_1_TIMER         TIM2
#define PWM_1_TIMER_HANDDLE &htim2
#define PWM_2_TIMER         TIM2
#define PWM_2_TIMER_HANDDLE &htim2
#define PWM_3_TIMER         TIM2
#define PWM_3_TIMER_HANDDLE &htim2
#define PWM_1_CHANNEL       TIM_CHANNEL_2
#define PWM_2_CHANNEL       TIM_CHANNEL_3
#define PWM_3_CHANNEL       TIM_CHANNEL_4
#define Motor_Enable_Port   GPIOA
#define Motor_Enable_Pin    GPIO_PIN_4

#define V_Limit             6.7
#define V_dc                12
#define Pole_Pair           7

/* 运行模式定义 */
typedef enum Run_Mode {
    Open_Loop,
} Run_Mode;

void SimpleFOC_Init(void);
void SimpleFOC_RUN(int mode, float target);

#endif