/*
 * EXTI_inturrptMode.c
 *
 *  Created on: 31/3/2023
 *  Author: Mohamed Samir
 */



#include "EXTI_inturrptMode.h"

//static Led_info led={DIO_GroupD,Pin7,Source_Connection};

void intLed(void);
static s8 x = 0;
void EXTI_inturrptMode()
{
	Switch_Info sw = {DIO_GroupD,Pin2,InternalPullUp};
	SW_SwitchErrStateInit(&sw);
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin5,DIO_Output);
	EXTI_init();
	//Led_LedErrStateTurnOff(&led);
	setCallback_INT0(intLed);
	EXTI_Enable(EXTI0);
	while(1)
	{
		if(x==0)
		{
			DIO_ErrStateSetPinValue(DIO_GroupD,Pin5,DIO_Low);

		}
		else if(x==1)
		{
			DIO_ErrStateSetPinValue(DIO_GroupD,Pin5,DIO_High);

		}

	}




}

void intLed(void)
{

	if(x==0)
	{

		x=1;
	}
	else if(x==1)
	{

		x=0;
	}
}


