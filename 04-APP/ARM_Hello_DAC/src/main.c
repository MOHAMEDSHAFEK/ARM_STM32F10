/*
 * main.c
 *
 *  Created on: Sebtemper 7, 2020
 *      Author: shfek
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "song1.h"
#include "SYSTICK_interface.h"
volatile u16 i=0;
//void EXT1_func(void);
void main(void)
{
	/*RCC Initialize*/
	 RCC_voidInitSysClock();
	// RCC_voidEnableClock(RCC_APB2,AFIO_ENABLE);
	 RCC_voidEnableClock(RCC_APB2,GPIOA_ENABLE);

	 /*PINA2 as a output*/
	 MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN6,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP);
	 /*Enable systick/ */
	 MSTK_voidInit();
	 /*callback for external interrupt*/
	 MSTK_voidSetIntervalPeriodic(125,voidSetDAC);

	while(1)
	{

	}
}


void voidSetDAC(void)
{
	 u8 t=0;
	for(int j=0;j<8;j++)
	{
		t=GET_BIT(song1_raw[i],j);
		switch(j)
		{
			case 0: 		 MGPIO_voidSetPinValue(GPIOA,PIN0,t); break;
			case 1: 		 MGPIO_voidSetPinValue(GPIOA,PIN1,t); break;
			case 2: 		 MGPIO_voidSetPinValue(GPIOA,PIN2,t); break;
			case 3: 		 MGPIO_voidSetPinValue(GPIOA,PIN3,t); break;
			case 4: 		 MGPIO_voidSetPinValue(GPIOA,PIN4,t); break;
			case 5: 		 MGPIO_voidSetPinValue(GPIOA,PIN5,t); break;
			case 6: 		 MGPIO_voidSetPinValue(GPIOA,PIN6,t); break;
			case 7: 		 MGPIO_voidSetPinValue(GPIOA,PIN7,t); break;
		}
	}
	i++;
	if(i==39288)
	{
		i=0;
	}
}



