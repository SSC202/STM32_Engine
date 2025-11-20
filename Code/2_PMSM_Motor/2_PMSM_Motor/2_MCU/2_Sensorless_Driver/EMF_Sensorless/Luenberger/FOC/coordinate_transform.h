/**
 * @file    坐标变换相关函数
 * @note    本文件包含了电机坐标变换的相关函数和接口
 *          接口类型
 *              abc_t               三相静止坐标系下的物理量类型结构体(电压/电流...)
 *              dq_t                两相旋转坐标系下的物理量类型结构体(电压/电流...)
 *              alpha_beta_t        两相静止坐标系下的物理量类型结构体(电压/电流...)
 *          接口函数
 *              函数规范: 第一个参数为变换前的结构体指针,第二个参数为变换后的结构体指针,第三个参数为变换时的电角度
 *              abc_2_alphabeta     ABC 轴系物理量变换到 alpha-beta 轴系
 *              abc_2_dq            ABC 轴系物理量变换到 dq 轴系
 *              alphabeta_2_abc     alpha-beta 轴系物理量变换到 ABC 轴系
 *              alphabeta_2_dq      alpha-beta 轴系物理量变换到 dq 轴系
 *              dq_2_abc            dq 轴系物理量变换到 ABC 轴系
 *              dq_2_alphabeta      dq 轴系物理量变换到 alpha-beta 轴系
 */
#ifndef __COORDINATE_TRANSFORM_H
#define __COORDINATE_TRANSFORM_H

#include "foc_math.h"

/**
 * 结构体相关定义
 */

typedef struct
{
    float a;
    float b;
    float c;
} abc_t; // ABC 三相静止坐标系结构体

typedef struct
{
    float alpha;
    float beta;
} alpha_beta_t; // alpha-beta 两相静止坐标系结构体

typedef struct
{
    float d;
    float q;
} dq_t; // dq 旋转坐标系结构体

/**
 * 接口函数相关定义
 */
void abc_2_alphabeta(abc_t *abc, alpha_beta_t *alpha_beta);
void abc_2_dq(abc_t *abc, dq_t *dq, float theta);
void alphabeta_2_abc(alpha_beta_t *alpha_beta, abc_t *abc);
void alphabeta_2_dq(alpha_beta_t *alpha_beta, dq_t *dq, float theta);
void dq_2_abc(dq_t *dq, abc_t *abc, float theta);
void dq_2_alphabeta(dq_t *dq, alpha_beta_t *alpha_beta, float theta);

#endif // !_TF_H__
