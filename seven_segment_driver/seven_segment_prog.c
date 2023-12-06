/*
 * seven_segment_prog.c
 *
 *  Created on: Dec 5, 2023
 *      Author: khaled
 */
#include "STD_TYPES.h"
#include "errorState.h"

#include "seven_segment_config.h"
#include "seven_segment_priv.h"

#include "DIO_int.h"

ES_t seven_segment_enuInit(void) {
	ES_t Local_enuErrorState = ES_NOTOK;
	u32 Local_u32CheckError = 0;
	Local_u32CheckError |= ((u32)DIO_enuSetPinDirection(SEG_APORT, SEG_APIN,
	DIO_u8OUTPUT) << ERROR_BIT_NUM * 0);
	Local_u32CheckError |= ((u32)DIO_enuSetPinDirection(SEG_BPORT, SEG_BPIN,
	DIO_u8OUTPUT) << ERROR_BIT_NUM * 1);
	Local_u32CheckError |= ((u32)DIO_enuSetPinDirection(SEG_CPORT, SEG_CPIN,
	DIO_u8OUTPUT) << ERROR_BIT_NUM * 2);
	Local_u32CheckError |= ((u32)DIO_enuSetPinDirection(SEG_DPORT, SEG_DPIN,
	DIO_u8OUTPUT) << ERROR_BIT_NUM * 3);
	Local_u32CheckError |= ((u32)DIO_enuSetPinDirection(SEG_EPORT, SEG_EPIN,
	DIO_u8OUTPUT) << ERROR_BIT_NUM * 4);
	Local_u32CheckError |= ((u32)DIO_enuSetPinDirection(SEG_FPORT, SEG_FPIN,
	DIO_u8OUTPUT) << ERROR_BIT_NUM * 5);
	Local_u32CheckError |= ((u32)DIO_enuSetPinDirection(SEG_GPORT, SEG_GPIN,
	DIO_u8OUTPUT) << ERROR_BIT_NUM * 6);

	u8 Local_u8Iterator = 0;
	for (Local_u8Iterator = 0; Local_u8Iterator <  LED_NUM; ++Local_u8Iterator) {
		u8 Local_u8Error=((Local_u32CheckError >> ( ERROR_BIT_NUM * Local_u8Iterator))) & ERROR_BIT_ONES ;
		if( Local_u8Error != ES_OK) {
			return Local_enuErrorState;

		}
	}
	Local_enuErrorState = ES_OK;

#if  SEG_CMNPIN <=DIO_u8PIN7 && SEG_CMNPORT<= DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_CMNPORT, SEG_CMNPIN, DIO_u8OUTPUT);
#elif SEG_CMNPIN == NOT_CONNECTED  &&  SEG_CMNPORT== NOT_CONNECTED

#else
#error"select a valid pin to COMMON "
#endif

#if  SEG_DOTPIN <=DIO_u8PIN7 && SEG_DOTPORT<= DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_DOTPORT,SEG_DOTPIN,DIO_u8OUTPUT);
#elif SEG_DOTPIN==NOT_CONNECTED&&SEG_DOTPORT==NOT_CONNECTED

#else
#error"select a valid pin to DOT "
#endif

	return Local_enuErrorState;
}

ES_t seven_segment_enuEnableCommon(void) {

	ES_t Local_enuErrorstate = ES_NOTOK;
#if SEG_TYPE == SEG_CMN_CATHODE
	Local_enuErrorstate = DIO_enuSetPintValue(SEG_CMNPORT, SEG_CMNPIN,
			DIO_u8LOW);
#elif SEG_TYPE ==SEG_CMN_ANODE
	Local_enuErrorstate = DIO_enuSetPintValue(SEG_CMNPORT, SEG_CMNPIN,
	DIO_u8HIGH);
#else
#error "enter a valid type"
#endif
	return Local_enuErrorstate;
}

