/*
 * timer.c
 *
 *  Created on: 4/4/2023
 *      Author: Mohamed Samir
 */

#include "Timer0_interface.h"

// PWM Software for any DIO Pin Functions
static void ISR_soft_pwm_OVF(void);
static void ISR_soft_pwm_CTC(void);
static DIO_PinNumber pwm_pin ;
static DIO_GroupNumber pwm_port;

static void(*ISR_Timer0_OVF)(void) = Null;
static void(*ISR_Timer0_CTC)(void) = Null;

void Timer0_voidInit (void)
{
// TIMER 0
#if TIMER0_MODE_SELECT==TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

#elif TIMER0_MODE_SELECT == TIMER0_PWM_FAST_MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	#if TIMER0_PWM_FAST_MODE_SELECT == NON_INVERTING
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#elif TIMER0_PWM_FAST_MODE_SELECT == INVERTING
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#endif


#elif (TIMER0_MODE_SELECT == TIMER0_PWM_PHASE_MODE)
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

	// NON-INVERTED (01) for INVERTED (11)
	#if TIMER0_PWM_PHASE_MODE_SELECT == NON_INVERTING
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#elif TIMER0_PWM_PHASE_MODE_SELECT == INVERTING
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#endif

#elif (TIMER0_MODE_SELECT == TIMER0_CTC_MODE)
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#if TIMER0_CTC_MODE_SELECT == TOGGLE_MODE_OC
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
	#elif TIMER0_CTC_MODE_SELECT == CLEAR_MODE_OC
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#elif TIMER0_CTC_MODE_SELECT == SET_MODE_OC
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);

	// put something in ISR(TIMER0_COMP_vect)
	#endif

#endif

#if	TIMER0_INTERRUPT == ENABLE
	SET_BIT(SREG, 7);

	#if TIMER0_TCNT_INTERRUPT == ENABLE
	SET_BIT(TIMSK, TOIE0);
	#endif

	#if TIMER0_OCR_INTERRUPT == ENABLE
	SET_BIT(TIMSK, OCIE0);
	#endif

#endif


// SETTING the prescaler
#if TIMER0_PRESCALER == PRESCALER_NO
	// set NO prescaler
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_8
	// set prescaler to FCPU/8
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_64
	// set prescaler to FCPU/64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_256
	// set prescaler to FCPU/256
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

#elif TIMER0_PRESCALER == PRESCALER_1024
	// set prescaler to FCPU/1024
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

#endif

}

void Timer0_voidInterruptDisable(void)
{
	CLR_BIT(TIMSK, TOIE0);
	CLR_BIT(TIMSK, OCIE0);

}
void Timer0_voidInterruptEnable(void)
{
#if	TIMER0_INTERRUPT == ENABLE
	SET_BIT(SREG, 7);

	#if TIMER0_TCNT_INTERRUPT == ENABLE
	SET_BIT(TIMSK, TOIE0);
	#endif

	#if TIMER0_OCR_INTERRUPT == ENABLE
	SET_BIT(TIMSK, OCIE0);
	#endif

#endif
}

