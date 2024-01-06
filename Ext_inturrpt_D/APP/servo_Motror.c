/*
 * servo_Motror.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */

#include "servo_Motror.h"
void servo_Motor()
{
	Timer1_init();
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin5,DIO_Output);
	OCR1A = 30;
	ICR1 = 625 ;
	while(1)
	{
		//17 - 75
		for(u8 i= 30; i<62;i++)
		{
			OCR1A = i;
			_delay_ms(300);
		}
		for(u8 i= 62; i>30;i--)
		{
			OCR1A = i;
			_delay_ms(300);
		}
	}
}
