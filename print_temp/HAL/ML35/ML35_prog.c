/*
 * ML35_prog.c
 *
 *  Created on: Feb 13, 2024
 *      Author: khaled
 */
#include "STD_TYPES.h"
#include "../../ADC_int.h"

#include "ML35_int.h"

u8 LM_read(void)
{
	u16 volt = ADC_getValue(LM35_CHANNEL);
	u8 temp =  volt/10;

	return temp;
}
