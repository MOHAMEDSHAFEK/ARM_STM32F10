/*************************************************************/
/* SPI_program.c
*creat on September 16,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***************************************************/

#include "SPI_Interface.h"
#include "SPI_Prvivate.h"
#include "SPI_Config.h"

void MSPI1_voidSendREceiveSynch(vu8 Copy_u8DataToTransmit,u8 *Copy_u8DataToReceive);
{
	/*Clear For Slave Selct,Pin*/
	MGPIO_voidSetPinValue(MSPI1_SALAVE_PIN ,LOW);
	MSPI1-> DR =Copy_u8DataToTransmit;
	
	/*Wait Busy Flag to finish*/
	while(GET_BIT(MSPI1->SR,7)==1);
	
	/*Return to the received data */
	*Copy_u8DataToReceive=MSPI1->DR;
	
	/*set For Slave Selct,Pin*/
	MGPIO_voidSetPinValue(MSPI1_SALAVE_PIN ,LOW);
}


void STK_Handler(void)
{
	
}
