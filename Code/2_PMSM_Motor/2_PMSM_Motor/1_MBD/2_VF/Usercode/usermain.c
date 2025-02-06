#include "usermain.h"

float potentiometer_voltage; // 电位器电压
float Ia, Ib, Ic;
uint16_t IA_Offset, IB_Offset, IC_Offset;

uint16_t adc1_in1, adc1_in2, adc1_in3, adc_vbus;
uint8_t ADC_offset  = 0;
uint8_t Motor_state = 0;

void usermain(void)
{
    RetargetInit(&huart3);

    // 三相电流采样输入运放初始化
    HAL_OPAMP_Start(&hopamp1);
    HAL_OPAMP_Start(&hopamp2);
    HAL_OPAMP_Start(&hopamp3);
    // ADC 校准
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
    __HAL_ADC_CLEAR_FLAG(&hadc1, ADC_FLAG_JEOC);
    __HAL_ADC_CLEAR_FLAG(&hadc1, ADC_FLAG_EOC);
    __HAL_ADC_CLEAR_FLAG(&hadc2, ADC_FLAG_JEOC);
    // 采样定时器启动
    HAL_TIM_Base_Start(&htim1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    // 采样定时器配置
    TIM1->ARR  = 8000 - 1;
    TIM1->CCR4 = 8000 - 2;
    // 三相电流采样注入组转换
    HAL_ADCEx_InjectedStart_IT(&hadc1);
    HAL_ADCEx_InjectedStart(&hadc2);
    // // 启动过流比较器
    // HAL_DAC_Start(&hdac3, DAC_CHANNEL_1);
    // HAL_DAC_SetValue(&hdac3, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 3000);
    // HAL_COMP_Start(&hcomp1);
    // VF 参数配置
    rtU.u_d  = 0;
    rtU.u_q  = 12;
    rtU.Freq = 4;
    rtU.T_pwm = 1;
    while (1) {

        // 电位器电压规则组转换
        HAL_ADC_Start(&hadc1);
        // 母线电压规则组转换
        HAL_ADC_Start(&hadc2);
        // 电位器电压计算
        potentiometer_voltage = HAL_ADC_GetValue(&hadc1);
        potentiometer_voltage = potentiometer_voltage * 3.3f / 4096;
        // 母线电压计算
        adc_vbus = HAL_ADC_GetValue(&hadc2);
        rtU.u_dc = adc_vbus * 3.3f / 4096 * 26;

        printf("%.2f,%.2f,%.2f,%.2f\r\n", potentiometer_voltage, Ia, Ib, Ic);
        HAL_Delay(1);
    }
}

/**
 * @brief   ADC 注入组转换中断函数
 */
void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    static uint8_t cnt;
    UNUSED(hadc);
    if (hadc == &hadc1) {
        // 均值滤波
        if (ADC_offset == 0) {
            cnt++;
            adc1_in1 = hadc1.Instance->JDR1;
            adc1_in2 = hadc2.Instance->JDR1;
            adc1_in3 = hadc1.Instance->JDR2;
            IA_Offset += adc1_in1;
            IB_Offset += adc1_in2;
            IC_Offset += adc1_in3;
            if (cnt >= 10) {
                ADC_offset = 1;
                IA_Offset  = IA_Offset / 10;
                IB_Offset  = IB_Offset / 10;
                IC_Offset  = IC_Offset / 10;
            }
        } else {
            adc1_in1 = hadc1.Instance->JDR1;
            adc1_in3 = hadc1.Instance->JDR2;
            adc1_in2 = hadc2.Instance->JDR1;
            Ia       = (adc1_in1 - IA_Offset) * 0.02197f;
            Ib       = (adc1_in2 - IB_Offset) * 0.02197f;
            Ic       = (adc1_in3 - IC_Offset) * 0.02197f;
            VF_Mode_step();
            TIM1->CCR1 = rtY.Duty[0] * 8000;
            TIM1->CCR2 = rtY.Duty[1] * 8000;
            TIM1->CCR3 = rtY.Duty[2] * 8000;
        }
    }
}

/**
 * @brief   按键外部中断函数
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    UNUSED(GPIO_Pin);
    if (Button3_Pin == GPIO_Pin) {
        Motor_state = ~Motor_state;
        if (0 == Motor_state) {
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
            HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
            HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);
        } else {
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
            HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
            HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
            HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
        }
    }
}
