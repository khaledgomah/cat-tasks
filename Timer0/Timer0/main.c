#include "memMap.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "errorState.h"
#include "Timers.h"
#include "LCD_int.h"
#include "EXINT_int.h"
#include <util/delay.h>
void greenOn(void);
void yellowOn(void);
void redOn(void);
void walkOff(void);
void walkOn(void);
void walksteady(void);
void init(void);
static u8 f = 0;
static u8 c = 18;


int main() {
	init();
	TCNT0=255;
	u8 x=0;
	while (1) {
		x++;
		_delay_ms(1000);
		LCD_vidClearScreen();
		LCD_enuWriteNumber(x);
	}
	return 0;
}


ISR(VECT_INT0)
{
	if (f==0)
	{
		c=0;
	}
	else if (f==1)
	{
		
		c=18;
		TCNT0=255;
	}
}


ISR(__vector_11)
{


	 c++;

	 if(c==19)
	 {
		if (f==0)
		{
			greenOn();
			walkOff();
			f=1;
		}
		else if(f==1)
		{
			yellowOn();
			walksteady();
			f=2;
        }
		else if (f==2)
		{
			redOn();
			walkOn();
			f=0;
		}
		c=0;
	 }

}
void greenOn(void)
{
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8HIGH);
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8LOW);
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8LOW);
}
void yellowOn(void)
{
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8LOW);
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8HIGH);
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8LOW);
}
void redOn(void)
{
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8LOW);
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8LOW);
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8HIGH);
}

void walkOff(void)
{
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8HIGH);
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8LOW);
}
void walksteady(void)
{
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8LOW);
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8LOW);
}

void walkOn(void)
{
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8LOW);
	DIO_enuSetPintValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8HIGH);
}

void init(void)
{
		
		sei();
		DIO_enuInit();
		LCD_enuInit();
		TIMER0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_1024);
		TIMER0_OV_InterruptEnable();
		DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN7,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN6,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN4,DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN3,DIO_u8OUTPUT);
		enableINT(INT0);
		risingAdge(INT0);
	}