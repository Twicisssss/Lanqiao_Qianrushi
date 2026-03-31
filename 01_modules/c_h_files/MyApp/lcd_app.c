/**
 * @file lcd_app.c
 * @brief LCD应用层，实现LCD格式化显示功能
 * @author Twicis
 * @date 2026-01-11
 * @version v1.0.0
 * @note 提供类似printf的格式化显示接口
 */
#include "lcd_app.h"


/**
 * @brief 在LCD指定行显示格式化字符串
 * @param Line 显示行号（Line0-Line9）
 * @param format 格式化字符串
 * @param ... 可变参数列表
 * @return 无
 * @note 最大支持20个字符显示
 */
void lcd_sprintf(uint8_t Line, char *format,...)
{
    // 字符串缓冲区，用于存储格式化后的字符串
    char String[21];
    // 可变参数列表
    va_list arg;
    // 使用格式化字符串初始化参数列表
    va_start(arg,format);
    // 格式化字符串并存储到缓冲区
    vsprintf(String,format, arg);
    // 结束参数列表
    va_end(arg);
    // 在LCD上指定行显示格式化后的字符串
    LCD_DisplayStringLine(Line,(u8 *)String);
}

// 测试计数器
uint16_t count=0;
// 当前按键ID
uint8_t key_id=0;

/**
 * @brief LCD显示任务，刷新LCD显示内容
 * @param 无
 * @return 无
 * @note 需在主循环或调度器中定期调用
 */
void lcd_task(void)
{
    lcd_sprintf(Line0,"This is LCD_TEST");
    lcd_sprintf(Line2,"Test count:%d",count);
    count++;
    lcd_sprintf(Line4,"Test key:%d",key_id);

    lcd_sprintf(Line6,"This is UART_TEST");

}
