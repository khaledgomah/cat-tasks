/*
 * DIO_priv.h
 *
 *  Created on: Nov 30, 2023
 *      Author: khaled
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define DIO_MASK_BIT	1

#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7



#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0
#define PULL_UP 1
#define FLOAT 0

#define PORTA_Address	(0x3B)
#define DDRA_Address	(0x3A)
#define PINA_Address	(0x39)

#define PORTB_Address	(0x38)
#define DDRB_Address	(0x37)
#define PINB_Address	(0x36)

#define PORTC_Address	(0x35)
#define DDRC_Address	(0x34)
#define PINC_Address	(0x33)

#define PORTD_Address	(0x32)
#define DDRD_Address	(0x31)
#define PIND_Address	(0x30)

#define PORTA 	*(( u8*)PORTA_Address)
#define DDRA 	*(( u8*)DDRA_Address)
#define PINA 	*((volatile u8*)PINA_Address)

#define PORTB 	*(( u8*)PORTB_Address)
#define DDRB 	*(( u8*)DDRB_Address)
#define PINB 	*((volatile u8*)PINB_Address)

#define PORTC 	*(( u8*)PORTC_Address)
#define DDRC 	*(( u8*)DDRC_Address)
#define PINC 	*((volatile u8*)PINC_Address)

#define PORTD 	*(( u8*)PORTD_Address)
#define DDRD 	*(( u8*)DDRD_Address)
#define PIND 	*((volatile u8*)PIND_Address)

#define CONC_HELP(h7,h6,h5,h4,h3,h2,h1,h0) 0b##h7##h6##h5##h4##h3##h2##h1##h0
#define CONC(h7,h6,h5,h4,h3,h2,h1,h0)		CONC_HELP(h0,h1,h2,h3,h4,h5,h6,h7)

#endif /* DIO_PRIV_H_ */
