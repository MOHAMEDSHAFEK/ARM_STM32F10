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
#include "LED_animation.h"
u8 count=0;
int main(void)
{
	/*Initialize*/
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2,GPIOA_ENABLE);
	 MSYSTICK_voidEnabled();
	 MGPIO_VoidSetPinDirection(GPIOA,PIN8,OUTPUT_SPEED_2MHZ_PP);
	 LED_animation MY_LED[]=	{{GPIOA,PIN0},
	 															{GPIOA,PIN1},
	 															{GPIOA,PIN2},
	 															{GPIOA,PIN3},
	 															{GPIOA,PIN4},
	 															{GPIOA,PIN5},
	 															{GPIOA,PIN6},
	 															{GPIOA,PIN7},
	 																				  };
	 LED_voidLEDEnable(MY_LED,8);

	 while(1)
	{
		// _delay_ms(1000);
		LED_voidPingPong(MY_LED,8);
		LED_voidOpenFlowerClosFlower(MY_LED,8);
		LED_voidLEDFladher(MY_LED,8);

	}
}

/*
SysTick_Handler(void)
{
	if(count<1)
	{
	MGPIO_ViodSetPinValue(GPIOA,PIN8,HIGH);
	count++;
	}
	else
	{
		MGPIO_ViodSetPinValue(GPIOA,PIN8,LOW);
		count=0;
	}
}
*/
