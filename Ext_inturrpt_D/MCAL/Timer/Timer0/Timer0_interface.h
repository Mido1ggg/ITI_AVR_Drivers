/*
 * tiemr.h
 *
 *  Created on: 4/4/2023
 *      Author: Mohamed Samir
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

#include "../../../Common/STD_TYPES.h"
#include "../../../Common/bitMath.h"
#include "../../../Common/definition.h"
#include "../../../MCAL/DIO/DIO_Interface.h"
#include "Timer0_private.h"
#include "Timer0_Cfg.h"


void Timer0_voidInit (void);
void Timer0_voidDelay_ms(f32 Tdelay);

void Timer0_voidSetPin_softPWM(DIO_GroupNumber port,DIO_PinNumber pin);
void Timer0_voidSetDuty_percentage (u8 OcrVal,DIO_GroupNumber port,DIO_PinNumber pin);

void Timer0_voidFastPWM_percentage(u8 DutyCycle);

void Timer0_voidInterruptDisable(void);
void Timer0_voidInterruptEnable(void);
void Timer0_OVF_setCallbackFunc(void(*Timer0_Fptr)(void));
void Timer0_CTC_setCallbackFunc(void(*Timer0_Fptr)(void));

void __vector_11(void)__attribute__((signal));
void __vector_10(void)__attribute__((signal));


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
