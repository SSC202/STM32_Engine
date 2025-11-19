#ifndef __SMO_H
#define __SMO_H

#include "coordinate_transform.h"
#include "foc_math.h"

#define Rs 120e-3
#define Ls 50e-6

/**
 * @brief   滑模观测器结构体
 */
typedef struct {
    // 运行控制相关参数
    uint8_t enable; // 算法使能

    // 临时变量
    alpha_beta_t i_hat; // alpha/beta 轴电流观测值
    alpha_beta_t e_hat; // alpha/beta 轴反电动势观测值

    // 输出参数
    float theta_obs; // 估计角度
    float speed_obs; // 估计速度

    // 输入参数
    alpha_beta_t i;   // alpha/beta 轴采样电流
    alpha_beta_t u;   // alpha/beta 轴电压
    float theta_true; // 真实角度
    float speed_true; // 真实速度

    // 初始化
    float K;           // 电流观测器增益
    float M;           // 反电动势观测器增益
    float sample_time; // 采样时间
    PID_t pll;         // 锁相环
    LPF_t speed_lpf;   // 电角速度低通滤波器

} SMO_TypeDef;

void SMO_Init(SMO_TypeDef *smo, float K, float M, float pll_kp, float pll_ki, float fc, float sample_time);
void SMO_Update(SMO_TypeDef *smo);

#endif
