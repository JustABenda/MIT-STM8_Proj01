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

/*INTERRUPT_HANDLER(TIM2_UPD_OVF_IRQHandler, ITC_IRQ_TIM2_OVF){
    TIM2_ClearFlag(TIM2_FLAG_UPDATE);
    printf("Hello World");
}*/

uint16_t RGB_R = 0;
uint16_t RGB_G = 0;
uint16_t RGB_B = 0;

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

    //attach_timer(TIMER2, TIM2_PRESCALER_32, 65535);
    attach_pwm(OC21, TIM2_PRESCALER_16, 6999, 3000, FALSE);
    attach_pwm(OC22, TIM2_PRESCALER_16, 6999, 3000, TRUE);
    attach_pwm(OC23, TIM2_PRESCALER_16, 6999, 3000, TRUE);

    update_pwm_duty(OC21, RGB_B);
    update_pwm_duty(OC22, RGB_G);
    update_pwm_duty(OC23, RGB_R);
    
}
bool print = FALSE;
void main_task(void){
    if(isUp(controls)){
        RGB_R = RGB_R >= 6900 ? 0 : RGB_R + 100;
        print = TRUE;
    }
    if(isSelect(controls)){
        RGB_G = RGB_G >= 6900 ? 0 : RGB_G + 50;
        print = TRUE;
    }
    if(isDown(controls)){
        RGB_B = RGB_B >= 6900 ? 0 : RGB_B + 150;
        print = TRUE;
    }
    if(print) printf("RGB: %d %d %d\n", RGB_R, RGB_G, RGB_B);
    print = FALSE;
    update_pwm_duty(OC21, RGB_B);
    update_pwm_duty(OC22, RGB_G);
    update_pwm_duty(OC23, RGB_R);
}

int main(void)
{
    setup(); //Calls inits
    locked_timer_task(main_task,50,0);
    return 0;
}