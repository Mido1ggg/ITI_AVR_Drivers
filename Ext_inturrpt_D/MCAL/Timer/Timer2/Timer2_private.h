/*
 * Timer_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define TCCR2	(*(volatile u8*)0x45)
#define FOC2	7
#define WGM20 	6
#define COM21 	5
#define COM20 	4
#define WGM21 	3
#define CS22 	2
#define CS21 	1
#define CS20	0

#define	TCNT2	(*(volatile u8*)0x44)
#define OCR2	(*(volatile u8*)0x43)

#define TIMSK	(*(volatile u8*)0x59)
#define OCIE2	7
#define TOIE2 	6

#define TIFR	(*(volatile u8*)0x58)
#define TOV2	6
#define OCF2	7

#define SREG	(*(volatile u8*)0x5F)


#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
