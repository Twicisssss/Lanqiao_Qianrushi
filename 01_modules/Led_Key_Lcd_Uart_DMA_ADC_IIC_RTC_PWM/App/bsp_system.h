#ifndef __BSP_SYSTEM_H_
#define __BSP_SYSTEM_H_

#include "main.h"
#include "usart.h"
extern uint8_t uart_rx_buf[128];
extern uint8_t uart_rx_dma_buf[128];
extern uint16_t uart_rx_index;
extern uint32_t uart_rx_ticks;
#include "adc.h"
#include "rtc.h"
#include "tim.h"
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim2;
extern DMA_HandleTypeDef hdma_tim3_ch1;
extern DMA_HandleTypeDef hdma_tim2_ch1;

#include "scheduler.h"

#include "led_app.h"
extern uint8_t led_buf[8];
#include "key_app.h"
#include "lcd_app.h"
#include "uart_app.h"
#include "adc_app.h"
extern uint32_t adc_dma_buf[2][30];
extern float adc_value[2];
#include "i2c_hal.h"
extern uint8_t at_test_write_data[10];
extern uint8_t at_test_read_data[10];
extern uint8_t mcp4017_value;
#include "rtc_app.h"
extern RTC_TimeTypeDef time;
extern RTC_DateTypeDef date;
#include "tim_app.h"
extern float PA6_pwm_duty;//TIM16_CH1
extern float PA7_pwm_duty;//TIM17_CH1
extern uint32_t tim_ic_PB4_buf[64]; //TIM3_CH1--R39
extern uint32_t tim_ic_PB4_val;
extern uint32_t tim_ic_PB4_temp;
extern uint32_t tim_ic_PA15_buf[64];//TIM2_CH1--R40
extern uint32_t tim_ic_PA15_val;
extern uint32_t tim_ic_PA15_temp;

#endif

