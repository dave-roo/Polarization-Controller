/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "comlink.h"

// void setVoltage(channel, voltage)
// check connection

//Check the COM port for data
void getCOM(UART_HandleTypeDef huart6, char txData){
	HAL_UART_Transmit(&huart6, (uint8_t *)txData, 10, 10);
}


// getVoltage(channel)
// checkConnection()
// delay()
// local()
// scramble()
// scan()

