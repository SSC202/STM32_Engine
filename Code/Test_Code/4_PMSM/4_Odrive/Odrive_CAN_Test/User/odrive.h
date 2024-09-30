#ifndef __ODRIVE_H
#define __ODRIVE_H

#include "stm32f1xx.h"
#include "can.h"

#define AXIS0_CAN_NODE_ID (0x000)
#define AXIS1_CAN_NODE_ID (0x001)
#define NODE_ID(num)      ((num) == 0 ? AXIS0_CAN_NODE_ID : AXIS1_CAN_NODE_ID)

typedef enum {
    MSG_CO_NMT_CTRL = 0x000, // CANOpen NMT Message REC
    MSG_ODRIVE_HEARTBEAT,
    MSG_ODRIVE_ESTOP,
    MSG_GET_MOTOR_ERROR, // Errors
    MSG_GET_ENCODER_ERROR,
    MSG_GET_SENSORLESS_ERROR,
    MSG_SET_AXIS_NODE_ID,
    MSG_SET_AXIS_REQUESTED_STATE,
    MSG_SET_AXIS_STARTUP_CONFIG,
    MSG_GET_ENCODER_ESTIMATES,
    MSG_GET_ENCODER_COUNT,
    MSG_SET_CONTROLLER_MODES,
    MSG_SET_INPUT_POS,
    MSG_SET_INPUT_VEL,
    MSG_SET_INPUT_CURRENT,
    MSG_SET_VEL_LIMIT,
    MSG_START_ANTICOGGING,
    MSG_SET_TRAJ_VEL_LIMIT,
    MSG_SET_TRAJ_ACCEL_LIMITS,
    MSG_SET_TRAJ_A_PER_CSS,
    MSG_GET_IQ,
    MSG_GET_SENSORLESS_ESTIMATES,
    MSG_RESET_ODRIVE,
    MSG_GET_VBUS_VOLTAGE,
    MSG_CLEAR_ERRORS,
    MSG_CO_HEARTBEAT_CMD = 0x700, // CANOpen NMT Heartbeat  SEND
} OdriveMsg_t;

typedef struct
{
    float set_pos0; // 轴-0目标位置
    float set_pos1; // 轴-1目标位置
    int pos0;
    int pos1;
} OdirveTypeDef;

extern OdirveTypeDef odrive;

void odrive_canfilter_init(void);
void odrive_init(void);
void odrive_pos_callback(unsigned char num);
void odrive_pos_ctrl(unsigned char num, float pos);

#endif