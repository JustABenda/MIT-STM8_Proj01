#include <time_handler.h>

void init_time(){
    init_milis();
}
void unsafe_delay(uint32_t mls){ //Unsafe
    uint32_t timer_start = milis();
    while(milis() - timer_start <= mls);
}
void locked_timer_task(void(*pointer)(void), uint32_t delay, uint16_t limit){
    uint32_t time = 0;
    uint16_t c = 0;
    while (limit == 0 || c < limit) { //Loop
        if (milis() - time >= delay) {
            pointer();
            time = milis(); //Reset timer
            if(limit != 0) c++; //limit counter
        }
    }
}
void locked_timer_task_extended(void(*pointer_pre)(void), void(*pointer_timed)(void), void(*pointer_after)(void), uint32_t delay, uint16_t limit){
    uint32_t time = 0;
    uint16_t c = 0;
    while (limit == 0 || c < limit) { //Loop
        if(pointer_pre) pointer_pre();
        if (milis() - time >= delay) {
            pointer_timed();
            time = milis(); //Reset timer
            if(limit != 0) c++; //limit counter
        }
        if(pointer_after) pointer_after();
    }
}
void attach_timer(uint8_t id, uint8_t prescaler, uint32_t period){
    if(id == TIMER2){
        TIM2_TimeBaseInit(TIM4_PRESCALER_32, period);
        TIM2_Cmd(ENABLE);
        TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);
    }else if(id == TIMER3){
        TIM3_TimeBaseInit(prescaler, period);
        TIM3_Cmd(ENABLE);
        TIM3_ITConfig(TIM3_IT_UPDATE, ENABLE);
    }
}