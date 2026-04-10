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
    lcd_sprintf(Line0,"Lcd Test  Led1=%d",led_buf[0]);
    
    lcd_sprintf(Line1,"time:%2d-%2d-%2d",time.Hours,time.Minutes,time.Seconds);
    lcd_sprintf(Line2,"date:%2d-%2d-%2d",date.Year,date.Month,date.Date);
    
    lcd_sprintf(Line3,"AO1:%.2f  AO2:%.2f",adc_value[0],adc_value[1]);
    
    lcd_sprintf(Line4,"mcp4017:%d",mcp4017_value);
    lcd_sprintf(Line5,"m24c02:%d",m24c02_data[0]);

    lcd_sprintf(Line6,"PA7:%2.1f---PA6:%2.1f",PA7_duty,PA6_duty);
    
    lcd_sprintf(Line7,"PA15:%5lu",tim_ic_PA15_val);
    lcd_sprintf(Line8,"PB4 :%5lu",tim_ic_PB4_val);
}

