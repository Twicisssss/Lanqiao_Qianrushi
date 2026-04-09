#ifndef __TIM_APP_H__
#define __TIM_APP_H__
#include "bsp_system.h"

void pwm_set_duty(float duty_set,uint8_t TIMX);
void pwm_set_freq(uint32_t freq_set,uint8_t TIMX);
void tim_ic_task(void);

#endif
