/*
 * DC_Motor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */


#include "DC_Motor_Interface.h"

void Motor_voidInit(DC_motor_Info * motor_info)
{
	DIO_ErrStateSetPinDirection(motor_info->GP0,motor_info->P0,DIO_Output);
	DIO_ErrStateSetPinDirection(motor_info->GP1,motor_info->P1,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupB,Pin3,DIO_Output);
	Timer0_voidInit();
	//Timer0_voidSetPin_softPWM(motor_info->GP0,motor_info->P0);
}

void Motor_voidDirCtrl(DC_motor_Dir dir,DC_motor_Info * motor_info)
{
	if(dir == RightDir)
	{
		DIO_ErrStateSetPinValue(motor_info->GP0,motor_info->P0,DIO_High);
		DIO_ErrStateSetPinValue(motor_info->GP1,motor_info->P1,DIO_Low);
	}
	if(dir == LeftDir)
	{
		DIO_ErrStateSetPinValue(motor_info->GP0,motor_info->P0,DIO_Low);
		DIO_ErrStateSetPinValue(motor_info->GP1,motor_info->P1,DIO_High);
	}
}
void MOTOR_voidSpeed(u8 speed_percentage,DC_motor_Dir dir,DC_motor_Info * motor_info)
{
	if(speed_percentage<101 && speed_percentage>-1)
	{/*Continue*/}
	else{ speed_percentage = 0;}

	if(dir == RightDir)
	{
		//Timer0_voidSetDuty_percentage(speed_percentage,motor_info->GP0,motor_info->P0);
		Timer0_voidFastPWM_percentage(speed_percentage);
		DIO_ErrStateSetPinValue(motor_info->GP1,motor_info->P1,DIO_Low);
	}
	if(dir == LeftDir)
	{
		//DIO_ErrStateSetPinValue(motor_info->GP0,motor_info->P0,DIO_Low);
		Timer0_voidFastPWM_percentage(speed_percentage);
		Timer0_voidSetDuty_percentage(speed_percentage,motor_info->GP1,motor_info->P1);
	}

}
