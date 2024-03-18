#ifndef __UNSAFEDELAY__
#define __UNSAFEDELAY__
#include <stdio.h>
#include <stm/milis.h>
#include <main.h>

#define TIMER2 2
#define TIMER3 3

#define TIMER2_IRQ 13
#define TIMER3_IRQ 15

extern void pointer_routine_timer_2(void);
extern void pointer_routine_timer_3(void);

void init_time();

void unsafe_delay(uint32_t mls);

void locked_timer_task(void(*pointer)(void), uint32_t delay, uint16_t limit);

void locked_timer_task_extended(void(*pointer_pre)(void), void(*pointer_timed)(void), void(*pointer_after)(void), uint32_t delay, uint16_t limit);

void attach_timer(uint8_t id, uint8_t prescaler, uint32_t period);

#endif