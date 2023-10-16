#include "motor.h"
#include <stdio.h>

static volatile int encode_count1 = 0;
static volatile int encode_count2 = 0;
static volatile int encode_count3 = 0;
static volatile int encode_count4 = 0;
/*******************宏定义段*******************/

#define ENABLE_MOTOR(x)                                                              \
    do {                                                                             \
        if (x == 1) {                                                                \
            HAL_GPIO_WritePin(Motor1_IN1_GPIO_Port, Motor1_IN1_Pin, GPIO_PIN_SET);   \
            HAL_GPIO_WritePin(Motor1_IN2_GPIO_Port, Motor1_IN2_Pin, GPIO_PIN_RESET); \
        }                                                                            \
        if (x == 2) {                                                                \
            HAL_GPIO_WritePin(Motor2_IN1_GPIO_Port, Motor2_IN1_Pin, GPIO_PIN_SET);   \
            HAL_GPIO_WritePin(Motor2_IN2_GPIO_Port, Motor2_IN2_Pin, GPIO_PIN_RESET); \
        }                                                                            \
        if (x == 3) {                                                                \
            HAL_GPIO_WritePin(Motor3_IN1_GPIO_Port, Motor3_IN1_Pin, GPIO_PIN_SET);   \
            HAL_GPIO_WritePin(Motor3_IN2_GPIO_Port, Motor3_IN2_Pin, GPIO_PIN_RESET); \
        }                                                                            \
        if (x == 4) {                                                                \
            HAL_GPIO_WritePin(Motor4_IN1_GPIO_Port, Motor4_IN1_Pin, GPIO_PIN_SET);   \
            HAL_GPIO_WritePin(Motor4_IN2_GPIO_Port, Motor4_IN2_Pin, GPIO_PIN_RESET); \
        }                                                                            \
    } while (0)

#define DISABLE_MOTOR(x)                                                             \
    do {                                                                             \
        if (x == 1) {                                                                \
            HAL_GPIO_WritePin(Motor1_IN1_GPIO_Port, Motor1_IN1_Pin, GPIO_PIN_RESET); \
            HAL_GPIO_WritePin(Motor1_IN2_GPIO_Port, Motor1_IN2_Pin, GPIO_PIN_RESET); \
        }                                                                            \
        if (x == 2) {                                                                \
            HAL_GPIO_WritePin(Motor2_IN1_GPIO_Port, Motor2_IN1_Pin, GPIO_PIN_RESET); \
            HAL_GPIO_WritePin(Motor2_IN2_GPIO_Port, Motor2_IN2_Pin, GPIO_PIN_RESET); \
        }                                                                            \
        if (x == 3) {                                                                \
            HAL_GPIO_WritePin(Motor3_IN1_GPIO_Port, Motor3_IN1_Pin, GPIO_PIN_RESET); \
            HAL_GPIO_WritePin(Motor3_IN2_GPIO_Port, Motor3_IN2_Pin, GPIO_PIN_RESET); \
        }                                                                            \
        if (x == 4) {                                                                \
            HAL_GPIO_WritePin(Motor4_IN1_GPIO_Port, Motor4_IN1_Pin, GPIO_PIN_RESET); \
            HAL_GPIO_WritePin(Motor4_IN2_GPIO_Port, Motor4_IN2_Pin, GPIO_PIN_RESET); \
        }                                                                            \
    } while (0)
#define Encoder_Timer_Channel_1 TIM_CHANNEL_1 // 编码器通道1
#define Encoder_Timer_Channel_2 TIM_CHANNEL_2 // 编码器通道2
/******************驱动函数段******************/

/**
 * @brief   电机启动函数
 */
