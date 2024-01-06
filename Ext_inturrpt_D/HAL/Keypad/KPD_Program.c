/***************************************************/
/* Auther : Mohamed Samir                          */
/* Date   : 6 APR 2021                             */
/* Verion : 01v                                    */
/***************************************************/
#include "KPD_interface.h"

const u8 KPD_u8SwitchVal[4][4] = KPD_KEYS;

const u8 KPD_u8RowsPins[4] = { ROW1, ROW2, ROW3, ROW4 };
const u8 KPD_u8ColsPins[4] = { COL1, COL2, COL3, COL4 };

void KPD_voidInit(void) {

	DIO_ErrStateSetPinDirection(KPD_PORT, ROW1, DIO_Output);
	DIO_ErrStateSetPinDirection(KPD_PORT, ROW2, DIO_Output);
	DIO_ErrStateSetPinDirection(KPD_PORT, ROW3, DIO_Output);
	DIO_ErrStateSetPinDirection(KPD_PORT, ROW4, DIO_Output);

	DIO_ErrStateSetPinDirection(KPD_PORT, COL1, DIO_Input);
	DIO_ErrStateSetPinDirection(KPD_PORT, COL2, DIO_Input);
	DIO_ErrStateSetPinDirection(KPD_PORT, COL3, DIO_Input);
	DIO_ErrStateSetPinDirection(KPD_PORT, COL4, DIO_Input);
	
	// setting the Rows to HIGH and activate the columns internal Pull Up resistors
	PORTC_ITI = 0xff ;

}

u8 KPD_u8GetPressedKey(void) {

	u8 Local_u8Col, Local_u8Row;
	u8 Local_u8Sw = KPD_u8KEY_NOT_PRESSED;
	u8 Local_u8Flag = 0;
	u8 val = 0;

	for (Local_u8Row = 0; Local_u8Row <= 3; Local_u8Row++) {

		DIO_ErrStateSetPinValue(KPD_PORT, KPD_u8RowsPins[Local_u8Row], DIO_Low);

		for (Local_u8Col = 0; Local_u8Col <= 3; Local_u8Col++) {

			// Key pressed
			DIO_ErrStateReadPinValue(KPD_PORT, KPD_u8ColsPins[Local_u8Col],&val);
			if (DIO_Low == val)
			{
				// bouncing 
				_delay_ms(7);

				// to delay till pressing is over
				while (DIO_Low == val)
				{
					DIO_ErrStateReadPinValue(KPD_PORT,KPD_u8ColsPins[Local_u8Col], &val);
				}

				Local_u8Sw = KPD_u8SwitchVal[Local_u8Row][Local_u8Col];

				Local_u8Flag = 1;

				break;

			}
		}

		// Reseting the previous Row
		DIO_ErrStateSetPinValue(KPD_PORT, KPD_u8RowsPins[Local_u8Row],DIO_High);

		// if we found the pressed sw will get out the function
		if (1 == Local_u8Flag) {
			break;
		}

	}
	return (Local_u8Sw);
}	





