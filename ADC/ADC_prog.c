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

u8 ADC_ref;

void ADC_int(ADC_vref volt,ADC_Prescaler prescaler) {
	ADC_ref=volt;
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

static u16 ADC_read(ADC_Channel channel)
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

u16 ADC_getValue(ADC_Channel channel)
{
	 u16 adc = ADC_read( channel);
	 u16 volt;
	 switch (ADC_ref) {
		case ADC_256:
			  volt = (u32)adc*2560/1024;

			break;
		case ADC_VCC:
			  volt = (u32)adc*5000/1024;

			break;
		case ADC_REF:
			  volt = (u32)adc*5000/1024;
			break;

	}
return volt;
}
