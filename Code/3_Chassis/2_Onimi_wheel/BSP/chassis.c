#include "chassis.h"

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

    *vx = (lf_speed + lb_speed + rf_speed + rb_speed) / 4.0;
    *vy = (lf_speed + rb_speed - rf_speed - lb_speed) / 4.0;
    *wc = (-lf_speed - lb_speed + rf_speed + rb_speed) / (4.0 * r);
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
    float l_f_speed = lf_speed * 60.0 / (2 * PI);
    float l_b_speed = lb_speed * 60.0 / (2 * PI);
    float r_f_speed = -(rf_speed * 60.0 / (2 * PI));
    float r_b_speed = -(rb_speed * 60.0 / (2 * PI));

    Motor_Speed_Set(&LEFT_FRONT_WHEEL, l_f_speed);
    Motor_Speed_Set(&LEFT_BACKWORD_WHEEL, l_b_speed);
    Motor_Speed_Set(&RIGHT_FRONT_WHEEL, r_f_speed);
    Motor_Speed_Set(&RIGHT_BACKWORD_WHEEL, r_b_speed);
}

#endif
#ifdef ONIMI_MODE_THREE

#include "math.h"

#define PI 3.14159

/**
 * @brief   正运动学方程，返回轮式里程计的速度数据
 * @param   vx          底盘前向速度，单位m/s
 * @param   vy          底盘左横向速度，单位m/s
 * @param   wc          转向角速度，使用弧度，单位rad/s
 */
void Forward_kinematic_equation(float *vx, float *vy, float *wc)
{
    // rpm 转换为 m/s
    float m1_speed = -(M1_WHEEL.speed * (2 * PI * WHEEL_R) / 60.0);
    float m2_speed = -(M2_WHEEL.speed * (2 * PI * WHEEL_R) / 60.0);
    float m3_speed = -(M3_WHEEL.speed * (2 * PI * WHEEL_R) / 60.0);

    *vx = (-m2_speed / sqrt(3) + m3_speed / sqrt(3));
    *vy = (2 * m1_speed - m2_speed - m3_speed) / 3.0;
    *wc = (m1_speed + m2_speed + m3_speed) / (3.0 * BASE_R);
}

/**
 * @brief   逆运动学方程，输入速度求解电机转速
 * @param   vx          底盘前向速度，单位m/s
 * @param   vy          底盘左横向速度，单位m/s
 * @param   wc          转向角速度，使用弧度，单位rad/s
 */
void Inverse_kinematic_equation(float vx, float vy, float wc)
{
    float m1_speed = 0.0;
    float m2_speed = 0.0;
    float m3_speed = 0.0;

    m1_speed = (float)(vy + BASE_R * wc) / WHEEL_R;
    m2_speed = (float)(-sqrt(3) * vx / 2.0 - vy / 2.0 + BASE_R * wc) / WHEEL_R;
    m3_speed = (float)(sqrt(3) * vx / 2.0 - vy / 2.0 + BASE_R * wc) / WHEEL_R;

    // m/s 转换为 rpm
    float m_1_speed = -(m1_speed * 60.0 / (2 * PI));
    float m_2_speed = -(m2_speed * 60.0 / (2 * PI));
    float m_3_speed = -(m3_speed * 60.0 / (2 * PI));

    Motor_Speed_Set(&M1_WHEEL, m_1_speed);
    Motor_Speed_Set(&M2_WHEEL, m_2_speed);
    Motor_Speed_Set(&M3_WHEEL, m_3_speed);
}

#endif