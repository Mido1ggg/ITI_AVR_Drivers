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
#include "Timer2_private.h"
#include "Timer2_Cfg.h"

void Timer2_voidInit (void);
void Timer2_voidDelay_ms(f32 Tdelay);

void Timer2_voidSetPin_softPWM(DIO_GroupNumber port,DIO_PinNumber pin);
void Timer2_voidSetDuty_percentage (u8 OcrVal);

void Timer2_voidFastPWM_percentage(u8 DutyCycle);

void Timer2_OVF_setCallbackFunc(void(*Timer0_Fptr)(void));
void Timer2_CTC_setCallbackFunc(void(*Timer0_Fptr)(void));

void __vector_4(void)__attribute__((signal));
void __vector_5(void)__attribute__((signal));


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
