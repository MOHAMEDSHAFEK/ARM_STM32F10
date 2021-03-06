/*
* BIT_MATH.h
*
*  Created on: Jul 29, 2020
*      Author: Mohamed shafek
*     Version: V01
*/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT) (VAR) |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT) (VAR) &= ~(1 << (BIT))
#define TOG_BIT(VAR,BIT) (VAR) ^=  (1 << (BIT))
#define GET_BIT(VAR,BIT) (((VAR) >> (BIT)) & 0x01)

#define NULL ((void*)0)
#endif /* BIT_MATH_H_ */
