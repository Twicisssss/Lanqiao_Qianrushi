#include "scheduler.h"

typedef struct{
    void (*task_function)(void);
    uint32_t time_rate;
    uint32_t time_last;
}TaskT;
TaskT SchedulerTasks[]={
    {led_task,10,0},
    {key_task,20,0},
    {lcd_task,50,0},
    {uart_task,100,0},
    {adc_task,120,0},
    {rtc_task,120,0},
};

uint8_t task_num=0;
void scheduler_init(void)
{
    LCD_Init();
    LCD_Clear(Black);
    LCD_SetBackColor(Black);
    LCD_SetTextColor(White);
    
    HAL_ADC_Start_DMA(&hadc1,(uint32_t *)&adc_dma_buf[0][0],30);
    HAL_ADC_Start_DMA(&hadc2,(uint32_t *)&adc_dma_buf[1][0],30);
    
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
