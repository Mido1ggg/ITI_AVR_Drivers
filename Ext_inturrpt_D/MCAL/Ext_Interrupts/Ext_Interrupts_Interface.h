/*
 * Ext_Interrupts.h
 *
 *  Created on: 22/9/2022
 *      Author: Mohamed Samir
 */


#ifndef MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_INTERFACE_H_
#define MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_INTERFACE_H_

#include "Ext_Interrupts_Cfg.h"
#include "../../Common/bitMath.h"
#include "../../Common/STD_TYPES.h"
#include "../../Common/definition.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "EXTI_private.h"


 void EXTI_init();
 void EXTI_Enable(EXT_type interrupt);
 void EXTI_Disable(EXT_type interrupt);

#if EXTI0_USAGE == EXTI0_POLLING

 u8 EXTI0_u8Checkflag(void);
 void EXTI0_voidClearFlag(void);

#endif

#if EXTI1_USAGE == EXTI1_POLLING

 u8 EXTI1_u8Checkflag(void);
 void EXTI1_voidClearFlag(void);

#endif

#if EXTI2_USAGE == EXTI2_POLLING

 u8 EXTI2_u8Checkflag(void);
 void EXTI2_voidClearFlag(void);

#endif

#if EXTI0_USAGE == EXTI0_INTERRUPT
 //CallBack Functions
 void setCallback_INT0(void (*Fptr)());
 void setCallback_INT1(void (*Fptr)());
 void setCallback_INT2(void (*Fptr)());

 void __vector_1(void)__attribute__((signal));
 void __vector_2(void)__attribute__((signal));
 void __vector_3(void)__attribute__((signal));
#endif
#endif /* MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_INTERFACE_H_ */
