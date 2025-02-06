#include "step_motor.h"
#include "math.h"
#include <string.h>

/********************* 宏定义段 *****************************/

#define MOTOR_ENA(x)           HAL_GPIO_WritePin(Motor_ENA_Port, Motor_ENA_Pin, x)
#define MOTOR_DIR(x)           HAL_GPIO_WritePin(Motor_DIR_Port, Motor_DIR_Pin, x)

#define PI                     3.1415926
#define MOTOR_STEP_ANGLE       1.8                                                   // 步进电机步距角，1.8°
#define MOTOR_MICRO_STEP_ANGLE ((float)(MOTOR_STEP_ANGLE * PI) / (360 * MICRO_STEP)) // 细分步距角，弧度

#if (T_Accel == 1)

#define A_T_x10     ((float)(10 * MOTOR_MICRO_STEP_ANGLE * T1_FREQ))
#define T1_FREQ_148 ((float)((T1_FREQ * 0.676) / 10))
#define A_SQ        ((float)(2 * 100000 * MOTOR_MICRO_STEP_ANGLE))
#define A_x200      ((float)(200 * MOTOR_MICRO_STEP_ANGLE))

#endif
#if (S_Accel == 1)

#define MIN_SPEED     ((float)(T1_FREQ / 65535U))          // 最低频率
#define FSPR          ((float)(360.0f / MOTOR_STEP_ANGLE)) // 步进电机的一圈所需脉冲数
#define SPR           ((float)(FSPR * MICRO_STEP))         // 细分后一圈所需脉冲数
#define CONVER(speed) ((float)(speed * SPR / 60.0f))       // 根据电机转速（r/min），计算电机步速（step/s）
#define FORM_LEN      4000
float Form[FORM_LEN]; /* S加减速 速度表 */

#endif

#define STOP  0 // 停止状态
#define ACCEL 1 // 加速状态
#define DECEL 2 // 减速状态
#define RUN   3 // 匀速状态

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

#if (T_Accel == 1)
// 加速过程中最后一次脉冲周期
static uint16_t last_accel_delay = 0;
// 总移动步数计数器
static uint32_t step_count = 0;
static int32_t rest        = 0;
#endif

#if (S_Accel == 1)

static __IO uint8_t i      = 0;
static __IO uint32_t index = 0;

/**
 * @brief  S曲线速度表计算
 * @param  pScurve S曲线结构体指针
 * @param  Vo      初速度
 * @param  Vt      末速度
 * @param  T       加速时间
 * @retval 0：正常，1：参数错误
 */
static uint8_t Calc_param(int32_t Vo, int32_t Vt, float T)
{
    int32_t i    = 0;
    float Vm     = 0.0f; // 中间点速度
    float K      = 0.0f; // 加加速度
    float Ti     = 0.0f; // 时间间隔 dt
    float Sumt   = 0.0f; // 时间累加量
    float DeltaV = 0.0f; // 速度的增量dv
    float temp   = 0.0f; // 中间变量

    /* 计算初、末速度 */
    accel_param.Vo = CONVER(Vo);
    accel_param.Vt = CONVER(Vt);

    /* 计算初始参数 */
    T = T / 2.0f; // 加加速段的时间（加速度斜率>0的时间）

    Vm = (accel_param.Vo + accel_param.Vt) / 2.0f; // 计算中点的速度

    K = fabsf((2.0f * (Vm - accel_param.Vo)) / (T * T)); // 根据中点速度计算加加速度

    accel_param.INC_AccelTotalStep = (int32_t)((accel_param.Vo * T) + ((K * T * T * T) / 6.0f)); // 加加速需要的步数

    accel_param.Dec_AccelTotalStep = (int32_t)(((accel_param.Vt + accel_param.Vo) * T - accel_param.INC_AccelTotalStep)); // 减加速需要的步数 S = Vt * Time - S1

    /* 计算共需要的步数，并校检内存大小，申请内存空间存放速度表 */
    accel_param.AccelTotalStep = accel_param.Dec_AccelTotalStep + accel_param.INC_AccelTotalStep; // 加速需要的步数
    if (accel_param.AccelTotalStep % 2 != 0)                                                      // 由于浮点型数据转换成整形数据带来了误差,所以这里加1
        accel_param.AccelTotalStep += 1;

    /* 判断内存长度 */
    if (FORM_LEN < accel_param.AccelTotalStep) {
        return 1;
    }

    /* 根据第一步的时间计算，第一步的速度和脉冲时间间隔 */
    Ti = pow(6.0f * 1.0f / K, 1.0f / 3.0f); // 开方求解 Ti 时间常数
    Sumt += Ti;                             // 累计时间常数
    /* 计算第一步的速度 */
    DeltaV = 0.5f * K * Sumt * Sumt;
    /* 在初始速度的基础上增加速度 */
    Form[0] = accel_param.Vo + DeltaV;

    /***************************************************************************/
    /* 最小速度限幅 */
    if (Form[0] <= MIN_SPEED) // 以当前定时器频率所能达到的最低速度
        Form[0] = MIN_SPEED;

    /***************************************************************************/
    /* 计算S形速度表 */
    for (i = 1; i < accel_param.AccelTotalStep; i++) {
        /* 根据时间周期与频率成反比的关系，可以计算出Ti,在这里每次计算上一步时间，用于积累到当前时间 */
        Ti = 1.0f / Form[i - 1];
        if (i < accel_param.INC_AccelTotalStep) {
            /* 累积时间 */
            Sumt += Ti;
            /* 速度的变化量 dV = 1/2 * K * Ti^2 */
            DeltaV = 0.5f * K * Sumt * Sumt;
            /* 根据初始速度和变化量求得速度表 */
            Form[i] = accel_param.Vo + DeltaV;
            /* 为了保证在最后一步可以使得时间严谨的与预期计算的时间一致，在最后一步进行处理 */
            if (i == accel_param.INC_AccelTotalStep - 1) { Sumt = fabsf(Sumt - T); }
        }
        /* 减加速度计算 */
        else {
            /* 时间累积 */
            Sumt += Ti;
            /* 计算速度 */
            temp    = fabsf(T - Sumt);
            DeltaV  = 0.5f * K * temp * temp;
            Form[i] = accel_param.Vt - DeltaV;
        }
    }
    return 0;
}
#endif
/**
 * @brief 定时器中断回调函数
 */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
