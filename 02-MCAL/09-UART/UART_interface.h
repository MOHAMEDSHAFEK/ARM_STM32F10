/*************************************************************/
/* UART_interface.h
*creat on September 19,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#ifndef UART_interface_c_
#define UART_interface_c_
#define  


void MUSART_voidInit(void);
void MUSART_voidTransmit(u8 copy_u8Arry[]);
u8 MUSART_voidREceive(void);
void MSPI1_voidSendREceiveSynch(vu8 Copy_u8DataToTransmit,u8 *Copy_u8DataToReceive);
void MSPI1_voidSendREceiveAsynch(vu8 Copy_u8DataToTransmit, void(*CallBack)(u8));
#endif  /*UART_interface_c_*/