#ifndef __BLDC_H
#define __BLDC_H

#include "bldc.h"
#include "tim.h"

#define UL_Port     GPIOB
#define UL_Pin      GPIO_PIN_13
#define VL_Port     GPIOB
#define VL_Pin      GPIO_PIN_14
#define WL_Port     GPIOB
#define WL_Pin      GPIO_PIN_15

#define HALL_U_Port GPIOB
#define HALL_U_Pin  GPIO_PIN_6
#define HALL_V_Port GPIOB
#define HALL_V_Pin  GPIO_PIN_7
#define HALL_W_Port GPIOB
#define HALL_W_Pin  GPIO_PIN_8

uint8_t hall_edge_read(uint8_t val);
void hall_read(uint8_t *hall_value, uint8_t *hall_statu);
void bldc_pwm(uint8_t step, float duty);

#endif