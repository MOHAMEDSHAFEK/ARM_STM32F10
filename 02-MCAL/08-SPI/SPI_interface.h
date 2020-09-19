/*************************************************************/
/* SPI_interface.h
*creat on September 16,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#ifndef SPI_interface_c_
#define SPI_interface_c_
#define  


void MSPI1_voidInit(void);
void MSPI1_voidSendREceiveSynch(vu8 Copy_u8DataToTransmit,u8 *Copy_u8DataToReceive);
void MSPI1_voidSendREceiveAsynch(vu8 Copy_u8DataToTransmit, void(*CallBack)(u8));
#endif  /*SPI_interface_c_*/