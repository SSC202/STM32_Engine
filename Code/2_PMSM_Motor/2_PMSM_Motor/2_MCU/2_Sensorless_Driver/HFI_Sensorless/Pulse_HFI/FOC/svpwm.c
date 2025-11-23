#include "svpwm.h"

/**
 * @brief       SVPWM 占空比生成函数
 * @attention   使用三次谐波注入法
 * @param       u_ref      参考电压
 * @param       u_dc       母线电压
 * @param       duty_abc   输出占空比
 */
void e_svpwm(abc_t *u_ref, float u_dc, duty_abc_t *duty_abc)
{
    float ua_ref_eq  = u_ref->a + 0.5f * get_middle(u_ref->a, u_ref->b, u_ref->c);
    duty_abc->dutya = 0.5f + ua_ref_eq / u_dc;
    float ub_ref_eq  = u_ref->b + 0.5f * get_middle(u_ref->a, u_ref->b, u_ref->c);
    duty_abc->dutyb = 0.5f + ub_ref_eq / u_dc;
    float uc_ref_eq  = u_ref->c + 0.5f * get_middle(u_ref->a, u_ref->b, u_ref->c);
    duty_abc->dutyc = 0.5f + uc_ref_eq / u_dc;
}