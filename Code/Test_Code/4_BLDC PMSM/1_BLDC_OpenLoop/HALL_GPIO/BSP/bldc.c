#include "bldc.h"

BLDC_Motor motor;

/***************************宏定义段*******************************/
#define MAX_PWM_DUTY (((50000) - 1) * 0.96) /* 最大占空比限制 */

/****************************驱动函数段******************************/

/**
 * @brief  U相上桥臂导通，V相下桥臂导通
 * @param  无
 * @retval 无
 */
static void UH_VL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, motor.pwm_duty); /* U相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET); /* U相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_SET);   /* V相下桥臂导通 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET); /* W相下桥臂关闭 */
}

/**
 * @brief  U相上桥臂导通，W相下桥臂导通
 * @param  无
 * @retval 无
 */
static void UH_WL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, motor.pwm_duty); /* U相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET); /* U相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET); /* V相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_SET);   /* W相下桥臂导通 */
}

/**
 * @brief  V相上桥臂导通，W相下桥臂导通
 * @param  无
 * @retval 无
 */
static void VH_WL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, motor.pwm_duty); /* V相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET); /* U相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET); /* V相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_SET);   /* W相下桥臂导通 */
}

/**
 * @brief  V相上桥臂导通，U相下桥臂导通
 * @param  无
 * @retval 无
 */
static void VH_UL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, motor.pwm_duty); /* V相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_SET);   /* U相下桥臂导通 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET); /* V相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET); /* W相下桥臂关闭 */
}

/**
 * @brief  W相上桥臂导通，U相下桥臂导通
 * @param  无
 * @retval 无
 */
static void WH_UL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, motor.pwm_duty); /* W相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_SET);   /* U相下桥臂导通 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET); /* V相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET); /* W相下桥臂关闭 */
}

/**
 * @brief  W相上桥臂导通，V相下桥臂导通
 * @param  无
 * @retval 无
 */
static void WH_VL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, motor.pwm_duty); /* W相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET); /* U相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_SET);   /* V相下桥臂导通 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET); /* W相下桥臂关闭 */
}

/**
 * @brief       获取霍尔传感器引脚状态
 * @retval      霍尔传感器引脚状态
 */
static uint32_t HALL_Get_State(void)
{
    __IO static uint32_t state;
    state = 0;

    if (HAL_GPIO_ReadPin(HALL_A_GPIO_Port, HALL_A_GPIO_Pin) != GPIO_PIN_RESET) /* 霍尔传感器状态获取 */
    {
        state |= 0x01U;
    }
    if (HAL_GPIO_ReadPin(HALL_B_GPIO_Port, HALL_B_GPIO_Pin) != GPIO_PIN_RESET) /* 霍尔传感器状态获取 */
    {
        state |= 0x02U;
    }
    if (HAL_GPIO_ReadPin(HALL_C_GPIO_Port, HALL_C_GPIO_Pin) != GPIO_PIN_RESET) /* 霍尔传感器状态获取 */
    {
        state |= 0x04U;
    }

    return state;
}

typedef void (*pctr)(void);
/*  六步换向函数指针数组 */
pctr pfunclist[6] =
    {
        &UH_WL, &VH_UL, &VH_WL,
        &WH_VL, &UH_VL, &WH_UL};

/**
 * @brief       定时器中断回调
 * @param       htim:定时器句柄
 * @retval      无
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == SAMPLE_TIMER) {
        if (motor.run_flag == RUN) {
            if (motor.dir == CW) /* 正转 */
            {
                motor.step_sta = HALL_Get_State(); /* 顺序6,2,3,1,5,4 */
            } else                                 /* 反转 */
            {
                motor.step_sta = 7 - HALL_Get_State(); /* 顺序5,1,3,2,6,4 。使用7减完后可与数组pfunclist_m1对应上顺序 实际霍尔值为：2,6,4,5,1,3*/
            }

            if ((motor.step_sta <= 6) && (motor.step_sta >= 1)) /* 判断霍尔组合值是否正常 */
            {
                pfunclist[motor.step_sta - 1](); /* 通过数组成员查找对应的函数指针 */

            } else /* 霍尔传感器错误、接触不良、断开等情况 */
            {
                BLDC_Motor_Stop();
                motor.run_flag = STOP;
            }
        }
    }
}
/****************************用户函数段******************************/
/**
 * @brief  关闭电机运转
 * @param  无
 * @retval 无
 */
void BLDC_Motor_Stop(void)
{
    /* 关闭PWM输出 */
    HAL_TIM_PWM_Stop(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL);
    HAL_TIM_PWM_Stop(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL);
    HAL_TIM_PWM_Stop(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL);
    /* 上下桥臂全部关断 */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET);
}

/**
 * @brief  开启电机运转
 * @param  无
 * @retval 无
 */
void BLDC_Motor_Start(void)
{
    /* 使能PWM输出 */
    HAL_TIM_PWM_Start(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL);
    HAL_TIM_PWM_Start(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL);
    HAL_TIM_PWM_Start(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL);
}

/**
 * @brief       电机控制函数
 * @param       dir     电机方向
 * @param       Duty    PWM占空比
 * @retval      无
 */
void BLDC_Motor_Control(int32_t dir, float duty)
{

    motor.dir      = dir;  /* 方向 */
    motor.pwm_duty = duty; /* 占空比 */
}

/**
 * @brief       无刷电机初始化
 * @retval      无
 */
void BLDC_Motor_Init(void)
{
    HAL_TIM_Base_Start_IT(SAMPLE_TIMER_HANDLE);
}