ES_t seven_segment_enuDisableCommon(void){

	ES_t Local_enuErrorstate = ES_NOTOK;
#if SEG_TYPE ==SEG_CMN_CATHODE
	Local_enuErrorstate = DIO_enuSetPintValue(SEG_CMNPORT, SEG_CMNPIN,
			DIO_u8HIGH);
#elif SEG_TYPE ==SEG_CMN_ANODE
	Local_enuErrorstate = DIO_enuSetPintValue(SEG_CMNPORT, SEG_CMNPIN,
	DIO_u8LOW);
#else
#error "enter a valid type"
#endif

	return Local_enuErrorstate;
}

ES_t seven_segment_enuEnableDot(void) {

	ES_t Local_enuErrorstate = ES_NOTOK;
#if SEG_TYPE ==SEG_CMN_CATHODE
	Local_enuErrorstate = DIO_enuSetPintValue(SEG_CMNPORT, SEG_CMNPIN,
			DIO_u8HIGH);
#elif SEG_TYPE ==SEG_CMN_ANODE
	Local_enuErrorstate = DIO_enuSetPintValue(SEG_CMNPORT, SEG_CMNPIN,
	DIO_u8LOW);
#else
#error "enter a valid type"
#endif
	return Local_enuErrorstate;
}

ES_t seven_segment_enuDisableDot(void) {

	ES_t Local_enuErrorstate = ES_NOTOK;
#if SEG_TYPE ==SEG_CMN_CATHODE
	Local_enuErrorstate = DIO_enuSetPintValue(SEG_CMNPORT, SEG_CMNPIN,
			DIO_u8LOW);
#elif SEG_TYPE ==SEG_CMN_ANODE
	Local_enuErrorstate = DIO_enuSetPintValue(SEG_CMNPORT, SEG_CMNPIN,
	DIO_u8HIGH);
#else
#error "enter a valid type"
#endif
	return Local_enuErrorstate;
}

ES_t seven_segment_enuDisplayNumber(u8 Copy_u8Num) {
	ES_t Local_enuErrorState = ES_NOTOK;
	u32 Local_u32CheckError = 0;
	if (Copy_u8Num < 10) {
#if SEG_TYPE == SEG_CMN_CATHODE
		Local_u32CheckError |=
		((u32)DIO_enuSetPintValue(SEG_APORT, SEG_APIN,
						((SEG_Au8NumDesplay[Copy_u8Num] >> 0) & 1))
				<< ERROR_BIT_NUM * 0);
		Local_u32CheckError |=
		((u32)DIO_enuSetPintValue(SEG_BPORT, SEG_BPIN,
						((SEG_Au8NumDesplay[Copy_u8Num] >> 1) & 1))
				<< ERROR_BIT_NUM * 1);
		Local_u32CheckError |=
		((u32)DIO_enuSetPintValue(SEG_CPORT, SEG_CPIN,
						((SEG_Au8NumDesplay[Copy_u8Num] >> 2) & 1))
				<< ERROR_BIT_NUM * 2);
		Local_u32CheckError |=
		((u32)DIO_enuSetPintValue(SEG_DPORT, SEG_DPIN,
						((SEG_Au8NumDesplay[Copy_u8Num] >> 3) & 1))
				<< ERROR_BIT_NUM * 3);
		Local_u32CheckError |=
		((u32)DIO_enuSetPintValue(SEG_EPORT, SEG_EPIN,
						((SEG_Au8NumDesplay[Copy_u8Num] >> 4) & 1))
				<< ERROR_BIT_NUM * 4);
		Local_u32CheckError |=
		((u32)DIO_enuSetPintValue(SEG_FPORT, SEG_FPIN,
						((SEG_Au8NumDesplay[Copy_u8Num] >> 5) & 1))
				<< ERROR_BIT_NUM * 5);
		Local_u32CheckError |=
		((u32)DIO_enuSetPintValue(SEG_GPORT, SEG_GPIN,
						((SEG_Au8NumDesplay[Copy_u8Num] >> 6) & 1))
				<< ERROR_BIT_NUM * 6);

#elif SEG_TYPE == SEG_CMN_ANODE
		Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_APORT, SEG_APIN,
				!((SEG_Au8NumDesplay[Copy_u8Num] >> 0) & 1))
				<< ERROR_BIT_NUM * 0);
		Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_BPORT, SEG_BPIN,
				!((SEG_Au8NumDesplay[Copy_u8Num] >> 1) & 1))
				<< ERROR_BIT_NUM * 1);
		Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_CPORT, SEG_CPIN,
				!((SEG_Au8NumDesplay[Copy_u8Num] >> 2) & 1))
				<< ERROR_BIT_NUM * 2);
		Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_DPORT, SEG_DPIN,
				!((SEG_Au8NumDesplay[Copy_u8Num] >> 3) & 1))
				<< ERROR_BIT_NUM * 3);
		Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_EPORT, SEG_EPIN,
				!((SEG_Au8NumDesplay[Copy_u8Num] >> 4) & 1))
				<< ERROR_BIT_NUM * 4);
		Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_FPORT, SEG_FPIN,
				!((SEG_Au8NumDesplay[Copy_u8Num] >> 5) & 1))
				<< ERROR_BIT_NUM * 5);
		Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_GPORT, SEG_GPIN,
				!((SEG_Au8NumDesplay[Copy_u8Num] >> 6) & 1))
				<< ERROR_BIT_NUM * 6);
