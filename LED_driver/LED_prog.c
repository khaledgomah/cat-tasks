#include "errorState.h"
#include "STD_TYPES.h"

#include "LED_conf.h"
#include "LED_priv.h"

#include "DIO_int.h"

ES_t LED_enuInit(LED_T* Copy_pstrucLedConfig) {
	ES_t Local_enuErrorState = ES_NOTOK;
	if (Copy_pstrucLedConfig != NULL) {
		u8 Local_u8Iterator;

		for (Local_u8Iterator = 0; Local_u8Iterator < LED_NUM;
				++Local_u8Iterator) {

			DIO_enuSetPinDirection(
					Copy_pstrucLedConfig[Local_u8Iterator].LED_PortID,
					Copy_pstrucLedConfig[Local_u8Iterator].LED_PinID,
					DIO_u8OUTPUT);
			if (Copy_pstrucLedConfig[Local_u8Iterator].LED_Connection
					== LED_SOURCE) {

				if (Copy_pstrucLedConfig[Local_u8Iterator].LED_InitState
						== LED_ON)

				{
					Local_enuErrorState = DIO_enuSetPintValue(
							Copy_pstrucLedConfig[Local_u8Iterator].LED_PortID,
							Copy_pstrucLedConfig[Local_u8Iterator].LED_PinID,
							DIO_u8HIGH);
				} else if (Copy_pstrucLedConfig[Local_u8Iterator].LED_InitState
						== LED_OFF) {
					Local_enuErrorState = DIO_enuSetPintValue(
							Copy_pstrucLedConfig[Local_u8Iterator].LED_PortID,
							Copy_pstrucLedConfig[Local_u8Iterator].LED_PinID,
							DIO_u8LOW);
				} else {
					return ES_OUT_OF_RANGE;
				}

			} else if (Copy_pstrucLedConfig[Local_u8Iterator].LED_Connection
					== LED_SINK) {
				if (Copy_pstrucLedConfig[Local_u8Iterator].LED_InitState
						== LED_ON)

				{
					Local_enuErrorState = DIO_enuSetPintValue(
							Copy_pstrucLedConfig[Local_u8Iterator].LED_PortID,
							Copy_pstrucLedConfig[Local_u8Iterator].LED_PinID,
							DIO_u8LOW);
				} else if (Copy_pstrucLedConfig[Local_u8Iterator].LED_InitState
						== LED_OFF) {
					Local_enuErrorState = DIO_enuSetPintValue(
							Copy_pstrucLedConfig[Local_u8Iterator].LED_PortID,
							Copy_pstrucLedConfig[Local_u8Iterator].LED_PinID,
							DIO_u8HIGH);
				} else {
					return ES_OUT_OF_RANGE;
				}

			} else {
				return ES_OUT_OF_RANGE;
			}

		}

	} else {
		return ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}

ES_t LED_enuTurnOn(LED_T* Copy_pstrucLedID) {
	ES_t Local_enuErrorState = ES_NOTOK;
	if (Copy_pstrucLedID != NULL) {
		if (Copy_pstrucLedID->LED_Connection == LED_SOURCE) {
			Local_enuErrorState = DIO_enuSetPintValue(
					Copy_pstrucLedID->LED_PortID, Copy_pstrucLedID->LED_PinID,
					DIO_u8HIGH);
		} else if (Copy_pstrucLedID->LED_Connection == LED_SINK) {
			Local_enuErrorState = DIO_enuSetPintValue(
					Copy_pstrucLedID->LED_PortID, Copy_pstrucLedID->LED_PinID,
					DIO_u8LOW);
		} else {
			return ES_OUT_OF_RANGE;
		}

	} else {
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}
ES_t LED_enuTurnOff(LED_T* Copy_pstrucLedID) {
	ES_t Local_enuErrorState = ES_NOTOK;
	if (Copy_pstrucLedID != NULL) {
		if (Copy_pstrucLedID->LED_Connection == LED_SOURCE) {
			Local_enuErrorState = DIO_enuSetPintValue(
					Copy_pstrucLedID->LED_PortID, Copy_pstrucLedID->LED_PinID,
					DIO_u8LOW);
		} else if (Copy_pstrucLedID->LED_Connection == LED_SINK) {
			Local_enuErrorState = DIO_enuSetPintValue(
					Copy_pstrucLedID->LED_PortID, Copy_pstrucLedID->LED_PinID,
					DIO_u8HIGH);
		} else {
			return ES_OUT_OF_RANGE;
		}

	} else {
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}
