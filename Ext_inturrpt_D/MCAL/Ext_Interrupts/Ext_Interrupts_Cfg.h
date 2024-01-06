/*
 * Ext_Interrupts_Cfg.h
 *
 *  Created on: 22/9/2022
 *      Author: Mohamed Samir
 */

#ifndef MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_CFG_H_
#define MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_CFG_H_



//****************************************
// Interrupt MODEs
//ENABLE or DISABLE the pin interrupt
#define EXT_INT0_MODE	ENABLE
#define EXT_INT1_MODE	DISABLE
#define EXT_INT2_MODE	DISABLE

// sense modes =>  LOW_LEVEL_TRIG - ONCHANGE - FALLING_EDGE_TRIG - RAISING_EDGE_TRIG
#define INT0_SENSE_MODE	FALLING_EDGE_TRIG
#define INT1_SENSE_MODE	FALLING_EDGE_TRIG
#define INT2_SENSE_MODE	FALLING_EDGE_TRIG

// external interrupt Usage EXTI0_INTERRUPT - EXTI0_POLLING
#define EXTI0_USAGE    EXTI0_INTERRUPT
#define EXTI1_USAGE    EXTI1_INTERRUPT
#define EXTI2_USAGE    EXTI2_INTERRUPT

#endif /* MCAL_EXT_INTERRUPTS_EXT_INTERRUPTS_CFG_H_ */
