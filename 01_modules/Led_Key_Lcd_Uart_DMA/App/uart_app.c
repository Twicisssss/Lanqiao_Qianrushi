#include "uart_app.h"

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//    if(huart->Instance == USART1)
//    {
//        uart_rx_ticks = HAL_GetTick();
//        uart_rx_index++;
//        HAL_UART_Receive_IT(&huart1,&uart_rx_buf[uart_rx_index],1);
//    }
//}
uint8_t dma_flag=0;
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t Size)
{
    printf("dma data:%s\n",uart_rx_dma_buf);
    printf("dma success\n");
    dma_flag=1;
    memset(uart_rx_dma_buf,0,sizeof(uart_rx_dma_buf));
}

void uart_task(void)
{
    if(dma_flag==1)
    {
        printf("uart data:%s\n",uart_rx_dma_buf);
        dma_flag=0;
    }
//    if(uart_rx_index==0)return;
//    if(HAL_GetTick()-uart_rx_ticks>100)
//    {
//        printf("uart data:%s\n",uart_rx_buf);
//        
//        
//        memset(uart_rx_buf,0,uart_rx_index);
//        uart_rx_index=0;
//        huart1.pRxBuffPtr=uart_rx_buf;
//    }
}

/*usart.c
#include "bsp_system.h"
#include "string.h"
typedf struct __FILE FILE

uint8_t uart_rx_buf[128]={0};
uint16_t uart_rx_index=0;
uint32_t uart_rx_ticks=0;

uint8_t uart_rx_dma_buf[128]={0};

void MX_USART1_UART_Init(void)
{
    //...
    //HAL_UART_Receive_IT(&huart1,uart_rx_buf,1);
    
}

int fputc(int ch,FILE *str)
{
    HAL_UART_Transmit(&huart1,(uint8_t *)&ch,1,10);
    return ch;
}
*/


/*it.c
void USART1_IRQHandler(void)
{
    //...
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1,uart_rx_dma_buf,sizeof(uart_rx_dma_buf));
    __HAL_DMA_DISABLE_IT(&hdma_usart1_rx,DMA_IT_HT);
}
*/

