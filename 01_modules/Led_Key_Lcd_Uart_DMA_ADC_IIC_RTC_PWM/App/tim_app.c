#include "tim_app.h"
float PA6_pwm_duty=0;//TIM16_CH1
float PA7_pwm_duty=0;//TIM17_CH1
void pwm_set_duty(float duty_set,uint8_t TIMX)
{
    if(TIMX==16)
        TIM16->CCR1 = (TIM16->ARR+1) * (duty_set/100.0f);
    else if(TIMX==17)
        TIM17->CCR1 = (TIM17->ARR+1) * (duty_set/100.0f);
}

void pwm_set_freq(uint32_t freq_set,uint8_t TIMX)
{
    uint32_t clk = HAL_RCC_GetPCLK2Freq();
    
    if((RCC->CFGR & RCC_CFGR_PPRE2) != RCC_CFGR_PPRE2_DIV1)
        clk*=2;
    
    uint32_t arr = clk/freq_set -1;
    
    if(TIMX==16)
    {
        float duty = TIM16->CCR1 / (float)(TIM16->ARR+1);
        TIM16->ARR = arr;
        TIM16->CCR1= (TIM16->ARR+1)*duty;
        TIM16->EGR=TIM_EGR_UG;
    }
    else if(TIMX==17)
    {
        float duty = TIM17->CCR1 / (float)(TIM17->ARR+1);
        TIM17->ARR = arr;
        TIM17->CCR1= (TIM17->ARR+1)*duty;
        TIM17->EGR=TIM_EGR_UG;
    }
}


uint32_t tim_ic_PB4_buf[64];//TIM3_CH1--R39
uint32_t tim_ic_PB4_val = 0;
uint32_t tim_ic_PB4_temp = 0;

uint32_t tim_ic_PA15_buf[64];//TIM2_CH1--R40
uint32_t tim_ic_PA15_val = 0;
uint32_t tim_ic_PA15_temp = 0;
void tim_ic_task(void)
{
    tim_ic_PB4_temp=0;
    tim_ic_PA15_temp=0;
    for(uint8_t i=0;i<64;i++)
    {
        tim_ic_PB4_temp+=tim_ic_PB4_buf[i];
        tim_ic_PA15_temp+=tim_ic_PA15_buf[i];
    }
    tim_ic_PB4_temp/=64;
    tim_ic_PA15_temp/=64;
    tim_ic_PB4_val = (int)((float)(1000.0f*1000.0f)/(float)tim_ic_PB4_temp);
    tim_ic_PA15_val = (int)((float)(1000.0f*1000.0f)/(float)tim_ic_PA15_temp);
}

