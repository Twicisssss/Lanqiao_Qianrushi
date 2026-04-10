#include "tim_app.h"


float PA7_duty=80.0;
float PA6_duty=20.0;
void pwm_init(void)
{
    HAL_TIM_PWM_Start(&htim16,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim17,TIM_CHANNEL_1);
    pwm_duty_set(PA6_duty,16);
    pwm_duty_set(PA7_duty,17);
}
void pwm_duty_set(float duty_set,uint8_t TIMX)
{
    if(TIMX==16)
    {
        TIM16->CCR1 = (TIM16->ARR+1) * (duty_set/100.0f);
    }
    else if(TIMX==17)
    {
        TIM17->CCR1 = (TIM17->ARR+1) * (duty_set/100.0f);
    }
}


uint32_t tim_ic_PA15_buf[64];//TIM2_CH1--R40
uint32_t tim_ic_PA15_val = 0;
uint32_t tim_ic_PA15_temp = 0;

uint32_t tim_ic_PB4_buf[64];//TIM3_CH1--R39
uint32_t tim_ic_PB4_val = 0;
uint32_t tim_ic_PB4_temp = 0;
void ic_init(void)
{
    HAL_TIM_IC_Start_DMA(&htim2,TIM_CHANNEL_1,tim_ic_PA15_buf,64);
    HAL_TIM_IC_Start_DMA(&htim3,TIM_CHANNEL_1,tim_ic_PB4_buf,64);
}
void ic_task(void)
{
    tim_ic_PA15_temp=tim_ic_PB4_temp=0;
    
    for(uint8_t i=0;i<64;i++)
    {
        tim_ic_PA15_temp+=tim_ic_PA15_buf[i];
        tim_ic_PB4_temp+=tim_ic_PB4_buf[i];
    }
    tim_ic_PA15_temp/=64;
    tim_ic_PB4_temp/=64;
    
    tim_ic_PA15_val=(int)((float)(1000.0f*1000.0f)/(float)tim_ic_PA15_temp);
    tim_ic_PB4_val=(int)((float)(1000.0f*1000.0f)/(float)tim_ic_PB4_temp);
}

