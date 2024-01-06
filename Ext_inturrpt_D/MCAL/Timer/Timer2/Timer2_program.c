/*
 * timer.c
 *
 *  Created on: 29/9/2022
 *      Author: Mohamed Samir
 */

#include "Timer2_interface.h"

// PWM Software for any DIO Pin Functions
static void ISR_soft_pwm_OVF(void);
static void ISR_soft_pwm_CTC(void);
static DIO_PinNumber pwm_pin ;
static DIO_GroupNumber pwm_port;

static void(*ISR_Timer2_OVF)(void) = Null;
static void(*ISR_Timer2_CTC)(void) = Null;

void Timer2_voidInit (void)
{

// TIMER 2
#if TIMER2_MODE_SELECT==TIMER2_NORMAL_MODE
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);

#elif TIMER2_MODE_SELECT == TIMER2_PWM_FAST_MODE
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);

	#if TIMER2_PWM_FAST_MODE_SELECT == NON_INVERTING
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#elif TIMER2_PWM_FAST_MODE_SELECT == INVERTING
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#endif


#elif (TIMER2_MODE_SELECT == TIMER2_PWM_PHASE_MODE)
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);

	// NON-INVERTED (01) for INVERTED (11)
	#if TIMER2_PWM_PHASE_MODE_SELECT == NON_INVERTING
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#elif TIMER2_PWM_PHASE_MODE_SELECT == INVERTING
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#endif

#elif (TIMER2_MODE_SELECT == TIMER2_CTC_MODE)
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	#if TIMER2_CTC_MODE_SELECT == TOGGLE_MODE_OC
	SET_BIT(TCCR2,COM20);
	CLR_BIT(TCCR2,COM21);
	#elif TIMER2_CTC_MODE_SELECT == CLEAR_MODE_OC
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#elif TIMER2_CTC_MODE_SELECT == SET_MODE_OC
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);

	// put something in ISR(TIMER2_COMP_vect)
	#endif

#endif

#if	TIMER2_INTERRUPT == ENABLE
	SET_BIT(SREG, 7);

	#if TIMER2_TCNT_INTERRUPT == ENABLE
	SET_BIT(TIMSK, TOIE2);
	#endif

	#if TIMER2_OCR_INTERRUPT == ENABLE
	SET_BIT(TIMSK, OCIE2);
	#endif

#endif

// SETTING the prescaler
#if TIMER2_PRESCALER == PRESCALER_NO
	// set NO prescaler
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_8
	// set prescaler to FCPU/8
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_32
	// set prescaler to FCPU/32
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_64
	// set prescaler to FCPU/64
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_128
	// set prescaler to FCPU/128
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_256
	// set prescaler to FCPU/256
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

#elif TIMER2_PRESCALER == PRESCALER_1024
	// set prescaler to FCPU/1024
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);

#endif


}


// PWM Software for any DIO Pin Functions
void Timer2_voidSetPin_softPWM(DIO_GroupNumber port,DIO_PinNumber pin)
{
	// Initialize DIO Pin
	DIO_ErrStateSetPinDirection(port,pin,DIO_Output);
	// Normal Mode
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2, WGM21);
	//Enable interrupt
	SET_BIT(SREG, 7);
	SET_BIT(TIMSK, TOIE2);
	SET_BIT(TIMSK, OCIE2);
	// 64 prescaler
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);

	pwm_pin = pin;
	pwm_port = port;
	ISR_Timer2_OVF = ISR_soft_pwm_OVF;
	ISR_Timer2_CTC = ISR_soft_pwm_CTC;
}
void Timer2_voidSetDuty_percentage (u8 OcrVal)
{
	OcrVal = ((f32)OcrVal/100)*TIMER2_TCNT2_TICKS;
	OCR2 = OcrVal;
}
void ISR_soft_pwm_OVF(void)
{
	DIO_ErrStateSetPinValue(pwm_port,pwm_pin,DIO_High);

}
void ISR_soft_pwm_CTC(void)
{
	DIO_ErrStateSetPinValue(pwm_port,pwm_pin,DIO_Low);
}

