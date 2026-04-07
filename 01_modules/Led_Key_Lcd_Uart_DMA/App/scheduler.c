#include "scheduler.h"
typedef struct{
    void (*task_func)(void);
    uint32_t time_rate;
    uint32_t time_last;
}Task;
Task SchedulerTasks[]={
  {led_task,10,0},  
  {key_task,20,0},  
  {lcd_task,50,0},  
  {uart_task,50,0},  
};

uint8_t task_num=0;
void scheduler_init(void)
{
    system_init();
    LCD_Init();
    LCD_Clear(Black);
    LCD_SetTextColor(White);
    LCD_SetBackColor(Black);
    
    
    task_num=sizeof(SchedulerTasks)/sizeof(Task);
}
void scheduler_run(void)
{
    uint32_t time_now=HAL_GetTick();
    for(uint8_t i=0;i<task_num;i++)
    {
        if(time_now >= SchedulerTasks[i].time_rate + SchedulerTasks[i].time_last)
        {
            SchedulerTasks[i].time_last = time_now;
            SchedulerTasks[i].task_func();
        }
    }
}


