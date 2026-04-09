#include "rtc_app.h"

RTC_TimeTypeDef time;
RTC_DateTypeDef date;

void rtc_set(RTC_TimeTypeDef *time_set, RTC_DateTypeDef *date_set)
{
    HAL_RTC_SetTime(&hrtc, time_set, RTC_FORMAT_BIN);
    HAL_RTC_SetDate(&hrtc, date_set, RTC_FORMAT_BIN);
}

void rtc_task(void)
{
    HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);
}
