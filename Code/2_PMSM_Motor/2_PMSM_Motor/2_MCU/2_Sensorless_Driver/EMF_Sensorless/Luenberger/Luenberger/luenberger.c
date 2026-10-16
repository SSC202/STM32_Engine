#include "luenberger.h"

/**
 * @brief   龙伯格观测器更新函数
 * @param   lun 龙伯格观测器句柄
 * @param   u   逆变器输出 alpha-beta 轴电压
 * @param   i   电流采样得到 alpha-beta 轴电流
 */
void Luenberger_Update(Luenberger_TypeDef *lun)
{
    // 1. 计算电流误差
    static alpha_beta_t i_err;
    if (lun->enable != 0)
    {
        i_err.alpha = lun->i_hat.alpha - lun->i.alpha;
        i_err.beta = lun->i_hat.beta - lun->i.beta;
    }
    else
    {
        i_err.alpha = 0;
        i_err.beta = 0;
    }

    // 2. 观测器更新
    static float coeff1;
    static float coeff2;
    static float i_alpha_hat_new;
    static float i_beta_hat_new;
    static float e_alpha_hat_new;
    static float e_beta_hat_new;

    coeff1 = 1.f - (Rs * lun->sample_time / Ls);
    coeff2 = lun->sample_time / Ls;

    if (lun->enable != 0)
    {
        i_alpha_hat_new = coeff1 * lun->i_hat.alpha - coeff2 * lun->e_hat.alpha + coeff2 * lun->u.alpha + (lun->L1 * lun->sample_time) * (i_err.alpha);
        i_beta_hat_new = coeff1 * lun->i_hat.beta - coeff2 * lun->e_hat.beta + coeff2 * lun->u.beta + (lun->L1 * lun->sample_time) * (i_err.beta);
        e_alpha_hat_new = lun->e_hat.alpha - lun->speed_obs * lun->sample_time * lun->e_hat.beta + (lun->L2 * lun->sample_time) * (i_err.alpha);
        e_beta_hat_new = lun->e_hat.beta + lun->speed_obs * lun->sample_time * lun->e_hat.alpha + (lun->L2 * lun->sample_time) * (i_err.beta);
    }
    else
    {
        i_alpha_hat_new = 0;
        i_beta_hat_new = 0;
        e_alpha_hat_new = 0;
        e_beta_hat_new = 0;
    }

    lun->i_hat.alpha = i_alpha_hat_new;
    lun->i_hat.beta = i_beta_hat_new;
    lun->e_hat.alpha = e_alpha_hat_new;
    lun->e_hat.beta = e_beta_hat_new;

    // 3. 锁相环获取电角速度和电角度
    static float e_hat;
    static float e_alpha;
    static float e_beta;
    static float e_sig;

    e_hat = sqrtf(lun->e_hat.alpha * lun->e_hat.alpha + lun->e_hat.beta * lun->e_hat.beta + 1e-6);

    e_alpha = lun->e_hat.alpha / e_hat;
    e_beta = lun->e_hat.beta / e_hat;

    e_sig = e_alpha * cosf(lun->theta_obs) + e_beta * sinf(lun->theta_obs);

    // PLL Caculate
    lun->pll.ref = 0;
    lun->pll.fdb = e_sig;
    PID_Calc(&lun->pll, lun->enable, lun->sample_time);
    // Speed LPF
    lun->speed_lpf.input = lun->pll.output;
    LPF_Calc(&lun->speed_lpf, lun->enable);
    lun->speed_obs = lun->speed_lpf.output;
    // Theta
    lun->theta_obs += lun->pll.output * lun->sample_time;
    lun->theta_obs = normalize(1, lun->theta_obs, 0);

    // 不使能时采用有感运行数据
    if (lun->enable == 0)
    {
        lun->speed_obs = lun->speed_true;
    }
    if (lun->enable == 0)
    {
        lun->theta_obs = lun->theta_true;
    }
}

/**
 * @brief   龙伯格观测器初始化函数
 * @param   lun 龙伯格观测器句柄
 * @param   kp      PLL kp
 * @param   ki      PLL ki
 * @param   fc      Speed LPF fc
 */
void Luenberger_Init(Luenberger_TypeDef *lun, float L1, float L2, float pll_kp, float pll_ki, float fc, float sample_time)
{
    lun->L1 = L1;
    lun->L2 = L2;
    lun->sample_time = sample_time;

    PID_Init(&lun->pll, pll_kp, pll_ki, 0, INFINITY);

    LPF_Init(&lun->speed_lpf, fc, sample_time);

    lun->enable = 0;

    lun->i_hat.alpha = 0;
    lun->i_hat.beta = 0;
    lun->e_hat.alpha = 0;
    lun->e_hat.beta = 0;
    lun->i.alpha = 0;
    lun->i.beta = 0;
    lun->u.alpha = 0;
    lun->u.beta = 0;
}
