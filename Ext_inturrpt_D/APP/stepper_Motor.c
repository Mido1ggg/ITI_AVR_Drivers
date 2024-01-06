/*
 * stepper_Motor.c
 */


#include "stepper_Motor.h"
//#include "../MCAL/DIO/DIO_Interface.h"
#include <avr/io.h>

void stepper_Motor(void)
{
	int period;
	DDRB = 0xF0;		/* Make PORTB lower pins as output */
	period = 100;		/* Set period in between two steps */
	while (1)
	{
		PORTB = 0x10;
		_delay_ms(period);
		PORTB = 0x20;
		_delay_ms(period);
		PORTB = 0x40;
		_delay_ms(period);
		PORTB = 0x80;
		_delay_ms(period);
		//_delay_ms(1000);
	}
}
