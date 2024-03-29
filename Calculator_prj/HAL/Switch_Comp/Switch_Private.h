/*
 * Switch_Private.h
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#ifndef HAL_SWITCH_SWITCH_PRIVATE_H_
#define HAL_SWITCH_SWITCH_PRIVATE_H_


typedef enum
{
	SwitchNoError,
	SwitchGroupNumError,
	SwitchPinNumError

}SwitchErrState;

typedef enum
{
	PressedPullUp,
	NotPressedPullUp,
	NotPressedPullDown=0,
	PressedPullDown,


}SwitchState;

typedef enum
{
	InternalPullUp,
	ExternalPullUp,
	ExternalPullDown
}SwitchConnectionType;


#endif /* HAL_SWITCH_SWITCH_PRIVATE_H_ */
