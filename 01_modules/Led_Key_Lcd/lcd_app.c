#include "lcd_app.h"
#include "lcd.h"
#include "stdio.h"
#include "stdarg.h"

void lcdSprintf(uint8_t Line,char *format, ...)
{
    char buf[21];
    va_list arg;
    va_start(arg, format);
    vsnprintf(buf, format, arg);
    va_end(arg);
    LCD_ShowString(Line, (uint8_t *)buf);
}


