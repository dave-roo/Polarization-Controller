/*
 * rebtn.h
 *
 *  
 *      
 */

#include "rebtn.h"

double encoderTurn(char channel, double counter)
{

	//Rotary Encoder - Channel A (GPIOA - PINS 4 & 5)
	if( channel == 'A' ){
			if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && counter != 0) //LEFT TURN
			{
				counter = counter - 0.05;
			}
			else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0 && counter != 3) //RIGHT TURN
			{
				counter = counter + 0.05;
			}
	}
	
	
	//Rotary Encoder - Channel B (GPIOA - PINS 1 & 2)
	if( channel == 'B' ){
		
			if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2)==1 && counter != 0) //LEFT TURN
			{
				counter = counter - 0.05;
			}
			else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2)==0 && counter != 3) //RIGHT TURN
			{
				counter = counter + 0.05;
			}
	}
	
	//Rotary Encoder - Channel C (GPIOC - PINS 1 & 2)
	if( channel == 'C' ){
		
			if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)==0 && HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_1)==1 && counter != 0) //LEFT TURN
			{
				counter = counter - 0.05;
			}
			else if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)==0 && HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_1)==0 && counter != 3) //RIGHT TURN
			{
				counter = counter + 0.05;
			}
	}
	
	//Rotary Encoder - Channel D (GPIOC - PINS 14 & 15)
	if( channel == 'D' ){
		
			if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)==0 && HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14)==1 && counter != 0) //LEFT TURN
			{
				counter = counter - 0.05;
			}
			else if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)==0 && HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14)==0 && counter != 3) //RIGHT TURN
			{
				counter = counter + 0.05;
			}
	}
	
	//Upper limit of the voltage
	if(counter > 3){
		counter = 3.0;
	}
	
	//Lower limit of the voltage
	if(counter < 0){
		counter = 0.0;
	}
	
	return counter;
}

