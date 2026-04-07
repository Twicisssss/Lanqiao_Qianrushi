#ifndef __BSP_SYSTEM_H__
#define __BSP_SYSTEM_H__

#include "main.h"
#include "usart.h"
extern uint8_t uart_rx_buf[128];
extern uint16_t uart_rx_index;
extern uint32_t uart_rx_ticks;
extern uint8_t uart_rx_dma_buf[128];

#include "system.h"
#include "scheduler.h"

#include "led_app.h"
extern uint8_t led_buf[8];
#include "key_app.h"
#include "lcd_app.h"
#include "uart_app.h"

#endif
