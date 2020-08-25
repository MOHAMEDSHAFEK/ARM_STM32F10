/*
 * main.c
 *
 *  Created on: Mar 17, 2020
 *      Author: shfek
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"


#define DELAY_SIZE   1000000



void my_delay(void)
{
	for(u32 i=0; i<DELAY_SIZE; i++)
	{
		asm("NOP");
	}
}

int main(void)
{
	/*Initialize*/
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2,GPIOA_ENABLE);

	 MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	// DIO_voidSetPinDirection(PORTA,PIN1,OUTPUT_2MHZ_GPPP);

	 MNVIC_voidInit();
	 MNVIC_voidSetPriorityS(6,0b01000000);
	 MNVIC_voidSetPriorityS(7,0b00110000);
	 // Enable EXTI0 Interrupt from NVIC
	 MNVIC_voidEnableInterrupt(6);
	 MNVIC_voidEnableInterrupt(7);
	 MNVIC_voidSetPendingFlag(6);


	while(1)
	{



	}
}


void EXTI0_IRQHandler(void) /*be very precise in this naming convention*/
{							/* this is like TMR0_vect in AVR in terms of reserved naming   */
	MGPIO_ViodSetPinValue(GPIOA,PIN0,HIGH);
	MNVIC_voidSetPendingFlag(7);
	my_delay();
	MGPIO_ViodSetPinValue(GPIOA,PIN1,HIGH);
}

void EXTI1_IRQHandler(void)
{
	MGPIO_ViodSetPinValue(GPIOA,PIN2,HIGH);
}

void EXTI2_IRQHandler(void)
{

}
