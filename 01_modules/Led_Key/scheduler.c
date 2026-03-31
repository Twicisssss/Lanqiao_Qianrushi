#include "scheduler.h"

void test_task(void){}

typedef struct {
    void (*task_func)(void);    // 任务函数指针
    uint32_t time_rate;         // 任务执行间隔
    uint32_t time_last;         // 上次执行时间
} Task;
Task SchedulerTasks[]={
    {test_task, 1000, 0}, // 每1000ms执行一次test_task
}
uint8_t task_num = 0;
void scheduler_init(void)
{
    system_init();

    task_num = sizeof(SchedulerTasks) / sizeof(Task);
}

void scheduler_run(void)
{
    uint32_t time_now = HAL_GetTick(); // 获取当前系统时间
    for (uint8_t i = 0; i < task_num; i++) 
    {
        if (time_now >= SchedulerTasks[i].time_last + SchedulerTasks[i].time_rate)
        {
            SchedulerTasks[i].time_last = time_now; // 更新上次执行时间
            SchedulerTasks[i].task_func(); // 执行任务函数
        }
    }
}
