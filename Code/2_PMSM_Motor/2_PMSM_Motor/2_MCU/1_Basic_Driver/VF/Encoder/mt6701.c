#include "mt6701.h"
#include "foc_math.h"

static uint8_t calculate_crc(uint32_t data)
{
    uint8_t crc = 0;
    uint32_t polynomial = 0x43; // (X^6 + X + 1)的二进制值

    // (D[13:0] 和 Mg[3:0])
    for (int i = 17; i >= 0; i--)
    {
        uint8_t bit = (data >> i) & 1;
        crc <<= 1;
        if ((crc >> 6) ^ bit)
            crc ^= polynomial;
        crc &= 0x3F;
    }
    return crc;
}

static void MT6701_Get_Angle(float *angle)
{
    uint8_t raw_data[3];
    int16_t encoder_angle;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); // 片选拉低
    HAL_SPI_TransmitReceive(&hspi1, raw_data, raw_data, 3, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); // 片选拉低
    uint8_t crc_raw = raw_data[2] & ((1 << 6) - 1);
    uint32_t crc_data = (raw_data[0] << 16 | raw_data[1] << 8 | raw_data[2]) >> 6;
    if (calculate_crc(crc_data) != crc_raw)
    {
        return;
    }
    encoder_angle = (raw_data[1] >> 2) | (raw_data[0] << 6);
    *angle = (float)(2 * M_PI * encoder_angle) / (1 << 14);
    return;
}

/**
 * @brief   编码器初始化
 * @param   pole_pairs      电机极对数
 * @param   encoder         编码器结构体
 * @param   encoder_direct  编码器方向
 * @param   offset          编码器机械偏移
 */
void Encoder_Init(Encoder_t *encoder, uint8_t pole_pairs, int encoder_direct, float offset)
{
    encoder->pole_pairs = pole_pairs;
    encoder->encoder_direct = encoder_direct;
    encoder->encoder_offset = offset;
    return;
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
    encoder->electric_theta = normalize((encoder->pole_pairs * encoder->encoder_direct), encoder->curr_encoder_theta, encoder->encoder_offset);
    // 差分法计算速度 / 累积角度计算
    encoder->encoder_theta_diff = encoder->curr_encoder_theta - encoder->last_encoder_theta;
    if (encoder->encoder_theta_diff > M_PI)
    {
        encoder->encoder_theta_diff = encoder->encoder_theta_diff - 2 * M_PI;
    }
    else if (encoder->encoder_theta_diff < -M_PI)
    {
        encoder->encoder_theta_diff = encoder->encoder_theta_diff + 2 * M_PI;
    }
    float speed;
    speed = encoder->encoder_theta_diff / (4e-4);
    encoder->last_encoder_theta = encoder->curr_encoder_theta;
    encoder->encoder_speed = 0.1f * speed + 0.9f * encoder->encoder_speed; // 一阶低通滤波
    return;
}