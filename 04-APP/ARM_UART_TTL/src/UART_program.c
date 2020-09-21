/*************************************************************/
/* UART_program.c
*creat on September 19,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***************************************************/

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUSART_voidInit(void)
{
	/*9600 BRR´0x341*/
	MUSART->BRR=0x341;
	/*
		1- Enable RX
		2- ENABLE TX
		3- ENABLE USART
	*/
	 SET_BIT(MUSART->CR1,2);
	 SET_BIT(MUSART->CR1,3);
	 SET_BIT(MUSART->CR1,13);
	 /*clear  status registers */
	 MUSART->SR=0;
}
void MUSART_voidTransmit(u8 copy_u8Arry[])
{
	u8 Local_u8SizeOfArray=0;
	while(copy_u8Arry[Local_u8SizeOfArray]!='\0')
	{
		MUSART->DR=copy_u8Arry[Local_u8SizeOfArray];
		/*while(GET_BIT(MUSART->SR,6)==0)*/
		while(GET_BIT(MUSART->SR,6)==0);
		//while((MUSART->SR)&0x40)==0);
		Local_u8SizeOfArray++;
	}
}
u8 MUSART_voidREceive(void)
{
	while(GET_BIT(MUSART->SR,5)==0);
	//while((MUSART->SR)&1<<5)==0);
	return (0xFF&(MUSART->DR));
}