static void uMotor_Start(Motor *umotor)
{
    umotor->state = Motor_RUN;
    ENABLE_MOTOR(umotor->id);
    switch (umotor->id) {
        case 1:
            HAL_TIM_PWM_Start(Motor1_PWM_Timer_Handle, Motor1_PWM_Timer_Channel);
            break;
        case 2:
            HAL_TIM_PWM_Start(Motor2_PWM_Timer_Handle, Motor2_PWM_Timer_Channel);
            break;
        case 3:
            HAL_TIM_PWM_Start(Motor3_PWM_Timer_Handle, Motor3_PWM_Timer_Channel);
            break;
        case 4:
            HAL_TIM_PWM_Start(Motor4_PWM_Timer_Handle, Motor4_PWM_Timer_Channel);
            break;
        default:
            break;
    }
}

/**
 * @brief   电机停止函数
 */
static void Motor_Stop(Motor *umotor)
{
    umotor->state = Motor_STOP;
    DISABLE_MOTOR(umotor->id);
    switch (umotor->id) {
        case 1:
            HAL_TIM_PWM_Stop(Motor1_PWM_Timer_Handle, Motor1_PWM_Timer_Channel);
            break;
        case 2:
            HAL_TIM_PWM_Stop(Motor2_PWM_Timer_Handle, Motor2_PWM_Timer_Channel);
            break;
        case 3:
            HAL_TIM_PWM_Stop(Motor3_PWM_Timer_Handle, Motor3_PWM_Timer_Channel);
            break;
        case 4:
            HAL_TIM_PWM_Stop(Motor4_PWM_Timer_Handle, Motor4_PWM_Timer_Channel);
            break;
        default:
            break;
    }
}

/**
 * @brief       电机旋转方向设置函数
 * @param       dir 电机旋转方向
 */
static void Motor_DIR_Set(Motor *umotor, uint8_t dir)
{
    // 关闭输出
    switch (umotor->id) {
        case 1:
            HAL_TIM_PWM_Stop(Motor1_PWM_Timer_Handle, Motor1_PWM_Timer_Channel);
            break;
        case 2:
            HAL_TIM_PWM_Stop(Motor2_PWM_Timer_Handle, Motor2_PWM_Timer_Channel);
            break;
        case 3:
            HAL_TIM_PWM_Stop(Motor3_PWM_Timer_Handle, Motor3_PWM_Timer_Channel);
            break;
        case 4:
            HAL_TIM_PWM_Stop(Motor4_PWM_Timer_Handle, Motor4_PWM_Timer_Channel);
            break;
        default:
            break;
    }

    // 设置方向
    switch (umotor->id) {
        case 1:
            if (dir == 0) /* 正转 */
            {
                HAL_GPIO_WritePin(Motor1_IN1_GPIO_Port, Motor1_IN1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Motor1_IN2_GPIO_Port, Motor1_IN2_Pin, GPIO_PIN_RESET);
                HAL_TIM_PWM_Start(Motor1_PWM_Timer_Handle, Motor1_PWM_Timer_Channel); /* 开启通道输出 */
            } else if (dir == 1) {
                HAL_GPIO_WritePin(Motor1_IN1_GPIO_Port, Motor1_IN1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Motor1_IN2_GPIO_Port, Motor1_IN2_Pin, GPIO_PIN_SET);
                HAL_TIM_PWM_Start(Motor1_PWM_Timer_Handle, Motor1_PWM_Timer_Channel); /* 开启通道输出 */
            }
            break;
        case 2:
            if (dir == 0) /* 正转 */
            {
                HAL_GPIO_WritePin(Motor2_IN1_GPIO_Port, Motor2_IN1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Motor2_IN2_GPIO_Port, Motor2_IN2_Pin, GPIO_PIN_RESET);
                HAL_TIM_PWM_Start(Motor2_PWM_Timer_Handle, Motor2_PWM_Timer_Channel); /* 开启通道输出 */
            } else if (dir == 1) {
                HAL_GPIO_WritePin(Motor2_IN1_GPIO_Port, Motor2_IN1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Motor2_IN2_GPIO_Port, Motor2_IN2_Pin, GPIO_PIN_SET);
                HAL_TIM_PWM_Start(Motor2_PWM_Timer_Handle, Motor2_PWM_Timer_Channel); /* 开启通道输出 */
            }
            break;
        case 3:
            if (dir == 0) /* 正转 */
            {
                HAL_GPIO_WritePin(Motor3_IN1_GPIO_Port, Motor3_IN1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Motor3_IN2_GPIO_Port, Motor3_IN2_Pin, GPIO_PIN_RESET);
                HAL_TIM_PWM_Start(Motor3_PWM_Timer_Handle, Motor3_PWM_Timer_Channel); /* 开启通道输出 */
            } else if (dir == 1) {
                HAL_GPIO_WritePin(Motor3_IN1_GPIO_Port, Motor3_IN1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Motor3_IN2_GPIO_Port, Motor3_IN2_Pin, GPIO_PIN_SET);
                HAL_TIM_PWM_Start(Motor3_PWM_Timer_Handle, Motor3_PWM_Timer_Channel); /* 开启通道输出 */
            }
            break;
        case 4:
            if (dir == 0) /* 正转 */
            {
                HAL_GPIO_WritePin(Motor4_IN1_GPIO_Port, Motor4_IN1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Motor4_IN2_GPIO_Port, Motor4_IN2_Pin, GPIO_PIN_RESET);
                HAL_TIM_PWM_Start(Motor4_PWM_Timer_Handle, Motor4_PWM_Timer_Channel); /* 开启通道输出 */
            } else if (dir == 1) {
                HAL_GPIO_WritePin(Motor4_IN1_GPIO_Port, Motor4_IN1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Motor4_IN2_GPIO_Port, Motor4_IN2_Pin, GPIO_PIN_SET);
                HAL_TIM_PWM_Start(Motor4_PWM_Timer_Handle, Motor4_PWM_Timer_Channel); /* 开启通道输出 */
            }
            break;
        default:
            break;
    }
}

