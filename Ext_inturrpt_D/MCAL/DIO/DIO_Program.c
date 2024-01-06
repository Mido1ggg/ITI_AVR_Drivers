/***************************************************/
/* Auther : Mohamed Samir                          */
/* Date   : 24 MAR 2023                            */
/***************************************************/
#include "DIO_Interface.h"

ErrState  DIO_ErrStateSetPinDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_DirectionState Copy_DirectionState)
{
	if(Copy_PinNumber<=Pin7 && Copy_PinNumber>=Pin0)
	{
		/*Input-> write Zero DDR (CLR) */
		if (Copy_DirectionState == DIO_Input )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : CLR_BIT(DDRA_ITI , Copy_PinNumber ) ;
			break ;
			/*Group B*/
			case DIO_GroupB : CLR_BIT(DDRB_ITI , Copy_PinNumber ) ;
			break ;
			/*Group C*/
			case DIO_GroupC : CLR_BIT(DDRC_ITI , Copy_PinNumber ) ;
			break ;
			/*Group D*/
			case DIO_GroupD : CLR_BIT(DDRD_ITI , Copy_PinNumber ) ;
			break ;
			/*Wrong*/
			default:
				return GroupError ;
			}


		}

		/*Output -> write DDR = one */
		else if (Copy_DirectionState == DIO_Output )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : SET_BIT(DDRA_ITI,Copy_PinNumber);break;
			/*Group B*/
			case DIO_GroupB : SET_BIT(DDRB_ITI,Copy_PinNumber);break;
			/*Group C*/
			case DIO_GroupC : SET_BIT(DDRC_ITI,Copy_PinNumber);break;
			/*Group D*/
			case DIO_GroupD : SET_BIT(DDRD_ITI,Copy_PinNumber);break;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		else
		{
			return DirectionError ;
		}

		return NoError ;
	}
	else
	{
		return PinNumberError ;
	}
}

ErrState  DIO_ErrStateSetPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_ValueState Copy_ValueState)
{
	if(Copy_PinNumber<=Pin7 && Copy_PinNumber>=Pin0)
	{
		/*Low-> write Zero Port (CLR) */
		if (Copy_ValueState == DIO_Low )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : CLR_BIT(PORTA_ITI , Copy_PinNumber ) ;break ;
			/*Group B*/
			case DIO_GroupB : CLR_BIT(PORTB_ITI , Copy_PinNumber ) ;break ;
			/*Group C*/
			case DIO_GroupC : CLR_BIT(PORTC_ITI , Copy_PinNumber ) ;break ;
			/*Group D*/
			case DIO_GroupD : CLR_BIT(PORTD_ITI , Copy_PinNumber ) ;break ;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		/*High -> write port = one */
		else if (Copy_ValueState == DIO_High )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : SET_BIT(PORTA_ITI,Copy_PinNumber);break;
			/*Group B*/
			case DIO_GroupB : SET_BIT(PORTB_ITI,Copy_PinNumber);break;
			/*Group C*/
			case DIO_GroupC : SET_BIT(PORTC_ITI,Copy_PinNumber);break;
			/*Group D*/
			case DIO_GroupD : SET_BIT(PORTD_ITI,Copy_PinNumber);break;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		else
		{
			return DirectionError ;
		}

		return NoError ;
	}
	else
	{
		return PinNumberError ;
	}

}

ErrState  DIO_ErrStateReadPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber ,u8 *Result)
{
	/*check on pin range from 0 to 7 */
	if (Copy_PinNumber>= Pin0 && Copy_PinNumber <=Pin7)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: *Result=GET_BIT(PINA_ITI,Copy_PinNumber); break ;
		case DIO_GroupB: *Result=GET_BIT(PINB_ITI,Copy_PinNumber); break ;
		case DIO_GroupC: *Result=GET_BIT(PINC_ITI,Copy_PinNumber); break ;
		case DIO_GroupD: *Result=GET_BIT(PIND_ITI,Copy_PinNumber); break ;
		default:
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return PinNumberError ;
	}

}



//
ErrState  DIO_ErrStateSetGroupDirection(DIO_GroupNumber Copy_GroupNumber ,u8 Copy_DirectionState)
{
	if (Copy_DirectionState <= 0xff && Copy_DirectionState>=0x00)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: DDRA_ITI =  Copy_DirectionState ;break ;
		case DIO_GroupB: DDRB_ITI =  Copy_DirectionState ;break ;
		case DIO_GroupC: DDRC_ITI =  Copy_DirectionState ;break ;
		case DIO_GroupD: DDRD_ITI =  Copy_DirectionState ;break ;
		default :
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return DirectionRangError;
	}
}
ErrState  DIO_ErrStateSetGroupValue(DIO_GroupNumber Copy_GroupNumber ,u8 Copy_ValueState)
{
	if (Copy_ValueState <= 0xff && Copy_ValueState>=0x00)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: PORTA_ITI =  Copy_ValueState ;break ;
		case DIO_GroupB: PORTB_ITI =  Copy_ValueState ;break ;
		case DIO_GroupC: PORTC_ITI =  Copy_ValueState ;break ;
		case DIO_GroupD: PORTD_ITI =  Copy_ValueState ;break ;
		default :
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return ValueRangError;
	}

}
ErrState  DIO_ErrStateReadGroupValue(DIO_GroupNumber Copy_GroupNumber ,u8 *Result)
{
	if(Result!=Null)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: *Result = PINA_ITI ; break ;
		case DIO_GroupB: *Result = PINB_ITI ; break ;
		case DIO_GroupC: *Result = PINC_ITI ; break ;
		case DIO_GroupD: *Result = PIND_ITI ; break ;
		default :
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return AddressError;
	}

}
