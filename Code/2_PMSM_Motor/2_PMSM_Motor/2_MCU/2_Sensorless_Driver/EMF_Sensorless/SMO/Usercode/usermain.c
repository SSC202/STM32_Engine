#include "usermain.h"

#define POLE_PAIRS 7             // 极对数
#define ENCODER_DIRECT 1         // 编码器方向
#define ENCODER_OFFSET 3.025010  // 编码器机械偏移

enum SYSTEM_SAMPLE_STATE
{
    SAMPLE_INIT, // 采样初始化
    SAMPLE_RUN   // 采样运行
};
enum SYSTEM_SAMPLE_STATE system_sample_state = SAMPLE_INIT; // 系统采样状态
const float system_sample_time = 2e-4;                      // 系统运行频率 10kHz(PWM 40kHz)
uint8_t system_enable = 0;                                  // 系统使能标志位
uint8_t system_print = 0;                                   // 系统打印标志位

Encoder_t encoder; // 编码器结构体

const float u_dc = 12.0f; // 母线电压(V)
abc_t i_abc;              // 三相电流(A)
dq_t i_dq;                // dq 轴电流(A)
dq_t u_dq;                // dq 轴指令电压(V)
abc_t u_abc;              // ABC 相指令电压(V)
duty_abc_t duty_abc;      // ABC 相占空比指令

PID_t speed_pi; // 速度环控制器
PID_t id_pi;    // 电流环d轴控制器
PID_t iq_pi;    // 电流环q轴控制器

float speed_ref; // 速度环指令

alpha_beta_t u_alpha_beta; // alpha-beta 轴系电压
alpha_beta_t i_alpha_beta; // alpha-beta 轴系电流
LPF_t i_alpha_lpf;         // alpha 轴系电流滤波器
LPF_t i_beta_lpf;          // beta 轴系电流滤波器
SMO_TypeDef smo;           // 滑模观测器

int fputc(int c, FILE *stream)
{
    uint8_t ch[] = {(uint8_t)c};
    HAL_UART_Transmit(&huart3, ch, 1, HAL_MAX_DELAY);
    return c;
}

void usermain()
{
    // 控制器初始化
    PID_Init(&id_pi, 0.015150, 82.178520, 0, u_dc / M_SQRT3);
    PID_Init(&iq_pi, 0.019434, 82.178520, 0, u_dc / M_SQRT3);
    PID_Init(&speed_pi, 0.0348555, 0.503485, 0, 2);
    LPF_Init(&i_alpha_lpf, 100, system_sample_time);
    LPF_Init(&i_beta_lpf, 100, system_sample_time);
    // SMO 初始化
    SMO_Init(&smo, 2, 10, 10000, 20000, 10, system_sample_time);
    // 编码器初始化
    Encoder_Init(&encoder, POLE_PAIRS, ENCODER_DIRECT, ENCODER_OFFSET);
    // 电流采样校准
    __HAL_ADC_CLEAR_FLAG(&hadc1, ADC_FLAG_JEOC);
    __HAL_ADC_CLEAR_FLAG(&hadc1, ADC_FLAG_EOC);
    HAL_TIM_Base_Start(&htim1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    HAL_ADCEx_InjectedStart_IT(&hadc1);
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
            printf("i_alpha:%.4f,%.4f\r\n", i_alpha_lpf.output, smo.i_hat.alpha);
            break;
        case 3:
            printf("i_beta:%.4f,%.4f\r\n", i_beta_lpf.output, smo.i_hat.beta);
            break;
        case 4:
            printf("theta:%.4f,%.4f\r\n", smo.theta_true, smo.theta_obs);
            break;
        case 5:
            printf("theta:%.4f,%.4f\r\n", smo.speed_true, smo.speed_obs);
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
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);

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

    static uint32_t adc_ic_offset_sum = 0;
    static uint32_t adc_ic = 0;
    static float adc_ic_offset = 0;

    if (hadc->Instance == ADC1)
    {
        if (system_sample_state == SAMPLE_INIT)
        {
            adc_cnt++;
            if (adc_cnt >= 1)
            {
                adc_ia_offset_sum += hadc1.Instance->JDR1;
                adc_ib_offset_sum += hadc1.Instance->JDR2;
                adc_ic_offset_sum += hadc1.Instance->JDR3;
            }
            if (adc_cnt == 1000)
            {
                adc_ia_offset = adc_ia_offset_sum / 1000.0f;
                adc_ib_offset = adc_ib_offset_sum / 1000.0f;
                adc_ic_offset = adc_ic_offset_sum / 1000.0f;
                system_sample_state = SAMPLE_RUN;
                adc_ia_offset_sum = 0;
                adc_ib_offset_sum = 0;
                adc_ic_offset_sum = 0;
                adc_cnt = 0;
            }
        }
        else
        {
            adc_ia = hadc1.Instance->JDR1;
            i_abc.a = ((((float)adc_ia - adc_ia_offset) / 4096.f) * 3.3f) * 20.0f;

            adc_ib = hadc1.Instance->JDR2;
            i_abc.b = ((((float)adc_ib - adc_ib_offset) / 4096.f) * 3.3f) * 20.0f;

            adc_ic = hadc1.Instance->JDR3;
            i_abc.c = ((((float)adc_ic - adc_ic_offset) / 4096.f) * 3.3f) * 20.0f;

            // 过流保护
            if ((i_abc.a * i_abc.a > 400) || (i_abc.b * i_abc.b > 400) || (i_abc.c * i_abc.c > 400))
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
     * @brief   SMO 运行
     */
    i_alpha_lpf.input = i_alpha_beta.alpha;
    LPF_Calc(&i_alpha_lpf, 1);

    i_beta_lpf.input = i_alpha_beta.beta;
    LPF_Calc(&i_beta_lpf, 1);

    abc_2_alphabeta(&u_abc, &u_alpha_beta);
    abc_2_alphabeta(&i_abc, &i_alpha_beta);
    smo.speed_true = encoder.encoder_speed * POLE_PAIRS * encoder.encoder_direct;
    smo.theta_true = encoder.electric_theta;
    smo.u.alpha = u_alpha_beta.alpha;
    smo.u.beta = u_alpha_beta.beta;
    smo.i.alpha = i_alpha_beta.alpha;
    smo.i.beta = i_alpha_beta.beta;
    SMO_Update(&smo);

    /**
     * @brief   FOC 运行
     */
    // speed PI Controller

    speed_pi.ref = speed_ref;
    speed_pi.fdb = encoder.encoder_speed;
    PID_Calc(&speed_pi, system_enable, system_sample_time);

    // abc-to-dq
    abc_2_dq(&i_abc, &i_dq, encoder.electric_theta);

    // (id=0 control)Current PI Controller
    // d-axis
    id_pi.ref = 0;
    id_pi.fdb = i_dq.d;
    PID_Calc(&id_pi, system_enable, system_sample_time);
    u_dq.d = id_pi.output;

    // q-axis
    iq_pi.ref = speed_pi.output;
    iq_pi.fdb = i_dq.q;
    PID_Calc(&iq_pi, system_enable, system_sample_time);
    u_dq.q = iq_pi.output;

    // dq-to-abc
    dq_2_abc(&u_dq, &u_abc, encoder.electric_theta);
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
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
}
