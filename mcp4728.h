/*
 * mcp4728.h
 *
*/

/* 
 uint8_t i2cData[3];

	//0101 is the single write command
	//1??0 Select channel
	//1000 = Channel A (8 in hex)
	//1010 = Channel B (A in hex)
	//1100 = Channel C (C in hex)
	//1110 = Channel D (E in hex)

	i2cData[0] = 0x5E; //2th byte (0x5? (5 is the write command)
	i2cData[1] = 0x00; //3th byte
	i2cData[2] = 0x00; //4th byte
*/
 
#include "main.h"

/************************************** Public functions **************************************/
void updateDAC(I2C_HandleTypeDef hi2c1, char channel, double voltage);
