/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: khaled
 */



#include "STD_TYPES.h"
#include "LCD_driver/LCD_int.h"
#include "ADC_int.h"
int main()
{

	u16 num1,num2;
	LCD_enuInit();
	LCD_enuSendCommand(0x0c);


	while(1)
	{
		ADC_int(ADC_VCC,ADC_PRESCALER_64);
		num1 = ADC_getValue(CHANNEL_6);
		LCD_enuGoToPosition(SECOND_LINE,POSETION_0);
		LCD_enuWriteNumber(num1);
		LCD_enuWriteString("    ");
		num2 = ADC_getValue(CHANNEL_7);
		LCD_enuGoToPosition(FIRST_LINE,POSETION_0);
		LCD_enuWriteNumber(num2);
		LCD_enuWriteString("    ");

	}


}

