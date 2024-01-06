/*
 * timer.c
 *
 *  Created on: 29/9/2022
 *      Author: Mohamed Samir
 */

#include "Timer1_interface.h"


//u8 pwm_pin ;
/*
static void(*ISR_Timer1_OVF)(void) = Null;
static void(*ISR_Timer1_CTC_A)(void) = Null;
static void(*ISR_Timer1_CTC_B)(void) = Null;
*/

void Timer1_init (void)
{

// TIMER 1
#if TIMER1_MODE_SELECT==TIME1_NORMAL_MODE
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	//TCNT1 = 0x00 ;

#endif
#if (TIMER1_MODE_SELECT == TIMER1_PWM_FAST_OCA_MODE)

	#if (TIMER1_FAST_PWM_MODE_SELECT == NON_INVERTING)
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#endif

	#if	(TIMER1_PWM_FAST_A_MODE_TOP_SELECT == TOP_ICR)
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	#endif

#endif

#if (TIMER1_MODE_SELECT == TIMER1_PWM_FAST_OCB_MODE)
	#if (TIMER1_FAST_PWM_MODE_SELECT == NON_INVERTING)
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#endif
	#if	(TIMER1_PWM_FAST_A_MODE_TOP_SELECT == TOP_ICR)
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	#endif
#endif

// SETTING the prescaler
#if TIMER1_PRESCALER == PRESCALER_NO
	// set NO prescaler
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_8
	// set prescaler to FCPU/8
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_64
	// set prescaler to FCPU/64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_256
	// set prescaler to FCPU/256
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);

#elif TIMER1_PRESCALER == PRESCALER_1024
	// set prescaler to FCPU/1024
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);

#endif


}


/*void set_soft_PWM_Timer0(channel_type pin)
{
	// Normal Mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0, WGM01);
	//Enable interrupt
	SET_BIT(TIMSK, TOIE0);
	SET_BIT(TIMSK, OCIE0);
	// 64 prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

	pwm_pin = pin;
}*/

// timer delay in milli sec
//void Timer0_Delay(f32 Tdelay)
//{
//
//	/*
//	 *  1 tick when prescaler is /1024 = 1024/8 = 128us = 0.128ms
//	 *  OVF in 8bit timer = 0.128*256 = 32.8ms
//	 */
//
//#if (TIMER0_MODE_SELECT == TIMER0_NORMAL_MODE) && (TIMER0_INTERRUPT == DISABLE)
//	#if TIMER0_PRESCALER == PRESCALER_8
//	f32 OVFtime	= ((f32)PRESCALER_8/F_CPU)*TIMER0_TCNT_TICKS*1000;
//	#endif
//	#if TIMER0_PRESCALER == PRESCALER_64
//	f32 OVFtime	= ((f32)PRESCALER_64/F_CPU)*TIMER0_TCNT_TICKS*1000;
//	#endif
//	#if TIMER0_PRESCALER == PRESCALER_256
//	f32 OVFtime	= ((f32)PRESCALER_256/F_CPU)*TIMER0_TCNT_TICKS*1000;
//	#endif
//	#if TIMER0_PRESCALER == PRESCALER_1024
//	f32 OVFtime	= ((f32)PRESCALER_1024/F_CPU)*TIMER0_TCNT_TICKS*1000;
//	#endif
//
//// TIMER 0
//	if (Tdelay > OVFtime )
//	{
//		// x = how many times timer will OVF
//		f32 i = (f32)Tdelay/OVFtime ;
//		u16 x = Tdelay/OVFtime ;
//		i = i - x ;
//		if (i > 0)
//		{
//			TCNT0 = 256 - (i*256) ;
//		}
//		else
//		{
//			TCNT0 = 0;
//		}
//		//TCNT0 = 192;
//		u16 counter = x+1 ;
//		//u16 counter = 3907;
//		Timer_init();
//
//		while (counter)
//		{
//			while ((GET_BIT(TIFR,TOV0)) == 0);
//			SET_BIT(TIFR,TOV0);
//			TCNT0 = 0 ;
//			counter--;
//		}
//		TCCR0 = 0;
//	}
//
//	if (Tdelay < OVFtime)
//	{
//		// Putting the delay time in the counter REG
//		f32 i = (f32)Tdelay/OVFtime ;
//		u16 x = Tdelay/OVFtime ;
//		i = i - x ;
//		if (i > 0)
//		{
//			TCNT0 = 256 - (i*256) ;
//		}
//		else
//		{
//			TCNT0 = 0;
//		}
//		Timer_init();
//		while ((GET_BIT(TIFR,TOV0)) == 0);
//		SET_BIT(TIFR,TOV0);
//		TCNT0 = 0 ;
//		TCCR0 = 0;
//	}
//
//#endif
//
//}


//void Timer1_OVF_setCallbackFunc(void(*Timer1_Fptr)(void))
//{
//	ISR_Timer1_OVF = Timer1_Fptr ;
//}
//void Timer1_CTC_OCA_setCallbackFunc(void(*Timer1_A_Fptr)(void))
//{
//	ISR_Timer1_CTC_A = Timer1_A_Fptr ;
//}
//void Timer1_CTC_OCB_setCallbackFunc(void(*Timer1_B_Fptr)(void))
//{
//	ISR_Timer1_CTC_B = Timer1_B_Fptr ;
//}
//void __vector_9(void)
//{
//	if (ISR_Timer1_OVF != Null)
//	{
//		ISR_Timer1_OVF();
//	}
//}
//void __vector_7(void)
//{
//	if (ISR_Timer1_CTC_A != Null)
//	{
//
//		ISR_Timer1_CTC_A();
//	}
//}
//void __vector_8(void)
//{
//	if (ISR_Timer1_CTC_B != Null)
//	{
//
//		ISR_Timer1_CTC_B();
//	}
//}


