#ifndef __FOC_MOTOR_H
#define __FOC_MOTOR_H

#include "foc_utils.h"

#include "usermain.h"

typedef enum {
    CW      = 1, 
    CCW     = -1,
    UNKNOWN = 0
} Direction;

extern Direction sensor_direction;
extern float zero_electric_angle;

int align_sensor(void);
void set_phase_voltage(float u_q, float u_d, float electric_angle);

#endif