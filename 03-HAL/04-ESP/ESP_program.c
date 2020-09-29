/*
 * ESP_interface.h
 *
 *  Created on: September 28, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**********************************************/
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"
/********************************************/

/*******************************************/
#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"
/********************************************/

void MESP_voidInit(void)
{
	u8 Local_u8Result =0;
	while(Local_u8Result==0)
	{
		/*stop echo*/
		MUSART_voidTransmit("ATE0\r\n");
		Local_u8Result=voidEspValidatecmd();
	}
	Local_u8Result=0;
	while(Local_u8Result==0)
	{
		/*stop echo*/
		MUSART_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Result=voidEspValidatecmd();
	}
	
	
	
}

u8 voidEspValidatecmd(void)
{
	u8 Result =0
	u8 i = 0;
	u8 Dummy=0;
	u8 Local_u8Response[100]={0};
	while (Dummy !=255) 
	{
		Dummy=MUSART_voidREceive();
		Local_u8Response[i]=Dummy;
		i++;
	}
	/*check if ok*/
	if (Local_u8Response[0]=='o'&&Local_u8Response[1]=='k')
	{
		Result = 1;
	}
	
	return Result;
	
}



u8 MUSART_voidREceive(void)
{
	u16 timeout =0;
	u8 Loc_u8RecivedData =0
	while((MUSART->SR)&1<<5)==0)
	{
		timeout++;
		if(timeout == 10000)
		{
			Loc_u8RecivedData=255;
			break;
		}
	}
	if (Loc_u8RecivedData==0)
	{
		Loc_u8RecivedData=(0xFF&(MUSART->DR));
	}
	return Loc_u8RecivedData;
}
