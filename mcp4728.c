/*
 * mcp4728.c
 *
 */

#include "main.h"
#include "mcp4728.h"

//uint8_t i2cData[3];
uint8_t i2cData[3];
const uint8_t DACaddress = {0xC0};
unsigned char voltageList[40][40] = {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02},
																		 {0x00, 0x28, 0x50, 0x78, 0xA0, 0xC8, 0xF0, 0x18, 0x40, 0x68, 0x90, 0xB8, 0xE0, 0x08, 0x30, 0x58, 0x80, 0xA8}};

void updateDAC(I2C_HandleTypeDef hi2c1, char channel, double voltage)
{
	int hexVolt = voltage/0.05;
	
	i2cData[0] = 0x58; //2th byte (0x5? (5 is the write command))
	i2cData[1] = voltageList[0][hexVolt]; //3th byte
	i2cData[2] = voltageList[1][hexVolt]; //4th byte

	HAL_I2C_Master_Transmit(&hi2c1, 0xC0, i2cData, 3, 10);
	HAL_Delay(30);
	/*
	i2cData[0] = 0x5A; //2th byte (0x5? (5 is the write command)
	HAL_I2C_Master_Transmit(&setup, 0xC0, i2cData, 3, 10);
	i2cData[0] = 0x5C; //2th byte (0x5? (5 is the write command)
	HAL_I2C_Master_Transmit(&setup, 0xC0, i2cData, 3, 10);
	i2cData[0] = 0x5E; //2th byte (0x5? (5 is the write command)
	HAL_I2C_Master_Transmit(&setup, 0xC0, i2cData, 3, 10);
	*/

}

