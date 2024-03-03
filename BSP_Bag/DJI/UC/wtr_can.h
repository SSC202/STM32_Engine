/**
 * @file    wtr_can 配置
 * @note    1. 如果使用STM32H7系列的FDCAN，需要进行以下配置流程：
 *          (1) CubeMX 配置：
 *              Frame Format            ----        Classis Mode
 *              Mode                    ----        Normal  Mode
 *              Rx FiFO0 Elmts Nbr      ----        32
 *              Tx Fifo Queue Elmts Nbr ----        32
 *              Std Filters Nbr         ----        1
 *              其余为默认配置
 *
 *              对于时钟，进行以下配置：
 *              主频540Mhz，预分频27，Normal Time Seg1/Seg2 为2，此时波特率为 1000000 bit/s
 *          (2) 代码配置：
 *              使用以下代码进行初始化
 *                  fdcanx.FDCAN_Rx_Filter_Init();
                    fdcanx.FDCAN_Start();
                    fdcanx.FDCAN_Interrupt_Init();

 *              注意：此库指定了FDCANx的配置。
                如果使用多FDCAN，CubeMX中配置应注意：Message RAM值应相差0x406, 即0, 0x406, 0x80C...
                使用多FDCAN时，使用的中断均为FIFO0的中断，如果需要使用FIFO1，请自行编写代码。
                各个FDCAN之间互相独立。

 *           2. 如果使用STM32F4以下系列的CAN（通常为CAN1），需要进行以下配置流程：
 *          (1) CubeMX 配置：
 *              主频180Mhz，预分频9，Normal Time Seg1为3，Normal Time Seg2为1，此时波特率为 1000000 bit/s
 *          (2) 代码配置：
 *              使用以下代码进行初始化
 *                  can1.CAN_Rx_Filter_Init();
                    can1.CAN_Start();
                    can1.CAN_Interrupt_Init();
            (3) 如果使用CAN2，注意：
                将宏定义    USE_CAN2    设置为1;
                CAN2 和 CAN1 共用过滤器（但基本不会产生影响），先使能CAN1再使能CAN2（CAN2打开时必须打开CAN1）
 *
 * @author  SSC
 * @date    2024.3.3(第三次更新)
 */
#ifndef __WTR_CAN_H
#define __WTR_CAN_H

