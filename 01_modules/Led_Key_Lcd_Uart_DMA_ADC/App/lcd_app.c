#include "lcd_app.h"

void lcd_sprintf(uint8_t LineX,char *format,...)
{
    char String[21];
    va_list arg;
    va_start(arg,format);
    vsprintf(String,format,arg);
    va_end(arg);
    LCD_DisplayStringLine(LineX,(u8 *)String);
}


void lcd_task(void)
{
    lcd_sprintf(Line0,"hello world");
    lcd_sprintf(Line2,"led1=%d",led_buf[0]);
    lcd_sprintf(Line4,"adc1=%.2f(R38)",adc_value[0]);
    lcd_sprintf(Line6,"adc2=%.2f(R37)",adc_value[1]);
}


