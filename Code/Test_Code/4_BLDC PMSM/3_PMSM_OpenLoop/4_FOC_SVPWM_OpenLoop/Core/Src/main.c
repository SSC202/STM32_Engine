/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "comp.h"
#include "dac.h"
#include "opamp.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "VF.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define Button3_Pin       GPIO_PIN_13
#define Button3_GPIO_Port GPIOC
#define Button3_EXTI_IRQn EXTI15_10_IRQn
#define LED2_Pin          GPIO_PIN_4
#define LED2_GPIO_Port    GPIOC
#define LED1_Pin          GPIO_PIN_6
#define LED1_GPIO_Port    GPIOC
#define Button1_Pin       GPIO_PIN_10
#define Button1_GPIO_Port GPIOC
#define Button1_EXTI_IRQn EXTI15_10_IRQn
#define Button2_Pin       GPIO_PIN_11
#define Button2_GPIO_Port GPIOC
#define Button2_EXTI_IRQn EXTI15_10_IRQn
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
float Ia, Ib, Ic;
float load_data[5];
uint16_t adc1_in1, adc1_in2, adc1_in3, adc1_in4, adc_vbus;
uint16_t IA_Offset, IB_Offset, IC_Offset;
uint8_t ADC_offset  = 0;
uint16_t finalspeed = 0;
uint8_t Motor_state = 0;

extern ExtU rtU;
extern ExtY rtY;
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_ADC2_Init();
    MX_COMP1_Init();
    MX_DAC3_Init();
    MX_OPAMP1_Init();
    MX_OPAMP2_Init();
    MX_OPAMP3_Init();
    MX_TIM1_Init();
    MX_USART3_UART_Init();
    MX_DAC1_Init();
    /* USER CODE BEGIN 2 */
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
    __HAL_ADC_CLEAR_FLAG(&hadc1, ADC_FLAG_JEOC);
    __HAL_ADC_CLEAR_FLAG(&hadc1, ADC_FLAG_EOC);
    __HAL_ADC_CLEAR_FLAG(&hadc2, ADC_FLAG_JEOC);
    HAL_ADCEx_InjectedStart_IT(&hadc1);
    HAL_ADCEx_InjectedStart(&hadc2);
    TIM1->ARR  = 8000 - 1;
    TIM1->CCR4 = 8000 - 2;
    HAL_TIM_Base_Start(&htim1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    rtU.ud   = 0;
    rtU.uq   = 12;
    rtU.Freq = 4;
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
        HAL_ADC_Start(&hadc2);
        adc_vbus  = HAL_ADC_GetValue(&hadc2);
        rtU.ubus = adc_vbus * 3.3f / 4096 * 26;
        HAL_Delay(10);
    }
    /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
     */
    HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState       = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState   = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource  = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM       = RCC_PLLM_DIV3;
    RCC_OscInitStruct.PLL.PLLN       = 40;
    RCC_OscInitStruct.PLL.PLLP       = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ       = RCC_PLLQ_DIV2;
    RCC_OscInitStruct.PLL.PLLR       = RCC_PLLR_DIV2;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType      = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK) {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
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

void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    static uint8_t cnt;
    if (hadc == &hadc1) {
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
            VF_step();
            TIM1->CCR1   = (int)(rtY.DutyOut[0] * 8000);
            TIM1->CCR2   = (int)(rtY.DutyOut[1] * 8000);
            TIM1->CCR3   = (int)(rtY.DutyOut[2] * 8000);
            load_data[0] = Ia;
            load_data[1] = Ib;
            load_data[2] = rtY.DutyOut[0];
            load_data[3] = rtY.DutyOut[1];
            load_data[4] = rtY.DutyOut[2];
        }
    }

    /* NOTE : This function should not be modified. When the callback is needed,
              function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
    */
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
