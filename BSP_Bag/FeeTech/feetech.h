/**
 * @file    飞特舵机驱动库  C版本
 * @note    飞特舵机使用串口进行驱动
 *
 *          舵机供电为12V，接入24V可能会导致舵机烧坏；
 *
 *          接线顺序如下：
 *          UART(TTL) ----- 高速TTL转RS485模块 ----- 飞特舵机串口驱动模块 ----- 舵机
 *
 *          舵机使用前，应设置舵机的ID号（使用Feetech舵机的上位机进行修改）；
 *
 *          本驱动库未编写同步写和同步读指令；
 * 
 *          本驱动库已经制定了一个飞特舵机的全局数组。
 *
 *          使用此库前，首先指定FEETECH舵机的数量并指定串口；初始化函数Servo_Init()将自动为指定的串口号依次指定ID为1，2，3，4...，返回为0后方可正常工作。（未测试）
 *
 *          使用Servo_Write_PosEx()函数可以控制舵机的位置，Servo_Write_Speed()可以使得舵机进入恒速模式；
 *
 *          使用Servo_Ping()函数可以确认舵机的ID号，Servo_Read_...()函数用于采集舵机的电流，电压，移动状态，速度，力矩，位置
 *
 *
 * @author  Lyn & SSC
 */
#ifndef __FEETECH_H
#define __FEETECH_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx.h"
#include "usart.h"
#include <stdarg.h>
/************************ 用户宏定义 ****************************/
#define FEETECH_NUM 4 // FEETECH舵机数量
/*************************** 宏定义 ****************************/
//-------SRAM(只读)--------
#define SMS_STS_PRESENT_POSITION_L 56
#define SMS_STS_PRESENT_POSITION_H 57
#define SMS_STS_PRESENT_SPEED_L 58
#define SMS_STS_PRESENT_SPEED_H 59
#define SMS_STS_PRESENT_LOAD_L 60
#define SMS_STS_PRESENT_LOAD_H 61
#define SMS_STS_PRESENT_VOLTAGE 62
#define SMS_STS_PRESENT_TEMPERATURE 63
#define SMS_STS_MOVING 66
#define SMS_STS_PRESENT_CURRENT_L 69
#define SMS_STS_PRESENT_CURRENT_H 70
    /***************************结构体定义****************************/
    typedef struct FEET_Servo
    {
        UART_HandleTypeDef servo_uart_handle;                                    // UART 句柄
        int ID;                                                                  // 舵机ID
        uint8_t End;                                                             // 舵机大小端模式
        uint8_t Err;                                                             // 舵机错误状态
        uint8_t Mem[SMS_STS_PRESENT_CURRENT_H - SMS_STS_PRESENT_POSITION_L + 1]; // 舵机状态信息
    } FEET_Servo;

    extern FEET_Servo feetservo[FEETECH_NUM];                                   // 飞特舵机数组

    /****************************用户函数*****************************/

    int Servo_Init(int num, ...);

    int Servo_Write_PosEx(FEET_Servo *uservo, int16_t Position, uint16_t Speed, uint8_t ACC);
    int WheelMode(FEET_Servo *uservo);
    int Servo_Write_Speed(FEET_Servo *uservo, int16_t Speed, uint8_t ACC);
    int Servo_EnableTorque(FEET_Servo *uservo, uint8_t Enable);
    int Servo_UnLock_Eprom(FEET_Servo *uservo);
    int Servo_Lock_Eprom(FEET_Servo *uservo);
    int Servo_CalibrationOfs(FEET_Servo *uservo);
    int Servo_FeedBack(FEET_Servo *uservo);

    int Servo_Ping(FEET_Servo *uservo);
    int Servo_Read_Pos(FEET_Servo *uservo);
    int Servo_Read_Speed(FEET_Servo *uservo);
    int Servo_Read_Load(FEET_Servo *uservo);
    int Servo_Read_Voltage(FEET_Servo *uservo);
    int Servo_Read_Temper(FEET_Servo *uservo);
    int Servo_Read_Move(FEET_Servo *uservo);
    int Servo_Read_Current(FEET_Servo *uservo);

#ifdef __cplusplus
};
#endif

#endif