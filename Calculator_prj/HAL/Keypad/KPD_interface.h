/***************************************************/
/* Auther : Mohamed Samir                          */
/* Date   : 6 APR 2021                             */
/* Verion : 01v                                    */
/***************************************************/

#ifndef KPD_interface_h
#define KPD_interface_h

#include <avr/delay.h>
#include "../../Common/STD_TYPES.h"
#include "../../Common/bitMath.h"
#include "../../MCAL/DIO/DIO_Register.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "KPD_config.h"
#include "KPD_Private.h"




void KPD_voidInit(void);
u8 KPD_u8GetPressedKey(void);






#endif
