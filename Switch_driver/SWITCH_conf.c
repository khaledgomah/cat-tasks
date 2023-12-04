/*
 * CWITCH_conf.c
 *
 * Created: 12/3/2023 1:44:22 AM 
 *  Author: khaled
 */ 
#include "SWITCH_priv.h"
#include "errorState.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SWITCH_conf.h"
SW_t SW_AstrSwitchState [SW_NUM]={
	{DIO_u8PORTA,DIO_u8PIN0,DIO_u8PULL_UP},
	{DIO_u8PORTA,DIO_u8PIN1,DIO_u8FLOAT},
	{DIO_u8PORTA,DIO_u8PIN2,DIO_u8PULL_UP}
			};
