/*
 * ADC_test.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */
#include "ADC_test.h"
#include "../MCAL/DIO/DIO_Interface.h"
u16 reads = 0;
Lcd_info lcdd={DIO_GroupB,
		Pin0,
		DIO_GroupB,
		Pin1,
		DIO_GroupB,
		Pin2,
		DIO_GroupC};
void ADC_res(void)
{
	DIO_ErrStateSetPinValue(DIO_GroupD,Pin0,DIO_High);
	reads = ADC_read();
	LCD_VoidGoToXY(0,0,&lcdd);
	LCD_VoidSendNum((s16)reads,&lcdd);
	ADC_startConvertion(ADC_0);
	//_delay_ms(500);
	//LCD_VoidSendCommand(0x01,&lcdd);

}
void ADC_test(void)
{
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin0,DIO_Input);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin1,DIO_Input);
	//DIO_ErrStateSetPinDirection(DIO_GroupD,Pin0,DIO_Output);
	LCD_VoidInit(&lcdd);
	ADC_init();
	//LCD_VoidSendString("LDR: ",&lcdd);
	//LCD_VoidGoToXY(1,0,&lcdd);
	//LCD_VoidSendString("Temp: ",&lcdd);
	//ADC_setCallbackFunc(ADC_res);
	//ADC_startConvertion(ADC_0);
	//ADC_interruptEnable();

	while(1)
	{
		ADC_startConvertion(ADC_0);
		//DIO_ErrStateSetPinValue(DIO_GroupD,Pin0,DIO_Low);
		reads = ADC_read_Polling();
		LCD_VoidGoToXY(0,0,&lcdd);
		LCD_VoidSendString("LDR: ",&lcdd);
		LCD_VoidSendNum((s16)reads,&lcdd);
		ADC_startConvertion(ADC_1);
		reads = ADC_read_Polling();
		LCD_VoidGoToXY(1,0,&lcdd);
		LCD_VoidSendString("Temp: ",&lcdd);
		LCD_VoidSendNum((s16)reads,&lcdd);
		//LCD_VoidSendNum(5,&lcdd);
		_delay_ms(500);
		LCD_VoidSendCommand(0x01,&lcdd);
	}


}
