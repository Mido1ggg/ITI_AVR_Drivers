/*
 * timer_Cfg.h
 *
 *  Created on: ??�/??�/????
 *      Author: batma
 */

#ifndef MCAL_TIMER_TIMER_CFG_H_
#define MCAL_TIMER_TIMER_CFG_H_

#define DISABLE	0
#define ENABLE	1

#define TOGGLE_MODE_OC	0
#define ClEAR_MODE_OC	1
#define SET_MODE_OC		2

#define INVERTING			0
#define NON_INVERTING		1

#define PRESCALER_NO	0
#define PRESCALER_8		8
#define PRESCALER_32	32
#define PRESCALER_64	64
#define PRESCALER_128	128
#define PRESCALER_256	256
#define PRESCALER_1024	1024
#define TIMER_OFF		5

#define TIMER2_TCNT2_TICKS		256
#define TIMER2_NORMAL_MODE		0
#define TIMER2_CTC_MODE			1
#define TIMER2_PWM_FAST_MODE	2
#define TIMER2_PWM_PHASE_MODE	3

#define TIMER2_PRESCALER		 		PRESCALER_8
#define TIMER2_INTERRUPT				DISABLE
#define TIMER2_TCNT_INTERRUPT			DISABLE
#define TIMER2_OCR_INTERRUPT			DISABLE
#define TIMER2_MODE_SELECT				TIMER2_PWM_FAST_MODE
#define TIMER2_PWM_FAST_MODE_SELECT		NON_INVERTING
#define TIMER2_PWM_PHASE_MODE_SELECT	NON_INVERTING
#define TIMER2_CTC_MODE_SELECT 			TOGGLE_MODE_OC



#endif /* MCAL_TIMER_TIMER_CFG_H_ */
