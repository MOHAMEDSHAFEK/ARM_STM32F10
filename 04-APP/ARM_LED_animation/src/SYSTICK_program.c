/*************************************************************/
/* SYSTICK_program.c
*creat on August 25,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***************************************************/
#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"
/**********************************************/

void MSYSTICK_voidEnabled(void)
{
	#if CLOCK_SOURCE == AHB_8
		CLR_BIT(STK_CTRL,CLKSOURCE);
	#elif CLOCK_SOURCE == PROCESSOR_CLOCK_AHB
		SET_BIT(STK_CTRL,CLKSOURCE);
	#else
	#endif
		
		CLR_BIT(STK_CTRL,ENABLE);   //Enables the counter for systic timer
}
/*
Bit 1 TICKINT: SysTick exception request enable
0: Counting down to zero does not assert the SysTick exception request
1: Counting down to zero to asserts the SysTick exception request.
Note: Software can use COUNTFLAG to determine if SysTick has ever counted to zero.

*/
void MSYSTICK_voidDisabled(void)
{		
		CLR_BIT(STK_CTRL,ENABLE);   //Enables the counter for systic timer 
}

void _delay_ms(u32 copy_u32SysticTime)
{
	SET_BIT(STK_CTRL,ENABLE);   //Enables the counter for systic timer
	SET_BIT(STK_CTRL,TICKINT);  //Enables the interrupt for systic timer
	copy_u32SysticTime = copy_u32SysticTime*FACTOR_OF_CONVERT_NS_TO_MS;  //convert from micro  to  ms
	if(copy_u32SysticTime<MAX_NUMBER_OF_LOAD_SYSTICK)
	{
		 STK_LOAD =CLEAR_REGISTER;
		 STK_LOAD = STK_LOAD|copy_u32SysticTime;
		 while (1)
		 {
			 if(1==GET_BIT(STK_CTRL,COUNT_FLAG))
			 {
				 break;
			 }
		 }
		 STK_VAL=CLEAR_REGISTER;
	}
}
