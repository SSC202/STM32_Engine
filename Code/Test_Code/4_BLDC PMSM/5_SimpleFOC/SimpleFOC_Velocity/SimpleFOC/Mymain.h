#ifndef MYPROJECT_H
#define MYPROJECT_H

#include "stm32f1xx.h" 
#include "usart.h"
#include "delay.h"
#include "tim.h"

#include "foc_utils.h" 
#include "FOCMotor.h" 
#include "BLDCmotor.h" 
#include "pid.h"
#include "as5600.h"
#include "LPF.h"

#define M_Enable    do{HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);}while(0)      
#define M_Disable   do{HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);}while(0)     

#endif