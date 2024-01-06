/*
 * SPI.h
 *
 *  Created on: 9/10/2022
 *      Author: Mohamed Samir
 */


#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "../../Common/bitMath.h"
#include "../../Common/STD_TYPES.h"
#include <avr/io.h>
#include "SPI_Cfg.h"

void SPI_MasterInit(void);

void SPI_MasterTransmit(char cData);

void SPI_SlaveInit(void);

u8 SPI_TransRecieve(u8 val);



#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
