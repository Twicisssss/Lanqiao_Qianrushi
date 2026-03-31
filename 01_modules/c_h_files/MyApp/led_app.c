/**
 * @file led_app.c
 * @brief LED应用层，实现LED显示控制
 * @author Twicis
 * @date 2026-01-11
 * @version v1.0.0
 * @note 支持8个LED，通过led_buf数组控制显示状态
 */
#include "led_app.h"

/* LED状态缓冲区，每个元素对应一个LED，1为点亮，0为熄灭 */
uint8_t led_buf[8]={0,0,0,0,0,0,0,0};

/**
 * @brief 刷新LED显示
 * @param uc_led LED状态数组指针
 * @return 无
 * @note 将led_buf中的状态映射到硬件GPIO输出
 */
void led_disp(uint8_t *uc_led)
{
    // 当前LED状态位图
    uint8_t temp_now = 0x00;
    // 上次LED状态位图，用于检测变化
    uint8_t temp_old = 0xff;

    // 将数组状态转换为位图
    for(uint8_t i=0;i<8;i++)
        temp_now |= (led_buf[i] << i);

    // 仅在状态变化时更新GPIO
    if(temp_now != temp_old)
    {
        // 清除GPIOC高8位
        GPIOC->ODR &= 0x00ff;
        // 设置LED输出（低电平点亮）
        GPIOC->ODR |= ~(temp_now<<8);
        // 锁存使能
        GPIOD->BSRR |= 0x01<<2;
        // 锁存关闭
        GPIOD->BRR |= 0x01<<2;
        // 更新上次状态
        temp_old = temp_now;
    }
}

/**
 * @brief LED显示任务，刷新LED显示状态
 * @param 无
 * @return 无
 * @note 需在主循环或调度器中定期调用
 */
void led_task(void)
{
    led_disp(led_buf);
}
