#include "../MCAL/DIO/DIO_Interface.h"
#include "../Common/bitMath.h"
#include "../Common/STD_TYPES.h"
#include "Timer_0.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>

#define TCCR0	(*(volatile u8*)0x53)
#define TCNT0	(*(volatile u8*)0x52)
#define TIMSK	(*(volatile u8*)0x59)
#define TIFR	(*(volatile u8*)0x58)
#define SREG	(*(volatile u8*)0x5F)


void __vector_11(void)__attribute__((signal));
void __vector_11(void)
//ISR(TIMER0_OVF_vect)
{
	DIO_ErrStateSetPinValue(DIO_GroupA,Pin1,DIO_High);
	static u32 count=0;
	count++;
	if(count == 3907)
	{
		TOG_BIT(PORTA_ITI,0);
		count = 0;
		TCNT0 = 192;

	}
	//TIFR |= (1<<0) ;
}
void Timer_0_test()
{
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin0,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin1,DIO_Output);
	TIMSK = 0b00000001;
	SET_BIT(SREG,7);
	TCNT0 = 192;
	TCCR0 = 0b00000010;

	while(1)
	{

	}



}
