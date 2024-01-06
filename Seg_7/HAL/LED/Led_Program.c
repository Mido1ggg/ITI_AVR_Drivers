/*
 * Led_Program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */
#include "../../Common/definition.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Led_Interface.h"



LedErrState	Led_LedErrStateInit(Led_info *Led)
{
	if(DIO_ErrStateSetPinDirection(Led->Led_Group, Led->Led_Pin,DIO_Output))
	{
		return LedInitError;
	}
	return LedNoError;
}

LedErrState	Led_LedErrStateTurnOn(Led_info *Led) 
{
	
	if (Led->ConnectionType == Source_Connection)
	{
		DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_High);
	}
	else if (Led->ConnectionType == Sink_Connection)
	{
		DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_Low);
	}
	else 
	{
		return ConnectionTypeError;
	}
	return LedNoError;
	
	
} 
  


LedErrState	Led_LedErrStateTurnOff(Led_info *Led) 
{
	if (Led->ConnectionType == Source_Connection)
	{
		DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_Low);
	}
	else if (Led->ConnectionType == Sink_Connection)
	{
		DIO_ErrStateSetPinValue(Led->Led_Group, Led->Led_Pin, DIO_High);
	}
	else 
	{
		return ConnectionTypeError;
	}
	return NoError;
	
}
