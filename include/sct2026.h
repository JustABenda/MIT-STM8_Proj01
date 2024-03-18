#ifndef __SCT2026__
#define __SCT2026__

#include "stm/stm8s.h"
#include "stm/milis.h"
#include "stm/uart1.h"
#include <stdio.h>

#define N_OE_PORT GPIOD
#define N_OE_PIN GPIO_PIN_0

#define N_LATCH_PORT GPIOC
#define N_LATCH_PIN GPIO_PIN_4

#define SDI_PORT GPIOC
#define SDI_PIN GPIO_PIN_6

#define CLK_PORT GPIOC
#define CLK_PIN GPIO_PIN_5

void sct_init(); //init all pins for the bug
void sct_sendBit(bool bit); //send single bit to shifting register
void sct_sendWord(uint16_t word); //send bit sequence
void sct_reset(); //reset the bug
#endif