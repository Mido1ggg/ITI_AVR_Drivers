/*
 * tiemr.h
 *
 *  Created on: 29/9/2022
 *      Author: Mohamed Samir
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

//#include <avr/io.h>
#include "../../../Common/STD_TYPES.h"
#include "../../../Common/bitMath.h"
#include "../../../Common/definition.h"
#include "Timer1_private.h"
//#include <avr/interrupt.h>

#include "Timer1_Cfg.h"
//#include "../DIO/DIO.h"

void Timer1_init (void);
//void Timer1_Delay(f32 Tdelay);

//void set_soft_PWM_Timer0(channel_type pin);

/*
void Timer1_OVF_setCallbackFunc(void(*Timer1_Fptr)(void));
void Timer1_CTC_OCA_setCallbackFunc(void(*Timer1_A_Fptr)(void));
void Timer1_CTC_OCB_setCallbackFunc(void(*Timer1_B_Fptr)(void));
*/

/*
//Compare Match A
void __vector_7(void)__attribute__((signal));
//Compare Match B
void __vector_8(void)__attribute__((signal));
//Timer 1 OVF
void __vector_9(void)__attribute__((signal));
*/

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