// Fast PWM mode
void Timer2_voidFastPWM_percentage(u8 DutyCycle)
{
#if TIMER2_PWM_FAST_MODE_SELECT == INVERTING
	DutyCycle = (((f32)DutyCycle/100)*TIMER2_TCNT0_TICKS)+TIMER2_TCNT2_TICKS;
	OCR2 = DutyCycle;
#elif TIMER2_PWM_FAST_MODE_SELECT == NON_INVERTING
	DutyCycle = ((f32)DutyCycle/100)*TIMER2_TCNT2_TICKS;
	OCR2 = DutyCycle;
#endif
}

void Timer2_voidDelay_ms(f32 Tdelay)
{
	/*
	 *  1 tick when prescaler is /1024 = 1024/8 = 128us = 0.128ms
	 *  OVF in 8bit timer = 0.128*256 = 32.8ms
	 */
#if (TIMER2_MODE_SELECT == TIMER2_NORMAL_MODE) && (TIMER2_INTERRUPT == DISABLE)
	#if TIMER2_PRESCALER == PRESCALER_8
	f32 OVFtime	= ((f32)PRESCALER_8/F_CPU)*TIMER2_TCNT2_TICKS*1000;
	#endif
	#if TIMER2_PRESCALER == PRESCALER_32
	f32 OVFtime	= ((f32)PRESCALER_32/F_CPU)*TIMER2_TCNT_TICKS*1000;
	#endif
	#if TIMER2_PRESCALER == PRESCALER_64
	f32 OVFtime	= ((f32)PRESCALER_64/F_CPU)*TIMER2_TCNT_TICKS*1000;
	#endif
	#if TIMER2_PRESCALER == PRESCALER_128
	f32 OVFtime	= ((f32)PRESCALER_128/F_CPU)*TIMER2_TCNT_TICKS*1000;
	#endif
	#if TIMER2_PRESCALER == PRESCALER_256
	f32 OVFtime	= ((f32)PRESCALER_256/F_CPU)*TIMER2_TCNT_TICKS*1000;
	#endif
	#if TIMER2_PRESCALER == PRESCALER_1024
	f32 OVFtime	= ((f32)PRESCALER_1024/F_CPU)*TIMER2_TCNT_TICKS*1000;
	#endif
// TIMER 2
if (Tdelay > OVFtime )
	{
		// x = how many times timer will OVF
		f32 i = (f32)Tdelay/OVFtime ;
		u16 x = Tdelay/OVFtime ;
		i = i - x ;
		if (i > 0)
		{
			TCNT2 = 256 - (i*256) ;
		}
		else
		{
			TCNT2 = 0;
		}
		//TCNT0 = 192;
		u16 counter = x+1 ;
		//u16 counter = 3907;
		Timer2_voidInit();

		while (counter)
		{
			while ((GET_BIT(TIFR,TOV2)) == 0);
			SET_BIT(TIFR,TOV2);
			TCNT2 = 0 ;
			counter--;
		}
		TCCR2 = 0;
	}

	if (Tdelay < OVFtime)
	{
		// Putting the delay time in the counter REG
		f32 i = (f32)Tdelay/OVFtime ;
		u16 x = Tdelay/OVFtime ;
		i = i - x ;
		if (i > 0)
		{
			TCNT2 = 256 - (i*256) ;
		}
		else
		{
			TCNT2 = 0;
		}
		Timer2_voidInit();
		while ((GET_BIT(TIFR,TOV2)) == 0);
		SET_BIT(TIFR,TOV2);
		TCNT2 = 0 ;
		TCCR2 = 0;
	}
#endif
}


void Timer2_OVF_setCallbackFunc(void(*Timer2_Fptr)(void))
{
	ISR_Timer2_OVF = Timer2_Fptr ;
}
void Timer2_CTC_setCallbackFunc(void(*Timer2_Fptr)(void))
{
	ISR_Timer2_CTC = Timer2_Fptr ;
}
void __vector_5(void)
{
	if (ISR_Timer2_OVF != Null)
	{
		ISR_Timer2_OVF();
	}
}
void __vector_4(void)
{
	if (ISR_Timer2_CTC != Null)
	{

		ISR_Timer2_CTC();
	}
}


