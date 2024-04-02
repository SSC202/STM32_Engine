/**
 * @file    DJI电机驱动
 * @note    分为F4驱动(DJI A Board)和H7驱动两种类型
 *          (1) 使用H7驱动时，注意:
 *          对于STM32H723，最大驱动24个电机，每一个FDCANx对应变量中的hDJI[i][x](i = 0~7, x = 0~2)
 *          使用speedServo/positionServo函数进行PID计算；
 *          使用CanTransmit_DJI_5678/CanTransmit_DJI_1234进行CAN消息发送，注意指定FDCAN。
 */
#ifndef __DJI_H
#define __DJI_H

#ifdef __cplusplus
extern "C" {
#endif
#if (STM32F427xx)
#include "stm32f4xx.h"
#endif
#if (STM32H723xx)
#include "stm32h7xx.h"
#endif
#include "wtr_can.h"
typedef struct
{
    float KP;        // PID参数P
    float KI;        // PID参数I
    float KD;        // PID参数D
    float fdb;       // PID反馈值
    float ref;       // PID目标值
    float cur_error; // 当前误差
    float error[2];  // 前两次误差
    float output;    // 输出值
    float outputMax; // 最大输出值的绝对值
    float outputMin; // 最小输出值的绝对值用于防抖
} PID_t;

typedef enum {
    M3508 = 0,
    M2006
} DJI_e;

typedef struct
{
    DJI_e motorType;

    struct
    {
        int msg_cnt;            // 收到消息数
        float RotorAngle_0_360; // 电机转子角度 单位 度° 范围0~360
        float rpm;              // 电机转子速度，单位 rpm
        float current;          // 电机转矩电流
    } FdbData;

    struct
    {
        float RotorAngle_all;          // 电机总角度 单位 度° 范围-inf~inf
        float RotorAngle_0_360_Log[2]; // NOW->电机当前位置0~360 LAST->电机上一次更新位置0~360
        float RotorAngle_0_360_OffSet; // 电机机械角度偏移量 单位 度°
        int RotorRound;                // 电机转的圈数
    } Calculate;
    struct
    {
        float AxisAngle_inDegree; // 电机轴输出角度 单位 度°
        float AxisVelocity;       // 电机轴输出速度 单位 rpm
    } AxisData;

    float reductionRate;      // 减速比
    float encoder_resolution; // 编码器分辨率

    PID_t speedPID;
    PID_t posPID;
} DJI_t;

#if (STM32F427xx)
extern DJI_t hDJI[8][2];
#endif
#if (STM32H723xx)
extern DJI_t hDJI[8][3];
#endif
#if (STM32F427xx)
void CanTransmit_DJI_1234(CAN_HANDLER can, int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq);
void CanTransmit_DJI_5678(CAN_HANDLER can, int16_t cm5_iq, int16_t cm6_iq, int16_t cm7_iq, int16_t cm8_iq);
HAL_StatusTypeDef DJI_CanMsgDecode(uint8_t can_code, uint32_t Stdid, uint8_t *fdbData);
#endif
#if (STM32H723xx)
void CanTransmit_DJI_1234(FDCAN_HANDLER fdcan, int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq);
void CanTransmit_DJI_5678(FDCAN_HANDLER fdcan, int16_t cm5_iq, int16_t cm6_iq, int16_t cm7_iq, int16_t cm8_iq);
HAL_StatusTypeDef DJI_CanMsgDecode(uint8_t fdcan_code, uint32_t Stdid, uint8_t *fdbData);
#endif
void DJI_Init(void);

#ifdef __cplusplus
}
#endif

#endif
