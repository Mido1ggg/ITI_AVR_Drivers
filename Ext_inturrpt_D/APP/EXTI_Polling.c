/*
 * EXTI_Polling.c
 *
 *  Created on: 31/3/2023
 *      Author: Mohamed Samir
 */

#include "EXTI_Polling.h"

static Led_info led={DIO_GroupA,Pin7,Source_Connection};


void EXTI_Polling()
{
	EXTI_init();
	u8 x = 0;

	while(1)
	{

		while(0==EXTI1_u8Checkflag());
		EXTI1_voidClearFlag();
		if(x==0)
		{
			Led_LedErrStateTurnOff(&led);
			x++;
		}
		else if(x==1)
		{
			Led_LedErrStateTurnOn(&led);
			x--;
		}
	}




}
