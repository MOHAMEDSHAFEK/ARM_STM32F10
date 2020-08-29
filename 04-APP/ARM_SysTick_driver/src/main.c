/*
 * main.c
 *
 *  Created on: Aug 25, 2020
 *      Author: shafek
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
void function1(void);
u8 counter=0;
int main(void)
{
	/*Initialize*/
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2,GPIOA_ENABLE);
	 MSTK_voidInit();
	 MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	 MSTK_voidSetIntervalPeriodic(1000,function1);
	// MSTK_voidSetIntervalSingle(1000,function1);
	while(1)
	{

	}
}
void function1(void)
{
	if(counter==0){
		MGPIO_ViodSetPinValue(GPIOA,PIN0,HIGH);
		counter++;
	}
	else
	{
		MGPIO_ViodSetPinValue(GPIOA,PIN0,LOW);
		counter=0;
	}
}
