#include "uart_app.h"

uint8_t uart_flag=0;

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t Size)
{
    printf("Uart Callback Success\n");
    printf("Callback Data:%s\n\n",uart_rx_dma_buf);
    uart_flag=1;
}



void uart_task(void)
{
    if(uart_flag==1)
    {
        printf("Uart Task Success\n");
        printf("Task Data:%s\n",uart_rx_dma_buf);
        uart_flag=0;
        memset(uart_rx_dma_buf,0,sizeof(uart_rx_dma_buf));
    }
}

/* usart.c
#include "bsp_system.h"
typedef struct __FILE FILE;

uint8_t uart_rx_buf[128]={0};
uint8_t uart_rx_dma_buf[128]={0};
uint16_t uart_rx_index=0;
uint32_t uart_ticks=0;

void MX_USART1_UART_Init(void)
{
    //  ...省略...
    HAL_UARTEX_ReceiveToIdle_DMA(&huart1, uart_rx_dma_buf, 128);
    __HAL_DMA_DISABLE_IT(&hdma_usart1_rx,DMA_IT_HT)
}

int fputc(int ch,FLIE *str)
{
    HAL_Uart_Transmit(&huart1,(uint8_t *)&ch,1,10);
    return ch;
}

*/

/* it.c
void USART1_IRQHandler(void)
{
    //  ...省略...
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1,uart_rx_dma_buf,sizeof(uart_rx_dma_buf));
    __HAL_DMA_DISABLE_IT(&hdma_usart1_rx,DMA_IT_HT);
}
*/


