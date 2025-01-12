#ifndef _FeeTech_HPP
#define _FeeTech_HPP

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx.h"
#include "usart.h"

/***************************************************************************************/
#define INST_PING       0x01
#define INST_READ       0x02
#define INST_WRITE      0x03
#define INST_REG_WRITE  0x04
#define INST_REG_ACTION 0x05
#define INST_SYNC_READ  0x82
#define INST_SYNC_WRITE 0x83

#define SMS_STS_1M      0
#define SMS_STS_0_5M    1
#define SMS_STS_250K    2
#define SMS_STS_128K    3
#define SMS_STS_115200  4
#define SMS_STS_76800   5
#define SMS_STS_57600   6
#define SMS_STS_38400   7

// 内存表定义
//-------EPROM(只读)--------
#define SMS_STS_MODEL_L 3
#define SMS_STS_MODEL_H 4

//-------EPROM(读写)--------
#define SMS_STS_ID                5
#define SMS_STS_BAUD_RATE         6
#define SMS_STS_MIN_ANGLE_LIMIT_L 9
#define SMS_STS_MIN_ANGLE_LIMIT_H 10
#define SMS_STS_MAX_ANGLE_LIMIT_L 11
#define SMS_STS_MAX_ANGLE_LIMIT_H 12
#define SMS_STS_CW_DEAD           26
#define SMS_STS_CCW_DEAD          27
#define SMS_STS_OFS_L             31
#define SMS_STS_OFS_H             32
#define SMS_STS_MODE              33

//-------SRAM(读写)--------
#define SMS_STS_TORQUE_ENABLE   40
#define SMS_STS_ACC             41
#define SMS_STS_GOAL_POSITION_L 42
#define SMS_STS_GOAL_POSITION_H 43
#define SMS_STS_GOAL_TIME_L     44
#define SMS_STS_GOAL_TIME_H     45
#define SMS_STS_GOAL_SPEED_L    46
#define SMS_STS_GOAL_SPEED_H    47
#define SMS_STS_LOCK            55
#define SMS_ANGEL_MIN           9
#define SMS_ANGEL_MAX           9
#define SMS_ID                  5
#define SMS_POSE_MAKEUP         0x1F

//-------SRAM(只读)--------
#define SMS_STS_PRESENT_POSITION_L  56
#define SMS_STS_PRESENT_POSITION_H  57
#define SMS_STS_PRESENT_SPEED_L     58
#define SMS_STS_PRESENT_SPEED_H     59
#define SMS_STS_PRESENT_LOAD_L      60
#define SMS_STS_PRESENT_LOAD_H      61
#define SMS_STS_PRESENT_VOLTAGE     62
#define SMS_STS_PRESENT_TEMPERATURE 63
#define SMS_STS_MOVING              66
#define SMS_STS_PRESENT_CURRENT_L   69
#define SMS_STS_PRESENT_CURRENT_H   70

#define BYTEHEAD                    0xFF

#ifdef __cplusplus
};

class FEET_Servo
{
private:
    UART_HandleTypeDef servo_uart_handle;                                    // UART 句柄
    uint8_t ID;                                                              // 舵机ID
    uint8_t End;                                                             // 舵机大小端模式
    uint8_t Err;                                                             // 舵机错误状态
    uint8_t Mem[SMS_STS_PRESENT_CURRENT_H - SMS_STS_PRESENT_POSITION_L + 1]; // 舵机状态信息

    void Int16_2_Int8(uint8_t *DataL, uint8_t *DataH, int Data);
    int Int8_2_Int16(uint8_t DataL, uint8_t DataH);

    void Servo_Write_Buf(uint8_t MemAddr, uint8_t *nDat, uint8_t nLen, uint8_t Fun);
    uint16_t Servo_Read_Buf(uint8_t *nDat, int nLen);

    int Servo_Write_Byte(uint8_t MemAddr, uint8_t bDat);

    int Servo_Check_Head(void);
    int Servo_Ack(void);

    int Servo_Read(uint8_t MemAddr, uint8_t *nData, uint8_t nLen);
    int Servo_Read_Byte(uint8_t MemAddr);
    int Servo_Read_Word(uint8_t MemAddr);

    int Servo_gen_Write(uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);
    int Servo_reg_Write(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);

public:
    FEET_Servo(UART_HandleTypeDef uart_handle);

    int Servo_Write_PosEx(int16_t Position, uint16_t Speed = 100, uint8_t ACC = 100);
    int WheelMode(void);
    int Servo_Write_Speed(int16_t Speed, uint8_t ACC = 100);
    int Servo_EnableTorque(uint8_t Enable);
    int Servo_UnLock_Eprom(void);
    int Servo_Lock_Eprom(void);
    int Servo_CalibrationOfs(void);
    int Servo_FeedBack(void);

    int Servo_Ping(void);
    int Servo_Read_Pos(void);
    int Servo_Read_Speed(void);
    int Servo_Read_Load(void);
    int Servo_Read_Voltage(void);
    int Servo_Read_Temper(void);
    int Servo_Read_Move(void);
    int Servo_Read_Current(void);
};
#endif
#endif