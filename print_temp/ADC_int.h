/*
 * ADC_int.h
 *
 *  Created on: Feb 12, 2024
 *      Author: khaled
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

typedef enum {
	ADC_REF, ADC_VCC, ADC_256
} ADC_vref;

typedef enum  {
    ADC_PRESCALER_2 = 1,
    ADC_PRESCALER_4,
    ADC_PRESCALER_8,
    ADC_PRESCALER_16,
    ADC_PRESCALER_32,
    ADC_PRESCALER_64,
    ADC_PRESCALER_128,
   }ADC_Prescaler;

  typedef enum  {
       CHANNEL_0 = 0,
       CHANNEL_1,
       CHANNEL_2,
       CHANNEL_3,
       CHANNEL_4,
       CHANNEL_5,
       CHANNEL_6,
       CHANNEL_7
   }ADC_Channel;
void ADC_int(ADC_vref volt,ADC_Prescaler prescaler);

u16 ADC_getValue(ADC_Channel channel);

#endif /* ADC_INT_H_ */
