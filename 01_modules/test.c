void system_init(void);
void led_task(void);
void key_task(void);
void lcd_task(void);

/*调度器部分*/
#include "scheduler.h"
typedef struct {
    void (*task_func)(void); // 任务函数指针
    uint32_t time_rate;       // 任务执行间隔（单位：毫秒）
    uint32_t time_last;  // 上次执行时间（单位：毫秒
}Task;
Task SchedulerTasks[]={
    {led_task, 10, 0},
    {key_task, 10, 0},
    {lcd_task, 10, 0},
};

uint8_t task_num = 0;
void scheduler_init(void)
{
    system_init();

    task_num = sizeof(SchedulerTasks) / sizeof(Task);
}
void scheduler_run(void)
{
    uint32_t time_now = HAL_GetTick(); // 获取当前系统时间（单位：毫秒）

    for (uint8_t i = 0; i < task_num; i++) 
    {
        if (time_now >= SchedulerTasks[i].time_last + SchedulerTasks[i].time_rate) 
        {
             SchedulerTasks[i].time_last = time_now; // 更新上次执行时间
             SchedulerTasks[i].task_func(); // 执行任务函数
        }
    }
}


/*系统初始化部分*/
#include "system.h"
void system_init(void)
{
    GPIOC->ODR |= 0xff00;
    GPIOD->BSRR |= 0x01<<2;
    GPIOD->BRR |= 0x01<<2;
}

/*LED任务部分*/
#include "led_app.h"
uint8_t led_buf[8]={1,1,0,0,0,0,0,0};
void led_disp(uint8_t *uc_led)
{
    uint8_t temp_now = 0xff;
    uint8_t temp_old = 0x00;

    for(uint8_t i = 0; i < 8; i++) 
        temp_now |= uc_led[i]<<i;


    if(temp_now != temp_old)
    {       
        GPIOC->ODR &= 0x00ff;
        GPIOC->ODR |= ~(temp_now<<8);
        GPIOD->BSRR |= 0x01<<2;
        GPIOD->BRR |= 0x01<<2;

        temp_old = temp_now;
    }
}
void led_task(void)
{
    led_disp(led_buf);
}

/*按键任务部分*/
#include "key_app.h"
uint8_t key_read(void)
{
    uint8_t temp = 0;

    if(HAL_PinRead(GPIOD, GPIO_PIN_2) == GPIO_PIN_RESET) 
        temp = 1;
    else if(HAL_PinRead(GPIOD, GPIO_PIN_3) == GPIO_PIN_RESET) 
        temp = 2;
    else if(HAL_PinRead(GPIOD, GPIO_PIN_4) == GPIO_PIN_RESET) 
        temp = 3;
    else if(HAL_PinRead(GPIOD, GPIO_PIN_5) == GPIO_PIN_RESET) 
        temp = 4;

    return temp;
}
uint8_t key_val,key_old;
uint8_t key_down,key_up;
void key_task(void)
{
    key_val = key_read();
    key_down = (key_val) & (key_old ^ key_val);
    key_up = (~key_val) & (key_old ^ key_val);
    key_old = key_val;


    switch(key_down)
    {
        case 1: 
            led_buf[0] ^= 1;
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


/*LCD任务部分*/
#include "lcd_app.h"
#include "lcd.h"
#include "stdarg.h"
#include "stdio.h"

void lcd_sprintf(uint8_t Line,char *format, ...)
{
    char buf[21];
    va_list arg;
    va_start(arg, format);
    vsnprintf(buf, format, arg);
    va_end(arg);
    LCD_ShowString(Line, (uint8_t *)buf);
}


