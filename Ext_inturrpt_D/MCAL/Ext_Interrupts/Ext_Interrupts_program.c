/*
 * Ext_Interrupts.c
 *
 *  Created on: 22/9/2022
 *      Author: Mohamed Samir
 */
#include "Ext_Interrupts_Interface.h"

// Pointer to Function for interrupts
void (*INT0_ptr)(void) = Null;
void (*INT1_ptr)(void) = Null;
void (*INT2_ptr)(void) = Null;

void EXTI_init()
{


// Interrupt 0
	#if EXT_INT0_MODE == ENABLE
		EXTI_Enable(EXTI0);
		#if INT0_SENSE_MODE	== LOW_LEVEL_TRIG
			CLR_BIT(MCUCR_REG,ISC00);
			CLR_BIT(MCUCR_REG,ISC01);
		#elif INT0_SENSE_MODE	== ONCHANGE
			SET_BIT(MCUCR_REG,ISC00);
			CLR_BIT(MCUCR_REG,ISC01);
		#elif INT0_SENSE_MODE	== FALLING_EDGE_TRIG
			CLR_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
		#elif INT0_SENSE_MODE	== RAISING_EDGE_TRIG
			SET_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
		#endif
	#endif
// Interrupt 1
	#if EXT_INT1_MODE == ENABLE
			EXTI_Enable(EXTI1);
			#if INT1_SENSE_MODE	== LOW_LEVEL_TRIG
				CLR_BIT(MCUCR_REG,ISC10);
				CLR_BIT(MCUCR_REG,ISC11);
			#elif INT1_SENSE_MODE	== ONCHANGE
				SET_BIT(MCUCR_REG,ISC10);
				CLR_BIT(MCUCR_REG,ISC11);
			#elif INT1_SENSE_MODE	== FALLING_EDGE_TRIG
				CLR_BIT(MCUCR_REG,ISC10);
				SET_BIT(MCUCR_REG,ISC11);
			#elif INT1_SENSE_MODE	== RAISING_EDGE_TRIG
				SET_BIT(MCUCR_REG,ISC10);
				SET_BIT(MCUCR_REG,ISC11);
			#endif
		#endif
// Interrupt 2
	#if EXT_INT2_MODE == ENABLE

		#if INT1_SENSE_MODE	== FALLING_EDGE_TRIG
				CLR_BIT(MCUCSR_REG,ISC2);
			#elif INT1_SENSE_MODE	== RAISING_EDGE_TRIG
				SET_BIT(MCUCSR_REG,ISC2);
			#endif
		EXTI_Enable(EXTI2);
	#endif
}
void EXTI_Enable(EXT_type interrupt)
{
#if EXTI0_USAGE == EXTI0_INTERRUPT
	SET_BIT(SREG_REG,7);//enable GIE
#endif
	switch (interrupt)
	{
		case EXTI0:
			SET_BIT(GICR_REG,INT0);
			CLR_BIT(DDRD_ITI,2);
			SET_BIT(PORTD_ITI,2);
			break;
		case EXTI1:
			SET_BIT(GICR_REG,INT1);
			CLR_BIT(DDRD_ITI,3);
			SET_BIT(PORTD_ITI,3);
			break;
		case EXTI2:
			SET_BIT(GICR_REG,INT2);
			CLR_BIT(DDRB_ITI,2);
			SET_BIT(PORTB_ITI,2);
			break;
		default : break;
	}
}
void EXTI_Disable(EXT_type interrupt)
{
	switch (interrupt)
	{
		case EXTI0:
			CLR_BIT(GICR_REG,INT0);
			break;
		case EXTI1:
			CLR_BIT(GICR_REG,INT1);
			break;
		case EXTI2:
			CLR_BIT(GICR_REG,INT2);
			break;
		default : break;
	}

}

#if EXTI0_USAGE == EXTI0_POLLING



u8 EXTI0_u8Checkflag(void)
{

	u8 flag = GET_BIT(GIFR_REG,INTF0);

return flag;
}
void EXTI0_voidClearFlag(void)
{


	SET_BIT(GIFR_REG,INTF0);

}
#endif

#if EXTI1_USAGE == EXTI1_POLLING



u8 EXTI1_u8Checkflag(void)
{

	u8 flag = GET_BIT(GIFR_REG,INTF1);

return flag;
}
void EXTI1_voidClearFlag(void)
{


	SET_BIT(GIFR_REG,INTF1);

}
#endif

#if EXTI2_USAGE == EXTI2_POLLING



u8 EXTI2_u8Checkflag(void)
{

	u8 flag = GET_BIT(GIFR_REG,INTF2);

return flag;
}
void EXTI2_voidClearFlag(void)
{


	SET_BIT(GIFR_REG,INTF2);

}
#endif





// Callback Functions
#if EXTI0_USAGE == EXTI0_INTERRUPT

void setCallback_INT0(void (*Fptr)())
{

	INT0_ptr = Fptr;

}
#endif

#if EXTI1_USAGE == EXTI1_INTERRUPT

void setCallback_INT1(void (*Fptr)())
{
	INT1_ptr = Fptr;

}
#endif

#if EXTI2_USAGE == EXTI2_INTERRUPT

void setCallback_INT2(void (*Fptr)())
{
	INT2_ptr = Fptr;
}
#endif

// ISR Functions
#if EXTI0_USAGE == EXTI0_INTERRUPT
/*ISR(INT0_vect)*/
void __vector_1 (void)
{
	if (INT0_ptr != Null){
		INT0_ptr();
	}
}
#endif

#if EXTI1_USAGE == EXTI1_INTERRUPT
/*ISR(INT1_vect)*/
void __vector_2 (void)
{
	if (INT1_ptr != Null){
		INT1_ptr();
	}
}
#endif

#if EXTI2_USAGE == EXTI2_INTERRUPT
/*ISR(INT2_vect)*/
void __vector_3 (void)
{
	if (INT2_ptr != Null){
		INT2_ptr();
	}
}
#endif
