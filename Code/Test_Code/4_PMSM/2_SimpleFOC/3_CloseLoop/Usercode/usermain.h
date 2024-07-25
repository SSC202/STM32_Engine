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
#include "sensor.h"
#include "pid.h"

void usermain(void);

#endif