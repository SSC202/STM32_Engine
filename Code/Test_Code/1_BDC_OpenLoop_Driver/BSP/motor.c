#include "motor.h"

/******************编码器定义*******************/

typedef struct
{
    int encode_old;
    int encode_now;
    float speed;
} ENCODER;

Motor motor;
static ENCODER encoder;
static volatile int encode_count = 0;
/*******************宏定义段*******************/

#define ENABLE_MOTOR                                               \
    do {                                                           \
        HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_SET);   \
        HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_RESET); \
    } while (0)
#define DISABLE_MOTOR                                              \
    do {                                                           \
        HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_RESET); \
        HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_RESET); \
    } while (0)
#define Encoder_Timer_Channel_1 TIM_CHANNEL_1 // 编码器通道1
#define Encoder_Timer_Channel_2 TIM_CHANNEL_2 // 编码器通道2
/******************驱动函数段******************/

/**
 * @brief   电机启动函数
 */
static void Motor_Start(void)
{
    motor.state = Motor_RUN;
    ENABLE_MOTOR;
    HAL_TIM_PWM_Start(PWM_Timer_Handle, PWM_Timer_Channel);
}

/**
 * @brief   电机停止函数
 */
static void Motor_Stop(void)
{
    motor.state = Motor_STOP;
    DISABLE_MOTOR;
    HAL_TIM_PWM_Stop(PWM_Timer_Handle, PWM_Timer_Channel);
}

/**
 * @brief       电机旋转方向设置函数
 * @param       dir 电机旋转方向
 */
static void Motor_DIR_Set(uint8_t dir)
{
    HAL_TIM_PWM_Stop(PWM_Timer_Handle, PWM_Timer_Channel); /* 关闭主通道输出 */

    if (dir == 0) /* 正转 */
    {
        HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_RESET);
        HAL_TIM_PWM_Start(PWM_Timer_Handle, PWM_Timer_Channel); /* 开启通道输出 */
    } else if (dir == 0)                                        /* 反转 */
    {
        HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_SET);
        HAL_TIM_PWM_Start(PWM_Timer_Handle, PWM_Timer_Channel); /* 开启通道输出 */
    }
}

/**
 * @brief       电机PWM设置
 * @param       para:比较寄存器值
 * @retval      无
 */
static void uMotor_PWM_Set(uint16_t para)
{
    if (para < (__HAL_TIM_GetAutoreload(PWM_Timer_Handle) - 0x0F)) /* 限速 */
    {
        __HAL_TIM_SetCompare(PWM_Timer_Handle, PWM_Timer_Channel, para);
    }
}

/**
 * @brief       电机控制
 * @param       para pwm比较值 ,正数电机为正转，负数为反转
 * @retval      无
 */
static void Motor_PWM_Set(float para)
{
    int val = (int)para;

    if (val >= 0) {
        Motor_DIR_Set(0); /* 正转 */
        uMotor_PWM_Set(val);
    } else {
        Motor_DIR_Set(1); /* 反转 */
        uMotor_PWM_Set(-val);
    }
}

/**
 * @brief       获取编码器的值
 * @param       无
 * @retval      编码器值
 */
static int Motor_Get_Encoder(void)
{
    return (int32_t)__HAL_TIM_GET_COUNTER(Encoder_Timer_Handle) + encode_count * 65536; /* 当前计数值+之前累计编码器的值=总的编码器值 */
}

/**
 * @brief       电机速度计算函数
 * @param       ms：计算速度的间隔
 * @retval      无
 */
static void Motor_Speed_Cal(uint8_t ms)
{
    float speed;
    encoder.speed      = encoder.encode_now - encoder.encode_old;
    speed              = (float)(encoder.speed * ((1000 / ms) * 60.0) / REDUCTION_RATIO / ROTO_RATIO);
    encoder.encode_old = encoder.encode_now;
    motor.speed        = 0.52 * motor.speed + 0.48 * speed;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == Encoder_Timer) {
        if (__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim2)) {
            encode_count--;
        } else {
            encode_count++;
        }
    } else if (htim->Instance == Sample_Timer) {
        encoder.encode_now = Motor_Get_Encoder();
        Motor_Speed_Cal(5);
    }
}
/******************用户函数段******************/

/**
 * @brief   电机初始化函数
 */
void Motor_Init(void)
{
    // 编码器初始化
    HAL_TIM_Encoder_Start(Encoder_Timer_Handle, Encoder_Timer_Channel_1);
    HAL_TIM_Encoder_Start(Encoder_Timer_Handle, Encoder_Timer_Channel_2);
    __HAL_TIM_ENABLE_IT(Encoder_Timer_Handle, TIM_IT_UPDATE);
    __HAL_TIM_CLEAR_FLAG(Encoder_Timer_Handle, TIM_IT_UPDATE);
    // 采样定时器初始化
    HAL_TIM_Base_Start_IT(Sample_Timer_Handle);
    __HAL_TIM_CLEAR_IT(Sample_Timer_Handle, TIM_IT_UPDATE);
    // 电机初始化
    Motor_Stop();     /* 停止电机 */
    Motor_DIR_Set(0); /* 设置正转 */
    Motor_PWM_Set(0); /* 速度设置为0 */
    Motor_Start();    /* 开启电机 */
}

/**
 * @brief   开环速度控制函数
 * @param   speed:速度(rpm)
 */
void Motor_Speed_Set(float speed)
{
    if (speed > MAX_Speed) {
        speed = MAX_Speed;
    } else if (speed < -MAX_Speed) {
        speed = -MAX_Speed;
    }
    int32_t pwm = 0;
    if (motor.state == Motor_RUN) {
        pwm = (int32_t)(speed * (__HAL_TIM_GET_AUTORELOAD(PWM_Timer_Handle)) / MAX_Speed);
    }
    Motor_PWM_Set(pwm);
}
