/*************************************************************/
/* SPI_private_h
*creat on September 16,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#ifndef SPI_private_h_
#define SPI_private_h_

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_Register;


#define MSPI1	((volatile SPI_Register*)0x40013000)



#endif /*SPI_private_h*/