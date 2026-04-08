#include "key_app.h"
uint8_t key_read(void)
{
    uint8_t temp=0;

    if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==GPIO_PIN_RESET)
        temp=1;
    else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)==GPIO_PIN_RESET)
        temp=2;
    else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2)==GPIO_PIN_RESET)
        temp=3;
    else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==GPIO_PIN_RESET)
        temp=4;

    return temp;
}



uint8_t key_val,key_old;
uint8_t key_down,key_up;
void key_task(void)
{
    key_val=key_read();
    key_down = key_val&(key_old^key_val);
    key_up = ~key_val&(key_old^key_val);
    key_old=key_val;

    switch(key_down)
    {
        case 1:
            led_buf[0] ^=1;
        break;
        case 2:
            printf("\r\n=== AT24C02 Write Test ===\r\n");
            printf("addr:0x00  data:");
            for(uint8_t i=0; i<5; i++)
                printf("0x%02X ", at_test_write_data[i]);
            at24c02_write(at_test_write_data, 0x00, 5);
            printf("\r\nWrite completed!\r\n");
        break;
        case 3:
            printf("\r\n=== AT24C02 Read Test ===\r\n");
            memset(at_test_read_data, 0, sizeof(at_test_read_data));
            at24c02_read(at_test_read_data, 0x00, 5);
            printf("addr:0x00  data:");
            for(int i=0; i<5; i++)
                printf("0x%02X ", at_test_read_data[i]);
            printf("\r\n");

            // 验证数据
            if(memcmp(at_test_write_data, at_test_read_data, 5) == 0)
                printf("AT24C02 Test PASSED!\r\n");
            else
                printf("AT24C02 Test FAILED!\r\n");
        break;
        case 4:
            printf("\r\n=== MCP4017 Test ===\r\n");
            mcp4017_value += 16;// 每次增加16 (0-127)
            if(mcp4017_value > 127)
                mcp4017_value = 0;
            printf("Setting wiper value: %d (0x%02X)\r\n", mcp4017_value, mcp4017_value);
            mcp4017_write(mcp4017_value);
            
            // 验证读取
            uint8_t read_value;
            mcp4017_read(&read_value);
            printf("Read back value: %d (0x%02X)\r\n", read_value, read_value);
            
            if(mcp4017_value == read_value)
                printf("MCP4017 Test PASSED!\r\n");
            else
                printf("MCP4017 Test FAILED! (Expected:%d, Got:%d)\r\n", mcp4017_value, read_value);
        break;
    }
}


