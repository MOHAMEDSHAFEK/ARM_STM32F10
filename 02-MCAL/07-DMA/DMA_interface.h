/*************************************************************/
/* DMA_interface.h
*creat on September 12,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#ifndef DMA_interface_c_
#define DMA_interface_c_
#define  


void DMA_voidChannel1Init(void);


void DMA_voidChannel1Start(u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);



#endif  /*DMA_interface_c_*/