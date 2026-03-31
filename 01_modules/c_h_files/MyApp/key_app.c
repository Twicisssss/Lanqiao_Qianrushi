/**
 * @file key_app.c
 * @brief 按键应用层，实现按键扫描和事件处理
 * @author Twicis
 * @date 2026-01-11
 * @version v1.0.0
 * @note 支持4个按键，使用边沿检测实现按下和释放事件
 */
#include "key_app.h"

/**
 * @brief 读取当前按下的按键
 * @param 无
 * @return 按键编号，1-4表示对应按键，0表示无按键按下
 * @note 低电平表示按键按下
 */
uint8_t key_read(void)
{
    // 按键状态临时变量
    uint8_t temp=0;

    if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0) == GPIO_PIN_RESET)
        temp=1;
    else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1) == GPIO_PIN_RESET)
        temp=2;
    else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2) == GPIO_PIN_RESET)
        temp=3;
    else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET)
        temp=4;

    return temp;
}

// 当前按键值
uint8_t key_val,key_old;
// 按键按下和释放标志
uint8_t key_down,key_up;

/**
 * @brief 按键扫描任务，处理按键按下和释放事件
 * @param 无
 * @return 无
 * @note 需在主循环或调度器中定期调用
 */
void key_task(void)
{
    // 读取当前按键状态
    key_val = key_read();
    // 检测按键按下边沿
    key_down = key_val & (key_old^key_val);
    // 检测按键释放边沿
    key_up = ~key_val & (key_old^key_val);
    // 保存当前状态用于下次比较
    key_old = key_val;

    // 更新全局按键ID
    key_id=key_val;
    // 按键按下事件处理
    switch(key_down)
    {
        case 1:
            led_buf[0] ^= 1;
            count = 0;
        break;
        case 2:
            led_buf[1] ^= 1;
        break;
        case 3:
            led_buf[2] ^= 1;
        break;
        case 4:
            led_buf[3] ^= 1;
        break;
    }

}
