/**
 * @file uart_app.c
 * @brief UART应用层，实现串口数据接收和处理
 * @author Twicis
 * @date 2026-01-11
 * @version v1.0.0
 * @note 使用中断接收和超时判断实现不定长数据接收
 */
#include "uart_app.h"

/**
 * @brief UART接收完成回调函数
 * @param huart UART句柄指针
 * @return 无
 * @note 由HAL库在接收完成时自动调用
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    // 判断是否为USART1中断
    if(huart->Instance ==USART1)
    {
        // 记录接收时间戳
        uart_rx_ticks=uwTick;
        // 接收索引递增
        uart_rx_index++;
        // 开启下一字节接收
        HAL_UART_Receive_IT(&huart1,&uart_rx_buf[uart_rx_index],1);
    }
}


/**
 * @brief UART数据处理任务，检测并处理接收到的数据
 * @param 无
 * @return 无
 * @note 需在主循环或调度器中定期调用，使用100ms超时判断接收完成
 */
void uart_task(void)
{
    // 无数据则直接返回
    if(uart_rx_index == 0)return;
    // 超时100ms判断接收完成
    if(uwTick-uart_rx_ticks>100)
    {
        // 打印接收到的数据
        printf("uart data:%s\n",uart_rx_buf);

        // 清空接收缓冲区
        memset(uart_rx_buf,0,uart_rx_index);
        // 重置接收索引
        uart_rx_index = 0;
        // 重置接收缓冲区指针
        huart1.pRxBuffPtr = uart_rx_buf;
    }
}
