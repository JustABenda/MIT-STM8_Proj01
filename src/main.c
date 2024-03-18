#include <main.h>
#include <sct2026.h>
#include <controls.h>
#include <time_handler.h>
#include <utils.h>
#include <stm/stm8s.h>

#define __RX_UART1__
struct Controls *controls;

char input_buffer[255];
uint16_t index = 0;

void rx_action(void)
{
    char c = UART1_ReceiveData8();
    input_buffer[index] = c;
    if(c == '\n') {index = 0;printf(input_buffer);for(int i = 0; i < 255; i++) input_buffer[i] = '\0'; }
    else index++;
}

INTERRUPT_HANDLER(TIM2_UPD_OVF_IRQHandler, ITC_IRQ_TIM2_OVF){
    TIM2_ClearFlag(TIM2_FLAG_UPDATE);
}


void setup(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); //Set CLK

    /*Init Buttons*/
    init_controls(controls);

    init_time();
    init_uart1();
    enableInterrupts();

    sct_init();
    sct_reset();

    attach_timer(TIMER2, TIM2_PRESCALER_32, 65535);
    
}

void main_task(void){

}

int main(void)
{
    setup(); //Calls inits
    locked_timer_task(main_task,50,0);
    return 0;
}