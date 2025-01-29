#include "feetech.h"

/*******************************宏定义段********************************/

#define INST_PING 0x01
#define INST_READ 0x02
#define INST_WRITE 0x03
#define INST_REG_WRITE 0x04
#define INST_REG_ACTION 0x05
#define INST_SYNC_READ 0x82
#define INST_SYNC_WRITE 0x83

#define SMS_STS_1M 0
#define SMS_STS_0_5M 1
#define SMS_STS_250K 2
#define SMS_STS_128K 3
#define SMS_STS_115200 4
#define SMS_STS_76800 5
#define SMS_STS_57600 6
#define SMS_STS_38400 7

// 内存表定义
//-------EPROM(只读)--------
#define SMS_STS_MODEL_L 3
#define SMS_STS_MODEL_H 4

//-------EPROM(读写)--------
#define SMS_STS_ID 5
#define SMS_STS_BAUD_RATE 6
#define SMS_STS_MIN_ANGLE_LIMIT_L 9
#define SMS_STS_MIN_ANGLE_LIMIT_H 10
#define SMS_STS_MAX_ANGLE_LIMIT_L 11
#define SMS_STS_MAX_ANGLE_LIMIT_H 12
#define SMS_STS_CW_DEAD 26
#define SMS_STS_CCW_DEAD 27
#define SMS_STS_OFS_L 31
#define SMS_STS_OFS_H 32
#define SMS_STS_MODE 33

//-------SRAM(读写)--------
#define SMS_STS_TORQUE_ENABLE 40
#define SMS_STS_ACC 41
#define SMS_STS_GOAL_POSITION_L 42
#define SMS_STS_GOAL_POSITION_H 43
#define SMS_STS_GOAL_TIME_L 44
#define SMS_STS_GOAL_TIME_H 45
#define SMS_STS_GOAL_SPEED_L 46
#define SMS_STS_GOAL_SPEED_H 47
#define SMS_STS_LOCK 55
#define SMS_ANGEL_MIN 9
#define SMS_ANGEL_MAX 9
#define SMS_ID 5
#define SMS_POSE_MAKEUP 0x1F

FEET_Servo feetservo[FEETECH_NUM]; // 飞特舵机数组

/*****************************基本驱动函数******************************/

/**
 * @brief   1个16位拆分为2个八位数
 * @param   uservo    飞特舵机结构体
 * @param   DataL     低位
 * @param   DataH     高位
 * @param   Data      数据
 */
static void Int16_2_Int8(FEET_Servo *uservo, uint8_t *DataL, uint8_t *DataH, int Data)
{
    if (uservo->End)
    {
        *DataL = (Data >> 8);
        *DataH = (Data & 0xff);
    }
    else
    {
        *DataH = (Data >> 8);
        *DataL = (Data & 0xff);
    }
}

/**
 * @brief   2个八位数组合为16位数
 * @param   uservo      飞特舵机结构体
 * @param   DataL       低位
 * @param   DataH       高位
 * @return  组合的16位数据
 */
static int Int8_2_Int16(FEET_Servo *uservo, uint8_t DataL, uint8_t DataH)
{
    int Data;
    if (uservo->End)
    {
        Data = DataL;
        Data <<= 8;
        Data |= DataH;
    }
    else
    {
        Data = DataH;
        Data <<= 8;
        Data |= DataL;
    }
    return Data;
}

/**
 * @brief   舵机串口写函数
 * @param   uservo    飞特舵机结构体
 * @param   MemAddr   内存表地址
 * @param   nDat      发送数据缓冲区
 * @param   nLen      发送数据长度
 * @param   Fun       发送指令
 */
