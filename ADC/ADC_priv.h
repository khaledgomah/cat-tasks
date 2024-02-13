/*
 * ADC_priv.h
 *
 *  Created on: Feb 12, 2024
 *      Author: khaled
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_



// Voltage Reference Selections for ADC
#define ADMUX				*((volatile u8*)0x27)
#define REFS0				6
#define REFS1				7
//ADC Left Adjust Result
#define ADLAR				5

//ADC Control and Status Register A
#define ADCSRA			*((volatile u8*)0x26)
// ADC Enable
#define ADEN			7
// ADC Start Conversion
#define ADSC			6
//ADC Prescaler Select Bits
#define ADPS0			0
#define ADPS1			1
#define ADPS2			2

//ADC read
#define ADC		*((volatile u16*)0x24)

#endif /* ADC_PRIV_H_ */
