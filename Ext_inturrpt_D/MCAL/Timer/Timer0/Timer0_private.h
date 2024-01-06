/*
 * Timer_private.h
 *
 *  Created on: 4/4/2023
 *      Author: Mohamed Samir
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define TCCR0	(*(volatile u8*)0x53)
#define FOC0	7
#define WGM00 	6
#define COM01 	5
#define COM00 	4
#define WGM01 	3
#define CS02 	2
#define CS01 	1
#define CS00	0

#define	TCNT0	(*(volatile u8*)0x52)
#define OCR0	(*(volatile u8*)0x5C)

#define TIMSK	(*(volatile u8*)0x59)
#define OCIE0 	1
#define TOIE0	0

#define TIFR	(*(volatile u8*)0x58)
#define TOV0	0
#define OCF0	1

#define SREG	(*(volatile u8*)0x5F)


#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
