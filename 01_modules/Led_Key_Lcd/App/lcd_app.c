#include "lcd_app.h"


void lcd_sprintf(uint8_t Line, char *format,...)
{
    char String[21];        // ���������ڴ洢��ʽ������ַ���
    va_list arg;
    va_start(arg,format);   // ʹ�ø�ʽ���ַ�����ʼ�������б�
    vsprintf(String,format, arg);   // ��ʽ���ַ������洢�ڻ�������va_end(arg)�� // ���������б�
    va_end(arg);
    LCD_DisplayStringLine(Line,(u8 *)String);   // ��LCD��ָ������ʾ��ʽ������ַ���
}

uint16_t count=0;
uint8_t key_id=0;
void lcd_task(void)
{
    lcd_sprintf(Line0,"This is LCD_TEST");
    lcd_sprintf(Line2,"Test count:%d",count);
    count++;
    lcd_sprintf(Line4,"Test key:%d",key_id);
}
