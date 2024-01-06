/***************************************************/
/* Auther : Mohamed Samir                          */
/* Date   : 27 MAR 2021                            */
/* Verion : 01v                                    */
/***************************************************/

#include "LCD_interface.h"






void LCD_VoidInit(Lcd_info* lcd)
{
	
	
	/*Set Direction*/
	DIO_ErrStateSetPinDirection(lcd->Rs_Group,lcd->Rs_Pin,DIO_Output);
	DIO_ErrStateSetPinDirection(lcd->Rw_Group,lcd->Rw_Pin,DIO_Output);
	DIO_ErrStateSetPinDirection(lcd->E_Group,lcd->E_Pin,DIO_Output);
	DIO_ErrStateSetGroupDirection(lcd->Data_Group,0xff);

	_delay_ms(40);


	// Function set
	LCD_VoidSendCommand(LCD_Set8Bit2Line5x8,lcd);
	//_delay_us(40);
	_delay_ms(1);
	// Display ON/OFF control
	LCD_VoidSendCommand(LCD_CursorON,lcd);
	//_delay_us(40);
	_delay_ms(1);
	// Display Clear
	LCD_VoidSendCommand(LCD_ClearDisplay,lcd);
	_delay_ms(2);


}	


void LCD_VoidGoToXY(u8 Local_XPosition,u8 Local_YPosition, Lcd_info* lcd)
{
	// x_pos from 0 to 1
	// y_pos from 0 to 15
	u8 Adress = 0 ;
	if (0 == Local_XPosition)
	{
		Adress = LCD_FirstLine + LCD_SetAddressDDRAM;
	}
	else if (1 == Local_XPosition)
	{
		Adress = LCD_SecoundLine + LCD_SetAddressDDRAM;
	}
	if (Local_YPosition < 16)
	{
		Adress += Local_YPosition ;
	}
	else{/*error*/}

	LCD_VoidSendCommand(Adress,lcd) ;

}


void LCD_VoidSendString(u8 *Address_String, Lcd_info* lcd)
{
	u8 stringCounter=0;
	for(;Address_String[stringCounter] != '\0'; stringCounter++ )
	{
		LCD_VoidSendChar(Address_String[stringCounter],lcd);
	}
}


void LCD_VoidSendNum(s16 Copy_Num, Lcd_info* lcd)
 {
    u8 i,j,c,ArrCount,s[15];
	s16 sign;
	i = 0;
	ArrCount = 0;
	sign = Copy_Num;
	if (sign < 0)  /* record sign */
	{
	 Copy_Num = -Copy_Num;          /* make the NUM positive */
	}

	do {                       /* Convert NUM to ASCII in reverse order */

	 s[i] = (Copy_Num % 10) + '0';
	 i++;

	 } while ((Copy_Num /= 10) > 0);

	if (sign < 0)      /* putting sign */
	{
		s[i++] = '-';
	}

	ArrCount=i;
	j=ArrCount-1;
	for (i = 0; i<j; i++, j--) /* reversing the array to make the NUM in order */
	{
	  c = s[i];
	  s[i] = s[j];
	  s[j] = c;
	}

	for (i = 0; i<ArrCount; i++) /* PRINTNIG the NUM */
	{
		LCD_VoidSendChar (s[i],lcd);
	}


 }

void LCD_VoidSendFloat(f32 Copy_fNum, Lcd_info* lcd)
{
	// Extract integer part
	s16 INTpart = (s16)Copy_fNum;

	// Extract floating part
	f32 fpart = Copy_fNum - (f32)INTpart;

	//Exception for negative number
	if(fpart<0){fpart*=-1;}

	// convert integer part to string
	LCD_VoidSendNum(INTpart, lcd);

	// add dot
	LCD_VoidSendString(".", lcd);
	// Get the value of fraction part upto 4 digits of points after dot
	fpart = fpart * 10000;

	LCD_VoidSendNum(fpart, lcd);

}

void LCD_VoidWriteOnCGRAM(u8 CGRAMmemoryLocation, u8 *ArrChar, Lcd_info* lcd)
{
	u8 counter;
	if(CGRAMmemoryLocation<MAX_CHAR_SIZE_CGRAM) //If valid address
	{
		LCD_VoidSendCommand((LCD_SetAddressCGRAM+(CGRAMmemoryLocation*MAX_CHAR_SIZE_CGRAM)),lcd); //Write to CGRAM
		for(counter=0; counter<MAX_CHAR_SIZE_CGRAM; counter++)
		{
			LCD_VoidSendChar(ArrChar[counter],lcd); //Write the character pattern to CGRAM
		}
		LCD_VoidSendCommand(LCD_SetAddressDDRAM,lcd); //back to DDRAM location 0
	}
	else
	{
		/*Error*/
	}

}

void LCD_VoidDispCharCGRAM(u8 CGRAMmemoryLocation, Lcd_info* lcd)
{
	LCD_VoidSendChar(CGRAMmemoryLocation,lcd);
}

void LCD_VoidSendCommand(u8 Copy_Command, Lcd_info* lcd)
{
	
	// RS=0 to send a Command and RS=1 to send Instraction
	DIO_ErrStateSetPinValue (lcd->Rs_Group,lcd->Rs_Pin,DIO_Low);
	// RW=0 to Write and RW=1 to Read
	DIO_ErrStateSetPinValue (lcd->Rw_Group,lcd->Rw_Pin,DIO_Low);
	// Write Command
	DIO_ErrStateSetGroupValue(lcd->Data_Group,Copy_Command);
	// Enable=1 for 230 nano secounds 
	DIO_ErrStateSetPinValue (lcd->E_Group,lcd->E_Pin,DIO_High);
	_delay_ms(1);
	DIO_ErrStateSetPinValue (lcd->E_Group,lcd->E_Pin,DIO_Low);
	_delay_ms(1);
	
}

void LCD_VoidSendChar(u8 Copy_Char, Lcd_info* lcd)
{
	
	// RS=0 to send a Command and RS=1 to send Data
	DIO_ErrStateSetPinValue (lcd->Rs_Group,lcd->Rs_Pin,DIO_High);
	// RW=0 to Write and RW=1 to Read
	DIO_ErrStateSetPinValue (lcd->Rw_Group,lcd->Rw_Pin,DIO_Low);
	// Write Data
	DIO_ErrStateSetGroupValue(lcd->Data_Group,Copy_Char);
	// Enable=1 for 230 nano secounds 
	DIO_ErrStateSetPinValue (lcd->E_Group,lcd->E_Pin,DIO_High);
	_delay_ms(1);
	DIO_ErrStateSetPinValue (lcd->E_Group,lcd->E_Pin,DIO_Low);
	_delay_ms(1);
	
}		
