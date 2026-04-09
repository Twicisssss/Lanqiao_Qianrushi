#ifndef __I2C_HAL_H
#define __I2C_HAL_H
#include "bsp_system.h"
#include "stm32g4xx_hal.h"

void I2CStart(void);
void I2CStop(void);
unsigned char I2CWaitAck(void);
void I2CSendAck(void);
void I2CSendNotAck(void);
void I2CSendByte(unsigned char cSendByte);
unsigned char I2CReceiveByte(void);
void I2CInit(void);

void mcp4017_write(uint8_t data);
void mcp4017_read(uint8_t *data);
void at24c02_write(uint8_t *String,uint8_t addr,uint8_t num);
void at24c02_read(uint8_t *String,uint8_t addr,uint8_t num);



#endif