static void Servo_Write_Buf(FEET_Servo *uservo, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen, uint8_t Fun)
{
    uint8_t i;
    uint8_t msgLen = 2;
    uint8_t bBuf[6];
    uint8_t CheckSum = 0;
    bBuf[0] = 0xff;
    bBuf[1] = 0xff;
    bBuf[2] = uservo->ID;
    bBuf[4] = Fun;
    if (nDat)
    {
        msgLen += nLen + 1;
        bBuf[3] = msgLen; // 数据长度
        bBuf[5] = MemAddr;
        HAL_UART_Transmit(&(uservo->servo_uart_handle), bBuf, 6, 0xffff);
    }
    else
    {
        bBuf[3] = msgLen;
        HAL_UART_Transmit(&(uservo->servo_uart_handle), bBuf, 5, 0xffff);
    }
    CheckSum = uservo->ID + msgLen + Fun + MemAddr;
    if (nDat)
    {
        for (i = 0; i < nLen; i++)
        {
            CheckSum += nDat[i];
        }
        HAL_UART_Transmit(&(uservo->servo_uart_handle), nDat, nLen, 0xffff);
    }
    CheckSum = ~CheckSum;
    HAL_UART_Transmit(&(uservo->servo_uart_handle), &CheckSum, 1, 0xffff);
}

/**
 * @brief   舵机串口写字节函数
 * @param   uservo    飞特舵机结构体
 * @param   MemAddr   内存表地址
 * @param   bDat      发送数据
 */
static int Servo_Write_Byte(FEET_Servo *uservo, uint8_t MemAddr, uint8_t bDat)
{
    Servo_Write_Buf(uservo, MemAddr, &bDat, 1, INST_WRITE);
    return 0;
}

/**
 * @brief   舵机串口读取函数
 * @param   uservo      飞特舵机结构体
 * @param   nDat        读取缓冲区数组
 * @param   nLen        期望读取长度
 * @retval  实际读取长度
 */
static uint16_t Servo_Read_Buf(FEET_Servo *uservo, uint8_t *nDat, int nLen)
{
    uint16_t size = 0;
    HAL_UARTEx_ReceiveToIdle(&(uservo->servo_uart_handle), nDat, nLen, &size, 0x20);
    return size;
}

/**
 * @brief   普通写指令
 * @param   uservo      飞特舵机结构体
 * @param   MemAddr     内存表地址
 * @param   nDat        写数据
 * @param   nLen        写数据长度
 */
static int Servo_gen_Write(FEET_Servo *uservo, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen)
{
    Servo_Write_Buf(uservo, MemAddr, nDat, nLen, INST_WRITE);
    return 0;
}

/**
 * @brief 异步写指令
 * @param   uservo      飞特舵机结构体
 * @param   MemAddr     内存表地址
 * @param   nDat        写数据
 * @param   nLen        写数据长度
 */
static int Servo_reg_Write(FEET_Servo *uservo, uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen)
{
    Servo_Write_Buf(uservo, MemAddr, nDat, nLen, INST_REG_WRITE);
    return 0;
}

/**
 * @brief 校验帧头函数
 */
