#include "scheduler.h"
typedef struct{
    void (*task_func)(void);
    uint32_t time_rate;
    uint32_t time_last;
}Task;
Task SchedulerTasks[]={
    {led_task,1,0},
    {key_task,10,0},
    {lcd_task,100,0},
    {uart_task,10,0},
    {adc_task,20,0},
    {rtc_task,10,0},
    {ic_task,50,0},
};

uint8_t task_num=0;
void scheduler_init(void)
{
    task_num = sizeof(SchedulerTasks) / sizeof(Task);

    I2CInit();
    lcd_init();
    adc_init();
    pwm_init();
    ic_init();
}
void scheduler_run(void)
{
    uint32_t time_now = HAL_GetTick();
    for(uint8_t i=0;i<task_num;i++)
    {
        if(time_now >= SchedulerTasks[i].time_rate + SchedulerTasks[i].time_last)
        {
            SchedulerTasks[i].time_last = time_now;
            SchedulerTasks[i].task_func();
        }
    }
}
