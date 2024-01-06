/*
 * WDT_program.c
 *
 *  Created on: Dec 20, 2022
 *      Author: abdullah
 */


#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_pcfg.h"


#if WDT_USAGE == WDT_USE

void WDT_voidSleep   ( u8 Copy_u8SleepTime ){

	WDTCR_REG = 0b00011000 ;//disable first
	WDTCR_REG = 0 ;
	WDTCR_REG = ( 0b1000 ) | ( Copy_u8SleepTime ) ;

}
void WDT_voidDisable (void){

	WDTCR_REG = 0b00011000 ;
	WDTCR_REG = 0 ;

}
void WDT_voidRefresh (void){

	asm("WDR");

}
#endif
