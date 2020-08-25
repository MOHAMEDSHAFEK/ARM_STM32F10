/***********************************************************************/
/*
 * EXTI_private.h
 *
 *  Created on: August 24, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
/************************************************************************/
#ifndef EXTI_private_H_
#define EXTI_private_H_


typedef struct {
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
	
	
}EXTI_t;


#define EXTI ((volatile EXTI_t *)0x40010400)
		
		
#define EXTI_LINE0    0
#define EXTI_LINE1    1
#define EXTI_LINE2    2
#define EXTI_LINE3    3
#define EXTI_LINE4    4
#define EXTI_LINE5    5
#define EXTI_LINE6    6
#define EXTI_LINE7    7
#define EXTI_LINE8    8
#define EXTI_LINE9    9
#define EXTI_LINE10   10
#define EXTI_LINE11   11
#define EXTI_LINE12   12
#define EXTI_LINE13   13
#define EXTI_LINE14   14
#define EXTI_LINE15   15

#defone RISING         0
#defone FALLING        1
#defone ON_CHANGE      2

#endif /* EXTI_private_H_ */