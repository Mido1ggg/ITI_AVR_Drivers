//#include <avr/io.h>
#include <avr/delay.h>

#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LED/Led_Interface.h"
#include "HAL/Switch_Comp/Switch_Interface.h"



void main()
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

	/*LED Setup*/
	Led_info led0={DIO_GroupA,Pin0,Source_Connection};
	Led_info led1={DIO_GroupA,Pin1,Source_Connection};
	Led_info led2={DIO_GroupA,Pin2,Source_Connection};

	Led_LedErrStateInit(&led0);
	Led_LedErrStateInit(&led1);

	/*motor*/
	DIO_ErrStateSetPinDirection(DIO_GroupC,Pin1,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupC,Pin3,DIO_Output);



	while(1)
	{
		SW_SwitchErrStateGetState(&sw0,&sw0_val);
		SW_SwitchErrStateGetState(&sw1,&sw1_val);


		if(sw0_val == PressedPullUp)
		{
			Led_LedErrStateTurnOn(&led0);
			Led_LedErrStateTurnOff(&led1);
			DIO_ErrStateSetPinValue(DIO_GroupC,Pin1,DIO_High);
			DIO_ErrStateSetPinValue(DIO_GroupC,Pin3,DIO_Low);

		}

		else if(sw1_val == PressedPullUp)
		{
			Led_LedErrStateTurnOn(&led1);
			Led_LedErrStateTurnOff(&led0);
			DIO_ErrStateSetPinValue(DIO_GroupC,Pin3,DIO_High);
			DIO_ErrStateSetPinValue(DIO_GroupC,Pin1,DIO_Low);
		}



	}


}
