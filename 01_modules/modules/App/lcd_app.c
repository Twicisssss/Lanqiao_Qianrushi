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

void lcd_init(void)
{
    LCD_Init();
    LCD_Clear(Black);
    LCD_SetBackColor(Black);
    LCD_SetTextColor(White);
}
void lcd_task(void)
{
    lcd_sprintf(Line0,"Lcd Test");
    lcd_sprintf(Line2,"Led1=%d",led_buf[0]);
}

