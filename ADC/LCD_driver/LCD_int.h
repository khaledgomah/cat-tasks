
#include "STD_TYPES.h"
#include "errorState.h"

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define POSETION_0		0
#define POSETION_1		1
#define POSETION_2		2
#define POSETION_3		3
#define POSETION_4		4
#define POSETION_5		5
#define POSETION_6		6
#define POSETION_7		7

#define FIRST_LINE								1
#define SECOND_LINE								2

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuGoToPosition(u8 Copy_u8Line, u8 Copy_u8Position);

ES_t LCD_enuWriteString(u8 *Copy_pu8Str);

ES_t LCD_enuWriteNumber(int Copy_s32Number);

void LCD_vidClearScreen(void);


#endif /* LCD_INT_H_ */
