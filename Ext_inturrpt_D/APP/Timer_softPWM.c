/*
 * Timer_Driver_test.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */


#include "Timer_0.h"


// Timer interrupt OVF 2 LEDs
void Timer_ISR(void)
{
	static u16 i =0;
	static u8 x =0;
	i++;
	if(i == 1954)
	{
		i = 0;
		TCNT0 = 224;
		TOG_BIT(PORTA_ITI,0);
		if(x==1)
		{
			TOG_BIT(PORTA_ITI,1);
		}
		else if(x==2)
		{
			TOG_BIT(PORTA_ITI,2);
			x=0;
		}
		x++;

	}
}

//CTC MODE to toggle 1 LED
/*void Timer_OVF_ISR(void)
{
	SET_BIT(PORTA_ITI,1);
	static u16 i =0;
	if (i == 4000)
	{
		i = 0;
		//OCR0=250;
		TOG_BIT(PORTA_ITI,0);
	}
	i++;
}
void Timer_CTC_ISR(void)
{
	TCNT0 = 0;
}*/
void Timer_Driver_test(void)
{
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin0,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin1,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin2,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin3,DIO_Output);
	Timer_init();
	//OCR0=250;
	//Timer0_CTC_setCallbackFunc(Timer_CTC_ISR);
	Timer0_OVF_setCallbackFunc(Timer_OVF_ISR);
	while(1)
	{
		/*Timer0_Delay(1000);
		TOG_BIT(PORTA_ITI,0);*/
	}
}
