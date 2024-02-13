/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: khaled
 */



#include "STD_TYPES.h"
#include "LCD_driver/LCD_int.h"
#include "ADC_int.h"
#include "HAL/ML35/ML35_int.h"

void print_temp();

int main()
{
	ADC_int(ADC_VCC,ADC_PRESCALER_64);
	LCD_enuInit();
	LCD_enuSendCommand(0x0c);
	LCD_enuGoToPosition(FIRST_LINE,POSETION_3);
	LCD_enuWriteString("Temperature");
	while(1)
	{

		LCD_enuGoToPosition(SECOND_LINE,POSETION_6);
		print_temp();
	}


}

void print_temp() {
	u8 temp = LM_read();
	LCD_enuWriteNumber(temp);
	LCD_enuWriteString("C   ");
}
