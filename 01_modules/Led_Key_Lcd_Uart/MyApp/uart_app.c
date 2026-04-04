#include "uart_app.h"

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance ==USART1)
    {
        uart_rx_ticks=uwTick;
        uart_rx_index++;
        HAL_UART_Receive_IT(&huart1,&uart_rx_buf[uart_rx_index],1);
        
//        printf("Receive Successfully\n");
    }
}
    
    
void uart_task(void)
{
    if(uart_rx_index == 0)return;
    if(uwTick-uart_rx_ticks>100)
    {
        
        printf("uart data:%s\n",uart_rx_buf);
        
        memset(uart_rx_buf,0,uart_rx_index);
        uart_rx_index = 0;
        huart1.pRxBuffPtr = uart_rx_buf;
    }
}
