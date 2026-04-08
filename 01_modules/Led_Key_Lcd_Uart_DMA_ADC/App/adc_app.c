#include "adc_app.h"
uint32_t adc_dma_buf[2][30];
float adc_value[2];

void adc_task(void)
{
    for(uint8_t i=0;i<30;i++)
    {
        adc_value[0] += (float)adc_dma_buf[0][i];
        adc_value[1] += (float)adc_dma_buf[1][i];
    }
    adc_value[0]=adc_value[0]/30 *3.3f/4096;
    adc_value[1]=adc_value[1]/30 *3.3f/4096;
}
