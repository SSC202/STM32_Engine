#include "my_math.h"

/**
 * @brief   机械角度转换为电角度
 * @param   polepairs       电机极对数(带方向,>0表示电角度正方向和编码器机械角度正方向相同)
 * @param   mechine_angle   电机机械角度(编码器返回角度)
 * @param   offset          电机电角度零点和电机机械角度零点之间的偏差
 *                          该偏差由下述方法整定:
 *                          设定一个ud值,uq设置为0,启动电机,电机将会旋转到电角度零点,此时读取编码器角度即为偏差
 * @return  电机的电角度,归一化为 -PI 到 PI 之间
 */
float normalize(int pole_pairs, float mechine_angle, float offset)
{
    float electric_angle = pole_pairs * mechine_angle - offset;
    float out            = electric_angle;
    while (out < -M_PI) {
        out = out + 2 * M_PI;
    }
    while (out > M_PI) {
        out = out - 2 * M_PI;
    }
    return out;
}

/**
 * @brief   取最大值函数
 */
float get_max(float a, float b, float c)
{
    float ret = 0;
    if (a >= b && a >= c)
        ret = a;
    else if (b >= a && b >= c)
        ret = b;
    else
        ret = c;
    return ret;
}

/**
 * @brief   取最小值函数
 */
float get_min(float a, float b, float c)
{
    float ret = 0;
    if (a <= b && a <= c)
        ret = a;
    else if (b <= a && b <= c)
        ret = b;
    else
        ret = c;
    return ret;
}

/**
 * @brief   取中间值函数
 */
float get_middle(float a, float b, float c)
{
    float ret = 0;
    ret       = a + b + c - get_max(a, b, c) - get_min(a, b, c);
    return ret;
}

/****************************** PID 控制器 ********************************* */

/**
 * @brief   增量式 PID 控制器初始化
 * @param   pid         PID 控制器句柄
 * @param   kp          Kp  比例参数
 * @param   ki          Ki  积分参数(考虑采样时间)
 * @param   kd          Kd  微分参数
 * @param   outputMax   输出饱和值
 */
void PID_init(PID_t *pid, float kp, float ki, float kd, float outputMax)
{
    pid->KP        = kp;
    pid->KI        = ki;
    pid->KD        = kd;
    pid->outputMax = outputMax;
}

/**
 * @brief   增量式PID计算
 * @param   pid         PID 控制器句柄
 * @param   enable      使能信号    若此值为0,PID控制器的输入,反馈和输出都置为0
 * @param   t_sample    采样时间
 */
void PID_Calc(PID_t *pid, uint8_t enable, float t_sample)
{
    pid->ref       = pid->ref * enable;
    pid->fdb       = pid->fdb * enable;
    pid->cur_error = pid->ref - pid->fdb;
    pid->output += pid->KP * (pid->cur_error - pid->error[1]) + pid->KI * t_sample * pid->cur_error + pid->KD * (pid->cur_error - 2 * pid->error[1] + pid->error[0]);
    pid->output   = pid->output * enable;
    pid->error[0] = pid->error[1];
    pid->error[1] = pid->ref - pid->fdb;
    /*设定输出上限*/
    if (pid->output > pid->outputMax) pid->output = pid->outputMax;
    if (pid->output < -pid->outputMax) pid->output = -pid->outputMax;
}

/****************************** IIR 滤波器 ********************************* */

/**
 * @brief   数字一阶低通滤波器初始化(后向差分法)
 * @param   lpf         滤波器句柄
 * @param   f_c         截止频率
 * @param   t_sample    采样时间
 */
void LPF_Init(LPF_t *lpf, float f_c, float t_sample)
{
    lpf->wc          = 2 * M_PI * f_c;
    lpf->tsample     = t_sample;
    lpf->alpha       = (lpf->wc * lpf->tsample) / (lpf->wc * lpf->tsample + 1.0f);
    lpf->output_last = 0;
    lpf->output  = 0;
    lpf->input       = 0;
}

/**
 * @brief   数字一阶低通滤波器计算(后向差分法)
 * @param   lpf         滤波器句柄
 */
void LPF_Calc(LPF_t *lpf)
{
    lpf->output  = lpf->output_last + lpf->alpha * (lpf->input - lpf->output_last);
    lpf->output_last = lpf->output;
}