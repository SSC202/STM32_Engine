#ifndef __CHASSIS_H
#define __CHASSIS_H

#include "motor.h"

/*************底盘模型选择段**************/
// #define MECANUM_MODE     // 麦克纳姆轮四轮模型
#define ONIMI_MODE_THREE // 全向轮三轮模型

/*************底盘参数定义段**************/
#ifdef MECANUM_MODE
#define WHEEL_R        0.040f // 轮半径，单位为m
#define CHASSIS_WEIGTH 0.263f // 底盘宽度，单位为m
#define CHASSIS_LENGTH 0.230f // 底盘长度，单位为m

#endif

#ifdef ONIMI_MODE_THREE
#define WHEEL_R 0.065f // 轮半径，单位为m
#define BASE_R  0.150f // 基圆半径，单位为m

#endif
/***************电机指定段***************/
#ifdef MECANUM_MODE
#define RIGHT_FRONT_WHEEL    motor2 // 右前轮
#define RIGHT_BACKWORD_WHEEL motor1 // 右后轮
#define LEFT_FRONT_WHEEL     motor4 // 左前轮
#define LEFT_BACKWORD_WHEEL  motor3 // 左后轮

#endif
#ifdef ONIMI_MODE_THREE
#define M1_WHEEL motor1 // M1
#define M2_WHEEL motor2 // M2
#define M3_WHEEL motor4 // M3

#endif
/****************用户函数****************/

void Forward_kinematic_equation(float *vx, float *vy, float *wc);
void Inverse_kinematic_equation(float vx, float vy, float wc);

#endif