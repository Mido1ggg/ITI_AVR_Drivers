/*
 * SPI_test.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */
#include "SPI_test.h"
#include <avr/delay.h>
void SPI_test()
{
	Lcd_info lcdd={DIO_GroupB,
	Pin0,
	DIO_GroupB,
	Pin1,
	DIO_GroupB,
	Pin2,
	DIO_GroupA};

	LCD_VoidInit(&lcdd);
	SPI_SlaveInit();
	//MOSI
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin5,DIO_Output);
	//MISO
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin6,DIO_Input);
	//SS
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin4,DIO_Input);
	//SCK
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin7,DIO_Input);
	//LED
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin7,DIO_Output);
	u8 Data = 0;

	while(1)
	{


	  Data=SPI_TransRecieve('K');
	  if(Data == 'A')
	  {

		  TOG_BIT(PORTD_ITI,7);
		  LCD_VoidSendChar(Data,&lcdd);
		  //_delay_ms(1000);

	  }


	}



}
