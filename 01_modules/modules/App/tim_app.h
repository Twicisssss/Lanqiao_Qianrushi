#ifndef __TIM_HAL_H__
#define __TIM_HAL_H__
#include "bsp_system.h"

void pwm_init(void);
void pwm_duty_set(float duty_set,uint8_t channel);
void ic_init(void);
void ic_task(void);


#endif
