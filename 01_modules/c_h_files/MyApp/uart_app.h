/**
 * @file uart_app.h
 * @brief UART应用层头文件，提供串口通信任务接口
 * @author Twicis
 * @date 2026-01-11
 * @version v1.0.0
 * @note 需配合uart_app.c使用，UART任务需定期调用
 */
#ifndef __UART_APP_H_
#define __UART_APP_H_

#include "bsp_system.h"
#include "usart.h"
#include "string.h"

/**
 * @brief UART数据处理任务，检测并处理接收到的数据
 * @param 无
 * @return 无
 * @note 需在主循环或调度器中定期调用，使用超时判断接收完成
 */
void uart_task(void);


#endif