// PWM Software for any DIO Pin Functions
void Timer0_voidSetPin_softPWM(DIO_GroupNumber port,DIO_PinNumber pin)
{
	// Initialize DIO Pin
	DIO_ErrStateSetPinDirection(port,pin,DIO_Output);
	// Normal Mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0, WGM01);
	//Enable interrupt
	SET_BIT(SREG, 7);
	SET_BIT(TIMSK, TOIE0);
	SET_BIT(TIMSK, OCIE0);
	// 64 prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);


	ISR_Timer0_OVF = ISR_soft_pwm_OVF;
	ISR_Timer0_CTC = ISR_soft_pwm_CTC;
}
void Timer0_voidSetDuty_percentage (u8 OcrVal,DIO_GroupNumber port,DIO_PinNumber pin)
{
	pwm_pin = pin;
	pwm_port = port;
	OcrVal = ((f32)OcrVal/100)*TIMER0_TCNT0_TICKS;
	OCR0 = OcrVal;
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
void Timer0_voidFastPWM_percentage(u8 DutyCycle)
{
#if TIMER0_PWM_FAST_MODE_SELECT == INVERTING
	DutyCycle = (((f32)DutyCycle/100)*TIMER0_TCNT0_TICKS)+TIMER0_TCNT0_TICKS;
	OCR0 = DutyCycle;
#elif TIMER0_PWM_FAST_MODE_SELECT == NON_INVERTING
	DutyCycle = ((f32)DutyCycle/100)*TIMER0_TCNT0_TICKS;
	OCR0 = DutyCycle;
#endif
}

// Timer Delay in milli sec using Polling
void Timer0_voidDelay_ms(f32 Tdelay)
{

	/*
	 *  1 tick when prescaler is /1024 = 1024/8 = 128us = 0.128ms
	 *  OVF in 8bit timer = 0.128*256 = 32.8ms
	 */
#if (TIMER0_MODE_SELECT == TIMER0_NORMAL_MODE) && (TIMER0_INTERRUPT == DISABLE)
	#if TIMER0_PRESCALER == PRESCALER_8
	f32 OVFtime	= ((f32)PRESCALER_8/F_CPU)*TIMER0_TCNT_TICKS*1000;
	#endif
	#if TIMER0_PRESCALER == PRESCALER_64
	f32 OVFtime	= ((f32)PRESCALER_64/F_CPU)*TIMER0_TCNT_TICKS*1000;
	#endif
	#if TIMER0_PRESCALER == PRESCALER_256
	f32 OVFtime	= ((f32)PRESCALER_256/F_CPU)*TIMER0_TCNT_TICKS*1000;
	#endif
	#if TIMER0_PRESCALER == PRESCALER_1024
	f32 OVFtime	= ((f32)PRESCALER_1024/F_CPU)*TIMER0_TCNT_TICKS*1000;
	#endif

// TIMER 0
	if (Tdelay > OVFtime )
	{
		// x = how many times timer will OVF
		f32 i = (f32)Tdelay/OVFtime ;
		u16 x = Tdelay/OVFtime ;
		i = i - x ;
		if (i > 0)
		{
			TCNT0 = 256 - (i*256) ;
		}
		else
		{
			TCNT0 = 0;
		}
		//TCNT0 = 192;
		u16 counter = x+1 ;
		//u16 counter = 3907;
		Timer_init();

		while (counter)
		{
			while ((GET_BIT(TIFR,TOV0)) == 0);
			SET_BIT(TIFR,TOV0);
			TCNT0 = 0 ;
			counter--;
		}
		TCCR0 = 0;
	}

	if (Tdelay < OVFtime)
	{
		// Putting the delay time in the counter REG
		f32 i = (f32)Tdelay/OVFtime ;
		u16 x = Tdelay/OVFtime ;
		i = i - x ;
		if (i > 0)
		{
			TCNT0 = 256 - (i*256) ;
		}
		else
		{
			TCNT0 = 0;
		}
		Timer_init();
		while ((GET_BIT(TIFR,TOV0)) == 0);
		SET_BIT(TIFR,TOV0);
		TCNT0 = 0 ;
		TCCR0 = 0;
	}

	/*if (Tdelay == OVFtime)
	{
		// count for 1 OVF
		Timer_init();
		TCNT0 = 0 ;
		while ((GET_BIT(TIFR,TOV0)) == 0);
		TCCR0 = 0;
	}*/
#endif

}


void Timer0_OVF_setCallbackFunc(void(*Timer0_Fptr)(void))
{
	ISR_Timer0_OVF = Timer0_Fptr ;
}
void Timer0_CTC_setCallbackFunc(void(*Timer0_Fptr)(void))
{
	ISR_Timer0_CTC = Timer0_Fptr ;
}
void __vector_11(void)
{
	if (ISR_Timer0_OVF != Null)
	{
		ISR_Timer0_OVF();
	}
}
void __vector_10(void)
{
	if (ISR_Timer0_CTC != Null)
	{

		ISR_Timer0_CTC();
	}
}
