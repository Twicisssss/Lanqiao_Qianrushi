/**
 * @file lcd_app.h
 * @brief LCD应用层头文件，提供LCD任务接口和全局变量声明
 * @author Twicis
 * @date 2026-01-11
 * @version v1.0.0
 * @note 需配合lcd_app.c使用，LCD任务需定期调用
 */
#ifndef __LCD_APP_H
#define __LCD_APP_H

#include "bsp_system.h"
#include "lcd.h"
#include "stdio.h"
#include "stdarg.h"

/**
 * @brief LCD显示任务，刷新LCD显示内容
 * @param 无
 * @return 无
 * @note 需在主循环或调度器中定期调用
 */
void lcd_task(void);

// 计数器变量
extern uint16_t count;
// 当前按键ID
extern uint8_t key_id;


#endif
