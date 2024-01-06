/*
 * StopWatch_Clock.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */


#include "StopWatch_Clock.h"
u8 LCD_sec1;
u8 LCD_sec2;
u8 LCD_min1;
u8 LCD_min2;
u8 LCD_hr1 ;
u8 LCD_hr2 ;
u8 Digit[6]={0,0,8,5,0,0};
	Lcd_info lcdd={DIO_GroupB,
	Pin0,
	DIO_GroupB,
	Pin1,
	DIO_GroupB,
	Pin2,
	DIO_GroupA};

void Task1(void);
void Task2(void);
void Task3(void);

void ISR_TimerCTC_count1sec(void)
{
	static u32 counter ;
	if(!(counter%40))
	{
		counter = 0;
		/*LCD_VoidGoToXY(1,4,&lcdd);
		LCD_VoidSendNum(counter,&lcdd);*/
		LCD_sec1++;
		Task1();
		Digit[0] = LCD_sec1;
		Digit[1] = LCD_sec2;
		//if(!(counter%(2400)))
		if((Digit[1]==5) && (Digit[0]==9))
		{
			Task2();
		}
		//if(!(counter%(144000)))
		if((Digit[3]==6) && (Digit[2]==0))
		{
			Task3();
		}

		LCD_VoidGoToXY(0,10, &lcdd);
		LCD_VoidSendNum(Digit[1], &lcdd);
		LCD_VoidSendNum(Digit[0], &lcdd);


	}

	counter++;

}

void StopWatch_Clock()
{


	Timer0_voidInit();
	OCR0 = 50;
	// SPEED RUN
	//OCR0 = 15;
	Timer0_CTC_setCallbackFunc(ISR_TimerCTC_count1sec);
	LCD_VoidInit(&lcdd);
	LCD_VoidGoToXY(0,4,&lcdd);

	LCD_VoidSendNum(Digit[5],&lcdd);
	LCD_VoidSendNum(Digit[4],&lcdd);
	LCD_VoidSendChar(58,&lcdd);

	LCD_VoidSendNum(Digit[3],&lcdd);
	LCD_VoidSendNum(Digit[2],&lcdd);
	LCD_VoidSendChar(58,&lcdd);

	LCD_VoidSendNum(Digit[1],&lcdd);
	LCD_VoidSendNum(Digit[0],&lcdd);
	//LCD_VoidSendFloat(5.55,&lcdd);

	while(1)
	{


	}




}
void Task1(void)
{
	if (LCD_sec1 > 9)
	{
		LCD_sec1 = 0;
		LCD_sec2++;
	}



}
void Task2(void)
{

		LCD_sec2 = 0;
		LCD_sec1 = 0;
		LCD_min1++;
		if(LCD_min1>9)
		{
			LCD_min1 = 0;
			LCD_min2++;
		}

	Digit[2] = LCD_min1;
	Digit[3] = LCD_min2;
	LCD_VoidGoToXY(0, 7, &lcdd);

	LCD_VoidSendNum(Digit[3], &lcdd);
	LCD_VoidSendNum(Digit[2], &lcdd);
}

void Task3(void)
{

		LCD_min1 = 0;
		LCD_min2 = 0;
		LCD_hr1++;
		if(LCD_hr1>9)
		{
			LCD_hr1 = 0;
			LCD_hr2++;
		}
		if((LCD_hr2==2) && (LCD_hr1>3))
		{
			LCD_hr1 = 0;
			LCD_hr2 = 0;
		}


	Digit[4] = LCD_hr1 ;
	Digit[5] = LCD_hr2 ;
	LCD_VoidGoToXY(0, 4, &lcdd);

	LCD_VoidSendNum(Digit[5], &lcdd);
	LCD_VoidSendNum(Digit[4], &lcdd);
}
