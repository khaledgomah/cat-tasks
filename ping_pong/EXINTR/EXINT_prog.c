/*
 * prog.c
 *
 *  Created on: Feb 2, 2024
 *      Author: khaled
 */
#include  "../STD_TYPES.h"

#include  "EXINT_priv.h"


void disableGIE(void)
{
	SREG &=~(HIGH<<SREG_INT);//clear bit
}

void enableGIE(void)
{
	SREG |=(HIGH<<SREG_INT);//set bit
}


void risingAdge(u8 interruptNum)
{
	if (interruptNum == INT0)
	{
		MCUCR |=(HIGH<<MCUCR_ISC00);
		MCUCR |=(HIGH<<MCUCR_ISC01);
	}
	else if(interruptNum == INT1)
	{
		MCUCR |=(HIGH<<MCUCR_ISC10);
		MCUCR |=(HIGH<<MCUCR_ISC11);
	}
	else if(interruptNum == INT2)
	{
		MCUCSR |=(HIGH<<MCUCSR_ISC2);
	}
}

void changeLevel(u8 interruptNum)
{
	if (interruptNum == INT0)
	{
		MCUCR |=(HIGH<<MCUCR_ISC00);
		MCUCR &=~(HIGH<<MCUCR_ISC01);
	}
	else if(interruptNum == INT1)
	{
		MCUCR |=(HIGH<<MCUCR_ISC10);
		MCUCR &=~(HIGH<<MCUCR_ISC11);
	}

}
void fallingAdge(u8 interruptNum)
{
	if (interruptNum == INT0)
		{
			MCUCR &=~(HIGH<<MCUCR_ISC00);
			MCUCR |=(HIGH<<MCUCR_ISC01);
		}
		else if(interruptNum == INT1)
		{
			MCUCR &=~(HIGH<<MCUCR_ISC10);
			MCUCR |=(HIGH<<MCUCR_ISC11);
		}
		else if(interruptNum == INT2)
		{
			MCUCSR &=~(HIGH<<MCUCSR_ISC2);
		}
}

void enableINT(u8 interruptNum)
{
	//set bit
	switch (interruptNum) {
		case INT0:
			GICR |=(HIGH<<GICR_INT0);

			break;
		case INT1:
			GICR |=(HIGH<<GICR_INT1);

			break;
		case INT2:
			GICR |=(HIGH<<GICR_INT2);

			break;
		default:
			break;
	}
}
void disableINT(u8 interruptNum)
{
	//clear bit
	switch (interruptNum) {
		case INT0:
			GICR &=~(HIGH<<GICR_INT0);

			break;
		case INT1:
			GICR &=~(HIGH<<GICR_INT1);

			break;
		case INT2:
			GICR &=~(HIGH<<GICR_INT2);

			break;
		default:
			break;
	}
}
