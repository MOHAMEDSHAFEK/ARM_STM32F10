/*
 * LED_enamtion.c
 *
 *  Created on: Aug 25, 2020
 *      Author: shafek
 */

#include "LED_animation.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"

void LED_voidLEDEnable(LED_animation  copy_structarry[],u8 copy_u8NumberOfLed)
{
	s8 i=0;
	for (i=0 ; i<copy_u8NumberOfLed; i++)
	{
		MGPIO_VoidSetPinDirection(copy_structarry[i].port,copy_structarry[i].pin,OUTPUT_SPEED_2MHZ_PP);
	}
}

void LED_voidPingPong(LED_animation  copy_structarry[],u8 copy_u8NumberOfLed)
{
	s8 i=0;
	s8 j=0;
	for(j=0;j<4;j++)
	{
			for (i=0 ; i<copy_u8NumberOfLed; i++)
			{
				MGPIO_ViodSetPinValue(copy_structarry[i].port,copy_structarry[i].pin,HIGH);
				_delay_ms(200);
			}
			i=0;
			for (i=0 ; i<copy_u8NumberOfLed; i++)
			{
				MGPIO_ViodSetPinValue(copy_structarry[i].port,copy_structarry[i].pin,LOW);
			}
			_delay_ms(100);
			i=0;
			for (i=copy_u8NumberOfLed-1 ; i>=0; i--)
			{
				MGPIO_ViodSetPinValue(copy_structarry[i].port,copy_structarry[i].pin,HIGH);
				_delay_ms(200);
			}
			i=0;
			for (i=0 ; i<copy_u8NumberOfLed; i++)
			{
				MGPIO_ViodSetPinValue(copy_structarry[i].port,copy_structarry[i].pin,LOW);
			}
			_delay_ms(100);
	}
}


void LED_voidOpenFlowerClosFlower(LED_animation  copy_structarry[],u8 copy_u8NumberOfLed)
{
	s8 i=0;
	s8 j=0;
	s8 l=0;
	for(j=0;j<4;j++)
	{
			for (i=0,l=copy_u8NumberOfLed-1 ; i<copy_u8NumberOfLed/2; i++,l--)
			{
				MGPIO_ViodSetPinValue(copy_structarry[i].port,copy_structarry[i].pin,HIGH);
				MGPIO_ViodSetPinValue(copy_structarry[l].port,copy_structarry[l].pin,HIGH);
				_delay_ms(200);
			}
			i=0;
			l=0;
			for (i=(copy_u8NumberOfLed/2-1),l=copy_u8NumberOfLed/2 ; i>=0; i--,l++)
			{
				MGPIO_ViodSetPinValue(copy_structarry[i].port,copy_structarry[i].pin,LOW);
				MGPIO_ViodSetPinValue(copy_structarry[l].port,copy_structarry[l].pin,LOW);
				_delay_ms(200);
			}
			i=0;
			l=0;
			for (i=0 ; i<copy_u8NumberOfLed; i++)
			{
				MGPIO_ViodSetPinValue(copy_structarry[i].port,copy_structarry[i].pin,LOW);
			}
			_delay_ms(100);
	}
}


void LED_voidLEDFladher(LED_animation  copy_structarry[],u8 copy_u8NumberOfLed)
{
	s8 i=0;
	s8 j=0;
	for(j=0;j<8;j++)
	{
			for (i=0 ; i<copy_u8NumberOfLed; i++)
			{
				MGPIO_ViodSetPinValue(copy_structarry[i].port,copy_structarry[i].pin,HIGH);
			}
			_delay_ms(500);
			i=0;
			for (i=0 ; i<copy_u8NumberOfLed; i++)
			{
				MGPIO_ViodSetPinValue(copy_structarry[i].port,copy_structarry[i].pin,LOW);
			}
			_delay_ms(500);
	}
}

