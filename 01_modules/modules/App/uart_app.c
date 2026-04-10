#include "uart_app.h"
uint8_t uart_flag=0;

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    uart_flag=1;
    printf("\nDma Data:%s\n",uart_rx_dma_buf);
    memcpy(uart_rx_buf,uart_rx_dma_buf,Size);
    memset(uart_rx_dma_buf,0,128);
}

void uart_task(void)
{
    if(uart_flag == 1)
    {
        printf("uart data:%s\n",uart_rx_buf);
        memset(uart_rx_buf,0,128);
        uart_flag=0;
    }
}

