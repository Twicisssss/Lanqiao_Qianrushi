#include "key_app.h"

uint8_t key_read(void)
{
    uint8_t temp = 0;

    if(HAL_Pin_Read(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
        temp = 1;
    else if(HAL_Pin_Read(GPIOA, GPIO_PIN_1) == GPIO_PIN_RESET)
        temp = 2;
    else if(HAL_Pin_Read(GPIOA, GPIO_PIN_2) == GPIO_PIN_RESET)
        temp = 3;
    else if(HAL_Pin_Read(GPIOA, GPIO_PIN_3) == GPIO_PIN_RESET)
        temp = 4;

    return temp;
}

uint8_t key_val,key_old;
uint8_t key_down,key_up;
void key_task(void)
{
    key_val = key_read();
    key_down = (key_val) & (key_val ^ key_old);
    key_up = (~key_val) & (key_val ^ key_old);
    key_old = key_val;

    switch(key_down)
    {
        case 1:
            // Handle key 1 press
            break;
        case 2:
            // Handle key 2 press
            break;
        case 3:
            // Handle key 3 press
            break;
        case 4:
            // Handle key 4 press
            break;
    }
}



