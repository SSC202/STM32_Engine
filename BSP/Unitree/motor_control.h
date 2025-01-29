#ifndef __MOTOR_CONTORL_H
#define __MOTOR_CONTORL_H

#include <stdint.h>
#include "main.h" // stm32 hal
#include "ris_protocol.h"
#include "usart.h"


#pragma pack(1)                  //将结构体内变量强制1字节对齐

/**
 * 电机反馈数据包
 */
typedef struct
{
    uint8_t head[2];    // 包头         2Byte
    RIS_Mode_t mode;    // 电机控制模式  1Byte
    RIS_Fbk_t   fbk;    // 电机反馈数据 11Byte
    uint16_t  CRC16;    // CRC          2Byte
} MotorData_t;  //返回数据

/**
 * 电机命令控制数据包
 */
typedef struct
{
    // 定义 电机控制命令数据包
    uint8_t head[2];    // 包头         2Byte
    RIS_Mode_t mode;    // 电机控制模式  1Byte
    RIS_Comd_t comd;    // 电机期望数据 12Byte
    uint16_t   CRC16;   // CRC          2Byte
} ControlData_t;     //电机控制命令数据包

#pragma pack()


/**
 * 发送数据管理包
 */
typedef struct
{
    // 定义 发送格式化数据
    ControlData_t motor_send_data;   //电机控制数据结构体
    int hex_len;                        //发送的16进制命令数组长度, 34
    long long send_time;                //发送该命令的时间, 微秒(us)
    // 待发送的各项数据
    unsigned short id;                  //电机ID，0代表全部电机
    unsigned short mode;                // 0:空闲, 5:开环转动, 10:闭环FOC控制
    //实际给FOC的指令力矩为：
    // K_P*delta_Pos + K_W*delta_W + T
    float T;                            //期望关节的输出力矩（电机本身的力矩）（Nm）
    float W;                            //期望关节速度（电机本身的速度）(rad/s)
    float Pos;                          //期望关节位置（rad）
    float K_P;                          //关节刚度系数
    float K_W;                          //关节速度系数
} MOTOR_send;

/**
 * 接受数据管理包
 */
typedef struct
{
    // 定义 接收数据
    MotorData_t motor_recv_data;    //电机接收数据结构体，详见motor_msg.h
    int hex_len;                        //接收的16进制命令数组长度, 78
    long long resv_time;                //接收该命令的时间, 微秒(us)
    int correct;                        //接收数据是否完整（1完整，0不完整）
    //解读得出的电机数据
    unsigned char motor_id;             //电机ID
    unsigned char mode;                 // 0:空闲, 5:开环转动, 10:闭环FOC控制
    int Temp;                           //温度
    unsigned char MError;               //错误码
    float T;                            // 当前实际电机输出力矩
		float W;														// speed
    float Pos;                          // 当前电机位置（主控0点修正，电机关节还是以编码器0点为准）
		float footForce;												// 足端气压传感器数据 12bit (0-4095)

} MOTOR_recv;

uint32_t crc32_core(uint32_t *ptr, uint32_t len);
int modify_data(MOTOR_send *motor_s);
int extract_data(MOTOR_recv *motor_r);
<<<<<<< HEAD
HAL_StatusTypeDef SERVO_Send_recv(MOTOR_send *pData, MOTOR_recv *rData);

=======
HAL_StatusTypeDef SERVO_Send_recv(UART_HandleTypeDef *usartx,MOTOR_send *pData, MOTOR_recv *rData);
#ifdef __cplusplus
}
#endif
>>>>>>> 003342ef04704ce77fd147fcd8a814782fe4197b
#endif
