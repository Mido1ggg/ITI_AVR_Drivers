/*
 * DC_Motor_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer/Timer0/Timer0_interface.h"

typedef struct
{
	DIO_GroupNumber GP0;
	DIO_PinNumber	P0;
	DIO_GroupNumber GP1;
	DIO_PinNumber	P1;
}DC_motor_Info;

typedef enum
{
	RightDir,
	LeftDir
}DC_motor_Dir;

void Motor_voidInit(DC_motor_Info * motor_info);
void Motor_voidDirCtrl(DC_motor_Dir dir,DC_motor_Info * motor_info);
void MOTOR_voidSpeed(u8 speed_percentage,DC_motor_Dir dir,DC_motor_Info * motor_info);

#endif /* HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
