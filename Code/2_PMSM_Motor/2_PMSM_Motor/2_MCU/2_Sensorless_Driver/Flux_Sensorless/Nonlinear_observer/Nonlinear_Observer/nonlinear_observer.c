#include "nonlinear_observer.h"

/**
 * @brief   非线性磁链观测器更新函数
 * @param   obs 非线性观测器句柄
 * @param   u   逆变器输出 alpha-beta 轴电压
 * @param   i   电流采样得到 alpha-beta 轴电流
 */
void Nonlinear_Observer_Update(Nonlinear_Observer_TypeDef *obs)
{
    // 1. 非线性磁链观测器
    float y1;
    float y2;

    y1 = -Rs * obs->i.alpha + obs->u.alpha;
    y2 = -Rs * obs->i.beta + obs->u.beta;

    float eta1;
    float eta2;

    eta1 = obs->x1 - Ls * obs->i.alpha;
    eta2 = obs->x2 - Ls * obs->i.beta;

    float eta;
    float eta_err;

    if (obs->enable != 0)
    {
        eta = eta1 * eta1 + eta2 * eta2;
        eta_err = Flux_f * Flux_f - eta;
    }
    else
    {
        eta_err = 0;
        eta = 0;
    }

    float x1_new;
    float x2_new;

    if (obs->enable != 0)
    {
        x1_new = obs->x1 + obs->sample_time * (y1 + 0.5f * obs->gamma * eta1 * eta_err);
        x2_new = obs->x2 + obs->sample_time * (y2 + 0.5f * obs->gamma * eta2 * eta_err);
    }
    else
    {
        x1_new = 0;
        x2_new = 0;
    }

    obs->x1 = x1_new;
    obs->x2 = x2_new;

    // 2. 锁相环获取电角速度和电角度
    float flux_sig;

    float flux_alpha = (obs->x1 - Ls * obs->i.alpha) / Flux_f;
    float flux_beta = (obs->x2 - Ls * obs->i.beta) / Flux_f;

    flux_sig = -flux_alpha * sinf(obs->theta_obs) + flux_beta * cosf(obs->theta_obs);

    // PLL Caculate
    obs->pll.ref = flux_sig;
    obs->pll.fdb = 0;
    PID_Calc(&obs->pll, obs->enable, obs->sample_time);
    // Speed LPF
    obs->speed_lpf.input = obs->pll.output;
    LPF_Calc(&obs->speed_lpf, obs->enable);
    obs->speed_obs = obs->speed_lpf.output;
    // Theta
    obs->theta_obs += obs->pll.output * obs->sample_time;
    obs->theta_obs = normalize(1, obs->theta_obs, 0);

    // 不使能时采用有感运行数据
    if (obs->enable == 0)
    {
        obs->speed_obs = obs->speed_true;
    }
    if (obs->enable == 0)
    {
        obs->theta_obs = obs->theta_true;
    }
}

/**
 * @brief   非线性磁链观测器初始化函数
 * @param   obs     非线性磁链观测器句柄
 * @param   kp      PLL kp
 * @param   ki      PLL ki
 * @param   fc      Speed LPF fc
 */
void Nonlinear_Observer_Init(Nonlinear_Observer_TypeDef *obs, float gamma, float flux, float pll_kp, float pll_ki, float fc, float sample_time)
{
    obs->gamma = gamma;
    obs->flux = flux;
    obs->sample_time = sample_time;

    PID_Init(&obs->pll, pll_kp, pll_ki, 0, INFINITY);

    LPF_Init(&obs->speed_lpf, fc, sample_time);

    obs->enable = 0;

    obs->x1 = 0;
    obs->x2 = 0;
    obs->i.alpha = 0;
    obs->i.beta = 0;
    obs->u.alpha = 0;
    obs->u.beta = 0;
}
