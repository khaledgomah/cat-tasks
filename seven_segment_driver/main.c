/*
 * main.c
 *
 *  Created on: Dec 6, 2023
 *      Author: khaled
 */
#include "STD_TYPES.h"
#include "errorState.h"

#include "DIO_int.h"

#include "seven_segment_int.h"

#include <util/delay.h>

int main(void)

{
	DIO_enuInit();
	seven_segment_enuInit();
	while(1){
		seven_segment_enuEnableCommon();

	if (seven_segment_enuInit() == ES_OK) {
		u8 Local_u8Iterator = 0;

		for (Local_u8Iterator = 0; Local_u8Iterator < 10; ++Local_u8Iterator) {
			 seven_segment_enuDisplayNumber( Local_u8Iterator);
			 _delay_ms(500);
		}
		seven_segment_enuClearDisplay();
		 _delay_ms(500);

	}


	}
}

