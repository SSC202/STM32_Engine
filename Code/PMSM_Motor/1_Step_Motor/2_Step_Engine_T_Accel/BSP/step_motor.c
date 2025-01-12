#include "step_motor.h"
#include "math.h"

/********************* 宏定义段 *****************************/

#define MOTOR_ENA(x)           HAL_GPIO_WritePin(Motor_ENA_Port, Motor_ENA_Pin, x)
#define MOTOR_DIR(x)           HAL_GPIO_WritePin(Motor_DIR_Port, Motor_DIR_Pin, x)

#define PI                     3.1415926
#define MOTOR_STEP_ANGLE       1.8                                                   // 步进电机步距角，1.8°
#define MOTOR_MICRO_STEP_ANGLE ((float)(MOTOR_STEP_ANGLE * PI) / (360 * MICRO_STEP)) // 细分步距角，弧度
#define A_T_x10                ((float)(10 * MOTOR_MICRO_STEP_ANGLE * T1_FREQ))
#define T1_FREQ_148            ((float)((T1_FREQ * 0.676) / 10))
#define A_SQ                   ((float)(2 * 100000 * MOTOR_MICRO_STEP_ANGLE))
#define A_x200                 ((float)(200 * MOTOR_MICRO_STEP_ANGLE))

#define STOP                   0 // 停止状态
#define ACCEL                  1 // 加速状态
#define DECEL                  2 // 减速状态
#define RUN                    3 // 匀速状态

AccelData accel_param; // 系统加减速结构体

/******************* 驱动函数定义 ***************************/

/**
 * @brief 电机旋转方向设置
 * @param dir   方向，CW正转，CCW反转
 */
static void Motor_Dir_Set(dir_t dir)
{
    if (dir) {
        MOTOR_DIR(1);
    } else {
        MOTOR_DIR(0);
    }
}

/**
 * @brief   电机启动函数
 */
static void Motor_Start(void)
{
    MOTOR_ENA(0);
}

/**
 * @brief   电机停止函数
 */
static void Motor_Stop(void)
{
    MOTOR_ENA(1);
    HAL_TIM_OC_Stop_IT(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);
}

// 加速过程中最后一次脉冲周期
static uint16_t last_accel_delay = 0;
// 总移动步数计数器
static uint32_t step_count = 0;
static int32_t rest        = 0;

/**
 * @brief 定时器中断回调函数
 */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
    uint32_t tim_count = 0;
    uint32_t tmp       = 0;
    // 保存下一个脉冲周期
    uint16_t new_step_delay = 0;
    // 中断计数值
    static uint8_t i = 0;

    if (htim->Instance == Motor_PWM_Timer) {
        // 设置比较值
        tim_count = __HAL_TIM_GET_COUNTER(Motor_PWM_Timer_Handle);
        tmp       = tim_count + accel_param.step_delay / 2;
        __HAL_TIM_SET_COMPARE(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel, tmp);
        i++;
        if (i == 2) {
            i = 0; // 清零定时器中断次数计数值
            switch (accel_param.run_state) {
                case STOP:          /* 步进电机停止状态 */
                    step_count = 0; // 清零步数计数器
                    rest       = 0; // 清零余值
                    HAL_TIM_OC_Stop_IT(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);
                    break;
                case ACCEL: /* 步进电机加速状态 */
                    step_count++;
                    accel_param.accel_count++;

                    new_step_delay = accel_param.step_delay - (((2 * accel_param.step_delay) + rest) / (4 * accel_param.accel_count + 1)); // 计算新(下)一步脉冲周期(时间间隔)
                    rest           = ((2 * accel_param.step_delay) + rest) % (4 * accel_param.accel_count + 1);                            // 计算余数，下次计算补上余数，减少误差

                    // 检查是够应该开始减速
                    if (step_count >= accel_param.decel_start) {
                        accel_param.accel_count = accel_param.decel_val;
                        accel_param.run_state   = DECEL;
                    }
                    // 检查是否到达期望的最大速度
                    else if (new_step_delay <= accel_param.min_delay) {
                        last_accel_delay      = new_step_delay;
                        new_step_delay        = accel_param.min_delay;
                        rest                  = 0;
                        accel_param.run_state = RUN;
                    }
                    break;
                case RUN: /* 步进电机最大速度运行状态 */
                    step_count++;
                    new_step_delay = accel_param.min_delay;

                    // 检查是否需要开始减速
                    if (step_count >= accel_param.decel_start) {
                        accel_param.accel_count = accel_param.decel_val;
                        new_step_delay          = last_accel_delay; // 以最后一次加速的延时作为开始减速的延时
                        accel_param.run_state   = DECEL;
                    }
                    break;
                case DECEL: /* 步进电机减速状态 */
                    step_count++;
                    accel_param.accel_count++;
                    new_step_delay = accel_param.step_delay - (((2 * accel_param.step_delay) + rest) / (4 * accel_param.accel_count + 1)); // 计算新(下)一步脉冲周期(时间间隔)
                    rest           = ((2 * accel_param.step_delay) + rest) % (4 * accel_param.accel_count + 1);                            // 计算余数，下次计算补上余数，减少误差
                    // 检查是否为最后一步
                    if (accel_param.accel_count >= 0) {
                        accel_param.run_state = STOP;
                    }
                    break;
            }
            /* 求得下一次间隔时间 */
            accel_param.step_delay = new_step_delay;
        }
    }
}

