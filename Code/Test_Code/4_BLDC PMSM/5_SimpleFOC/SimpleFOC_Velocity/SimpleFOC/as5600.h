#ifndef __AS5600_H
#define __AS5600_H

#include "stm32f1xx.h"
/****************配置选择*********************/
/* 是否使能硬件IIC */
#define AS5600_IIC_HardWare 0
/* 是否使能软件IIC */
#define AS5600_IIC_SoftWare 1
/* 是否使用FreeRTOS */
#define USE_FreeRTOS 0
/****************芯片定义*********************/
#define AS5600_ADDR_Write         ((0X36 << 1) | 0x00) // 写地址
#define AS5600_ADDR_Read          ((0X36 << 1) | 0x01) // 读地址
#define AS5600_RAW_ANGLE_REGISTER 0x0C                 // 角度寄存器
/****************端口定义*********************/
#if (AS5600_IIC_SoftWare == 1)
#define IIC_SCL_Port GPIOB
#define IIC_SDA_Port GPIOB
#define IIC_SCL_Pin  GPIO_PIN_1
#define IIC_SDA_Pin  GPIO_PIN_2
#endif
/****************函数定义*********************/

extern long cpr;
extern float full_rotation_offset;
extern long angle_data_prev;
extern unsigned long velocity_calc_timestamp;
extern float angle_prev;

float AS5600_GetAngle(void);
float AS5600_GetVelocity(void);
void AS5600_Sensor_Init(void);

#endif