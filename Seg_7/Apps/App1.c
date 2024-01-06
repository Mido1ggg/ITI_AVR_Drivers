/*
 * App1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */


#include "App1.h"


void App1()
{

	/*Switch Setup*/
	Switch_Info sw0 = {DIO_GroupD,Pin0,InternalPullUp};
	Switch_Info sw1 = {DIO_GroupD,Pin1,InternalPullUp};
	Switch_Info sw2 = {DIO_GroupD,Pin2,InternalPullUp};

	u8 sw0_val = 1;
	u8 sw1_val = 1;
	u8 sw2_val = 1;

	SW_SwitchErrStateInit(&sw0);
	SW_SwitchErrStateInit(&sw1);
	SW_SwitchErrStateInit(&sw2);

	/*Seven Segment Setup*/
	SevSeg_info* sseg1 ;
	sseg1->SevSeg_Group = DIO_GroupA;
	SevSeg_SevErrInit(sseg1);

	u8 Reminder_var = 0;


	while(1)
	{
		/*Reading Push Buttons*/
		SW_SwitchErrStateGetState(&sw0,&sw0_val);
		SW_SwitchErrStateGetState(&sw1,&sw1_val);
		SW_SwitchErrStateGetState(&sw2,&sw2_val);

		/*First Switch to Count up from Zero to nine*/
		if(sw0_val == PressedPullUp)
		{
			for(u8 i=0; i<10;i++)
			{
				SevSeg_SevErrStateSetNumber(i,sseg1);
				_delay_ms(1000);
				Reminder_var = i;

				SW_SwitchErrStateGetState(&sw1,&sw1_val);
				SW_SwitchErrStateGetState(&sw2,&sw2_val);
				if((sw1_val == PressedPullUp)||(sw2_val == PressedPullUp))
				{
					break;
				}
			}

		}
		/*Second Switch to count Down from nine to zero*/
		else if(sw1_val == PressedPullUp)
		{
			for(s8 i=9; i>=0;i--)
			{
				SevSeg_SevErrStateSetNumber(i,sseg1);
				_delay_ms(1000);
				Reminder_var = i;

				SW_SwitchErrStateGetState(&sw0,&sw0_val);
				SW_SwitchErrStateGetState(&sw2,&sw2_val);
				if((sw0_val == PressedPullUp)||(sw2_val == PressedPullUp))
				{
					break;
				}
			}


		}
		/*Third Switch to Stop on last number Displayed*/
		else if(sw2_val == PressedPullUp)
		{
			SevSeg_SevErrStateSetNumber(Reminder_var,sseg1);
		}

	}


}

