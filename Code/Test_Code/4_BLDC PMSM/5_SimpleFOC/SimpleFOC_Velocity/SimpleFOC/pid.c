#include "Mymain.h"

float pid_vel_P, pid_ang_P;
float pid_vel_I, pid_ang_D;
float integral_vel_prev;
float error_vel_prev, error_ang_prev;
float output_vel_ramp;
float output_vel_prev;
unsigned long pid_vel_timestamp, pid_ang_timestamp;

void PID_init(void)
{
    pid_vel_P         = 0.1; // 0.1
    pid_vel_I         = 2;   // 2
    output_vel_ramp   = 100; // output derivative limit [volts/second]
    integral_vel_prev = 0;
    error_vel_prev    = 0;
    output_vel_prev   = 0;
    pid_vel_timestamp = SysTick->VAL;

    pid_ang_P         = 10;
    pid_ang_D         = 0.5;
    error_ang_prev    = 0;
    pid_ang_timestamp = SysTick->VAL;
}
// just P&I is enough,no need D
float PID_velocity(float error)
{
    unsigned long now_us;
    float Ts;
    float proportional, integral, output;
    float output_rate;

    now_us = SysTick->VAL;
    if (now_us < pid_vel_timestamp)
        Ts = (float)(pid_vel_timestamp - now_us) / 9 * 1e-6f;
    else
        Ts = (float)(0xFFFFFF - now_us + pid_vel_timestamp) / 9 * 1e-6f;
    pid_vel_timestamp = now_us;
    if (Ts == 0 || Ts > 0.5) Ts = 1e-3f;

    // u(s) = (P + I/s + Ds)e(s)
    // Discrete implementations
    // proportional part
    // u_p  = P *e(k)
    proportional = pid_vel_P * error;
    // Tustin transform of the integral part
    // u_ik = u_ik_1  + I*Ts/2*(ek + ek_1)
    integral = integral_vel_prev + pid_vel_I * Ts * 0.5 * (error + error_vel_prev);
    // antiwindup - limit the output
    integral = _constrain(integral, -voltage_limit, voltage_limit);

    // sum all the components
    output = proportional + integral;
    // antiwindup - limit the output variable
    output = _constrain(output, -voltage_limit, voltage_limit);

    // limit the acceleration by ramping the output
    output_rate = (output - output_vel_prev) / Ts;
    if (output_rate > output_vel_ramp)
        output = output_vel_prev + output_vel_ramp * Ts;
    else if (output_rate < -output_vel_ramp)
        output = output_vel_prev - output_vel_ramp * Ts;

    // saving for the next pass
    integral_vel_prev = integral;
    output_vel_prev   = output;
    error_vel_prev    = error;

    return output;
}

// P&D for angle_PID
float PID_angle(float error)
{
    unsigned long now_us;
    float Ts;
    float proportional, derivative, output;
    // float output_rate;

    now_us = SysTick->VAL;
    if (now_us < pid_ang_timestamp)
        Ts = (float)(pid_ang_timestamp - now_us) / 9 * 1e-6f;
    else
        Ts = (float)(0xFFFFFF - now_us + pid_ang_timestamp) / 9 * 1e-6f;
    pid_ang_timestamp = now_us;
    if (Ts == 0 || Ts > 0.5) Ts = 1e-3f;

    // u(s) = (P + I/s + Ds)e(s)
    // Discrete implementations
    // proportional part
    // u_p  = P *e(k)
    proportional = pid_ang_P * error;
    // u_dk = D(ek - ek_1)/Ts
    derivative = pid_ang_D * (error - error_ang_prev) / Ts;

    output = proportional + derivative;
    output = _constrain(output, -velocity_limit, velocity_limit);

    //  limit the acceleration by ramping the output
    //	output_rate = (output - output_ang_prev)/Ts;
    //	if(output_rate > output_ang_ramp)output = output_ang_prev + output_ang_ramp*Ts;
    //	else if(output_rate < -output_ang_ramp)output = output_ang_prev - output_ang_ramp*Ts;

    // saving for the next pass
    //	output_ang_prev = output;
    error_ang_prev = error;

    return output;
}
