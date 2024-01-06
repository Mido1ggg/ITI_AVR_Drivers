/*
 * bitMath.h
 *
 *  Created on: 8/9/2022
 *      Author: Mohamed Samir
 */



#ifndef bit_Math_h
#define bit_Math_h

#define SET_BIT(REG,BIT)   REG |= (1<<(BIT)) 
#define TOG_BIT(REG,BIT)   REG ^= (1<<(BIT))
#define CLR_BIT(REG,BIT)   REG &= ~(1<<(BIT))
#define GET_BIT(REG,BIT)   (REG>>BIT) & 0x1
#define ROT_R(REG,Num) 	 	   REG = (REG>>Num) | (REG<<(8-Num))
#define ROT_L(REG,Num) 	 	   REG = (REG<<Num) | (REG>>(8-Num))

#endif
