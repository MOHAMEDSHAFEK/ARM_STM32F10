/****************************************/
/*
 * EXTI_program.c
 *
 *  Created on: August 24, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
 /***************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*****************************************/
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


void MEXTI_VoidInit( void )
{
	#if 	EXTI_MODE == RISING
		SET_BIT(EXTI->RTSR, EXTI_LINE);
	#elif 	EXTI_MODE == FALLING
		SET_BIT(EXTI->FTSR, EXTI_LINE);
	#elif 	EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI->RTSR, EXTI_LINE);
		SET_BIT(EXTI->FTSR, EXTI_LINE);	
	#else #error "wrong mode "
	#endif	
	/*Disable interrupt*/
	CLR_BIT(EXTI->IMR, Copy_u8Line);	
}
void MEXTI_VoidEnable( u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR, Copy_u8Line);	
}
void MEXTI_VoidDisable( u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR, Copy_u8Line);
}
void MEXTI_VoidSwTrigger( u8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER, Copy_u8Line);
}
void MEXTI_VoidSetSignalLatch( u8 Copy_u8Line, u8 copy_u8Mode)
{
	switch(copy_u8Mode)
	{
		case RISING: 	SET_BIT(EXTI->RTSR, EXTI_LINE); break;
		case FALLING:	SET_BIT(EXTI->FTSR, EXTI_LINE); break; 
		case ON_CHANGE:	SET_BIT(EXTI->RTSR, EXTI_LINE);
						SET_BIT(EXTI->FTSR, EXTI_LINE); break;
			
	}
}
