#ifndef __LCD_APP_H
#define __LCD_APP_H

#include "bsp_system.h"
#include "lcd.h"
#include "stdio.h"
#include "stdarg.h"

void lcd_task(void);
extern uint16_t count;
extern uint8_t key_id;


#endif
