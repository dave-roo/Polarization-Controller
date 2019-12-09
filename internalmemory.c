/*
 * internalmemory.c
 *
 */
#include "main.h"
#include "internalmemory.h"

void save(int location, memoryLocation mem, Lcd_HandleTypeDef lcd, counterChannel cntChannel)
{
	 
};

void load(Lcd_HandleTypeDef * lcd, memoryLocation mem)
{
		Lcd_write_voltage(lcd, 'A', mem->channelA);
		Lcd_write_voltage(lcd, 'B', mem->channelB);
		Lcd_write_voltage(lcd, 'C', mem->channelC);
		Lcd_write_voltage(lcd, 'D', mem->channelD);
};

void refresh(int location, counterChannel cntChannel, Lcd_HandleTypeDef lcd)
{	
		char changeLcd[20];

		Lcd_cursor(&lcd, 0,18);
		Lcd_string(&lcd, "  ");
		HAL_Delay(100);
		Lcd_cursor(&lcd,location,0);
		sprintf(changeLcd, "%c %.2f ", cntChannel[location].channel, cntChannel[location].counterUpdate);
		Lcd_string(&lcd, changeLcd);
		

};

void select(int location, memoryLocation mem, Lcd_HandleTypeDef lcd)
{
		char changeLcd[20];
	
		Lcd_cursor(&lcd, 0,18);
		sprintf(changeLcd, "P%d", location);
		Lcd_string(&lcd, changeLcd);
		HAL_Delay(100);
	
		Lcd_cursor(&lcd, 0,0);
		sprintf(changeLcd, "A %.2f ", mem[location].channelA);
		Lcd_string(&lcd, changeLcd);
		HAL_Delay(100);

		Lcd_cursor(&lcd, 1,0);
		sprintf(changeLcd, "B %.2f ", mem[location].channelB);
		Lcd_string(&lcd, changeLcd);
		HAL_Delay(100);
	
		Lcd_cursor(&lcd, 2,0);
		sprintf(changeLcd, "C %.2f ", mem[location].channelC);
		Lcd_string(&lcd, changeLcd);
		HAL_Delay(100);
	
		Lcd_cursor(&lcd, 3,0);
		sprintf(changeLcd, "D %.2f ", mem[location].channelD);
		Lcd_string(&lcd, changeLcd);
		HAL_Delay(100);
};
