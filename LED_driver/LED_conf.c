/*
 * LED_conf.c
 *
 *  Created on: Dec 4, 2023
 *      Author: khaled
 */
#include "errorState.h"
#include "STD_TYPES.h"

#include "LED_priv.h"
#include "LED_conf.h"
#include "DIO_int.h"

LED_T LED_AStrLedConf[LED_NUM] = {
		{ DIO_u8PORTA, DIO_u8PIN0, LED_SINK, LED_ON, }, { DIO_u8PORTA,
				DIO_u8PIN1, LED_SOURCE, LED_OFF, } };

