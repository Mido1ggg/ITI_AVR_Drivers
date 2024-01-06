//#include <avr/io.h>
#include <avr/delay.h>
#include "APP/Calculator_interface.h"


void main()
{
	Lcd_info lcdd={DIO_GroupB,
	Pin0,
	DIO_GroupB,
	Pin1,
	DIO_GroupB,
	Pin2,
	DIO_GroupA};

	KPD_voidInit();
	LCD_VoidInit(&lcdd);


	while(1)
	{
		CalculatorMode(&lcdd);

	}




}


