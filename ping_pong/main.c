/*
 * main.c
 *
 *  Created on: Feb 2, 2024
 *      Author: khaled
 */
#include "errorState.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "EXINTR/EXINT_int.h"
#include "interrupt_interface.h"
#include <util/delay.h>

u8 player1=FIRST_LINE,player2=FIRST_LINE,currentLine;
u16 delay=200;

int main (void)
{
	u8 flag=0;
	DIO_enuInit();
	LCD_enuInit();

	enableGIE();

	enableINT(INT0);
	changeLevel(INT0);

	enableINT(INT1);
	changeLevel(INT1);

	LCD_enuSendCommand(0x0c);
	while (1)
	{

		for(u8 counter = 1;counter<15;counter++)
		{
			if (flag == 0)
			{
				flag = 1;
				_delay_ms(1000);

			}
			disableGIE();
			currentLine=FIRST_LINE;
			LCD_enuGoToPosition(currentLine,counter);
			LCD_enuDisplayChar('O');
			enableGIE();
			_delay_ms(delay);
			disableGIE();
			LCD_enuGoToPosition(currentLine,counter);
			LCD_enuDisplayChar(' ');
			currentLine=SECOND_LINE;
			counter++;
			LCD_enuGoToPosition(currentLine,counter);
			LCD_enuDisplayChar('O');
			enableGIE();
			_delay_ms(delay);
			disableGIE();
			LCD_enuGoToPosition(currentLine,counter);
			LCD_enuDisplayChar(' ');

			if(counter==14)
			{
				if (currentLine!=player2)
				{
					LCD_vidClearScreen();
					LCD_enuGoToPosition(FIRST_LINE,2);
					LCD_enuWriteString("player 1 win");
					while(1);
				}
			}
		}

for(u8 counter = 14 ;counter > 1 ;counter--)
{
	disableGIE();
	currentLine= FIRST_LINE;
		LCD_enuGoToPosition(currentLine,counter);
		LCD_enuDisplayChar('O');
		enableGIE();
		_delay_ms(delay);
		disableGIE();
		LCD_enuGoToPosition(currentLine,counter);
		LCD_enuDisplayChar(' ');
		currentLine=SECOND_LINE;
		counter--;
		LCD_enuGoToPosition(currentLine,counter);
		LCD_enuDisplayChar('O');
		enableGIE();
		_delay_ms(delay);
		disableGIE();
		LCD_enuGoToPosition(currentLine,counter);
		LCD_enuDisplayChar(' ');
		if(counter==1)
		{
			if (currentLine!=player1)
			{
				LCD_vidClearScreen();
				LCD_enuGoToPosition(FIRST_LINE,2);
				LCD_enuWriteString("player 2 win");
				while(1);
			}
		}
}

for(u8 counter = 1;counter < 15;counter++)
{
	disableGIE();
	currentLine=SECOND_LINE;
	LCD_enuGoToPosition(currentLine,counter);
	LCD_enuDisplayChar('O');
	enableGIE();
	_delay_ms(delay);
	disableGIE();
	LCD_enuGoToPosition(currentLine,counter);
	LCD_enuDisplayChar(' ');
	counter++;
	currentLine=FIRST_LINE;
	LCD_enuGoToPosition(currentLine,counter);
	LCD_enuDisplayChar('O');
	enableGIE();
	_delay_ms(delay);
	disableGIE();
	LCD_enuGoToPosition(currentLine,counter);
	LCD_enuDisplayChar(' ');

	if(counter==14)
	{
		if (currentLine!=player2)
		{
			LCD_vidClearScreen();
			LCD_enuGoToPosition(FIRST_LINE,2);
			LCD_enuWriteString("player 1 win");
			while(1);
		}
	}
}
for(u8 counter = 14 ;counter > 1 ;counter--)
{
	disableGIE();
	currentLine=SECOND_LINE;
		LCD_enuGoToPosition(currentLine,counter);
		LCD_enuDisplayChar('O');
		enableGIE();
		_delay_ms(delay);
		disableGIE();
		LCD_enuGoToPosition(currentLine,counter);
		LCD_enuDisplayChar(' ');
		counter--;
		currentLine=FIRST_LINE;
		LCD_enuGoToPosition(currentLine,counter);
		LCD_enuDisplayChar('O');
		enableGIE();
		_delay_ms(delay);
		disableGIE();
		LCD_enuGoToPosition(currentLine,counter);
		LCD_enuDisplayChar(' ');
		if(counter==1)
		{
			if (currentLine!=player1)
			{
				LCD_vidClearScreen();
				LCD_enuGoToPosition(FIRST_LINE,2);
				LCD_enuWriteString("player 2 win");
				while(1);
			}
		}

}




	}


	return 0;
}

ISR(VECT_INT0)
{
	//player 1 = 1 in the second line and = 0 in the first line
	if(player1==FIRST_LINE)
	{
		LCD_enuGoToPosition(FIRST_LINE,0);
			LCD_enuDisplayChar(' ');
			LCD_enuGoToPosition(SECOND_LINE,0);
			LCD_enuDisplayChar('|');
			player1 = SECOND_LINE;
	}
	else if(player1==SECOND_LINE)
	{
		LCD_enuGoToPosition(FIRST_LINE,0);
			LCD_enuDisplayChar('|');
			LCD_enuGoToPosition(SECOND_LINE,0);
			LCD_enuDisplayChar(' ');
			player1=FIRST_LINE;
	}
}

ISR(VECT_INT1)
{

	if(player2==FIRST_LINE)
	{
			LCD_enuGoToPosition(FIRST_LINE,15);
			LCD_enuDisplayChar(' ');
			LCD_enuGoToPosition(SECOND_LINE,15);
			LCD_enuDisplayChar('|');
			player2=SECOND_LINE;
	}
	else if(player2==SECOND_LINE)
	{
			LCD_enuGoToPosition(FIRST_LINE,15);
			LCD_enuDisplayChar('|');
			LCD_enuGoToPosition(SECOND_LINE,15);
			LCD_enuDisplayChar(' ');
			player2=FIRST_LINE;
	}
}
