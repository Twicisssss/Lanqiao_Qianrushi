#include "key_app.h"
uint8_t key_read(void)
{
    uint8_t temp=0;

    if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==GPIO_PIN_RESET)
        temp=1;
    else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)==GPIO_PIN_RESET)
        temp=2;
    else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2)==GPIO_PIN_RESET)
        temp=3;
    else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==GPIO_PIN_RESET)
        temp=4;

    return temp;
}

uint8_t key_val,key_old;
uint8_t key_down,key_up;
void key_task(void)
{
    key_val=key_read();
    key_down = key_val&(key_old^key_val);
    key_up = ~key_val&(key_old^key_val);
    key_old=key_val;

    switch(key_down)
    {
        case 1:
            led_buf[2] ^=1;
        break;
        case 2:
            led_buf[3] ^=1;
        break;
        case 3:
            led_buf[4] ^=1;
        break;
        case 4:
            led_buf[5] ^=1;
        break;
    }
}
}

