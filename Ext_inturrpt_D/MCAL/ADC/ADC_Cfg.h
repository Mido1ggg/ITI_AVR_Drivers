/*
 * ADC_Cfg.h
 *
 *  Created on: 26/9/2022
 *      Author: Mohamed Samir
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

#define ENABLE  1
#define DISABLE 0

#define ADC_ENABLE ENABLE

#define ADC_SOURCE_INTERNAL 0 // 2.56 volt
#define ADC_SOURCE_AVCC		1
#define ADC_SOURCE_RESERVED	2
#define ADC_SOURCE_VREF		3

#define ADC_SOURCE ADC_SOURCE_AVCC

#define ADC_PRESCALER_2		0
#define ADC_PRESCALER_4		1
#define ADC_PRESCALER_8		2
#define ADC_PRESCALER_16	3
#define ADC_PRESCALER_32	4
#define ADC_PRESCALER_64	5
#define ADC_PRESCALER_128	6

#define ADC_PRESCALER ADC_PRESCALER_64


typedef enum
{
	ADC_0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7
}adc_channel_type;

#endif /* MCAL_ADC_ADC_CFG_H_ */
