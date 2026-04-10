#include "led_app.h"

uint8_t led_buf[8]={0,1,0,1,1,1,1,1};

void led_disp(uint8_t *uc_led)
{
    uint8_t temp_now = 0x00;
    uint8_t temp_old = 0xff;
    
    for(uint8_t i=0;i<8;i++)
        temp_now |= (led_buf[i] << i);
    
    if(temp_now != temp_old)
    {
        GPIOC->ODR &= 0x00ff;
        GPIOC->ODR |= ~(temp_now<<8);
        GPIOD->BSRR |= 0x01<<2; //置位 GPIOD 的第 2 位
        GPIOD->BRR |= 0x01<<2;  //复位 GPIOD 的第 2 位
        temp_old = temp_now;
    }
}
void led_task(void)
{
    led_disp(led_buf);
}

