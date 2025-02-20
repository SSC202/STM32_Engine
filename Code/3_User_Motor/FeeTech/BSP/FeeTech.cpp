#include "FeeTech.hpp"
/*************************************硬件驱动函数******************************************/

/**
 * @brief 舵机构造函数
 * @param uart_handle 串口句柄
 */
FEET_Servo::FEET_Servo(UART_HandleTypeDef uart_handle)
{
    servo_uart_handle = uart_handle;
    ID                = 0x01;
    End               = 0; // 大小端结构
    Err               = 0;
}

/**
 * @brief 1个16位拆分为2个八位数
 * @param DataL 低位
 * @param DataH 高位
 * @param Data 数据
 */
void FEET_Servo::Int16_2_Int8(uint8_t *DataL, uint8_t *DataH, int Data)
{
    if (End) {
        *DataL = (Data >> 8);
        *DataH = (Data & 0xff);
    } else {
        *DataH = (Data >> 8);
        *DataL = (Data & 0xff);
    }
}

/**
 * @brief 2个八位数组合为16位数
 * @param DataL 低位
 * @param DataH 高位
 * @return
 */
int FEET_Servo::Int8_2_Int16(uint8_t DataL, uint8_t DataH)
{
    int Data;
    if (End) {
        Data = DataL;
        Data <<= 8;
        Data |= DataH;
    } else {
        Data = DataH;
        Data <<= 8;
        Data |= DataL;
    }
    return Data;
}

/**
 * @brief 舵机串口写函数
 * @param MemAddr   内存表地址
 * @param nDat      发送数据缓冲区
 * @param nLen      发送数据长度
 * @param Fun       发送指令
 */
void FEET_Servo::Servo_Write_Buf(uint8_t MemAddr, uint8_t *nDat, uint8_t nLen, uint8_t Fun)
{
    uint8_t i;
    uint8_t msgLen = 2;
    uint8_t bBuf[6];
    uint8_t CheckSum = 0;
    bBuf[0]          = 0xff;
    bBuf[1]          = 0xff;
    bBuf[2]          = ID;
    bBuf[4]          = Fun;
    if (nDat) {
        msgLen += nLen + 1;
        bBuf[3] = msgLen; // 数据长度
        bBuf[5] = MemAddr;
        HAL_UART_Transmit(&servo_uart_handle, bBuf, 6, 0xffff);

    } else {
        bBuf[3] = msgLen;
        HAL_UART_Transmit(&servo_uart_handle, bBuf, 5, 0xffff);
    }
    CheckSum = ID + msgLen + Fun + MemAddr;
    if (nDat) {
        for (i = 0; i < nLen; i++) {
            CheckSum += nDat[i];
        }
        HAL_UART_Transmit(&servo_uart_handle, nDat, nLen, 0xffff);
    }
    CheckSum = ~CheckSum;
    HAL_UART_Transmit(&servo_uart_handle, &CheckSum, 1, 0xffff);
}

/**
 * @brief 舵机串口写字节函数
 * @param MemAddr   内存表地址
 * @param bDat      发送数据
 */
int FEET_Servo::Servo_Write_Byte(uint8_t MemAddr, uint8_t bDat)
{
    Servo_Write_Buf(MemAddr, &bDat, 1, INST_WRITE);
    return 0;
}

/**
 * @brief 舵机串口读取函数
 * @param nDat  读取缓冲区数组
 * @param nLen  期望读取长度
 * @retval 实际读取长度
 */
uint16_t FEET_Servo::Servo_Read_Buf(uint8_t *nDat, int nLen)
{
    uint16_t size = 0;
    HAL_UARTEx_ReceiveToIdle(&servo_uart_handle, nDat, nLen, &size, 0x20);
    return size;
}

/**
 * @brief 普通写指令
 * @param MemAddr   内存表地址
 * @param nDat      写数据
 * @param nLen      写
 */
int FEET_Servo::Servo_gen_Write(uint8_t MemAddr, uint8_t *nDat, uint8_t nLen)
{
    Servo_Write_Buf(MemAddr, nDat, nLen, INST_WRITE);
    return 0;
}

