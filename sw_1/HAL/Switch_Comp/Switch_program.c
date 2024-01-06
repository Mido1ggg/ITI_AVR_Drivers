/*
 * Switch_program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#include "Switch_Interface.h"


SwitchErrState  SW_SwitchErrStateInit(Switch_Info * Switch)
{

	DIO_ErrStateSetPinDirection(Switch->SW_Group,Switch->SW_Pin,DIO_Input);
	if(Switch->ConnectionType == InternalPullUp)
	{
		switch(Switch->SW_Group)
		{
			/*Group A*/
			case DIO_GroupA : SET_BIT(PORTA_ITI , Switch->SW_Pin ) ;
			break ;
			/*Group B*/
			case DIO_GroupB : SET_BIT(PORTB_ITI , Switch->SW_Pin ) ;
			break ;
			/*Group C*/
			case DIO_GroupC : SET_BIT(PORTC_ITI , Switch->SW_Pin ) ;
			break ;
			/*Group D*/
			case DIO_GroupD : SET_BIT(PORTD_ITI , Switch->SW_Pin ) ;
			break ;
			/*Wrong*/
			default:
				return SwitchGroupNumError ;
		}
	}
	return SwitchNoError;
}
SwitchErrState  SW_SwitchErrStateGetState(Switch_Info * Switch ,SwitchState * Result)
{
	DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,Result);
	return SwitchNoError;
}
