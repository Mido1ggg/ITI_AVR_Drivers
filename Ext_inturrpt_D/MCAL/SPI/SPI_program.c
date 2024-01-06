/*
 * SPI.c
 *
 *  Created on: 9/10/2022
 *      Author: Mohamed Samir
 */
#include "SPI_Interface.h"

#if SPI_MODE == SPI_MASTER

void SPI_MasterInit(void)
{
	// Enable SPI, Master, set clock rate fck/16
	SET_BIT(SPCR,SPE);
	SET_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPR0);
	//SET_BIT(SPCR,DORD);
	// setup on Failing and sampling on Raising
	SET_BIT(SPCR,CPOL);
	SET_BIT(SPCR,CPHA);

}

#endif

#if SPI_MODE == SPI_SLAVE

void SPI_SlaveInit(void)
{
	SET_BIT(SPCR,SPE);
	//SET_BIT(SPCR,DORD);
	SET_BIT(SPCR,CPOL);
	SET_BIT(SPCR,CPHA);

}
#endif
u8 SPI_TransRecieve(u8 val)
{
	/* Wait for reception complete */
	SPDR=val;
	while(GET_BIT(SPSR,7)==0);
	/* Return data register */
	return SPDR;
}

