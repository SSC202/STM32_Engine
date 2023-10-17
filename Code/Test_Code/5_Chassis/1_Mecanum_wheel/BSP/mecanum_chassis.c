#include "mecanum_chassis.h"

#ifdef MECANUM_MODE

#define PI 3.14159

/**
 * @brief   正运动学方程，返回轮式里程计的速度数据
 * @param   vx          底盘前向速度，单位m/s
 * @param   vy          底盘左横向速度，单位m/s
 * @param   wc          转向角速度，使用弧度，单位rad/s
 */
void Forward_kinematic_equation(float *vx, float *vy, float *wc)
{
    float rx = CHASSIS_LENGTH / 2.0;
    float ry = CHASSIS_WEIGTH / 2.0;
    float r  = rx + ry;
    // rpm 转换为 m/s
    float lf_speed = LEFT_FRONT_WHEEL.speed * (2 * PI * WHEEL_R) / 60.0;
    float lb_speed = LEFT_BACKWORD_WHEEL.speed * (2 * PI * WHEEL_R) / 60.0;
    float rf_speed = -(RIGHT_FRONT_WHEEL.speed * (2 * PI * WHEEL_R) / 60.0);
    float rb_speed = -(RIGHT_BACKWORD_WHEEL.speed * (2 * PI * WHEEL_R) / 60.0);

    *vx = WHEEL_R * (lf_speed + lb_speed + rf_speed + rb_speed) / 4.0;
    *vy = WHEEL_R * (lf_speed + rb_speed - rf_speed - lb_speed) / 4.0;
    *wc = WHEEL_R * (-lf_speed - lb_speed + rf_speed + rb_speed) / (4.0 * r);
}

/**
 * @brief   逆运动学方程，输入速度求解电机转速
 * @param   vx          底盘前向速度，单位m/s
 * @param   vy          底盘左横向速度，单位m/s
 * @param   wc          转向角速度，使用弧度，单位rad/s
 */
void Inverse_kinematic_equation(float vx, float vy, float wc)
{
    float rx = CHASSIS_LENGTH / 2.0;
    float ry = CHASSIS_WEIGTH / 2.0;
    float r  = rx + ry;

    float lf_speed = 0.0;
    float lb_speed = 0.0;
    float rf_speed = 0.0;
    float rb_speed = 0.0;

    lf_speed = (float)(vx + vy - wc * r) / WHEEL_R;
    lb_speed = (float)(vx - vy - wc * r) / WHEEL_R;
    rf_speed = (float)(vx - vy + wc * r) / WHEEL_R;
    rb_speed = (float)(vx + vy + wc * r) / WHEEL_R;

    // m/s 转换为 rpm
    float l_f_speed = lf_speed * 60.0 / (2 * PI * WHEEL_R);
    float l_b_speed = lb_speed * 60.0 / (2 * PI * WHEEL_R);
    float r_f_speed = -(rf_speed * 60.0 / (2 * PI * WHEEL_R));
    float r_b_speed = -(rb_speed * 60.0 / (2 * PI * WHEEL_R));

    Motor_Speed_Set(&LEFT_FRONT_WHEEL, l_f_speed);
    Motor_Speed_Set(&LEFT_BACKWORD_WHEEL, l_b_speed);
    Motor_Speed_Set(&RIGHT_FRONT_WHEEL, r_f_speed);
    Motor_Speed_Set(&RIGHT_BACKWORD_WHEEL, r_b_speed);
}

#endif