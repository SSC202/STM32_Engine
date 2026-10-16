/**
 * @file    SVPWM 相关代码
 * @note    本文件包含 SVPWM 的相关定义
 *          接口类型    duty_abc_t  ABC 三相占空比结构体,使用时在主程序内定义全局变量
 *          接口函数    e_svpwm()   简单 SVPWM (三次谐波注入法)
 */
#ifndef __SVPWM_H
#define __SVPWM_H

#include "coordinate_transform.h"
#include "foc_math.h"

typedef struct
{
    float dutya;
    float dutyb;
    float dutyc;
} duty_abc_t;

void e_svpwm(abc_t *u_ref, float u_dc, duty_abc_t *duty_abc);

#endif // !_SVPWM_H__
