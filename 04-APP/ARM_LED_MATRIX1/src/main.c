/*
 * main.c
 *
 *  Created on: Aug 31, 2020
 *      Author: shafek
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "LED_MATRIX_interface.h"
#include "LED_MATRIX_config.h"
	u8 Array_LEDMatrix[42]={124, 4, 8, 16, 8, 4, 124, 0, 24, 36, 66, 36, 24, 0, 126, 16, 16, 112, 0, 36, 84, 84, 124, 0, 124, 4, 12, 16, 8, 4, 124, 0, 124, 84, 84, 92, 0, 32, 80, 80, 126};
	LED_MATRIX_PIN led_matrix_col_pins[NO_ROWS] = {

			{GPIOB,PIN0},
			{GPIOB,PIN1},
			{GPIOB,PIN5},
			{GPIOB,PIN6},
			{GPIOB,PIN7},
			{GPIOB,PIN8},
			{GPIOB,PIN9},
			{GPIOB,PIN10}


	};

	LED_MATRIX_PIN led_matrix_row_pins[NO_COLS] = {
			{GPIOA,PIN0},
			{GPIOA,PIN1},
			{GPIOA,PIN2},
			{GPIOA,PIN3},
			{GPIOA,PIN4},
			{GPIOA,PIN5},
			{GPIOA,PIN6},
			{GPIOA,PIN7}
	};
void main (void)
{

	/*Initialize*/
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2,GPIOA_ENABLE);
	 RCC_voidEnableClock(RCC_APB2,GPIOB_ENABLE);
	 HLEDMARX_voidInit(led_matrix_row_pins,led_matrix_col_pins);
	 MSTK_voidInit();
	 HLEDMARX_voidDisplay(Array_LEDMatrix);
		while(1)
		{

		}
}
