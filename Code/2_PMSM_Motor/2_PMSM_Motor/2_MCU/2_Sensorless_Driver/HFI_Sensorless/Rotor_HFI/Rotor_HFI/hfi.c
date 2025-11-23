#include "hfi.h"

/**
 * @brief   生成高频注入电压
 */
void HFI_Inject(HFI_t *hfi)
{
    if (hfi->enable == 0)
    {
        hfi->step = 1;
        hfi->u_alpha_betah.alpha = 0;
        hfi->u_alpha_betah.beta = 0;
    }
    else
    {
        hfi->u_alpha_betah.alpha = hfi->u_h * cosf((hfi->step / 5.f) * 2 * M_PI);
        hfi->u_alpha_betah.beta = hfi->u_h * sinf((hfi->step / 5.f) * 2 * M_PI);
        hfi->step++;
        if (hfi->step == 5)
        {
            hfi->step = 0;
        }
    }
}

/**
 * @brief   高频注入信号解调
 */
static void HFI_demodulate(HFI_t *hfi)
{
    float epsilon = -hfi->i_alpha_betah_now.alpha * cosf(((hfi->step / 5.f) * 2 * M_PI) - 2 * hfi->theta_obs) + hfi->i_alpha_betah_now.beta * sinf(((hfi->step / 5.f) * 2 * M_PI) - 2 * hfi->theta_obs);

    hfi->isig_lpf.input = epsilon;
    LPF_Calc(&hfi->isig_lpf, 1);
    hfi->isig = hfi->isig_lpf.output;
}

/**
 * @brief   高频注入位置观测
 */
static void HFI_observe(HFI_t *hfi)
{
    if (hfi->enable == 0)
    {
        hfi->pll.ref = 0;
        hfi->pll.fdb = 0;
        hfi->pll.cur_error = 0;
        hfi->pll.output = 0;
        hfi->speed_lpf.input = 0;
        hfi->speed_lpf.output = 0;
        hfi->speed_lpf.output_last = 0;
    }

    // PLL Caculate
    hfi->pll.ref = hfi->isig;
    hfi->pll.fdb = 0;
    PID_Calc(&hfi->pll, hfi->enable, hfi->sample_time);

    // Speed LPF
    hfi->speed_lpf.input = hfi->pll.output;
    LPF_Calc(&hfi->speed_lpf, hfi->enable);
    hfi->speed_obs = hfi->speed_lpf.output;

    // Theta
    hfi->theta_obs += hfi->pll.output * hfi->sample_time;

    while (hfi->theta_obs < -M_PI)
    {
        hfi->theta_obs = hfi->theta_obs + 2 * M_PI;
    }
    while (hfi->theta_obs > M_PI)
    {
        hfi->theta_obs = hfi->theta_obs - 2 * M_PI;
    }

    // 不使能时采用有感运行数据
    if (hfi->enable == 0)
    {
        hfi->speed_obs = hfi->speed_true;
    }
    if (hfi->enable == 0)
    {
        hfi->theta_obs = hfi->theta_true;
    }
}

/**
 * @brief   高频注入一次计算
 */
void HFI_Calc(HFI_t *hfi)
{
    // 信号解调
    HFI_demodulate(hfi);
    // 位置观测
    HFI_observe(hfi);
}

/**
 * @brief   高频注入参数初始化
 * @param   hfi     高频注入结构体
 * @param   uh      高频注入电压幅值
 * @param   ts      高频注入单次计算时间
 * @param   kp      PLL kp
 * @param   ki      PLL ki
 * @param   fc      Speed LPF fc
 */
void HFI_Init(HFI_t *hfi, float uh, float ts, float kp, float ki, float fc)
{
    hfi->u_h = uh;
    hfi->sample_time = ts;

    PID_Init(&hfi->pll, kp, ki, 0, INFINITY);

    LPF_Init(&hfi->speed_lpf, fc, hfi->sample_time);

    LPF_Init(&hfi->isig_lpf, 2, hfi->sample_time);

    hfi->enable = 0;
    hfi->step = 0;
}