#if (T_Accel == 1)
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

#endif
#if (S_Accel == 1)
    if (htim->Instance == Motor_PWM_Timer) {
        i++;
        if (i == 2) {
            /* 脉冲周期完整后清零 */
            i = 0;
            /* 判断当前的状态 */
            switch (accel_param.status) {
                case ACCEL:
                    if (accel_param.pos >= (accel_param.AccelTotalStep - 1)) {
                        accel_param.status = RUN;
                        index -= 1;
                        break;
                    }
                    /* 获取每一步的定时器计数值 */
                    accel_param.pluse_time = (uint16_t)(T1_FREQ / Form[index] / 2U);
                    /* 步数位置索引递增 */
                    index++;
                    break;
                case DECEL:
                    if (accel_param.pos >= (accel_param.TotalStep - 1)) {
                        /* 进入停止状态，清空速度表并且关闭输出通道 */
                        HAL_TIM_OC_Stop_IT(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);
                        memset((void *)Form, 0, sizeof(float) * FORM_LEN);
                        index              = 0;
                        accel_param.status = STOP;
                        break;
                    }
                    /* 获取每一步的定时器计数值 */
                    accel_param.pluse_time = (uint16_t)(T1_FREQ / Form[index] / 2U);
                    /* 步数位置索引递增 */
                    index--;
                    break;
                case RUN:
                    if (accel_param.pos >= accel_param.DecPoint) {
                        accel_param.status = DECEL;
                    }
                    break;
            }
            /* 步数位置索引递增 */
            accel_param.pos++;
        }
        /**********************************************************************/
        /* 获取当前计数器数值 */
        uint32_t tim_count = __HAL_TIM_GET_COUNTER(Motor_PWM_Timer_Handle);
        /* 计算下一次时间 */
        uint16_t tmp = tim_count + accel_param.pluse_time;
        /* 设置比较值 */
        __HAL_TIM_SET_COMPARE(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel, tmp);
    }

#endif
}

/******************* 用户函数定义 ***************************/

/**
 * @brief 电机初始化
 */
void Motor_Init(void)
{
    Motor_Start();
}

#if (T_Accel == 1)
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
#endif
#if (S_Accel == 1)

/**
 * @brief  步进电机S型加减速
 * @param  start_speed  启动速度
 * @param  end_speed    目标速度
 * @param  acc_time     加速时间
 * @param  step         运动步数（需考虑细分）
 * @retval 0：正常
 * @retval 1：参数设置错误或速度表空间不足
 */
uint8_t Motor_Move(int16_t start_speed, int16_t end_speed, float acc_time, int32_t step)
{
    /* 判断是否正在运动 */
    if (accel_param.status != STOP)
        return 1;

    /* 计算参数 */
    if (Calc_param(start_speed, end_speed, acc_time) != 0)
        return 1;

    if (step < 0) {
        step = -step;
        Motor_Dir_Set(CCW);
    } else {
        Motor_Dir_Set(CW);
    }

    /* 计算减速点，当运动步数小于两倍加速段时无法完成s加减速 */
    if (step >= accel_param.AccelTotalStep * 2) {
        accel_param.TotalStep = step;
        accel_param.DecPoint  = accel_param.TotalStep - accel_param.AccelTotalStep;
    } else {
        return 1;
    }

    /* 初始化电机状态 */
    accel_param.status = ACCEL;
    accel_param.pos    = 0;
    accel_param.dir    = 0;

    /* 计算第一步的定时器参数 */
    accel_param.pluse_time = (uint16_t)(T1_FREQ / Form[0] / 2U);

    /* 清零计数器 */
    __HAL_TIM_SET_COUNTER(Motor_PWM_Timer_Handle, 0);
    __HAL_TIM_SET_COMPARE(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel, accel_param.pluse_time);
    /* 开启输出比较中断 */
    HAL_TIM_OC_Start_IT(Motor_PWM_Timer_Handle, Motor_PWM_Timer_Channel);

    return 0;
}
#endif