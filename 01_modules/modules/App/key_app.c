#include "key_app.h"

uint8_t key_read(void)
{
    uint8_t temp=0;
    
    if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0) == GPIO_PIN_RESET)
        temp = 1;
    else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1) == GPIO_PIN_RESET)
        temp = 2;
    else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2) == GPIO_PIN_RESET)
        temp = 3;
    else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET)
        temp = 4;
    
    return temp;
}

uint8_t key_val,key_old;
uint8_t key_down,key_up;
void key_task(void)
{
    key_val = key_read();
    key_down = key_val & (key_old^key_val);
    key_up = ~key_val & (key_old^key_val);
    key_old = key_val;
    
    switch(key_down)
    {
        case 1:
            led_buf[0]^=1;
            printf("\nled:");
            for(uint8_t i=0;i<8;i++)
                printf("%d ",led_buf[i]);
            printf("\n\n");
            printf("adc1:%.2f V\n",adc_value[0]);
            printf("adc2:%.2f V\n",adc_value[1]);
            printf("\n\n");
            printf("time:%2d-%2d-%2d\n",time.Hours,time.Minutes,time.Seconds);
            printf("date:%2d-%2d-%2d\n",date.Year,date.Month,date.Date);
        break;
        case 2:
            
            mcp4017_set++;
            m24c02_read(0,m24c02_set,1);
            m24c02_set[0]++;
            mcp4017_write(mcp4017_set);
            m24c02_write(0,m24c02_set,1);
        break;
        case 3:
            mcp4017_read(&mcp4017_value);
            m24c02_read(0,m24c02_data,1);
        break;
        case 4:
            
        break;
    }
}

