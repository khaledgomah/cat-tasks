/*
 * prog.h
 *
 *  Created on: Feb 2, 2024
 *      Author: khaled
 */

#define INT0					10
#define INT1					20
#define INT2					30

#ifndef EXINT_INT_H_
#define EXINT_INT_H_

void disableGIE(void);
void enableGIE(void);
void enableINT(u8 interruptNum);
void disableINT(u8 interruptNum);
void risingAdge(u8 interruptNum);
void fallingAdge(u8 interruptNum);
void changeLevel(u8 interruptNum);


#endif /* EXINT_INT_H_ */
