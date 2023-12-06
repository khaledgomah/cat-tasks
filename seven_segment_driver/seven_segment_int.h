/*
 * seven_segment_int.h
 *
 *  Created on: Dec 4, 2023
 *      Author: khaled
 */

#ifndef SEVEN_SEGMENT_INT_H_
#define SEVEN_SEGMENT_INT_H_

ES_t seven_segment_enuInit(void);

ES_t seven_segment_enuEnableCommon(void);

ES_t seven_segment_enuEnableDot(void);

ES_t seven_segment_enuDisableCommon(void);

ES_t seven_segment_enuDisableDot(void);

ES_t seven_segment_enuDisplayNumber( u8 Copy_u8Num);

ES_t seven_segment_enuClearDisplay(void);





#endif /* SEVEN_SEGMENT_INT_H_ */
