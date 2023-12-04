/*
 * SWITCH.c
 *
 * Created: 12/3/2023 1:38:07 AM
 * Author : khaled
 */ 

#include <avr/io.h>
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SWITCH_conf.h"
#include "SWITCH_int.h"
#include "errorState.h"
extern SW_t SW_AstrSwitchState [SW_NUM];
int main(void)
{
	DIO_enuInit();
	Switch_enuInit(SW_AstrSwitchState);
	u8 pinState ;
    while (1) 
    {
    	Switch_enuGetState(&SW_AstrSwitchState[1],&pinState);
    	if(pinState==DIO_u8LOW)
    	{
    		DIO_enuSetPintValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8HIGH);
    	}
    	else
    	{
    		DIO_enuSetPintValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8LOW);
    	}
    }
}

