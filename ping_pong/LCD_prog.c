
#include "errorState.h"
#include "STD_TYPES.h"
#include "DIO_int.h"

#include "LCD_priv.h"
#include "LCD_config.h"

#include <util/delay.h>

static u8 LCD_u8PosCounter = 0;

ES_t LCD_enuInit(void) {
	ES_t Local_enuErrorState = ES_NOTOK;

	Local_enuErrorState = DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	Local_enuErrorState = DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	_delay_ms(35);

#if LCD_MODE == EIGHT_BIT
	Local_enuErrorState = DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = LCD_inlenuSendCommand(0x38);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	_delay_ms(1);

#elif LCD_MODE == FOUR_BIT
	/* Function Set */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_4Bit_TwoLine_5_7CharFont);
	if(Local_enuErrorState != ES_OK)
	return Local_enuErrorState;
	_delay_ms(1);

#else
#error "wrong configuration of LCD mode!!"
#endif

	/* Display ON/OFF Control */
	Local_enuErrorState = LCD_inlenuSendCommand(0x0F);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	_delay_ms(1);

	/* Display Clear */
	Local_enuErrorState = LCD_inlenuSendCommand(0x01);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	_delay_ms(2);

	/* Entry Mode Set */
	Local_enuErrorState = LCD_inlenuSendCommand(0x06);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	_delay_ms(1);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t LCD_enuDisplayChar(u8 Copy_u8Data) {
	ES_t Local_enuErrorState = ES_NOTOK;

	LCD_vidCheckPosition();

	Local_enuErrorState = DIO_enuSetPintValue(RS_PORT, RS_PIN, DIO_u8HIGH);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = LCD_enuLatch(Copy_u8Data);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Command) {
	ES_t Local_enuErrorState = ES_NOTOK;

	/* RS --> LOW to write Command */
	Local_enuErrorState = DIO_enuSetPintValue(RS_PORT, RS_PIN, DIO_u8LOW);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	/* Call Latch Function */
	Local_enuErrorState = LCD_enuLatch(Copy_u8Command);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

static ES_t LCD_enuLatch(u8 Copy_u8Data) {
	ES_t Local_enuErrorState = ES_NOTOK;

	Local_enuErrorState = DIO_enuSetPintValue(RW_PORT, RW_PIN, DIO_u8LOW);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(EN_PORT, EN_PIN, DIO_u8LOW);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

#if LCD_MODE == EIGHT_BIT
	Local_enuErrorState = DIO_enuSetPintValue(D7_PORT, D7_PIN,
			((Copy_u8Data >> 7) & MASK_BIT));
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D6_PORT, D6_PIN,
			((Copy_u8Data >> 6) & MASK_BIT));
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D5_PORT, D5_PIN,
			((Copy_u8Data >> 5) & MASK_BIT));
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D4_PORT, D4_PIN,
			((Copy_u8Data >> 4) & MASK_BIT));
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D3_PORT, D3_PIN,
			((Copy_u8Data >> 3) & MASK_BIT));
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D2_PORT, D2_PIN,
			((Copy_u8Data >> 2) & MASK_BIT));
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D1_PORT, D1_PIN,
			((Copy_u8Data >> 1) & MASK_BIT));
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D0_PORT, D0_PIN,
			((Copy_u8Data >> 0) & MASK_BIT));
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

