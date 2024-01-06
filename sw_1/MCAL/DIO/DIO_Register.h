/***************************************************/
/* Auther : Mohamed Samir                          */
/* Date   : 24 MAR 2023                            */
/***************************************************/

#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

/*Direction register*/
#define DDRA_ITI     (*(volatile u8*)0x3A)
#define DDRB_ITI     (*(volatile u8*)0x37)
#define DDRC_ITI     (*(volatile u8*)0x34)
#define DDRD_ITI     (*(volatile u8*)0x31)
/*Output Register (High/Low)*/
#define PORTA_ITI    (*(volatile u8*)0x3B)
#define PORTB_ITI    (*(volatile u8*)0x38)
#define PORTC_ITI    (*(volatile u8*)0x35)
#define PORTD_ITI    (*(volatile u8*)0x32)

/*Input Register (Read)*/
#define PINA_ITI    (*(volatile u8*)0x39)
#define PINB_ITI    (*(volatile u8*)0x36)
#define PINC_ITI    (*(volatile u8*)0x33)
#define PIND_ITI    (*(volatile u8*)0x30)
#endif /* MCAL_DIO_DIO_REGISTER_H_ */
