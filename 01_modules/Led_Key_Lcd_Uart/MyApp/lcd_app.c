#include "lcd_app.h"


void lcd_sprintf(uint8_t Line, char *format,...)
{
    char String[21];        // 缓冲区用于存储格式化后的字符串
    va_list arg;
    va_start(arg,format);   // 使用格式化字符串初始化参数列表
    vsprintf(String,format, arg);   // 格式化字符串并存储在缓冲区中va_end(arg)； // 清理参数列表
    LCD_DisplayStringLine(Line,(u8 *)String);   // 在LCD的指定行显示格式化后的字符串
}

uint16_t count=0;
uint8_t key_id=0;
void lcd_task(void)
{
    lcd_sprintf(Line0,"This is LCD_TEST");
    lcd_sprintf(Line2,"Test count:%d",count);
    count++;
    lcd_sprintf(Line4,"Test key:%d",key_id);
    
    lcd_sprintf(Line6,"This is UART_TEST");

}
