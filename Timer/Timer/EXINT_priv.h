/*
 * EXINT_priv.h
 *
 *  Created on: Feb 2, 2024
 *      Author: khaled
 */


#ifndef EXINT_PRIV_H_
#define EXINT_PRIV_H_

#define HIGH					1
#define LOW						0



//Interrupts numbers
#define INT0					10
#define INT1					20
#define INT2					30

//select sense level for interrupts 0 and 1
#define MCUCR				*((volatile u8*)0x55)
//INTERRUPT 0
#define MCUCR_ISC00				0
#define MCUCR_ISC01				1
//INTERRUPT 1
#define MCUCR_ISC10				2
#define MCUCR_ISC11				3


//select sense level for interrupt 2
#define MCUCSR				*((volatile u8*)0x54)
#define MCUCSR_ISC2				6


//control PIE
#define GICR				*((volatile u8*)0x5B)
#define GICR_INT2				5	// External Interrupt Request 2 Enable
#define GICR_INT0				6	// External Interrupt Request 0 Enable
#define GICR_INT1				7	// External Interrupt Request 1 Enable


//global interrupt enable
#define SREG					*((volatile u8*)0x5f)
#define SREG_INT				7	//high to enable GIE and low to disable


//General Interrupt Flag Register
#define GIFR					*((volatile u8*)0x5A)
#define GIFR_INTF0				6	// External Interrupt Flag 0
#define GIFR_INTF1				7	// External Interrupt Flag 1
#define GIFR_INTF2				5	// External Interrupt Flag 2

#endif /* EXINT_PRIV_H_ */
