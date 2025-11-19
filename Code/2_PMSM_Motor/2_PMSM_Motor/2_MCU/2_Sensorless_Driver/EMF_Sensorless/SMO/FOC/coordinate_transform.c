#include "coordinate_transform.h"

/**
 * @brief       ABC 轴系转换到 alpha_beta 轴系
 * @param[in]       abc             ABC坐标系物理量
 * @param[out]      alpha_beta      alpha-beta坐标系物理量
 */
void abc_2_alphabeta(abc_t *abc, alpha_beta_t *alpha_beta)
{
    alpha_beta->alpha = M_2_DIV3 * ((1.f) * abc->a - (0.5f) * abc->b - (0.5f) * abc->c);
    alpha_beta->beta  = M_2_DIV3 * ((0.f) * abc->a + (sqrtf(3.f) / 2.f) * abc->b - (sqrtf(3.f) / 2.f) * abc->c);
}

/**
 * @brief       ABC 轴系转换到 dq 轴系
 * @param[in]       abc             ABC坐标系物理量
 * @param[out]      dq              dq坐标系物理量
 * @param[in]       theta           电角度
 */
void abc_2_dq(abc_t *abc, dq_t *dq, float theta)
{
    dq->d = M_2_DIV3 * ((cosf(theta))*abc->a + (cosf(theta - 2.f * M_PI_3)) * abc->b + (cosf(theta + 2.f * M_PI_3)) * abc->c);
    dq->q = -M_2_DIV3 * ((sinf(theta))*abc->a + (sinf(theta - 2.f * M_PI_3)) * abc->b + (sinf(theta + 2.f * M_PI_3)) * abc->c);
}

/**
 * @brief       alpha_beta 轴系转换到 ABC 轴系
 * @param[in]       alpha_beta      alpha-beta坐标系物理量
 * @param[out]      abc             ABC坐标系物理量
 */
void alphabeta_2_abc(alpha_beta_t *alpha_beta, abc_t *abc)
{
    abc->a = ((1.f) * alpha_beta->alpha - (0.f) * alpha_beta->beta);
    abc->b = (-(0.5f) * alpha_beta->alpha + (M_SQRT3_2) * alpha_beta->beta);
    abc->c =  (-(0.5f) * alpha_beta->alpha - (M_SQRT3_2) * alpha_beta->beta);
}

/**
 * @brief       alpha_beta 轴系转换到 dq 轴系
 * @param[in]   alpha_beta          alpha-beta坐标系物理量
 * @param[out]  dq                  dq坐标系物理量
 * @param[in]   theta               电角度
 */
void alphabeta_2_dq(alpha_beta_t *alpha_beta, dq_t *dq, float theta)
{
    dq->d = (cosf(theta))*alpha_beta->alpha + (sinf(theta))*alpha_beta->beta;
    dq->q = -(sinf(theta))*alpha_beta->alpha + (cosf(theta))*alpha_beta->beta;
}

/**
 * @brief       dq 轴系转换到 abc 轴系
 * @param[in]   dq                  dq坐标系物理量
 * @param[out]  abc                 ABC坐标系物理量
 * @param[in]   theta               电角度
 */
void dq_2_abc(dq_t *dq, abc_t *abc, float theta)
{
    abc->a = cosf(theta) * dq->d - sinf(theta) * dq->q;
    abc->b = cosf(theta - 2.f * M_PI_3) * dq->d - sinf(theta - 2.f * M_PI_3) * dq->q;
    abc->c = cosf(theta + 2.f * M_PI_3) * dq->d - sinf(theta + 2.f * M_PI_3) * dq->q;
}

/**
 * @brief       dq 轴系转换到 alpha_beta 轴系
 * @param[in]   dq                  dq坐标系物理量
 * @param[out]  alpha_beta          alpha-beta坐标系物理量
 * @param[in]   theta               电角度
 */
void dq_2_alphabeta(dq_t *dq, alpha_beta_t *alpha_beta, float theta)
{
    alpha_beta->alpha = (cosf(theta))*dq->d - (sinf(theta))*dq->q;
    alpha_beta->beta  = (sinf(theta))*dq->d + (cosf(theta))*dq->q;
}