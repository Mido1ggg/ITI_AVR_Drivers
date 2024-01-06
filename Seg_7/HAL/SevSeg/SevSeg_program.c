/*
 * SevSeg_program.c
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#include "SevSeg_Interface.h"


u8 SevSeg_Arr[SevSeg_ArrSize]=
{		SevSegCA_0 ,
		SevSegCA_1 ,
		SevSegCA_2 ,
		SevSegCA_3 ,
		SevSegCA_4 ,
		SevSegCA_5 ,
		SevSegCA_6 ,
		SevSegCA_7 ,
		SevSegCA_8 ,
		SevSegCA_9
};

SevErrState	   SevSeg_SevErrInit(SevSeg_info* SevenSegment1)
{
	DIO_ErrStateSetGroupDirection ((SevenSegment1->SevSeg_Group),0xff);
	return SevSegNoError;
}

SevErrState    SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info* SevenSegment1)
{
	DIO_ErrStateSetGroupValue ((SevenSegment1->SevSeg_Group),SevSeg_Arr[Copy_Number]);
	_delay_ms(1000);
	return SevSegNoError;
}

SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info* SevenSegment1 , u8 Copy_start , u8 Copy_End )
{
	if (Copy_start<Copy_End)
	{
		for(s8 i = Copy_start; i<=Copy_End;i++)
		{
			DIO_ErrStateSetGroupValue ((SevenSegment1->SevSeg_Group),SevSeg_Arr[i]);
			_delay_ms(1000);
		}
	}
	else if(Copy_start>Copy_End)
	{
		for(s8 i = Copy_start; i>=Copy_End;i--)
		{
			DIO_ErrStateSetGroupValue ((SevenSegment1->SevSeg_Group),SevSeg_Arr[i]);
			_delay_ms(1000);
		}
	}
	else
	{
		return DispRangeError;
	}
	return SevSegNoError;
	
}

SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1)
{
	for(s8 i = FirstNum; i<=LastNum;i++)
	{
		DIO_ErrStateSetGroupValue ((SevenSegment1->SevSeg_Group),SevSeg_Arr[i]);
		_delay_ms(1000);
	}
	return SevSegNoError;
}