static int Servo_Check_Head(FEET_Servo *uservo)
{
    uint8_t bDat;
    uint8_t bBuf[2] = {0, 0};
    uint8_t Cnt = 0;
    while (1)
    {
        if (!Servo_Read_Buf(uservo, &bDat, 1))
        {
            return 0;
        }
        bBuf[1] = bBuf[0];
        bBuf[0] = bDat;
        if (bBuf[0] == 0xff && bBuf[1] == 0xff)
        {
            break;
        }
        Cnt++;
        if (Cnt > 10)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief   指令应答函数
 * @param   uservo      飞特舵机结构体
 */
static int Servo_Ack(FEET_Servo *uservo)
{
    uint8_t bBuf[4];
    uint8_t calSum;
    // Error = 0;
    if (uservo->ID != 0xfe)
    {
        if (!Servo_Check_Head(uservo))
        {
            return 0;
        }
        if (Servo_Read_Buf(uservo, bBuf, 4) != 4)
        {
            return 0;
        }
        if (bBuf[0] != uservo->ID)
        {
            return 0;
        }
        if (bBuf[1] != 2)
        {
            return 0;
        }
        calSum = ~(bBuf[0] + bBuf[1] + bBuf[2]);
        if (calSum != bBuf[3])
        {
            return 0;
        }
        // Error = bBuf[2];
    }
    return 1;
}

/**
 * @brief   舵机读取数据帧函数
 * @param   uservo      飞特舵机结构体
 * @param   MemAddr     内存表地址
 * @param   nData       接收数据缓冲区
 * @param   nLen        接收数据长度
 * @retval  实际接收数据长度
 */
static int Servo_Read(FEET_Servo *uservo, uint8_t MemAddr, uint8_t *nData, uint8_t nLen)
{
    int Size;
    uint8_t bBuf[4];
    uint8_t calSum;
    uint8_t i;
    Servo_Write_Buf(uservo, MemAddr, &nLen, 1, INST_READ);
    if (!Servo_Check_Head(uservo))
    {
        return 0;
    }
    // Error = 0;
    if (Servo_Read_Buf(uservo, bBuf, 3) != 3)
    {
        return 0;
    }
    Size = Servo_Read_Buf(uservo, nData, nLen);
    if (Size != nLen)
    {
        return 0;
    }
    if (Servo_Read_Buf(uservo, bBuf + 3, 1) != 1)
    {
        return 0;
    }
    calSum = bBuf[0] + bBuf[1] + bBuf[2];
    for (i = 0; i < Size; i++)
    {
        calSum += nData[i];
    }
    calSum = ~calSum;
    if (calSum != bBuf[3])
    {
        return 0;
    }
    // Error = bBuf[2];
    return Size;
}
/**
 * @brief   读取单字节数据函数
 * @param   uservo      飞特舵机结构体
 * @param   MemAddr     内存表地址
 */
static int Servo_Read_Byte(FEET_Servo *uservo, uint8_t MemAddr)
{
    uint8_t bDat;
    int Size = Servo_Read(uservo, MemAddr, &bDat, 1);
    if (Size != 1)
    {
        return -1;
    }
    else
    {
        return bDat;
    }
}

/**
 * @brief 读取双字节数据函数
 * @param   uservo      飞特舵机结构体
 * @param   MemAddr     内存表地址
 */
static int Servo_Read_Word(FEET_Servo *uservo, uint8_t MemAddr)
{
    uint8_t nDat[2];
    int Size;
    uint16_t wDat;
    Size = Servo_Read(uservo, MemAddr, nDat, 2);
    if (Size != 2)
        return -1;
    wDat = Int8_2_Int16(uservo, nDat[0], nDat[1]);
    return wDat;
}

/*******************************************用户函数*******************************************/

/**
 * @brief   舵机初始化函数
 * @param   num   parmN，指定后续的参数数量，使用时应当将其赋值为飞特舵机数量
 * @param   ...   可变参数列表，指定为UART_HandleTypedef类型，即传入huartx
 * @note    传入串口句柄数量应该与舵机数量对应，参数初始化结束后，会进行一次Ping
 * @retval  -1：传入参数数量不对应；-2：Ping出现错误；0：正常
 */
int Servo_Init(int num, ...)
{
    va_list ap;
    static uint8_t count = 0;

    va_start(ap, num);
    for (int i = 0; i < num; i++)
    {
        feetservo[i].End = 0;
        feetservo[i].ID = i + 1;
        feetservo[i].Err = 0;
        feetservo[i].servo_uart_handle = va_arg(ap, UART_HandleTypeDef);
        count++;
    }
    va_end(ap);

    if (count != FEETECH_NUM)
    {
        return -1;
    }

    for (int i = 0; i < FEETECH_NUM; i++)
    {
        if (Servo_Ping(&feetservo[i]) != feetservo[i].ID)
        {
            return -2;
        }
    }
    return 0;
}

/**
 * @brief 位置模式控制函数
 * @param Position  位置 0-4096
 * @param Speed     速度  0-254
 * @param ACC       加速度 0-254
 */
int Servo_Write_PosEx(FEET_Servo *uservo, int16_t Position, uint16_t Speed, uint8_t ACC)
{
    uint8_t bBuf[7];
    if (Position < 0)
    {
        Position = -Position;
        Position |= (1 << 15);
    }

    bBuf[0] = ACC;
    Int16_2_Int8(uservo, bBuf + 1, bBuf + 2, Position);
    Int16_2_Int8(uservo, bBuf + 3, bBuf + 4, 0);
    Int16_2_Int8(uservo, bBuf + 5, bBuf + 6, Speed);

    return Servo_gen_Write(uservo, SMS_STS_ACC, bBuf, 7);
}

/**
 * @brief 恒速模式指令
 */
int WheelMode(FEET_Servo *uservo)
{
    return Servo_Write_Byte(uservo, SMS_STS_MODE, 1);
}

/**
 * @brief 恒速模式速度控制指令
 * @param Speed 速度
 * @param ACC 加速度
 */
int Servo_Write_Speed(FEET_Servo *uservo, int16_t Speed, uint8_t ACC)
{
    uint8_t bBuf[2];
    if (Speed < 0)
    {
        Speed = -Speed;
        Speed |= (1 << 15);
    }
    bBuf[0] = ACC;
    Servo_gen_Write(uservo, SMS_STS_ACC, bBuf, 1);
    Int16_2_Int8(uservo, bBuf + 0, bBuf + 1, Speed);
    Servo_gen_Write(uservo, SMS_STS_GOAL_SPEED_L, bBuf, 2);
    return 1;
}

/**
 * @brief 扭矩控制指令
 * @param Enable    使能标志
 */
int Servo_EnableTorque(FEET_Servo *uservo, uint8_t Enable)
{
    return Servo_Write_Byte(uservo, SMS_STS_TORQUE_ENABLE, Enable);
}

/**
 * @brief EPROM 解锁指令
 */
int Servo_UnLock_Eprom(FEET_Servo *uservo)
{
    return Servo_Write_Byte(uservo, SMS_STS_LOCK, 0);
}

/**
 * @brief EPROM 加锁指令
 */
int Servo_Lock_Eprom(FEET_Servo *uservo)
{
    return Servo_Write_Byte(uservo, SMS_STS_LOCK, 1);
}

/**
 * @brief 中位校准指令
 */
int Servo_CalibrationOfs(FEET_Servo *uservo)
{
    return Servo_Write_Byte(uservo, SMS_STS_TORQUE_ENABLE, 128);
}

/**
 * @brief 反馈舵机信息指令
 */
int Servo_FeedBack(FEET_Servo *uservo)
{
    uint8_t Mem[SMS_STS_PRESENT_CURRENT_H - SMS_STS_PRESENT_POSITION_L + 1];
    int nLen = Servo_Read(uservo, SMS_STS_PRESENT_POSITION_L, Mem, sizeof(Mem));
    if (nLen != sizeof(Mem))
    {
        uservo->Err = 1;
        return -1;
    }
    uservo->Err = 0;
    return nLen;
}

/**
 * @brief   Ping 指令函数
 * @retval  读取ID
 */
int Servo_Ping(FEET_Servo *uservo)
{
    uint8_t bBuf[4];
    uint8_t calSum;
    Servo_Write_Buf(uservo, 0, NULL, 0, INST_PING);
    // Error = 0;
    if (!Servo_Check_Head(uservo))
    {
        return -1;
    }

    if (Servo_Read_Buf(uservo, bBuf, 4) != 4)
    {
        return -1;
    }
    if (bBuf[0] != uservo->ID && uservo->ID != 0xfe)
    {
        return -1;
    }
    if (bBuf[1] != 2)
    {
        return -1;
    }
    calSum = ~(bBuf[0] + bBuf[1] + bBuf[2]);
    if (calSum != bBuf[3])
    {
        return -1;
    }
    // Error = bBuf[2];
    return bBuf[0];
}

/**
 * @brief   位置读取函数
 * @retval  当前位置
 */
int Servo_Read_Pos(FEET_Servo *uservo)
{
    int Pos = -1;
    if (uservo->ID == -1)
    {
        Pos = (uservo->Mem[SMS_STS_PRESENT_POSITION_H - SMS_STS_PRESENT_POSITION_L]);
        Pos <<= 8;
        Pos |= (uservo->Mem[SMS_STS_PRESENT_POSITION_L - SMS_STS_PRESENT_POSITION_L]);
    }
    else
    {
        uservo->Err = 0;
        Pos = Servo_Read_Word(uservo, SMS_STS_PRESENT_POSITION_L);
        if (Pos == -1)
        {
            uservo->Err = 1;
        }
    }
    if (!(uservo->Err) && Pos & (1 << 15))
    {
        Pos = -(Pos & ~(1 << 15));
    }
    return Pos;
}

/**
 * @brief 速度读取函数
 * @retval  当前速度
 */
int Servo_Read_Speed(FEET_Servo *uservo)
{
    int Speed = -1;
    if (uservo->ID == -1)
    {
        Speed = uservo->Mem[SMS_STS_PRESENT_SPEED_H - SMS_STS_PRESENT_POSITION_L];
        Speed <<= 8;
        Speed |= uservo->Mem[SMS_STS_PRESENT_SPEED_L - SMS_STS_PRESENT_POSITION_L];
    }
    else
    {
        uservo->Err = 0;
        Speed = Servo_Read_Word(uservo, SMS_STS_PRESENT_SPEED_L);
        if (Speed == -1)
        {
            uservo->Err = 1;
            return -1;
        }
    }
    if (!(uservo->Err) && Speed & (1 << 15))
    {
        Speed = -(Speed & ~(1 << 15));
    }
    return Speed;
}

/**
 * @brief 力矩读取函数
 * @retval  当前力矩
 */
int Servo_Read_Load(FEET_Servo *uservo)
{
    int Load = -1;
    if (uservo->ID == -1)
    {
        Load = uservo->Mem[SMS_STS_PRESENT_LOAD_H - SMS_STS_PRESENT_POSITION_L];
        Load <<= 8;
        Load |= uservo->Mem[SMS_STS_PRESENT_LOAD_L - SMS_STS_PRESENT_POSITION_L];
    }
    else
    {
        uservo->Err = 0;
        Load = Servo_Read_Word(uservo, SMS_STS_PRESENT_LOAD_L);
        if (Load == -1)
        {
            uservo->Err = 1;
        }
    }
    if (!(uservo->Err) && Load & (1 << 10))
    {
        Load = -(Load & ~(1 << 10));
    }
    return Load;
}

/**
 * @brief 电压读取函数
 * @retval  当前电压
 */
int Servo_Read_Voltage(FEET_Servo *uservo)
{
    int Voltage = -1;
    if (uservo->ID == -1)
    {
        Voltage = uservo->Mem[SMS_STS_PRESENT_VOLTAGE - SMS_STS_PRESENT_POSITION_L];
    }
    else
    {
        uservo->Err = 0;
        Voltage = Servo_Read_Byte(uservo, SMS_STS_PRESENT_VOLTAGE);
        if (Voltage == -1)
        {
            uservo->Err = 1;
        }
    }
    return Voltage;
}

/**
 * @brief 温度读取函数
 * @retval  当前温度
 */
int Servo_Read_Temper(FEET_Servo *uservo)
{
    int Temper = -1;
    if (uservo->ID == -1)
    {
        Temper = uservo->Mem[SMS_STS_PRESENT_TEMPERATURE - SMS_STS_PRESENT_POSITION_L];
    }
    else
    {
        uservo->Err = 0;
        Temper = Servo_Read_Byte(uservo, SMS_STS_PRESENT_TEMPERATURE);
        if (Temper == -1)
        {
            uservo->Err = 1;
        }
    }
    return Temper;
}

/**
 * @brief 状态读取函数
 * @retval  当前状态
 */
int Servo_Read_Move(FEET_Servo *uservo)
{
    int Move = -1;
    if (uservo->ID == -1)
    {
        Move = uservo->Mem[SMS_STS_MOVING - SMS_STS_PRESENT_POSITION_L];
    }
    else
    {
        uservo->Err = 0;
        Move = Servo_Read_Byte(uservo, SMS_STS_MOVING);
        if (Move == -1)
        {
            uservo->Err = 1;
        }
    }
    return Move;
}

/**
 * @brief 电流读取函数
 * @retval  当前电流
 */
int Servo_Read_Current(FEET_Servo *uservo)
{
    int Current = -1;
    if (uservo->ID == -1)
    {
        Current = uservo->Mem[SMS_STS_PRESENT_CURRENT_H - SMS_STS_PRESENT_POSITION_L];
        Current <<= 8;
        Current |= uservo->Mem[SMS_STS_PRESENT_CURRENT_L - SMS_STS_PRESENT_POSITION_L];
    }
    else
    {
        uservo->Err = 0;
        Current = Servo_Read_Word(uservo, SMS_STS_PRESENT_CURRENT_L);
        if (Current == -1)
        {
            uservo->Err = 1;
            return -1;
        }
    }
    if (!(uservo->Err) && Current & (1 << 15))
    {
        Current = -(Current & ~(1 << 15));
    }
    return Current;
}