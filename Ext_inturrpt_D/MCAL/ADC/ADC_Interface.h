/*
 * ADC.h
 *
 *  Created on: 26/9/2022
 *      Author: Mohamed Samir
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


#include "../../Common/STD_TYPES.h"
#include "../../Common/bitMath.h"
#include "../../Common/definition.h"
#include "ADC_Cfg.h"
#include "ADC_private.h"
//#include <avr/io.h>

void ADC_init(void);
void ADC_startConvertion(adc_channel_type channel);

u16 ADC_read_Polling(void);
u16 ADC_read(void);
void ADC_interruptEnable(void);
void ADC_setCallbackFunc(void(*Fptr)(void));


void __vector_16(void)__attribute__((signal));

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
