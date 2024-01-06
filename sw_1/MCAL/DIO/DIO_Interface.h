/***************************************************/
/* Auther : Mohamed Samir                          */
/* Date   : 24 MAR 2023                            */
/***************************************************/

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include "../../Common/STD_TYPES.h"
#include "../../Common/bitMath.h"
#include "../../Common/definition.h"
#include "DIO_Register.h"
#include "DIO_Private.h"

ErrState  DIO_ErrStateSetPinDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_DirectionState Copy_DirectionState);
ErrState  DIO_ErrStateSetPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_ValueState Copy_ValueState);
ErrState  DIO_ErrStateReadPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,u8 *Result);


ErrState  DIO_ErrStateSetGroupDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_DirectionState Copy_DirectionState);
ErrState  DIO_ErrStateSetGroupValue(DIO_GroupNumber Copy_GroupNumber ,DIO_ValueState Copy_ValueState);
ErrState  DIO_ErrStateReadGroupValue(DIO_GroupNumber Copy_GroupNumber ,u8 *Result);






#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
