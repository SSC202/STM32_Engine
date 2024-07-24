#ifndef __USERMAIN_H
#define __USERMAIN_H

#define POLE_PAIRS 7
#define U_dc       12
#define Ts         1

#include "main.h"
#include "userdebug.h"

#include "tim.h"

#include "arm_math.h"

#include "foc_utils.h"
#include "foc_motor.h"

extern float shaft_angle;   // 机械角度，用于开环角度生成器
extern float open_velocity; // 开环速度，用于开环角度生成器
extern float uq;

void usermain(void);

#endif