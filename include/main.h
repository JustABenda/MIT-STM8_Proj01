#ifndef _MAIN_H_
#define _MAIN_H_ 1

#include "stm/stm8s.h"
#include "stm/milis.h"
#include "stm/uart1.h"
#include "stm/stm8s_i2c.h"
#include <stdio.h>

#include <controls.h>



#define N_OE_PORT GPIOD
#define N_OE_PIN GPIO_PIN_0

#define N_LATCH_PORT GPIOC
#define N_LATCH_PIN GPIO_PIN_4

#define SDI_PORT GPIOC
#define SDI_PIN GPIO_PIN_6

#define CLK_PORT GPIOC
#define CLK_PIN GPIO_PIN_5


#ifdef STM8S003
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#define BTN_PORT GPIOB
#define BTN_PIN  GPIO_PIN_7
#endif

#ifdef STM8S103
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_4
#endif

#ifdef STM8S105
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#endif

#ifdef STM8S208
#define LED_PORT GPIOC
#define LED_PIN  GPIO_PIN_5
#define BTN_PORT GPIOE
#define BTN_PIN  GPIO_PIN_4
#endif

// functions
int main(void);
void main_task(void);
void setup(void);
void rx_action(void);
void pointer_routine_timer_2(void);
void pointer_routine_timer_3(void);
/*-------------------------------  Assert -----------------------------------*/
#include "stm/__assert__.h"

#endif // !_MAIN_H_
