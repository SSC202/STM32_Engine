#include "usermain.h"

#define PI                3.14159265358979f
#define PHASE_SHIFT_ANGLE (float)(220.0f / 360.0f * 2.0f * PI)

float potentiometer_voltage; // 电位器电压
uint16_t IA_Offset, IB_Offset, IC_Offset;

uint16_t adc1_in1, adc1_in2, adc1_in3, adc_vbus;
uint8_t ADC_offset  = 0;
uint8_t Motor_state = 0;

float HallTemp       = 0;
float HallThetaAdd   = 0;
float HallTheta      = 0;
float HallSpeed      = 0;
float HallSpeedLast  = 0;
float HallSpeedtest  = 0;
float alpha          = 0.3;
uint8_t HallReadTemp = 0;

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
    // 启动过流比较器
    HAL_DAC_SetValue(&hdac3, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 3000);
    HAL_DAC_Start(&hdac3, DAC_CHANNEL_1);
    HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
    HAL_COMP_Start(&hcomp1);
    // 启动霍尔传感器
    HAL_TIMEx_HallSensor_Start_IT(&htim4);
    // FOC 参数配置
    rtU.T_pwm    = 1;
    rtU.SpeedRef = 1000;
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

        printf("%.2f,%.2f,%.2f,%.2f\r\n", rtU.SpeedFd, rtU.I_a, rtU.I_b, rtU.I_c);
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
            // HALL 编码器读取速度和角度
            HallTheta = HallTheta + HallThetaAdd;
            if (HallTheta < 0.0f) {
                HallTheta += 2.0f * PI;
            } else if (HallTheta > (2.0f * PI)) {
                HallTheta -= 2.0f * PI;
            }
            rtU.theta   = HallTheta;
            rtU.SpeedFd = HallSpeed;
            // 一阶低通LPF(未使用)
            HallSpeedtest = alpha * HallSpeed + (1 - alpha) * HallSpeedLast;
            HallSpeedLast = HallSpeed;
            // 电流采样
            adc1_in1 = hadc1.Instance->JDR1;
            adc1_in3 = hadc1.Instance->JDR2;
            adc1_in2 = hadc2.Instance->JDR1;
            rtU.I_a  = (adc1_in1 - IA_Offset) * 0.01933593f;
            rtU.I_b  = (adc1_in2 - IB_Offset) * 0.01933593f;
            rtU.I_c  = (adc1_in3 - IC_Offset) * 0.01933593f;
            FOC_Mode_step();
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
            rtU.Motor_OnOff = 0;
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
            HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
            HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
            HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);
        } else {
            rtU.Motor_OnOff = 1;
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
            HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
            HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
            HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
        }
    }
}

/**
 * @brief   HALL传感器定时中断函数
 */

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim4) {
        HallTemp     = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);
        HallThetaAdd = (PI / 3) / (HallTemp / 10000000) / 10000;
        HallSpeed    = (PI / 3) / (HallTemp / 10000000) * 30 / (2 * PI);
        HallReadTemp = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
        HallReadTemp |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) << 1;
        HallReadTemp |= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) << 2;
        if (HallReadTemp == 0x05) {
            HallTheta = 0.0f + PHASE_SHIFT_ANGLE;
        } else if (HallReadTemp == 0x04) {
            HallTheta = (PI / 3.0f) + PHASE_SHIFT_ANGLE;
        } else if (HallReadTemp == 0x06) {
            HallTheta = (PI * 2.0f / 3.0f) + PHASE_SHIFT_ANGLE;
        } else if (HallReadTemp == 0x02) {
            HallTheta = PI + PHASE_SHIFT_ANGLE;
        } else if (HallReadTemp == 0x03) {
            HallTheta = (PI * 4.0f / 3.0f) + PHASE_SHIFT_ANGLE;
        } else if (HallReadTemp == 0x01) {
            HallTheta = (PI * 5.0f / 3.0f) + PHASE_SHIFT_ANGLE;
        }
        if (HallTheta < 0.0f) {
            HallTheta += 2.0f * PI;
        } else if (HallTheta > (2.0f * PI)) {
            HallTheta -= 2.0f * PI;
        }
    }
}