#endif
	} else {
		Local_enuErrorState = ES_OUT_OF_RANGE;
		return Local_enuErrorState;
	}

	u8 Local_u8Iterator = 0;
	for (Local_u8Iterator = 0; Local_u8Iterator < ERROR_BIT_NUM * LED_NUM;
			++Local_u8Iterator) {
		u8 Local_u8Error=((Local_u32CheckError >> ( ERROR_BIT_NUM * Local_u8Iterator))) & ERROR_BIT_ONES ;

		if (Local_u8Error != ES_OK) {
			return Local_enuErrorState;

		}
	}
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;

}

ES_t seven_segment_enuClearDisplay(void) {

	ES_t Local_enuErrorState = ES_NOTOK;
	u32 Local_u32CheckError = 0;
#if SEG_TYPE ==SEG_CMN_CATHODE
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_APORT, SEG_APIN, DIO_u8LOW)<< ERROR_BIT_NUM * 0);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_BPORT, SEG_BPIN, DIO_u8LOW)<< ERROR_BIT_NUM * 1);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_CPORT, SEG_CPIN, DIO_u8LOW)<< ERROR_BIT_NUM * 2);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_DPORT, SEG_DPIN, DIO_u8LOW)<< ERROR_BIT_NUM * 3);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_EPORT, SEG_EPIN, DIO_u8LOW)<< ERROR_BIT_NUM * 4);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_FPORT, SEG_FPIN, DIO_u8LOW)<< ERROR_BIT_NUM * 5);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_GPORT, SEG_GPIN, DIO_u8LOW)<< ERROR_BIT_NUM * 6);
#elif SEG_TYPE ==SEG_CMN_ANODE
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_APORT, SEG_APIN, DIO_u8HIGH)<< ERROR_BIT_NUM * 0);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_BPORT, SEG_BPIN, DIO_u8HIGH)<< ERROR_BIT_NUM * 1);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_CPORT, SEG_CPIN, DIO_u8HIGH)<< ERROR_BIT_NUM * 2);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_DPORT, SEG_DPIN, DIO_u8HIGH)<< ERROR_BIT_NUM * 3);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_EPORT, SEG_EPIN, DIO_u8HIGH)<< ERROR_BIT_NUM * 4);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_FPORT, SEG_FPIN, DIO_u8HIGH)<< ERROR_BIT_NUM * 5);
	Local_u32CheckError |= ((u32)DIO_enuSetPintValue(SEG_GPORT, SEG_GPIN, DIO_u8HIGH)<< ERROR_BIT_NUM * 6);
#endif
	u8 Local_u8Iterator = 0;
	for (Local_u8Iterator = 0; Local_u8Iterator < ERROR_BIT_NUM * LED_NUM;
			++Local_u8Iterator) {
		u8 Local_u8Error=((Local_u32CheckError >> ( ERROR_BIT_NUM * Local_u8Iterator))) & ERROR_BIT_ONES ;
		if (Local_u8Error != ES_OK) {
			return Local_enuErrorState;

		}
	}
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

