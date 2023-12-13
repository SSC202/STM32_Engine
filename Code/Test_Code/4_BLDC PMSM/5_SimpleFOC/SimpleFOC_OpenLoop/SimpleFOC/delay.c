#include "delay.h"

void delay_us(unsigned long nus)
{
    unsigned long temp;

    SysTick->LOAD = nus * 9;
    SysTick->VAL  = 0;
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
    do {
        temp = SysTick->CTRL;
    } while ((temp & 0x01) && !(temp & (1 << 16)));

    SysTick->CTRL = 0;
    SysTick->VAL  = 0;
}

void delay_ms(unsigned short nms)
{
    unsigned long temp;

    SysTick->LOAD = (uint32_t)nms * 9000;
    SysTick->VAL  = 0;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    do {
        temp = SysTick->CTRL;
    } while ((temp & 0x01) && !(temp & (1 << 16)));

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    SysTick->VAL = 0;
}

void systick_CountMode(void)
{
    SysTick->LOAD = 0xFFFFFF - 1; // set reload register
    SysTick->VAL  = 0;
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk; // Enable SysTick Timer
}
