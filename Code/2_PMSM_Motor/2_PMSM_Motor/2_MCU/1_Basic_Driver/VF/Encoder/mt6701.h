#ifndef __MT6701_H
#define __MT6701_H

#include "stm32f1xx.h"
#include "spi.h"
#include "gpio.h"

typedef struct {
    float encoder_offset; // 编码器偏移量
    uint8_t pole_pairs;   // 电机极对数
    int encoder_direct;   // 编码器方向

    float curr_encoder_theta; // 电机当前机械角度
    float last_encoder_theta; // 电机前一机械角度
    float encoder_theta_diff; // 电机角度差值
    float electric_theta;     // 电机电角度
    float encoder_speed;      // 电机机械速度
} Encoder_t;

void Encoder_Get_Angle_Speed(Encoder_t *encoder);
void Encoder_Init(Encoder_t *encoder, uint8_t pole_pairs, int encoder_direct, float offset);

#endif