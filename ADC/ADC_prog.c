/*
 * ADC.c
 *
 *  Created on: Feb 12, 2024
 *      Author: khaled
 */

#include  "STD_TYPES.h"
#include  "ADC_priv.h"
#include  "ADC_int.h"
#include "BIT_MATH.h"
#include <util/delay.h>

void ADC_int(ADC_vref volt,ADC_Prescaler prescaler) {

	//prescaler
	ADCSRA&=0xf8;
	ADCSRA|=prescaler;
	//vref
	switch (volt) {
	case ADC_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	case ADC_REF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
	case ADC_VCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
	}
	//enable ADC
	SET_BIT(ADCSRA,ADEN);

}

u16 ADC_read(ADC_Channel channel)
{
	//select channel
	ADMUX&=0xe0;
	ADMUX|=channel;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	CLR_BIT(ADMUX,ADLAR);
	//busy wait
_delay_ms(100);
return ADC;
}

