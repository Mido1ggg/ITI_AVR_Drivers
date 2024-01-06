/*
 * SevSeg_Interface.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#ifndef HAL_SEVSEG_SEVSEG_INTERFACE_H_
#define HAL_SEVSEG_SEVSEG_INTERFACE_H_

#include "../../Common/definition.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include  "SevSeg_Private.h"
#include  "SevSeg_Configuration.h"
#include <avr/delay.h>

SevErrState	   SevSeg_SevErrInit(SevSeg_info * SevenSegment1);

SevErrState    SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1);

SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End );

/*display from zero to nine*/
SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1);


#endif /* HAL_SEVSEG_SEVSEG_INTERFACE_H_ */
