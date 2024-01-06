/*
 * App2.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: batma
 */



#include "App2.h"
#define seg1_Gnd	Pin0
#define seg2_Gnd	Pin1

void Slc_seg1(void);
void Slc_seg2(void);

void App2()
{


	/*Seven Segment Setup*/
	SevSeg_info* sseg1 ;
	sseg1->SevSeg_Group = DIO_GroupA;
	SevSeg_SevErrInit(sseg1);

	/*SevSeg_info* sseg2 ;
	sseg2->SevSeg_Group = DIO_GroupB;
	SevSeg_SevErrInit(sseg2);*/

	/*Sev_Seg Selectors*/
	DIO_ErrStateSetPinDirection(DIO_GroupC,seg1_Gnd,DIO_Output);
	DIO_ErrStateSetPinDirection(DIO_GroupC,seg2_Gnd,DIO_Output);




	while(1)
	{

		for(u8 i=0; i<10;i++)
		{
			for(u8 j=0; j<10;j++)
			{
				Slc_seg2();
				SevSeg_SevErrStateSetNumber(i,sseg1);
				_delay_us(500);
				Slc_seg1();
				SevSeg_SevErrStateSetNumber(j,sseg1);
				_delay_us(500);
			}

		}



	}
}
void Slc_seg1(void)
{
	DIO_ErrStateSetPinValue(DIO_GroupC,seg1_Gnd,DIO_Low);
	DIO_ErrStateSetPinValue(DIO_GroupC,seg2_Gnd,DIO_High);
}
void Slc_seg2(void)
{
	DIO_ErrStateSetPinValue(DIO_GroupC,seg2_Gnd,DIO_Low);
	DIO_ErrStateSetPinValue(DIO_GroupC,seg1_Gnd,DIO_High);
}