/******************* 用户函数定义 ***************************/

/**
 * @brief 电机初始化
 */
void Motor_Init(void)
{
    Motor_Start();
}

/** @brief  以给定的步数移动步进电机
 *  @note   通过计算加速到最大速度，以给定的步数开始减速，如果加速度和减速度很小，步进电机会移动很慢，还没达到最大速度就要开始减速
 *  @param step   移动的步数 (正数为顺时针，负数为逆时针).
 *  @param accel  加速加速度（10倍）
 *  @param decel  减速加速度（10倍）
 *  @param speed  最大速度（10倍）
 */
void Motor_Move(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed)
{
    // 达到最大速度时的步数.
    unsigned int max_s_lim;
    // 必须开始减速的步数
    unsigned int accel_lim;

    /* 根据步数和正负判断 */
    if (step == 0) {
        return;
    } else if (step < 0) // 逆时针
    {
        accel_param.dir = CCW;
        step            = -step;
    } else // 顺时针
    {
        accel_param.dir = CW;
    }
    // 输出电机方向
    Motor_Dir_Set(accel_param.dir);

    // 如果只移动一步
    if (step == 1) {
        accel_param.accel_count = -1;    // 只移动一步
        accel_param.run_state   = DECEL; // 减速状态
        accel_param.step_delay  = 1000;  // 短延时
    }
    // 步数不为零才移动
    else if (step != 0) {
        accel_param.min_delay  = (int32_t)(A_T_x10 / speed);                         // 设置最大速度极限, 计算得到min_delay用于定时器的计数器的值。
        accel_param.step_delay = (int32_t)((T1_FREQ_148 * sqrt(A_SQ / accel)) / 10); // 第一个脉冲计算
        max_s_lim              = (uint32_t)(speed * speed / (A_x200 * accel / 10));  // 计算多少步之后达到最大速度的限制
        if (max_s_lim == 0) {
            max_s_lim = 1; // 如果达到最大速度小于0.5步，将四舍五入为0，但必须移动至少一步才能达到想要的速度
        }
        accel_lim = (uint32_t)(step * decel / (accel + decel)); // 计算多少步之后开始减速
        if (accel_lim == 0) {
            accel_lim = 1; // 加速至少1步才能才能开始减速.
        }
        // 计算第一次开始减速的位置
        if (accel_lim <= max_s_lim) {
            accel_param.decel_val = accel_lim - step;
        } else {
            accel_param.decel_val = -(max_s_lim * accel / decel);
        }
        // 只剩下一步必须减速
        if (accel_param.decel_val == 0) {
            accel_param.decel_val = -1;
        }
        accel_param.decel_start = step + accel_param.decel_val; // 计算开始减速时的步数
        if (accel_param.step_delay <= accel_param.min_delay) {
            accel_param.step_delay = accel_param.min_delay; // 如果最大速度很慢，不需要进行加速运动
            accel_param.run_state  = RUN;
        } else {
            accel_param.run_state = ACCEL;
        }
        // 复位加速度计数值
        accel_param.accel_count = 0;
    }
    /* 获取当前计数值 */
    int tim_count = __HAL_TIM_GET_COUNTER(Motor_PWM_Timer_Handle);
    /* 在当前计数值基础上设置定时器比较值 */
    __HAL_TIM_SET_COMPARE(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel, tim_count + accel_param.step_delay);
    /* 启动输出 */
    HAL_TIM_OC_Start_IT(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);
}