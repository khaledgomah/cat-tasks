#include "STD_TYPES.h"
#include "DIO_int.h"
#include "errorState.h"
#include <util/delay.h>

int main() {
	u8 segCthd[] =
	{ 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f }, i,j;
		u8 snack[]={0x01,0x02,0x04,0x08,0x10,0x20};
	DIO_enuInit();

	while (1) {
		for (i=0;i<10;i++)
		{
			DIO_enuSetPortValue(DIO_u8PORTA,segCthd[i]);
			for(j=0;j<10;j++)
			{
				DIO_enuSetPortDirection(DIO_u8PORTD,0xff);
				DIO_enuSetPortValue(DIO_u8PORTD,segCthd[j]);
			_delay_ms(500);
			}
		}

	}
	return 0;
}