#elif LCD_MODE == FOUR_BIT
	u8 Local_u8FourBitData = 0;

	Local_u8FourBitData = (Copy_u8Data & 0xF0);
	Local_enuErrorState = DIO_enuSetPintValue(D7_PORT, D7_PIN, ((Local_u8FourBitData >> D7_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
	return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D6_PORT, D6_PIN, ((Local_u8FourBitData >> D6_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
	return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D5_PORT, D5_PIN, ((Local_u8FourBitData >> D5_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
	return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D4_PORT, D4_PIN, ((Local_u8FourBitData >> D4_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
	return Local_enuErrorState;

	LCD_vidTrigger_LATCH();
	_delay_ms(1);

	/* Send Data from D3..D0 */
	Local_u8FourBitData = (Copy_u8Data << FOUR_BIT);
	Local_enuErrorState = DIO_enuSetPintValue(D7_PORT, D7_PIN, ((Local_u8FourBitData >> D7_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
	return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D6_PORT, D6_PIN, ((Local_u8FourBitData >> D6_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
	return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D5_PORT, D5_PIN, ((Local_u8FourBitData >> D5_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
	return Local_enuErrorState;

	Local_enuErrorState = DIO_enuSetPintValue(D4_PORT, D4_PIN, ((Local_u8FourBitData >> D4_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
	return Local_enuErrorState;

#else
#error "wrong configuration of LCD mode!!"
#endif

	LCD_vidTrigger_LATCH();

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

static void LCD_vidTrigger_LATCH(void) {
	/* Enable EN --> it works at Rising Edge */
	DIO_enuSetPintValue(EN_PORT, EN_PIN, DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPintValue(EN_PORT, EN_PIN, DIO_u8LOW);
}

static inline ES_t LCD_inlenuSendCommand(u8 Copy_u8Command) {
	ES_t Local_enuErrorState = ES_NOTOK;

	/* RS --> LOW to write Command */
	Local_enuErrorState = DIO_enuSetPintValue(RS_PORT, RS_PIN, DIO_u8LOW);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	/* Call Latch Function */
	Local_enuErrorState = LCD_enuLatch(Copy_u8Command);
	if (Local_enuErrorState != ES_OK)
		return Local_enuErrorState;

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t LCD_enuGoToPosition(u8 Copy_u8Line, u8 Copy_u8Position) {
	ES_t Local_enuErrorState = ES_NOTOK;

	if (Copy_u8Position < 16) {
		if (Copy_u8Line == FIRST_LINE ) {
			Local_enuErrorState = ES_OK;
			Local_enuErrorState = LCD_inlenuSendCommand(
					START_OF_FIRST_LINE + Copy_u8Position);

			LCD_u8PosCounter = Copy_u8Position;
		} else if (Copy_u8Line == SECOND_LINE) {
			Local_enuErrorState = ES_OK;
			Local_enuErrorState = LCD_inlenuSendCommand(
					START_OF_SECOND_LINE + Copy_u8Position);
			LCD_u8PosCounter = Copy_u8Position + 16;
		}
	}

	return Local_enuErrorState;
}

static void LCD_vidCheckPosition(void) {
	if (LCD_u8PosCounter == 16) {
		LCD_enuGoToPosition(SECOND_LINE, 0);
		LCD_u8PosCounter++;
	} else if (LCD_u8PosCounter == 32) {
		LCD_inlenuSendCommand(0x01);
		LCD_enuGoToPosition(FIRST_LINE, 0);
		LCD_u8PosCounter = 0;
	} else {
		LCD_u8PosCounter++;
	}
}

void LCD_vidClearScreen(void) {
	LCD_inlenuSendCommand(0x01);
	LCD_u8PosCounter = 0;
}

ES_t LCD_enuWriteString(u8 *Copy_pu8Str) {
	ES_t Local_enuErrorState = ES_NOTOK;

	if (Copy_pu8Str != NULL) {
		while (*Copy_pu8Str != '\0') {
			Local_enuErrorState = LCD_enuDisplayChar(*Copy_pu8Str);
			if (Local_enuErrorState != ES_OK)
				return Local_enuErrorState;
			Copy_pu8Str++;
		}
		Local_enuErrorState = ES_OK;
	} else {
		return ES_NULL_POINTER;
	}

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t LCD_enuWriteNumber(int Copy_s32Number) {
	ES_t Local_enuErrorState = ES_NOTOK;
	u8 Local_As8Container[16];
	u8 Local_u8Iterator;

	sprintf(Local_As8Container, "%d", Copy_s32Number);

	for (Local_u8Iterator = 0; Local_As8Container[Local_u8Iterator] != '\0';
			Local_u8Iterator++) {
		Local_enuErrorState = LCD_enuDisplayChar(
				Local_As8Container[Local_u8Iterator]);
	}

	return Local_enuErrorState;
}
