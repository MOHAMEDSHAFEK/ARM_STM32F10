/*************************************************************/
/* DMA_private_h
*creat on September 12,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#ifndef DMA_private_h_
#define DMA_private_h_



typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
}DMA_Channel;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;

#define DMA	((volatile DMA_t*)0x40020000)



#endif /*DMA_private_h*/