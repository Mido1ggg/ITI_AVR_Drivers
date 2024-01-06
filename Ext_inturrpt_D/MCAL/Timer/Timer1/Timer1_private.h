/*
 * Timer_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define TCCR1A	(*(volatile u8*)0x4f)
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

#define TCCR1B	(*(volatile u8*)0x4e)
#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define TCNT1	(*(volatile u8*)0x4c)
#define OCR1A	(*(volatile u8*)0x4A)
#define OCR1B	(*(volatile u8*)0x48)
#define ICR1	(*(volatile u8*)0x46)

#define TIMSK	(*(volatile u8*)0x59)
#define TICIE1 	5
#define OCIE1A 	4
#define OCIE1B 	3
#define TOIE1 	2

#define TIFR	(*(volatile u8*)0x58)
#define ICF1 	5
#define OCF1A 	4
#define OCF1B 	3
#define TOV1 	2


#define SREG	(*(volatile u8*)0x5F)
#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
