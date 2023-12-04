
#include "STD_TYPES.h"
#include "errorState.h"
#include "SWITCH_conf.h"
#include "SWITCH_priv.h"
#include "DIO_int.h"
ES_t Switch_enuInit(SW_t* Copy_AStrSwitchs){
	ES_t Local_enuErrorState=ES_NOTOK;
	if (Copy_AStrSwitchs!=NULL)
	{
		u8 Local_u8Itrator;
		for(Local_u8Itrator=0;Local_u8Itrator<SW_NUM;Local_u8Itrator++){
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_AStrSwitchs[Local_u8Itrator].SW_PortID,Copy_AStrSwitchs[Local_u8Itrator].SW_PinID,DIO_u8INPUT);
			Local_enuErrorState = DIO_enuSetPintValue(Copy_AStrSwitchs[Local_u8Itrator].SW_PortID,Copy_AStrSwitchs[Local_u8Itrator].SW_PinID,Copy_AStrSwitchs[Local_u8Itrator].SW_State);
		}

	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;

}
ES_t Switch_enuGetState(SW_t* Copy_AStrSwitchs,u8* Copy_pu8SwState){
	ES_t Local_enuErrorState=ES_NOTOK;
	if (Copy_AStrSwitchs!=NULL&&Copy_pu8SwState!=NULL)
	{
		Local_enuErrorState = DIO_enuGetPinValue(Copy_AStrSwitchs->SW_PortID,Copy_AStrSwitchs->SW_PinID,Copy_pu8SwState);
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}
return Local_enuErrorState;
}

