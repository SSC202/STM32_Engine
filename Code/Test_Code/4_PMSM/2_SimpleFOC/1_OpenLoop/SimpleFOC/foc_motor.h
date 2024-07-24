#ifndef __FOC_MOTOR_H
#define __FOC_MOTOR_H

#include "foc_utils.h"

#include "usermain.h"


void set_phase_voltage(float u_q, float u_d, float electric_angle);

#endif