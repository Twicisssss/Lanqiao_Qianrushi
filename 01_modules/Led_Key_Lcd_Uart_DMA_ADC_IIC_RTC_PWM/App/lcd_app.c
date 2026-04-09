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

uint8_t at_test_write_data[10] = {0xA1, 0x22, 0x33, 0x44, 0x55};
uint8_t at_test_read_data[10] = {0};
uint8_t mcp4017_value = 0;

void lcd_task(void)
{
    lcd_sprintf(Line0,"hello world led1=%d",led_buf[0]);
    lcd_sprintf(Line1,"adc1=%.2f(R38)",adc_value[0]);
    lcd_sprintf(Line2,"adc2=%.2f(R37)",adc_value[1]);
    
    lcd_sprintf(Line3,"AT24C02[0]:0x%02X",at_test_read_data[0]);                //AT24C02存储值
    lcd_sprintf(Line4,"MCP4017:%d (0x%02X)   ", mcp4017_value, mcp4017_value);  //MCP4017当前值
    
    lcd_sprintf(Line5,"Time:%2d-%2d-%2d",time.Hours,time.Minutes,time.Seconds);    
    lcd_sprintf(Line6,"Date:%2d-%2d-%2d",date.Year,date.Month,date.Date);
    
    lcd_sprintf(Line7,"PA7pwmout:%2.2f", PA7_pwm_duty);// TIM17_CH1频率
    lcd_sprintf(Line8,"PB4  Freq:%lu",tim_ic_PB4_val);  // R39频率
    lcd_sprintf(Line9,"PA15 Freq:%lu",tim_ic_PA15_val);  // R39频率
}