/**
 * @brief       电机PWM设置
 * @param       para:比较寄存器值
 * @retval      无
 */
static void uMotor_PWM_Set(Motor *umotor, uint16_t para)
{
    switch (umotor->id) {
        case 1:
            __HAL_TIM_SET_COMPARE(Motor1_PWM_Timer_Handle, Motor1_PWM_Timer_Channel, para);
            break;
        case 2:
            __HAL_TIM_SET_COMPARE(Motor2_PWM_Timer_Handle, Motor2_PWM_Timer_Channel, para);
            break;
        case 3:
            __HAL_TIM_SET_COMPARE(Motor3_PWM_Timer_Handle, Motor3_PWM_Timer_Channel, para);
            break;
        case 4:
            __HAL_TIM_SET_COMPARE(Motor4_PWM_Timer_Handle, Motor4_PWM_Timer_Channel, para);
            break;
        default:
            break;
    }
}

/**
 * @brief       电机控制
 * @param       para pwm比较值 ,正数电机为正转，负数为反转
 * @retval      无
 */
static void Motor_PWM_Set(Motor *umotor, float para)
{
    int val = (int)para;

    if (val >= 0) {
        Motor_DIR_Set(umotor, 0); /* 正转 */
        uMotor_PWM_Set(umotor, val);
    } else {
        Motor_DIR_Set(umotor, 1); /* 反转 */
        uMotor_PWM_Set(umotor, -val);
    }
}

/**
 * @brief       获取编码器的值
 * @param       无
 * @retval      编码器值
 */
static int Motor_Get_Encoder(Motor *umotor)
{
    switch (umotor->id) {
        case 1:
            return (int32_t)__HAL_TIM_GET_COUNTER(Motor1_Encoder_Timer_Handle) + encode_count1 * 65536; /* 当前计数值+之前累计编码器的值=总的编码器值 */
            break;
        case 2:
            return (int32_t)__HAL_TIM_GET_COUNTER(Motor2_Encoder_Timer_Handle) + encode_count2 * 65536; /* 当前计数值+之前累计编码器的值=总的编码器值 */
            break;
        case 3:
            return (int32_t)__HAL_TIM_GET_COUNTER(Motor3_Encoder_Timer_Handle) + encode_count3 * 65536; /* 当前计数值+之前累计编码器的值=总的编码器值 */
            break;
        case 4:
            return (int32_t)__HAL_TIM_GET_COUNTER(Motor4_Encoder_Timer_Handle) + encode_count4 * 65536; /* 当前计数值+之前累计编码器的值=总的编码器值 */
            break;
        default:
            return 0;
            break;
    }
}

