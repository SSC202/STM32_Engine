#ifndef __ODRIVE_H
#define __ODRIVE_H

#include "stm32f4xx.h"
#include "can.h"

// Odrive 常用指令
#define ODRIVE_HEARTBEAT_MESSAGE 0x001
#define SET_AXIS_NODE_ID 0x006
#define SET_AXIS_REQUESTED_STATE 0x007
#define ENCODER_ESTIMATES 0x009
#define GET_ENCODER_COUNT 0x00A
#define SET_CONTROLLER_MODES 0x00B
#define SET_INPUT_POS 0x00C
#define SET_INPUT_VEL 0x00D
#define SET_INPUT_TORQUE 0x00E
#define SET_LIMITS 0x00F
#define GET_IQ 0x014
#define REBOOT_ODRIVE 0x016
#define GET_BUS_VOLTAGE_CURRENT 0x017
#define CLEAR_ERRORS 0x018
#define SET_POSITION_GAIN 0x01A
#define SET_VEL_GAINS 0x01B

// CAN 通讯相关定义
#define CAN_BAUDRATE_1000_KBPS 0x001a0002
#define CAN_BAUDRATE_500_KBPS 0x001a0005
#define CAN_BAUDRATE_250_KBPS 0x001a000b
#define CAN_BAUDRATE_125_KBPS 0x001c0014
#define CAN_BAUDRATE_100_KBPS 0x001b001b
#define CAN_BAUDRATE_50_KBPS 0x001b0037
#define CAN_BAUDRATE_10_KBPS 0x001b0117

#define CAN_Frame_Data 0
#define CAN_Frame_Remote 10
#define CAN_ID_Standard 0
#define CAN_ID_Extended 10

#define CAN_FILTER_MASK_MODE 0
#define CAN_FILTER_LIST_MODE 10

#define CAN_Timestamp_Enable 1
#define CAN_Timestamp_Disable 0

#define CAN_Initialization_Mode 0x10
#define CAN_Sleep_Mode 0xEF
#define CAN_Normal_Mode 0x45

#define CAN_TX_Mailbox_0 0x00
#define CAN_TX_Mailbox_1 0xAA
#define CAN_TX_Mailbox_2 0xFF

#define CAN_Timestamp_Enable 1
#define CAN_Timestamp_Disable 0

#define CAN_Filter_Scale_16bit 0
#define CAN_Filter_Scale_32bit 1

#define CAN_Filter_Bank_FIFO0 0
#define CAN_Filter_Bank_FIFO1 1

#define CAN_TX_Buffer_0 1
#define CAN_TX_Buffer_1 2
#define CAN_TX_Buffer_2 3

#define CAN_RX_Buffer_1 4
#define CAN_RX_Buffer_2 5

#define CAN_TX_All_Buffers 10
#define CAN_RX_ALL_Buffers 20

// CAN 接收结构体
typedef struct CAN_RX_Typedef
{
    int message_timestamp;
    int data_length;
    int data[8];
    int filter_index;
    int frame_type;
    int id_type;
    int32_t ID;
} CAN_RX_Typedef;

// CAN 发送结构体
typedef struct CAN_TX_Typedef
{
    int id_type;
    int frame_type;
    int send_timestamp;
    int32_t ID;
    int data_length;
    int data[8];
} CAN_TX_Typedef;

// Odrive 轴结构体
typedef struct Axis
{
    int AXIS_ID;
    float AXIS_Encoder_Pos;
    float AXIS_Encoder_Vel;
    int32_t AXIS_Encoder_CPR;
    int32_t AXIS_Encoder_Shadow;
    float AXIS_Bus_Voltage;
    float AXIS_Bus_Current;
    float AXIS_Iq_Setpoint;
    float AXIS_Iq_Measured;
    uint32_t AXIS_Error;
    uint8_t AXIS_Current_State;
    uint8_t Controller_Status;
} axis_t;

// Odrive 轴状态定义
typedef enum
{
    UNDEFINED = 0x0,
    IDLE = 0x1,
    STARTUP_SEQUENCE = 0x2,
    FULL_CALIBRATION_SEQUENCE = 0x3,
    MOTOR_CALIBRATION = 0x4,
    ENCODER_INDEX_SEARCH = 0x6,
    ENCODER_OFFSET_CALIBRATION = 0x7,
    CLOSED_LOOP_CONTROL = 0x8,
    LOCKIN_SPIN = 0x9,
    ENCODER_DIR_FIND = 0xA,
    HOMING = 0xB,
    ENCODER_HALL_POLARITY_CALIBRATION = 0xC,
    ENCODER_HALL_PHASE_CALIBRATION = 0xD
} Axis_State;

// Odrive 控制状态定义
typedef enum
{
    VOLTAGE_CONTROL = 0x0,
    TORQUE_CONTROL = 0x1,
    VELOCITY_CONTROL = 0x2,
    POSITION_CONTROL = 0x3
} Control_Mode;

// Odrive 输入状态定义
typedef enum
{
    INACTIVE = 0x0,
    PASSTHROUGH = 0x1,
    VEL_RAMP = 0x2,
    POS_FILTER = 0x3,
    MIX_CHANNELS = 0x4,
    TRAP_TRAJ = 0x5,
    TORQUE_RAMP = 0x6,
    MIRROR = 0x7,
    TUNING = 0x8
} Input_Mode;

extern axis_t odrive_axis[2];

void odrive_init(void);
void odrive_canfilter_init(void);
void Set_Axis_Requested_State(axis_t Axis, Axis_State state);
void Set_Input_Vel(axis_t Axis, float vel, float torqueff);
void Clear_Errors(axis_t Axis);
void Reboot_ODrive(axis_t Axis);
void Set_Controller_Modes(axis_t Axis, Control_Mode ControlMode, Input_Mode InputMode);
void Set_Input_Pos(axis_t Axis, float Input_Pos, int Vel_FF, int Torque_FF);
void Get_Encoder_Count(axis_t Axis);
void Set_Input_Torque(axis_t Axis, float torque);
void Get_Bus_Voltage_Current(axis_t Axis);
void Get_IQ(axis_t Axis);
void Set_Position_Gain(axis_t Axis, float pos_gain);
void Set_Vel_Gains(axis_t Axis, float Vel_Gain, float Vel_Int_Gain);
void Set_Axis_Node_ID(axis_t Axis, uint32_t node_id);
void Set_Limits(axis_t Axis, float vel_lim, float curr_lim);
void get_axis_status(axis_t *AXIS, int32_t CMD_ID);

#endif