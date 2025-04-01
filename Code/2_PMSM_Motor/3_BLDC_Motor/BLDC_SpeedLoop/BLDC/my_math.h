/**
 * @file    数学计算和通用计算相关
 * @note    本文件包含数学常量定义,通用计算的相关定义和基础数学运算的相关定义。
 *          1. 通用计算相关定义
 *              get_max()       三值取最大值函数
 *              get_min()       三值取最小值函数
 *              get_middle()    三值取中间值函数
 *
 *              normalize()     机械角度转换为电角度
 */
#ifndef __MY_MATH_H
#define __MY_MATH_H

#include "math.h"
#include "stm32g4xx.h"

#define M_PI 3.141592653589793f // PI

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

float normalize(int pole_pairs, float mechine_angle, float offset);
float get_middle(float a, float b, float c);
float get_max(float a, float b, float c);
float get_min(float a, float b, float c);

void PID_init(PID_t *pid, float kp, float ki, float kd, float outputMax);
void PID_Calc(PID_t *pid, uint8_t enable, float t_sample);

void LPF_Init(LPF_t *lpf, float f_c, float t_sample);
void LPF_Calc(LPF_t *lpf);

#endif