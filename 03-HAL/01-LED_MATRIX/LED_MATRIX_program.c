
/*
 * LED_MATRIX_program.c
 *
 *  Created on: August 31, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "LED_MATRIX_interface.h"
#include "LED_MATRIX_private.h"
#include "LED_MATRIX_config.h"

LED_MATRIX_PIN  row_pins_private[NO_ROWS] ;
LED_MATRIX_PIN  col_pins_private[NO_COLS] ;

void HLEDMARX_voidInit(LED_MATRIX_PIN *copy_rowpin,LED_MATRIX_PIN *copy_colpin )
{
	u8 i=0;
	for(i=0;i<NO_COLS;i++)
	{
		MGPIO_voidSetPinDirection(copy_colpin[i].port,copy_colpin[i].pin,OUTPUT_SPEED_2MHZ_PP);
		col_pins_private[i]=copy_colpin[i];
	}
	for(i=0;i<NO_ROWS;i++)
	{
		MGPIO_voidSetPinDirection(copy_rowpin[i].port,copy_rowpin[i].pin,OUTPUT_SPEED_2MHZ_PP);
		row_pins_private[i]=copy_rowpin[i];
	}
/*
	MGPIO_voidSetPinDirection(LEDMRX_COL0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7,OUTPUT_SPEED_2MHZ_PP);
	/*row
	MGPIO_voidSetPinDirection(LEDMRX_ROW0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7,OUTPUT_SPEED_2MHZ_PP);
	*/
}

void HLEDMARX_voidDisplay(u8 *copyDataArray)
{
	while(50)
	{
			/*Enable column 0*/
		HLEDMARX_voidDisableAllCols();
		HLEDMARX_voidSetRowValue(copyDataArray[0]);
		MGPIO_voidSetPinValue(GPIOA,PIN0,LOW);
		MSTK_voidSetBusyWait(2500);  //2.5msec
			/*Enable column 1*/
		HLEDMARX_voidDisableAllCols();
		HLEDMARX_voidSetRowValue(copyDataArray[1]);
		MGPIO_voidSetPinValue(GPIOA,PIN1,LOW);
		MSTK_voidSetBusyWait(2500);  //2.5msec
			/*Enable column 2*/
		HLEDMARX_voidDisableAllCols();
		HLEDMARX_voidSetRowValue(copyDataArray[2]);
		MGPIO_voidSetPinValue(GPIOA,PIN2,LOW);
		MSTK_voidSetBusyWait(2500);  //2.5msec
			/*Enable column 3*/
		HLEDMARX_voidDisableAllCols();
		HLEDMARX_voidSetRowValue(copyDataArray[3]);
		MGPIO_voidSetPinValue(GPIOA,PIN3,LOW);
		MSTK_voidSetBusyWait(2500);  //2.5msec
			/*Enable column 4*/
		HLEDMARX_voidDisableAllCols();
		HLEDMARX_voidSetRowValue(copyDataArray[4]);
		MGPIO_voidSetPinValue(GPIOA,PIN4,LOW);
		MSTK_voidSetBusyWait(2500);  //2.5msec
			/*Enable column 5*/
		HLEDMARX_voidDisableAllCols();
		HLEDMARX_voidSetRowValue(copyDataArray[5]);
		MGPIO_voidSetPinValue(GPIOA,PIN5,LOW);
		MSTK_voidSetBusyWait(2500);  //2.5msec
			/*Enable column 6*/
		HLEDMARX_voidDisableAllCols();
		HLEDMARX_voidSetRowValue(copyDataArray[6]);
		MGPIO_voidSetPinValue(GPIOA,PIN6,LOW);
		MSTK_voidSetBusyWait(2500);  //2.5msec
			/*Enable column 7*/
		HLEDMARX_voidDisableAllCols();
		HLEDMARX_voidSetRowValue(copyDataArray[7]);
		MGPIO_voidSetPinValue(GPIOA,PIN7,LOW);
		MSTK_voidSetBusyWait(2500);  //2.5msec
	}
}

static void HLEDMARX_voidDisableAllCols(void)
{
	/*
	u8 i=0;
	for(i=0;i<NO_COLS;i++)
	{
		MGPIO_voidSetPinValue(col_pins_private[i].port,col_pins_private[i].pin,HIGH);
	}
			Disable all colums*/
	MGPIO_voidSetPinValue(GPIOA,PIN0,HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN1,HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN2,HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN3,HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN4,HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN5,HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN6,HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN7,HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN8,HIGH);

}

static void HLEDMARX_voidSetRowValue(u8 copy_u8RowValue)
{
	u8 Local_u8BIT=0;
		/*row*/
	Local_u8BIT=GET_BIT(copy_u8RowValue,0);
	MGPIO_voidSetPinValue(GPIOB,PIN0,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(copy_u8RowValue,1);
	MGPIO_voidSetPinValue(GPIOB,PIN1,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(copy_u8RowValue,2);
	MGPIO_voidSetPinValue(GPIOB,PIN5,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(copy_u8RowValue,3);
	MGPIO_voidSetPinValue(GPIOB,PIN6,Local_u8BIT);

	Local_u8BIT=GET_BIT(copy_u8RowValue,4);
	MGPIO_voidSetPinValue(GPIOB,PIN7,Local_u8BIT);

	Local_u8BIT=GET_BIT(copy_u8RowValue,5);
	MGPIO_voidSetPinValue(GPIOB,PIN8,Local_u8BIT);

	Local_u8BIT=GET_BIT(copy_u8RowValue,6);
	MGPIO_voidSetPinValue(GPIOB,PIN9,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(copy_u8RowValue,7);
	MGPIO_voidSetPinValue(GPIOB,PIN10,Local_u8BIT);
}
