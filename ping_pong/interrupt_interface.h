/*
 * interrupt_interface.h
 *
 *  Created on: Feb 2, 2024
 *      Author: khaled
 */

#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_


#define ISR(vector)		void vector (void) __attribute__ ((signal));\
						void vector (void)


#define VECT_INT0				__vector_1
#define VECT_INT1				__vector_2
#define VECT_INT2				__vector_3


#endif /* INTERRUPT_INTERFACE_H_ */
