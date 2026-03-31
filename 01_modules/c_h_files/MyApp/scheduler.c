#include "scheduler.h"

typedef struct{
    void (*task_function)(void);
    uint32_t time_rate;
    uint32_t time_last;
}TaskT;
TaskT SchedulerTasks[]={
    {led_task,5,0},
    {key_task,10,0},
    {lcd_task,100,0},
    {uart_task,10,0},
};

uint8_t task_num=0;
void scheduler_init(void)
{
    LCD_Init();
    LCD_Clear(Black);
    LCD_SetBackColor(Black);
    LCD_SetTextColor(White);
    
    task_num=sizeof(SchedulerTasks)/sizeof(TaskT);
}
void scheduler_run(void)
{
    uint32_t time_now=HAL_GetTick();
    for(uint8_t i=0;i<task_num;i++)
    {
        if(time_now >= SchedulerTasks[i].time_last + SchedulerTasks[i].time_rate)
        {
            SchedulerTasks[i].time_last = time_now;
            SchedulerTasks[i].task_function();
        }
    }
}
