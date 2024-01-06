/*
 * EXTI0_private.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Abdullah.Abomosallam
 */

#ifndef MCAL_EXTI_EXTI0_EXTI0_PRIVATE_H_
#define MCAL_EXTI_EXTI0_EXTI0_PRIVATE_H_
#include "Ext_Interrupts_Interface.h"
#define MCUCR_REG	*((volatile u8*)0x55)
#define ISC00		0
#define ISC01		1
#define ISC10		2
#define ISC11		3

#define MCUCSR_REG	*((volatile u8*)0x54)
#define ISC2		6

#define GICR_REG	*((volatile u8*)0x5B)
#define INT1		7
#define INT0		6
#define INT2		5

#define GIFR_REG	*((volatile u8*)0x5A)
#define INTF1		7
#define INTF0		6
#define INTF2		5

#define SREG_REG	*((volatile u8*)0x5F)




#define DISABLE 0
#define ENABLE	1

// EXTI USAGE
#define EXTI0_POLLING  	0
#define EXTI0_INTERRUPT 1
#define EXTI1_POLLING  	0
#define EXTI1_INTERRUPT 1
#define EXTI2_POLLING  	0
#define EXTI2_INTERRUPT 1

// Sense MODE
#define LOW_LEVEL_TRIG		0
#define ONCHANGE			1
#define	FALLING_EDGE_TRIG	2
#define	RAISING_EDGE_TRIG	3

typedef enum {
	EXTI0,
	EXTI1,
	EXTI2
}EXT_type;

#endif /* MCAL_EXTI_EXTI0_EXTI0_PRIVATE_H_ */