/**
 * @brief       电机速度计算函数
 * @param       ms：计算速度的间隔
 * @retval      无
 */
static void Motor_Speed_Cal(Motor *umotor, uint8_t ms)
{
    float speed;
    umotor->encoder.speed      = umotor->encoder.encode_now - umotor->encoder.encode_old;
    speed                      = (float)(umotor->encoder.speed * ((1000 / ms) * 60.0) / REDUCTION_RATIO / ROTO_RATIO);
    umotor->encoder.encode_old = umotor->encoder.encode_now;
    umotor->speed              = 0.52 * umotor->speed + 0.48 * speed;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == Motor1_Encoder_Timer) {
        if (__HAL_TIM_IS_TIM_COUNTING_DOWN(Motor1_Encoder_Timer_Handle)) {
            encode_count1--;
        } else {
            encode_count1++;
        }
    }
    if (htim->Instance == Motor2_Encoder_Timer) {
        if (__HAL_TIM_IS_TIM_COUNTING_DOWN(Motor2_Encoder_Timer_Handle)) {
            encode_count2--;
        } else {
            encode_count2++;
        }
    }
    if (htim->Instance == Motor3_Encoder_Timer) {
        if (__HAL_TIM_IS_TIM_COUNTING_DOWN(Motor3_Encoder_Timer_Handle)) {
            encode_count3--;
        } else {
            encode_count3++;
        }
    }
    if (htim->Instance == Motor4_Encoder_Timer) {
        if (__HAL_TIM_IS_TIM_COUNTING_DOWN(Motor4_Encoder_Timer_Handle)) {
            encode_count4--;
        } else {
            encode_count4++;
        }
    } else if (htim->Instance == Sample_Timer) {
        // 采样过程
        motor1.encoder.encode_now = Motor_Get_Encoder(&motor1);
        Motor_Speed_Cal(&motor1, 5);
        motor2.encoder.encode_now = Motor_Get_Encoder(&motor2);
        Motor_Speed_Cal(&motor2, 5);
        motor3.encoder.encode_now = Motor_Get_Encoder(&motor3);
        Motor_Speed_Cal(&motor3, 5);
        motor4.encoder.encode_now = Motor_Get_Encoder(&motor4);
        Motor_Speed_Cal(&motor4, 5);
        // PID 速度调制
        motor1.pwm = PID_Cal(&(motor1.pid), motor1.speed);
        motor2.pwm = PID_Cal(&(motor2.pid), motor2.speed);
        motor3.pwm = PID_Cal(&(motor3.pid), motor3.speed);
        motor4.pwm = PID_Cal(&(motor4.pid), motor4.speed);
        if (motor1.pwm >= 47999) {
            motor1.pwm = 47999;
        } else if (motor1.pwm <= -47999) {
            motor1.pwm = -47999;
        }
        if (motor2.pwm >= 47999) {
            motor2.pwm = 47999;
        } else if (motor2.pwm <= -47999) {
            motor2.pwm = -47999;
        }
        if (motor3.pwm >= 47999) {
            motor3.pwm = 47999;
        } else if (motor3.pwm <= -47999) {
            motor3.pwm = -47999;
        }
        if (motor4.pwm >= 47999) {
            motor4.pwm = 47999;
        } else if (motor4.pwm <= -47999) {
            motor4.pwm = -47999;
        }
        Motor_PWM_Set(&motor1, motor1.pwm);
        Motor_PWM_Set(&motor2, motor2.pwm);
        Motor_PWM_Set(&motor3, motor3.pwm);
        Motor_PWM_Set(&motor4, motor4.pwm);
    }
}
/******************用户函数段******************/
Motor motor1;
Motor motor2;
Motor motor3;
Motor motor4;

