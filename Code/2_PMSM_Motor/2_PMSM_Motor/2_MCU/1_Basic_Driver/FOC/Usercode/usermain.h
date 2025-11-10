#ifndef __USERMAIN_H
#define __USERMAIN_H

#include "adc.h"
#include "tim.h"
#include "spi.h"
#include "usart.h"

#include "stm32f1xx.h"
#include "main.h"
#include "stdio.h"
#include "string.h"

#include "coordinate_transform.h"
#include "foc_math.h"
#include "svpwm.h"
#include "mt6701.h"

void usermain(void);

#endif
