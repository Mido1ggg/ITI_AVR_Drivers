/***************************************************/
/* Auther : Mohamed Samir                          */
/* Date   : 27 MAR 2021                            */
/* Verion : 01v                                    */
/***************************************************/

#ifndef LCD_interface_h
#define LCD_interface_h
#include "../../Common/STD_TYPES.h"
#include "../../Common/bitMath.h"
#include "../../Common/definition.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <avr/delay.h>
#include "LCD_Register.h"
#include "LCD_Privet.h"


void LCD_VoidInit(Lcd_info* lcd);

void LCD_VoidSendCommand(u8 Copy_Command, Lcd_info* lcd);
void LCD_VoidSendChar(u8 Copy_Char, Lcd_info* lcd);

void LCD_VoidGoToXY(u8 Local_XPosition,u8 Local_YPosition, Lcd_info* lcd);
void LCD_VoidSendString(u8 *Address_String, Lcd_info* lcd);
void LCD_VoidSendNum(s16 Copy_Num, Lcd_info* lcd);
void LCD_VoidSendFloat(f32 Copy_fNum, Lcd_info* lcd);

void LCD_VoidWriteOnCGRAM(u8 CGRAMmemoryLocation, u8 *ArrChar, Lcd_info* lcd);
void LCD_VoidDispCharCGRAM(u8 CGRAMmemoryLocation, Lcd_info* lcd);

#endif