#ifdef __cplusplus
extern "C" {
#endif
#if (STM32F427xx) // 如果使用STM32F4系列

#include "stm32f4xx.h"
#include "can.h"
/***********************CAN使能定义**********************/
#define USE_CAN2 0 // 使能CAN2
/***********************数据类型定义**********************/

// 帧类型定义
typedef enum {
    DATA_FRAME   = 0, // 数据帧
    REMOTE_FRAME = 1, // 远程帧
} CAN_FRAME_TYPE;

// 接收消息结构体定义
typedef struct {
    __IO uint16_t id;       // CANID
    __IO uint16_t ide;      // 数据帧类型
    CAN_FRAME_TYPE rtr;     // 远程帧，数据帧
    __IO uint8_t len;       // CAN报文长度
    __IO uint8_t buffer[8]; // CAN报文内容
} CAN_MSG;

// FDCAN 对象结构体定义
typedef struct FDCAN_HANDLER {
    // 成员变量
    CAN_MSG rx_MSG; // CAN报文结构体

    // 方法函数
    void (*CAN_Start)(void);
    void (*CAN_Rx_Filter_Init)(void);
    void (*CAN_Interrupt_Init)(void);
    uint8_t (*CAN_Send_MSG)(CAN_MSG *);
} CAN_HANDLER;

/************************变量定义***********************/
extern CAN_TxHeaderTypeDef hcan1_tx; // CAN1 发送处理单元句柄
extern CAN_RxHeaderTypeDef hcan1_rx; // CAN1 接受处理单元句柄
extern CAN_HANDLER can1;
extern uint8_t can1_rxdata[8];

#if (USE_CAN2 == 1)
extern CAN_TxHeaderTypeDef hcan2_tx; // CAN2 发送处理单元句柄
extern CAN_RxHeaderTypeDef hcan2_rx; // CAN2 接受处理单元句柄
extern CAN_HANDLER can2;
extern uint8_t can2_rxdata[8];
#endif
/************************函数定义***********************/

void CAN1_RX_Filter_Init(void);
void CAN1_Interrupt_Init(void);
uint8_t CAN1_Send_Msg(CAN_MSG *msg);
void CAN1_Start(void);

void CAN2_RX_Filter_Init(void);
void CAN2_Interrupt_Init(void);
uint8_t CAN2_Send_Msg(CAN_MSG *msg);
void CAN2_Start(void);

#endif
#if (STM32H723xx) || (STM32H743xx) // 如果使用STM32H7系列

#include "stm32h7xx.h"
#include "fdcan.h"
/***********************CAN使能定义**********************/
#define USE_FDCAN1 1 // 使能FDCAN1
#define USE_FDCAN2 1 // 使能FDCAN2
#define USE_FDCAN3 1 // 使能FDCAN3
/***********************数据类型定义**********************/

// 帧类型定义
typedef enum {
    DATA_FRAME   = 0, // 数据帧
    REMOTE_FRAME = 1, // 远程帧
} CAN_FRAME_TYPE;

// 接收消息结构体定义
typedef struct {
    __IO uint16_t id;       // CANID
    CAN_FRAME_TYPE rtr;     // 远程帧，数据帧
    __IO uint8_t len;       // CAN报文长度
    __IO uint8_t buffer[8]; // CAN报文内容
} CAN_MSG;

// FDCAN 对象结构体定义
typedef struct FDCAN_HANDLER {
    // 成员变量
    CAN_MSG rx_MSG;                  // CAN报文结构体
    __IO uint32_t RXFIFO_Inter_Type; // RXFIFO中断的类型（新数据，水印，FIFO溢出)
    __IO uint32_t RXFxS;             // FDCAN_RXF0C 或 FDCAN_RXF1C
    __IO uint8_t FxGI;               // FDCAN_F0GI 或 FDCAN_F1GI
    __IO uint8_t FxFL;               // FDCAN_F0FL 或 FDCAN_F1FL
    __IO uint8_t FxPI;               // FDCAN_F0PI 或 FDCAN_F1PI

    // 方法函数
    void (*FDCAN_Start)(void);
    void (*FDCAN_Rx_Filter_Init)(void);
    void (*FDCAN_Interrupt_Init)(void);
    uint8_t (*FDCAN_Send_MSG)(CAN_MSG *);
    void (*FDCAN_Update_RXFIFO_Status)(FDCAN_HandleTypeDef *, struct FDCAN_HANDLER *);
} FDCAN_HANDLER;

/************************变量定义***********************/
#if (USE_FDCAN1 == 1)
extern FDCAN_RxHeaderTypeDef hfdcan1_rx; // FDCAN1 接受处理单元句柄
extern FDCAN_TxHeaderTypeDef hfdcan1_tx; // FDCAN1 发送处理单元句柄
extern FDCAN_HANDLER fdcan1;
extern uint8_t fdcan1_rxdata[8];
#endif
#if (USE_FDCAN2 == 1)
extern FDCAN_RxHeaderTypeDef hfdcan2_rx; // FDCAN2 接受处理单元句柄
extern FDCAN_TxHeaderTypeDef hfdcan2_tx; // FDCAN2 发送处理单元句柄
extern FDCAN_HANDLER fdcan2;
extern uint8_t fdcan2_rxdata[8];
#endif
#if (USE_FDCAN3 == 1)
extern FDCAN_RxHeaderTypeDef hfdcan3_rx; // FDCAN3 接受处理单元句柄
extern FDCAN_TxHeaderTypeDef hfdcan3_tx; // FDCAN3 发送处理单元句柄
extern FDCAN_HANDLER fdcan3;
extern uint8_t fdcan3_rxdata[8];
#endif
/************************函数定义***********************/
#if (USE_FDCAN1 == 1)
void FDCAN1_RX_Filter_Init(void);
void FDCAN1_Interrupt_Init(void);
void FDCAN1_Update_RXFIFO_Status(FDCAN_HandleTypeDef *hfdcan, FDCAN_HANDLER *fdcan);
uint8_t FDCAN1_Send_Msg(CAN_MSG *msg);
void FDCAN1_Start(void);
#endif
#if (USE_FDCAN2 == 1)
void FDCAN2_RX_Filter_Init(void);
void FDCAN2_Interrupt_Init(void);
void FDCAN2_Update_RXFIFO_Status(FDCAN_HandleTypeDef *hfdcan, FDCAN_HANDLER *fdcan);
uint8_t FDCAN2_Send_Msg(CAN_MSG *msg);
void FDCAN2_Start(void);
#endif
#if (USE_FDCAN3 == 1)
void FDCAN3_RX_Filter_Init(void);
void FDCAN3_Interrupt_Init(void);
void FDCAN3_Update_RXFIFO_Status(FDCAN_HandleTypeDef *hfdcan, FDCAN_HANDLER *fdcan);
uint8_t FDCAN3_Send_Msg(CAN_MSG *msg);
void FDCAN3_Start(void);
#endif
#endif
#ifdef __cplusplus
}
#endif

#endif
