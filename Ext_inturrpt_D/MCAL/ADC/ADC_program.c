/*
 * ADC.c
 *
 *  Created on: 26/9/2022
 *      Author: Mohamed Samir
 */

#include "ADC_Interface.h"

void(*ISR_ptr)(void) = Null;

void ADC_init()
{
#if ADC_ENABLE
	// ADC Enable
	SET_BIT(ADCSRA,ADEN);

#if ADC_PRESCALER == ADC_PRESCALER_2
	// Prescaler Configuration as division factor by 2
	CLR_BIT(ADCSRA,ADPS2);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS0);
#elif ADC_PRESCALER == ADC_PRESCALER_4
	// Prescaler Configuration as division factor by 4
	CLR_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS0);
#elif ADC_PRESCALER == ADC_PRESCALER_8
	// Prescaler Configuration as division factor by 8
	CLR_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS0);
#elif ADC_PRESCALER == ADC_PRESCALER_16
	// Prescaler Configuration as division factor by 16
	SET_BIT(ADCSRA,ADPS2);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS0);
#elif ADC_PRESCALER == ADC_PRESCALER_32
	// Prescaler Configuration as division factor by 32
	SET_BIT(ADCSRA,ADPS2);
	CLR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS0);
#elif ADC_PRESCALER == ADC_PRESCALER_64
	// Prescaler Configuration as 64 (8MHz / 64 = 125 KHz)
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS0);
#elif ADC_PRESCALER == ADC_PRESCALER_128
	// Prescaler Configuration as division factor by 128
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS0);
#endif
#if ADC_SOURCE == ADC_SOURCE_INTERNAL
	// Referance Voltage as Internal (2.56v)
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#elif ADC_SOURCE == ADC_SOURCE_AVCC
	// Referance Voltage as AVCC with external capacitor at AREF pin
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#elif ADC_SOURCE == ADC_SOURCE_RESERVED
	// Referance Voltage as Reserved
	SET_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,REFS0);
#elif ADC_SOURCE == ADC_SOURCE_VREF
	// Referance Voltage as AREF, Internal Vref turned off
	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,REFS0);
#endif
#endif
}

void ADC_startConvertion(adc_channel_type channel)
{
	// start Conversation
	//ADCSRA |= (1<<ADSC);
	SET_BIT(ADCSRA,ADSC);
	// Enable Auto Trigger mode
	//SET_BIT(ADCSRA,ADATE);
	switch (channel) {
		case 0:
			// bits from 0 to 4 at ADMUX_Reg by default = 00000 refer to channel 0
			CLR_BIT(ADMUX, MUX0);
			CLR_BIT(ADMUX, MUX1);
			CLR_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX4);
			break;
		case 1:
			// bits from 0 to 4 at ADMUX_Reg by default = 00001 refer to channel 1
			SET_BIT(ADMUX, MUX0);
			CLR_BIT(ADMUX, MUX1);
			CLR_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX4);
			break;
		case 2:
			// bits from 0 to 4 at ADMUX_Reg by default = 00010 refer to channel 2
			SET_BIT(ADMUX, MUX0);
			CLR_BIT(ADMUX, MUX1);
			CLR_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX4);
			break;
		case 3:
			// bits from 0 to 4 at ADMUX_Reg by default = 00011 refer to channel 3
			SET_BIT(ADMUX, MUX0);
			SET_BIT(ADMUX, MUX1);
			CLR_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX4);
			break;
		case 4:
			// bits from 0 to 4 at ADMUX_Reg by default = 00100 refer to channel 4
			CLR_BIT(ADMUX, MUX0);
			CLR_BIT(ADMUX, MUX1);
			SET_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX4);
			break;
		case 5:
			// bits from 0 to 4 at ADMUX_Reg by default = 00101 refer to channel 5
			SET_BIT(ADMUX, MUX0);
			CLR_BIT(ADMUX, MUX1);
			SET_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX4);
			break;
		case 6:
			// bits from 0 to 4 at ADMUX_Reg by default = 00110 refer to channel 6
			CLR_BIT(ADMUX, MUX0);
			SET_BIT(ADMUX, MUX1);
			SET_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX4);
			break;
		case 7:
			// bits from 0 to 4 at ADMUX_Reg by default = 00111 refer to channel 7
			SET_BIT(ADMUX, MUX0);
			SET_BIT(ADMUX, MUX1);
			SET_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX4);
			break;

		default : break;
	}

}
u16 ADC_read_Polling(void)
{


	while( (GET_BIT(ADCSRA,ADIF)) == 0);
	SET_BIT(ADCSRA,ADIF);
	//u16 result = ADCL ;
	u16 adc_result = ADCL; /* Read the low byte */
	adc_result += (ADCH<<8); /* Read and add the high byte */
	return adc_result;
}
u16 ADC_read(void)
{
	return ADCL;
}
void ADC_interruptEnable(void)
{
	SET_BIT(ADCSRA,ADIE);
	SET_BIT(SREG,7);
}
void ADC_setCallbackFunc(void(*Fptr)(void))
{

	ISR_ptr = Fptr;

}

void __vector_16(void)
{
	if(ISR_ptr != Null)
	{
		ISR_ptr();
	}
}
