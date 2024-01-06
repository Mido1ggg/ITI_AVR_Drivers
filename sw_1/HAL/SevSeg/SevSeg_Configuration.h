/*
 * SevSeg_Configuration.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#ifndef HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
#define HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
typedef struct
{
	u8				SevSeg_Type       ;
	DIO_GroupNumber SevSeg_Group      ;
	DIO_GroupNumber	SevSeg_EnablePort ;
	DIO_PinNumber	SevSeg_EnablePin  ;
}SevSeg_info;


#endif /* HAL_SEVSEG_SEVSEG_CONFIGURATION_H_ */
