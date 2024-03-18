#ifndef __CONTROLS__
#define __CONTROLS__

#include "stm/stm8s.h"
#include "stm/milis.h"
#include "stm/uart1.h"
#include <stdio.h>

#define INPUT_PORT GPIOB
#define UP_BTN GPIO_PIN_2
#define DOWN_BTN GPIO_PIN_4
#define SELECT_BTN GPIO_PIN_3

typedef struct Controls
{
    int old_up;
    int old_down;
    int old_select;
} Controls;
int isUp(struct Controls* pointer);
int isDown(struct Controls* pointer);
int isSelect(struct Controls* pointer);
int getUp(struct Controls* pointer);
int getDown(struct Controls* pointer);
int getSelect(struct Controls* pointer);
int init_controls(struct Controls* pointer);

#endif