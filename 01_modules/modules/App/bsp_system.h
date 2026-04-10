#ifndef __BSP_SYSTEM_H__
#define __BSP_SYSTEM_H__

#include "main.h"
#include "usart.h"
extern uint8_t uart_rx_buf[128];
extern uint8_t uart_rx_dma_buf[128];
#include "adc.h"
#include "rtc.h"
#include "tim.h"

#include "scheduler.h"

#include "led_app.h"
extern uint8_t led_buf[8];
#include "key_app.h"
#include "lcd_app.h"
#include "uart_app.h"
#include "adc_app.h"
extern float adc_value[2];
#include "rtc_app.h"
extern RTC_TimeTypeDef time;
extern RTC_DateTypeDef date;
#include "i2c_hal.h"
extern uint8_t mcp4017_set;
extern uint8_t mcp4017_value;
extern uint8_t m24c02_set[20];
extern uint8_t m24c02_data[20];
#include "tim_app.h"
extern float PA7_duty;
extern float PA6_duty;
extern uint32_t tim_ic_PA15_buf[64];//TIM2_CH1--R40
extern uint32_t tim_ic_PA15_val;
extern uint32_t tim_ic_PA15_temp;
extern uint32_t tim_ic_PB4_buf[64];//TIM3_CH1--R39
extern uint32_t tim_ic_PB4_val;
extern uint32_t tim_ic_PB4_temp;

#endif
