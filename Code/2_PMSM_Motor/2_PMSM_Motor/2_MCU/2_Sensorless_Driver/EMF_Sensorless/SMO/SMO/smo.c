#include "smo.h"

/**
 * @brief   饱和函数
 * @param   x   饱和函数输入
 */
float sat(float x)
{
    const float delta = 0.1f;
    if (x > delta)
        return 1.0f;
    if (x < -delta)
        return -1.0f;
    return x / delta;
}

/**
 * @brief   滑模观测器更新函数
 * @param   smo 滑模观测器句柄
 * @param   u   逆变器输出 alpha-beta 轴电压
 * @param   i   电流采样得到 alpha-beta 轴电流
 */
void SMO_Update(SMO_TypeDef *smo)
{
    // 1. 计算电流误差
    alpha_beta_t i_err;
    i_err.alpha = smo->i_hat.alpha - smo->i.alpha;
    i_err.beta = smo->i_hat.beta - smo->i.beta;

    // 2. 观测器更新
    float coeff1 = 1.f - (Rs * smo->sample_time / Ls);
    float coeff2 = smo->sample_time / Ls;
    float i_alpha_hat_new = coeff1 * smo->i_hat.alpha - coeff2 * smo->e_hat.alpha + coeff2 * smo->u.alpha - (smo->K * smo->sample_time) * sat(i_err.alpha);
    float i_beta_hat_new = coeff1 * smo->i_hat.beta - coeff2 * smo->e_hat.beta + coeff2 * smo->u.beta - (smo->K * smo->sample_time) * sat(i_err.beta);
    float e_alpha_hat_new = smo->e_hat.alpha - smo->speed_obs * smo->sample_time * smo->e_hat.beta + (smo->M * smo->sample_time) * sat(i_err.alpha);
    float e_beta_hat_new = smo->e_hat.beta + smo->speed_obs * smo->sample_time * smo->e_hat.alpha + (smo->M * smo->sample_time) * sat(i_err.beta);

    smo->i_hat.alpha = i_alpha_hat_new;
    smo->i_hat.beta = i_beta_hat_new;
    smo->e_hat.alpha = e_alpha_hat_new;
    smo->e_hat.beta = e_beta_hat_new;

    // 3. 锁相环获取电角速度和电角度
    float e_hat;
    e_hat = sqrtf(smo->e_hat.alpha * smo->e_hat.alpha + smo->e_hat.beta * smo->e_hat.beta + 1e-6);
    float e_alpha = smo->e_hat.alpha / e_hat;
    float e_beta = smo->e_hat.beta / e_hat;
    float e_sig = e_alpha * cosf(smo->theta_obs) + e_beta * sinf(smo->theta_obs);
    // PLL Caculate
    smo->pll.ref = 0;
    smo->pll.fdb = e_sig;
    PID_Calc(&smo->pll, smo->enable, smo->sample_time);
    // Speed LPF
    smo->speed_lpf.input = smo->pll.output;
    LPF_Calc(&smo->speed_lpf, smo->enable);
    smo->speed_obs = smo->speed_lpf.output;
    // Theta
    smo->theta_obs += smo->pll.output * smo->sample_time;
    smo->theta_obs = normalize(1, smo->theta_obs, 0);

    // 不使能时采用有感运行数据
    if (smo->enable == 0)
    {
        smo->speed_obs = smo->speed_true;
    }
    if (smo->enable == 0)
    {
        smo->theta_obs = smo->theta_true;
    }
}

/**
 * @brief   滑模观测器初始化函数
 * @param   smo 滑模观测器句柄
 * @param   kp      PLL kp
 * @param   ki      PLL ki
 * @param   fc      Speed LPF fc
 */
void SMO_Init(SMO_TypeDef *smo, float K, float M, float pll_kp, float pll_ki, float fc, float sample_time)
{
    smo->K = K;
    smo->M = M;
    smo->sample_time = sample_time;

    PID_Init(&smo->pll, pll_kp, pll_ki, 0, INFINITY);

    LPF_Init(&smo->speed_lpf, fc, sample_time);

    smo->enable = 0;

    smo->i_hat.alpha = 0;
    smo->i_hat.beta = 0;
    smo->e_hat.alpha = 0;
    smo->e_hat.beta = 0;
}
