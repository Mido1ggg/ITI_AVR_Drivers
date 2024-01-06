/*
 * Speed_Control.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */

#include "Speed_Control.h"
#include <avr/delay.h>
void Speed_Control()
{
	u8 swval,n=0 ,speed=0;
	u8 arr[3]={0} ;
	DC_motor_Info motor1 ={DIO_GroupD,Pin6,DIO_GroupD,Pin7};
	Lcd_info lcdd={DIO_GroupB,
	Pin0,
	DIO_GroupB,
	Pin1,
	DIO_GroupB,
	Pin2,
	DIO_GroupA};
	LCD_VoidInit(&lcdd);
	LCD_VoidGoToXY(0,0,&lcdd);
	LCD_VoidSendString("Enter The Speed: ",&lcdd);
	LCD_VoidGoToXY(1,0,&lcdd);

	KPD_voidInit();

	Motor_voidInit(&motor1);

	//_delay_ms(1000);
	//MOTOR_voidSpeed(80,LeftDir,&motor1);
	while(1)
	{
		swval = KPD_u8GetPressedKey();
		if (swval != 0xff)
		{
			// Check if it is Number or Equal
			if(swval>47 && swval<58)
			{
				LCD_VoidSendChar(swval,&lcdd);
				n++ ;
				arr[n] = arr[n-1]*10 + (swval-48) ;



			}
			else if (swval == '=')
			{
				LCD_VoidSendCommand(0x01,&lcdd);
				LCD_VoidGoToXY(0,0,&lcdd);
				LCD_VoidSendString("Enter The Speed: ",&lcdd);
				LCD_VoidGoToXY(1,13,&lcdd);
				speed = arr[n];
				LCD_VoidSendNum(speed,&lcdd);
				LCD_VoidGoToXY(1,0,&lcdd);

				n = 0;
				MOTOR_voidSpeed(speed,RightDir,&motor1);
			}
		}
		_delay_ms(50);
	}
}

