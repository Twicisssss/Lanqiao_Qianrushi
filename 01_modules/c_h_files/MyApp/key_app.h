/**
 * @file key_app.h
 * @brief 按键应用层头文件，提供按键任务接口
 * @author Twicis
 * @date 2026-01-11
 * @version v1.0.0
 * @note 需配合key_app.c使用，按键任务需定期调用
 */
#ifndef __KEY_APP_H_
#define __KEY_APP_H_
#include "bsp_system.h"

/**
 * @brief 按键扫描任务，处理按键按下和释放事件
 * @param 无
 * @return 无
 * @note 需在主循环或调度器中定期调用
 */
void key_task(void);

#endif
