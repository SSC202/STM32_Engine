#ifndef _DELAY_H
#define _DELAY_H

#include "stm32f1xx.h"

void delay_us(unsigned long nus);
void delay_ms(unsigned short nms);
void systick_CountMode(void);

#endif
