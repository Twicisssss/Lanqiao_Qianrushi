#include "system.h"
void system_init(void)
{
    GPIOC->ODR |= 0xff00;   //将 GPIOC 高 8 位的输出数据寄存器设为高电平
    GPIOD->BSRR |= 0x01<<2; //置位 GPIOD 的第 2 位
    GPIOD->BRR |= 0x01<<2;  //复位 GPIOD 的第 2 位
}
