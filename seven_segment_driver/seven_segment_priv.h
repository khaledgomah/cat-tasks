/*
 * seven_segment_priv.h
 *
 *  Created on: Dec 5, 2023
 *      Author: khaled
 */

#ifndef SEVEN_SEGMENT_PRIV_H_
#define SEVEN_SEGMENT_PRIV_H_

#define SEG_CMN_ANODE		0
#define SEG_CMN_CATHODE		1

#define NOT_CONNECTED		10


#define ERROR_BIT_NUM		3

#define ERROR_BIT_ONES		7

#define LED_NUM				7

u8 SEG_Au8NumDesplay[] ={ 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
#endif /* SEVEN_SEGMENT_PRIV_H_ */