/**
 * @brief   电机初始化函数
 * @param   umotor  电机结构体
 * @param   ID  电机ID
 * @param   KP  比例常数
 * @param   KI  积分常数
 * @param   KD  微分常数
 */
void Motor_Init(Motor *umotor, uint8_t ID, float KP, float KI, float KD)
{
    // 电机属性初始化
    umotor->id                 = ID;
    umotor->encoder.encode_now = 0;
    umotor->encoder.encode_old = 0;
    umotor->encoder.speed      = 0;
    PID_Init(&(umotor->pid), KP, KI, KD);
    // 编码器初始化
    switch (ID) {
        case 1:
            HAL_TIM_Encoder_Start(Motor1_Encoder_Timer_Handle, Encoder_Timer_Channel_1);
            HAL_TIM_Encoder_Start(Motor1_Encoder_Timer_Handle, Encoder_Timer_Channel_2);
            __HAL_TIM_ENABLE_IT(Motor1_Encoder_Timer_Handle, TIM_IT_UPDATE);
            __HAL_TIM_CLEAR_FLAG(Motor1_Encoder_Timer_Handle, TIM_IT_UPDATE);
            break;
        case 2:
            HAL_TIM_Encoder_Start(Motor2_Encoder_Timer_Handle, Encoder_Timer_Channel_1);
            HAL_TIM_Encoder_Start(Motor2_Encoder_Timer_Handle, Encoder_Timer_Channel_2);
            __HAL_TIM_ENABLE_IT(Motor2_Encoder_Timer_Handle, TIM_IT_UPDATE);
            __HAL_TIM_CLEAR_FLAG(Motor2_Encoder_Timer_Handle, TIM_IT_UPDATE);
            break;
        case 3:
            HAL_TIM_Encoder_Start(Motor3_Encoder_Timer_Handle, Encoder_Timer_Channel_1);
            HAL_TIM_Encoder_Start(Motor3_Encoder_Timer_Handle, Encoder_Timer_Channel_2);
            __HAL_TIM_ENABLE_IT(Motor3_Encoder_Timer_Handle, TIM_IT_UPDATE);
            __HAL_TIM_CLEAR_FLAG(Motor3_Encoder_Timer_Handle, TIM_IT_UPDATE);
            break;
        case 4:
            HAL_TIM_Encoder_Start(Motor4_Encoder_Timer_Handle, Encoder_Timer_Channel_1);
            HAL_TIM_Encoder_Start(Motor4_Encoder_Timer_Handle, Encoder_Timer_Channel_2);
            __HAL_TIM_ENABLE_IT(Motor4_Encoder_Timer_Handle, TIM_IT_UPDATE);
            __HAL_TIM_CLEAR_FLAG(Motor4_Encoder_Timer_Handle, TIM_IT_UPDATE);
            break;
        default:
            break;
    }

    // 采样定时器初始化
    HAL_TIM_Base_Start_IT(Sample_Timer_Handle);
    __HAL_TIM_CLEAR_IT(Sample_Timer_Handle, TIM_IT_UPDATE);
    // 电机初始化
    Motor_Stop(umotor);       /* 停止电机 */
    Motor_DIR_Set(umotor, 0); /* 设置正转 */
    Motor_PWM_Set(umotor, 0); /* 速度设置为0 */
    // uMotor_Start(umotor);      /* 开启电机 */
}

/**
 * @brief   速度控制函数
 * @param   speed:速度(rpm)
 */
void Motor_Speed_Set(Motor *umotor, float speed)
{
    umotor->pid.SetPoint = speed;
}

/**
 * @brief   电机开启函数
 */
void Motor_Start(Motor *umotor)
{
    uMotor_Start(umotor);
}