/*
 * WDT_interface.h
 *
 *  Created on: Dec 20, 2022
 *      Author: abdullah
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_
#include "../../Common/STD_TYPES.h"
#include "../../Common/bitMath.h"

#define WDT_NOT_USE  0
#define WDT_USE      1

#define WDT_16_3_MS  0
#define WDT_32_5_MS  1
#define WDT_65_MS    2
#define WDT_130_MS   3
#define WDT_260_MS   4
#define WDT_520_3MS  5
#define WDT_1000_3MS 6
#define WDT_2100_MS  7

void WDT_voidSleep   ( u8 Copy_u8SleepTime );
void WDT_voidDisable (void);
void WDT_voidRefresh (void);

#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
