#ifndef __BSP_SYSTEM_H_
#define __BSP_SYSTEM_H_

#include "main.h"
#include "usart.h"
extern uint8_t uart_rx_buf[128];
extern uint8_t uart_rx_dma_buf[128];
extern uint16_t uart_rx_index;
extern uint32_t uart_rx_ticks;
#include "adc.h"

#include "scheduler.h"

#include "led_app.h"
extern uint8_t led_buf[8];
#include "key_app.h"
#include "lcd_app.h"
#include "uart_app.h"
#include "adc_app.h"
extern uint32_t adc_dma_buf[2][30];
extern float adc_value[2];


#endif

