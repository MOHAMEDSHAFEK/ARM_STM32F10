/*************************************************************/
/* UART_private_h
*creat on September 19,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#ifndef UART_private_h_
#define UART_private_h_

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
}USART_Register;


#define MUSART	((volatile USART_Register*)0x40013800)



#endif /*UART_private_h*/