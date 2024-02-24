
#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#include <stdio.h>
#include <stdlib.h>

#define EIGHT_BIT			1
#define FOUR_BIT			0
#define MASK_BIT			1
#define CLEAR				0x01

#define POSETION_0		0
#define POSETION_1		1
#define POSETION_2		2
#define POSETION_3		3
#define POSETION_4		4
#define POSETION_5		5
#define POSETION_6		6
#define POSETION_7		7
#define POSETION_8		8
#define POSETION_9		9
#define POSETION_10		10
#define POSETION_11		11
#define POSETION_12		12
#define POSETION_13		13
#define POSETION_14		14
#define POSETION_15		15

static inline ES_t LCD_inlenuSendCommand(u8 Copy_u8Command);
static void LCD_vidTrigger_LATCH(void);
static ES_t LCD_enuLatch(u8 Copy_u8Data);
static void LCD_vidCheckPosition(void);


#define FIRST_LINE								1
#define SECOND_LINE								2

#define START_OF_FIRST_LINE						0x80
#define START_OF_SECOND_LINE					0xC0


#endif /* LCD_PRIV_H_ */
