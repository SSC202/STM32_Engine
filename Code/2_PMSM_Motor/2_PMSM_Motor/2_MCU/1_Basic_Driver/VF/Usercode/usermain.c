#include "usermain.h"

#define POLE_PAIRS 7         // 极对数
#define ENCODER_DIRECT 1     // 编码器方向
#define ENCODER_OFFSET -1.93 // 编码器机械偏移

enum SYSTEM_SAMPLE_STATE
{
    SAMPLE_INIT, // 采样初始化
    SAMPLE_RUN   // 采样运行
};
enum SYSTEM_SAMPLE_STATE system_sample_state = SAMPLE_INIT; // 系统采样状态
const float system_sample_time = 4e-4;                      // 系统运行频率 2.5kHz(PWM 40kHz)
uint8_t system_enable = 0;                                  // 系统使能标志位
uint8_t system_print = 0;                                   // 系统打印标志位

Encoder_t encoder; // 编码器结构体

const float u_dc = 12.0f; // 母线电压(V)
abc_t i_abc;              // 三相电流(A)
dq_t u_dq;                // dq 轴指令电压(V)
abc_t u_abc;              // ABC 相指令电压(V)
duty_abc_t duty_abc;      // ABC 相占空比指令

float electric_speed = 0; // VF 指令电角速度(rad/s)
float electric_theta = 0; // VF 指令电角度(rad)

int fputc(int c, FILE *stream)
{
    uint8_t ch[] = {(uint8_t)c};
    HAL_UART_Transmit(&huart2, ch, 1, HAL_MAX_DELAY);
    return c;
}

void usermain()
{
    // 编码器初始化
    Encoder_Init(&encoder, POLE_PAIRS, ENCODER_DIRECT, ENCODER_OFFSET);
    // ADC 采样初始化
    HAL_ADCEx_Calibration_Start(&hadc1);
    HAL_ADCEx_Calibration_Start(&hadc2);
    __HAL_ADC_CLEAR_FLAG(&hadc1, ADC_FLAG_JEOC);
    __HAL_ADC_CLEAR_FLAG(&hadc1, ADC_FLAG_EOC);
    HAL_TIM_Base_Start(&htim1);
    HAL_ADCEx_InjectedStart_IT(&hadc1);
    HAL_ADCEx_InjectedStart(&hadc2);
    while (system_sample_state == SAMPLE_INIT)
    {
        HAL_Delay(1);
    }
    // 使能 PWM 输出
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
    while (1)
    {
        switch (system_print)
        {
        case 0:
            printf("duty:%f,%f,%f\r\n", duty_abc.dutya, duty_abc.dutyb, duty_abc.dutyc);
            break;
        case 1:
            printf("iabc:%f,%f,%f\r\n", i_abc.a, i_abc.b, i_abc.c);
            break;
        case 2:
            printf("speed:%f\r\n", encoder.encoder_speed);
            break;
        default:
            break;
        }
    }
}

/**
 * @brief   ADC 注入通道采样回调函数
 */
void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);

    /**
     * @brief   三相电流采样
     */
    static uint32_t adc_cnt = 0;

    static uint32_t adc_ia_offset_sum = 0;
    static uint32_t adc_ia = 0;
    static float adc_ia_offset = 0;

    static uint32_t adc_ib_offset_sum = 0;
    static uint32_t adc_ib = 0;
    static float adc_ib_offset = 0;

    if (hadc->Instance == ADC1)
    {
        if (system_sample_state == SAMPLE_INIT)
        {
            adc_cnt++;
            if (adc_cnt >= 1)
            {
                adc_ia_offset_sum += hadc1.Instance->JDR1;
                adc_ib_offset_sum += hadc2.Instance->JDR1;
            }
            if (adc_cnt == 1000)
            {
                adc_ia_offset = adc_ia_offset_sum / 1000.0f;
                adc_ib_offset = adc_ib_offset_sum / 1000.0f;
                system_sample_state = SAMPLE_RUN;
                adc_ia_offset_sum = 0;
                adc_ib_offset_sum = 0;
                adc_cnt = 0;
            }
        }
        else
        {
            adc_ia = hadc1.Instance->JDR1;
            i_abc.a = ((((float)adc_ia - adc_ia_offset) / 4096.f) * 3.3f) * 1.f;

            adc_ib = hadc2.Instance->JDR1;
            i_abc.b = ((((float)adc_ib - adc_ib_offset) / 4096.f) * 3.3f) * 1.f;

            i_abc.c = -(i_abc.a + i_abc.b);

            // 过流保护
            if ((i_abc.a * i_abc.a > 16) || (i_abc.b * i_abc.b > 16) || (i_abc.c * i_abc.c > 16))
            {
                system_enable = 0;
            }
        }
    }

    /**
     * @brief   编码器采样
     */
    Encoder_Get_Angle_Speed(&encoder);

    /**
     * @brief   VF 开环运行
     */

    // 生成开环电压矢量
    u_dq.d = 2;
    u_dq.q = 0;

    electric_theta = electric_theta + electric_speed * system_sample_time;
    normalize(1, electric_theta, 0); // 归一化

    // dq-to-abc
    dq_2_abc(&u_dq, &u_abc, electric_theta);
    e_svpwm(&u_abc, u_dc, &duty_abc);

    /**
     * @brief   PWM 输出
     */
    if (system_enable == 1)
    {
        TIM1->CCR1 = duty_abc.dutya * TIM1->ARR;
        TIM1->CCR2 = duty_abc.dutyb * TIM1->ARR;
        TIM1->CCR3 = duty_abc.dutyc * TIM1->ARR;
    }
    else
    {
        TIM1->CCR1 = 0 * TIM1->ARR;
        TIM1->CCR2 = 0 * TIM1->ARR;
        TIM1->CCR3 = 0 * TIM1->ARR;
    }
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);
}