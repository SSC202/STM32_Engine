#include "encoder.h"
#include "foc_math.h"
#include "string.h"

/**
 * @brief   编码器初始化
 * @param   pole_pairs      电机极对数
 * @param   encoder         编码器结构体
 * @param   encoder_direct  编码器方向
 * @param   encoder_type    编码器类型
 * @param   offset          编码器机械偏移
 */
void Encoder_Init(Encoder_t *encoder, uint8_t pole_pairs, int encoder_direct, float offset)
{
    MT6701_Init();

    encoder->pole_pairs     = pole_pairs;
    encoder->encoder_direct = encoder_direct;
    encoder->encoder_offset = offset;
}

/**
 * @brief   编码器获取角度/速度
 * @param   encoder   编码器结构体
 */
void Encoder_Get_Angle_Speed(Encoder_t *encoder)
{
 
    float theta;

    MT6701_Get_Angle(&theta);
	
    encoder->curr_encoder_theta = theta;
    encoder->electric_theta     = normalize((encoder->pole_pairs * encoder->encoder_direct), encoder->curr_encoder_theta, encoder->encoder_offset);
    // 差分法计算速度 / 累积角度计算
    encoder->encoder_theta_diff = encoder->curr_encoder_theta - encoder->last_encoder_theta;
    if (encoder->encoder_theta_diff > M_PI) {
        encoder->encoder_theta_diff = encoder->encoder_theta_diff - 2 * M_PI;
    } else if (encoder->encoder_theta_diff < -M_PI) {
        encoder->encoder_theta_diff = encoder->encoder_theta_diff + 2 * M_PI;
    }
    float speed;
    speed                       = encoder->encoder_theta_diff * 10000.0f;
    encoder->last_encoder_theta = encoder->curr_encoder_theta;
    encoder->encoder_speed      = 0.4f * speed + 0.6f * encoder->encoder_speed; // 一阶低通滤波
}
