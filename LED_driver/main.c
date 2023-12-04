/*
 * main.c
 *
 *  Created on: Dec 4, 2023
 *      Author: khaled
 */

#include "STD_TYPES.h"
#include "errorState.h"

#include "DIO_int.h"
#include "LED_conf.h"
#include "LED_int.h"

#include <util/delay.h>

extern LED_T LED_AStrLedConf[LED_NUM];

int main() {
	DIO_enuInit();
	LED_enuInit(LED_AStrLedConf);
	while (1) {
		LED_enuTurnOn(&LED_AStrLedConf[1]);
		_delay_ms(200);
		LED_enuTurnOff(&LED_AStrLedConf[1]);
		_delay_ms(200);

	}
}
