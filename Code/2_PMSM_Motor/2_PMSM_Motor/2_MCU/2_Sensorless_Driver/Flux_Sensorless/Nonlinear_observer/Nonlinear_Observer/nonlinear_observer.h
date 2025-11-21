#ifndef __NONLINEAR_OBSERVER_H
#define __NONLINEAR_OBSERVER_H

#include "coordinate_transform.h"
#include "foc_math.h"

#define Rs     120e-3  // 定子电阻
#define Ls     50e-6   // 定子电感
#define Flux_f 0.0015f // 转子磁链

/**
 * @brief  非线性磁链观测器结构体
 */
typedef struct
{
    // 运行控制相关参数
    uint8_t enable; // 算法使能

    // 临时变量
    float x1;              // x1 观测值
    float x2;              // x2 观测值

    // 输出参数
    float theta_obs; // 估计角度
    float speed_obs; // 估计速度

    // 输入参数
    alpha_beta_t i;   // alpha/beta 轴采样电流
    alpha_beta_t u;   // alpha/beta 轴电压
    float theta_true; // 真实角度
    float speed_true; // 真实速度

    // 初始化
    float gamma;       // 磁链观测器增益
    float sample_time; // 采样时间
    PID_t pll;         // 锁相环
    LPF_t speed_lpf;   // 电角速度低通滤波器

} Nonlinear_Observer_TypeDef;

void Nonlinear_Observer_Init(Nonlinear_Observer_TypeDef *lun, float gamma, float pll_kp, float pll_ki, float fc, float sample_time);
void Nonlinear_Observer_Update(Nonlinear_Observer_TypeDef *obs);

#endif
