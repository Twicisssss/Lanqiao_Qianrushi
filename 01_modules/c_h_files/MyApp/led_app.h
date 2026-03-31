/**
 * @file led_app.h
 * @brief LED应用层头文件，提供LED任务接口
 * @author Twicis
 * @date 2026-01-11
 * @version v1.0.0
 * @note 需配合led_app.c使用，LED任务需定期调用
 */
#ifndef __LED_APP_H_
#define __LED_APP_H_
#include "bsp_system.h"

/**
 * @brief LED显示任务，刷新LED显示状态
 * @param 无
 * @return 无
 * @note 需在主循环或调度器中定期调用
 */
void led_task(void);

#endif
