/*
 * WDT_test.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */

#include "WDT_test.h"
void WDT_test(void)
{
	// Turning Led on for 1 sec and turn it off , then reseting MCU
	// Blinking Led for 1 sec
	WDT_voidSleep(WDT_2100_MS);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin7,DIO_Output);
	DIO_ErrStateSetPinValue(DIO_GroupA,Pin7,DIO_High);
	_delay_ms(1000);
	DIO_ErrStateSetPinValue(DIO_GroupA,Pin7,DIO_Low);
	while(1)
	{

	}

}
