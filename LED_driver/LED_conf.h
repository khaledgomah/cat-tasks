/*
 * LED_conf.h
 *
 *  Created on: Dec 4, 2023
 *      Author: khaled
 */

#ifndef LED_CONF_H_
#define LED_CONF_H_

#define LED_NUM  2

typedef struct{
	u8 LED_PortID;
	u8 LED_PinID;
	u8 LED_Connection;
	u8 LED_InitState;
}LED_T;



#endif /* LED_CONF_H_ */
