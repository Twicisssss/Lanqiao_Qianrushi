#ifndef __RTC_APP_H__
#define __RTC_APP_H__
#include "bsp_system.h"

void rtc_set(RTC_TimeTypeDef *time_set,RTC_DateTypeDef *date_set);
void rtc_task(void);

#endif
