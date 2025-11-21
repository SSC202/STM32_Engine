/**
 * @file    数学计算和通用计算相关
 * @note    本文件包含数学常量定义,通用计算的相关定义和基础数学运算的相关定义。
 *          1. 通用计算相关定义
 *              接口函数:    get_max()       三值取最大值函数
 *                          get_min()       三值取最小值函数
 *                          get_middle()    三值取中间值函数
 *                          normalize()     机械角度转换为电角度
 *                          fast_sin()      快速正弦函数
 *                          fast_cos()      快速余弦函数
 *                          fast_sqrt()     快速开方函数
 *          2. PID 计算(增量式PID)
 *              接口类型: PID_t  PID结构体句柄,使用时在主函数内定义全局结构体
 *              接口函数:   PID_init()      PID结构体初始化
 *                          PID_Calc()     单次PID计算
 *          3. IIR 滤波器
 *              接口类型: LPF_t  低通滤波器结构体句柄,使用时在主函数内定义全局结构体
 *              接口函数:   LPF_Init()      低通滤波器结构体初始化
 *                          LPF_Calc()     单次低通滤波器计算
 *
 */
#ifndef __MY_MATH_H
#define __MY_MATH_H

#include "math.h"
#include "stm32g4xx.h"

#define M_PI         3.14159265359f // PI
#define M_PI_3       1.0471975512f  // PI/3

#define M_SQRT3      1.73205080757f // SQRT(3)
#define M_1_SQRT3    0.57735026919f // 1/SQRT(3)
#define M_SQRT3_2    0.86602540378f // SQRT(3)/2

#define M_2_DIV3     0.66666666667f // 2/3

#define M_TABLE_SIZE 1024

float normalize(int pps, float mechine_angle, float offset);
float get_middle(float a, float b, float c);
float get_max(float a, float b, float c);
float get_min(float a, float b, float c);

float fast_sin(float x);
float fast_cos(float x);
float fast_sqrt(float x);

/**
 * PID 相关定义
 */
typedef struct {
    float KP;        // PID参数P
    float KI;        // PID参数I
    float KD;        // PID参数D
    float fdb;       // PID反馈值
    float ref;       // PID目标值
    float cur_error; // 当前误差
    float error[2];  // 前两次误差
    float output;    // 输出值
    float outputMax; // 最大输出值的绝对值
    float outputMin; // 最小输出值的绝对值用于防抖
} PID_t;

/**
 * IIR 滤波器相关定义
 */
typedef struct
{
    float tsample;     // 采样时间
    float wc;          // 截止频率
    float alpha;       // 滤波器系数
    float input;       // 当前输入值
    float output_last; // 前次输出值
    float output;      // 当前输出值
} LPF_t;

void PID_Init(PID_t *pid, float kp, float ki, float kd, float outputMax);
void PID_Calc(PID_t *pid, uint8_t enable, float t_sample);

void LPF_Init(LPF_t *lpf, float f_c, float t_sample);
void LPF_Calc(LPF_t *lpf, uint8_t enable);

#endif