/**
 * @brief 异步写指令
 */
int FEET_Servo::Servo_reg_Write(uint8_t ID, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen)
{
    Servo_Write_Buf(MemAddr, nDat, nLen, INST_REG_WRITE);
    return 0;
}

/**
 * @brief 校验帧头函数
 */
int FEET_Servo::Servo_Check_Head(void)
{
    uint8_t bDat;
    uint8_t bBuf[2] = {0, 0};
    uint8_t Cnt     = 0;
    while (1) {
        if (!Servo_Read_Buf(&bDat, 1)) {
            return 0;
        }
        bBuf[1] = bBuf[0];
        bBuf[0] = bDat;
        if (bBuf[0] == 0xff && bBuf[1] == 0xff) {
            break;
        }
        Cnt++;
        if (Cnt > 10) {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief   指令应答函数
 */
int FEET_Servo::Servo_Ack(void)
{
    uint8_t bBuf[4];
    uint8_t calSum;
    // Error = 0;
    if (ID != 0xfe) {
        if (!Servo_Check_Head()) {
            return 0;
        }
        if (Servo_Read_Buf(bBuf, 4) != 4) {
            return 0;
        }
        if (bBuf[0] != ID) {
            return 0;
        }
        if (bBuf[1] != 2) {
            return 0;
        }
        calSum = ~(bBuf[0] + bBuf[1] + bBuf[2]);
        if (calSum != bBuf[3]) {
            return 0;
        }
        // Error = bBuf[2];
    }
    return 1;
}

/**
 * @brief 舵机读取数据帧函数
 * @param MemAddr 内存表地址
 * @param nData   接收数据缓冲区
 * @param nLen    接收数据长度
 * @retval  实际接收数据长度
 */
int FEET_Servo::Servo_Read(uint8_t MemAddr, uint8_t *nData, uint8_t nLen)
{
    int Size;
    uint8_t bBuf[4];
    uint8_t calSum;
    uint8_t i;
    Servo_Write_Buf(MemAddr, &nLen, 1, INST_READ);
    if (!Servo_Check_Head()) {
        return 0;
    }
    // Error = 0;
    if (Servo_Read_Buf(bBuf, 3) != 3) {
        return 0;
    }
    Size = Servo_Read_Buf(nData, nLen);
    if (Size != nLen) {
        return 0;
    }
    if (Servo_Read_Buf(bBuf + 3, 1) != 1) {
        return 0;
    }
    calSum = bBuf[0] + bBuf[1] + bBuf[2];
    for (i = 0; i < Size; i++) {
        calSum += nData[i];
    }
    calSum = ~calSum;
    if (calSum != bBuf[3]) {
        return 0;
    }
    // Error = bBuf[2];
    return Size;
}

/**
 * @brief 读取单字节数据函数
 * @param MemAddr 内存表地址
 */
int FEET_Servo::Servo_Read_Byte(uint8_t MemAddr)
{
    uint8_t bDat;
    int Size = Servo_Read(MemAddr, &bDat, 1);
    if (Size != 1) {
        return -1;
    } else {
        return bDat;
    }
}

/**
 * @brief 读取双字节数据函数
 * @param MemAddr 内存表地址
 */
int FEET_Servo::Servo_Read_Word(uint8_t MemAddr)
{
    uint8_t nDat[2];
    int Size;
    uint16_t wDat;
    Size = Servo_Read(MemAddr, nDat, 2);
    if (Size != 2)
        return -1;
    wDat = Int8_2_Int16(nDat[0], nDat[1]);
    return wDat;
}
/*************************************************************************************/

/**
 * @brief 位置模式控制函数
 * @param Position  位置 0-4096
 * @param Speed     速度  0-254
 * @param ACC       加速度 0-254
 * @return
 */
int FEET_Servo::Servo_Write_PosEx(int16_t Position, uint16_t Speed, uint8_t ACC)
{
    uint8_t bBuf[7];
    if (Position < 0) {
        Position = -Position;
        Position |= (1 << 15);
    }

    bBuf[0] = ACC;
    Int16_2_Int8(bBuf + 1, bBuf + 2, Position);
    Int16_2_Int8(bBuf + 3, bBuf + 4, 0);
    Int16_2_Int8(bBuf + 5, bBuf + 6, Speed);

    return Servo_gen_Write(SMS_STS_ACC, bBuf, 7);
}

/**
 * @brief 恒速模式指令
 */
int FEET_Servo::WheelMode(void)
{
    return Servo_Write_Byte(SMS_STS_MODE, 1);
}

/**
 * @brief 恒速模式速度控制指令
 * @param Speed 速度
 * @param ACC 加速度
 */
int FEET_Servo::Servo_Write_Speed(int16_t Speed, uint8_t ACC)
{
    uint8_t bBuf[2];
    if (Speed < 0) {
        Speed = -Speed;
        Speed |= (1 << 15);
    }
    bBuf[0] = ACC;
    Servo_gen_Write(SMS_STS_ACC, bBuf, 1);
    Int16_2_Int8(bBuf + 0, bBuf + 1, Speed);
    Servo_gen_Write(SMS_STS_GOAL_SPEED_L, bBuf, 2);
    return 1;
}

/**
 * @brief 扭矩控制指令
 * @param Enable    使能标志
 */
int FEET_Servo::Servo_EnableTorque(uint8_t Enable)
{
    return Servo_Write_Byte(SMS_STS_TORQUE_ENABLE, Enable);
}

/**
 * @brief EPROM 解锁指令
 */
int FEET_Servo::Servo_UnLock_Eprom(void)
{
    return Servo_Write_Byte(SMS_STS_LOCK, 0);
}

/**
 * @brief EPROM 加锁指令
 */
int FEET_Servo::Servo_Lock_Eprom(void)
{
    return Servo_Write_Byte(SMS_STS_LOCK, 1);
}

/**
 * @brief 中位校准指令
 */
int FEET_Servo::Servo_CalibrationOfs(void)
{
    return Servo_Write_Byte(SMS_STS_TORQUE_ENABLE, 128);
}

/**
 * @brief 反馈舵机信息指令
 */
int FEET_Servo::Servo_FeedBack(void)
{
    uint8_t Mem[SMS_STS_PRESENT_CURRENT_H - SMS_STS_PRESENT_POSITION_L + 1];
    int nLen = Servo_Read(SMS_STS_PRESENT_POSITION_L, Mem, sizeof(Mem));
    if (nLen != sizeof(Mem)) {
        Err = 1;
        return -1;
    }
    Err = 0;
    return nLen;
}

/**
 * @brief Ping 指令函数
 */
int FEET_Servo::Servo_Ping(void)
{
    uint8_t bBuf[4];
    uint8_t calSum;
    Servo_Write_Buf(0, NULL, 0, INST_PING);
    // Error = 0;
    if (!Servo_Check_Head()) {
        return -1;
    }

    if (Servo_Read_Buf(bBuf, 4) != 4) {
        return -1;
    }
    if (bBuf[0] != ID && ID != 0xfe) {
        return -1;
    }
    if (bBuf[1] != 2) {
        return -1;
    }
    calSum = ~(bBuf[0] + bBuf[1] + bBuf[2]);
    if (calSum != bBuf[3]) {
        return -1;
    }
    // Error = bBuf[2];
    return bBuf[0];
}

/**
 * @brief 位置读取函数
 * @retval  当前位置
 */
int FEET_Servo::Servo_Read_Pos(void)
{
    int Pos = -1;
    if (ID == -1) {
        Pos = Mem[SMS_STS_PRESENT_POSITION_H - SMS_STS_PRESENT_POSITION_L];
        Pos <<= 8;
        Pos |= Mem[SMS_STS_PRESENT_POSITION_L - SMS_STS_PRESENT_POSITION_L];
    } else {
        Err = 0;
        Pos = Servo_Read_Word(SMS_STS_PRESENT_POSITION_L);
        if (Pos == -1) {
            Err = 1;
        }
    }
    if (!Err && Pos & (1 << 15)) {
        Pos = -(Pos & ~(1 << 15));
    }
    return Pos;
}

/**
 * @brief 速度读取函数
 * @retval  当前速度
 */
int FEET_Servo::Servo_Read_Speed(void)
{
    int Speed = -1;
    if (ID == -1) {
        Speed = Mem[SMS_STS_PRESENT_SPEED_H - SMS_STS_PRESENT_POSITION_L];
        Speed <<= 8;
        Speed |= Mem[SMS_STS_PRESENT_SPEED_L - SMS_STS_PRESENT_POSITION_L];
    } else {
        Err   = 0;
        Speed = Servo_Read_Word(SMS_STS_PRESENT_SPEED_L);
        if (Speed == -1) {
            Err = 1;
            return -1;
        }
    }
    if (!Err && Speed & (1 << 15)) {
        Speed = -(Speed & ~(1 << 15));
    }
    return Speed;
}

/**
 * @brief 力矩读取函数
 * @retval  当前力矩
 */
int FEET_Servo::Servo_Read_Load(void)
{
    int Load = -1;
    if (ID == -1) {
        Load = Mem[SMS_STS_PRESENT_LOAD_H - SMS_STS_PRESENT_POSITION_L];
        Load <<= 8;
        Load |= Mem[SMS_STS_PRESENT_LOAD_L - SMS_STS_PRESENT_POSITION_L];
    } else {
        Err  = 0;
        Load = Servo_Read_Word(SMS_STS_PRESENT_LOAD_L);
        if (Load == -1) {
            Err = 1;
        }
    }
    if (!Err && Load & (1 << 10)) {
        Load = -(Load & ~(1 << 10));
    }
    return Load;
}

/**
 * @brief 电压读取函数
 * @retval  当前电压
 */
int FEET_Servo::Servo_Read_Voltage(void)
{
    int Voltage = -1;
    if (ID == -1) {
        Voltage = Mem[SMS_STS_PRESENT_VOLTAGE - SMS_STS_PRESENT_POSITION_L];
    } else {
        Err     = 0;
        Voltage = Servo_Read_Byte(SMS_STS_PRESENT_VOLTAGE);
        if (Voltage == -1) {
            Err = 1;
        }
    }
    return Voltage;
}

/**
 * @brief 温度读取函数
 * @retval  当前温度
 */
int FEET_Servo::Servo_Read_Temper(void)
{
    int Temper = -1;
    if (ID == -1) {
        Temper = Mem[SMS_STS_PRESENT_TEMPERATURE - SMS_STS_PRESENT_POSITION_L];
    } else {
        Err    = 0;
        Temper = Servo_Read_Byte(SMS_STS_PRESENT_TEMPERATURE);
        if (Temper == -1) {
            Err = 1;
        }
    }
    return Temper;
}

/**
 * @brief 状态读取函数
 * @retval  当前状态
 */
int FEET_Servo::Servo_Read_Move(void)
{
    int Move = -1;
    if (ID == -1) {
        Move = Mem[SMS_STS_MOVING - SMS_STS_PRESENT_POSITION_L];
    } else {
        Err  = 0;
        Move = Servo_Read_Byte(SMS_STS_MOVING);
        if (Move == -1) {
            Err = 1;
        }
    }
    return Move;
}

/**
 * @brief 电流读取函数
 * @retval  当前电流
 */
int FEET_Servo::Servo_Read_Current(void)
{
    int Current = -1;
    if (ID == -1) {
        Current = Mem[SMS_STS_PRESENT_CURRENT_H - SMS_STS_PRESENT_POSITION_L];
        Current <<= 8;
        Current |= Mem[SMS_STS_PRESENT_CURRENT_L - SMS_STS_PRESENT_POSITION_L];
    } else {
        Err     = 0;
        Current = Servo_Read_Word(SMS_STS_PRESENT_CURRENT_L);
        if (Current == -1) {
            Err = 1;
            return -1;
        }
    }
    if (!Err && Current & (1 << 15)) {
        Current = -(Current & ~(1 << 15));
    }
    return Current;
}