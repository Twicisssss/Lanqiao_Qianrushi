#include "lcd_app.h"

void lcd_sprintf(uint8_t Line,char *format,...)
{
    char String[21];
    va_list arg;
    va_start(arg,format);
    vsprintf(String,format,arg);
    va_end(arg);
    LCD_DisplayStringLine(Line,(u8 *)String);
}

void lcd_task(void)
{
    lcd_sprintf(Line0,"Hello");
    lcd_sprintf(Line2,"led1=%d",led_buf[0]);    
}
