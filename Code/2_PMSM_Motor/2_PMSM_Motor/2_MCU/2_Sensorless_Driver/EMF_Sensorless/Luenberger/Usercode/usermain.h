#ifndef __USERMAIN_H
#define __USERMAIN_H

#include "adc.h"
#include "tim.h"
#include "usart.h"

#include "stm32g4xx.h"
#include "main.h"
#include "stdio.h"
#include "string.h"

#include "coordinate_transform.h"
#include "foc_math.h"
#include "svpwm.h"
#include "encoder.h"

#include "luenberger.h"

void usermain(void);

#endif
