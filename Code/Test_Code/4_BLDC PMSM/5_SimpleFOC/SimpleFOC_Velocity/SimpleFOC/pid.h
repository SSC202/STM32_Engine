#ifndef __PID_H
#define __PID_H

void PID_init(void);
float PID_velocity(float error);
float PID_angle(float error);

#endif