/*
 * TFT_interface.h
 *
 *  Created on: September 21, 2020
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
#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"
/********************************************/

void HTFT_voidInitialize(void)
{
	/*  Reset Pulse */
	MGPIO_voidSetPinValue(TFT_REST_PULSE,HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_REST_PULSE,LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_REST_PULSE,HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_REST_PULSE,LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_REST_PULSE,HIGH);
	MSTK_voidSetBusyWait(120000);
	
	/* sleep out command */
	voidWriteCommand(0x11);
	/* wait 150 ms */
	MSTK_voidSetBusyWait(150000);
	/* color mode command */
	voidWriteCommand(0x3A);
	voidWriteData(0x05);
	/* Display on command */
	voidWriteCommand(0x29);
	
	
	
	
}
void HTFT_voidDisplayImage(const u16* copy_u16Image)
{
	u16 counter;
		/* set X address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);     //set first  X positio
	voidWriteData(0);
	voidWriteData(127);  //set end  X positio
		/* set Y address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);     //set first  Y positio
	voidWriteData(0);
	voidWriteData(159);  //set end  Y positio
		/* command RAM write */
	voidWriteCommand(0x2C);
	//voidWriteData(0xffff);    //first pixail black
	for(counter=0;counter<20480;counter++)
	{
		/* Write the high byte*/
		voidWriteData(copy_u16Image[counter]>>8);
		/* Write the low  byte*/
		voidWriteData(copy_u16Image[counter]&0x00ff);
	}

}


static void voidWriteCommand(u8 copy_u8Command)
{
	u8 Local_u8Temp;
		/* Set A0 Pin to Low*/
	MGPIO_voidSetPinValue(TFT_A0_PIN,LOW);
		/*send command over SPI*/
	MSPI1_voidSendReceiveSynch(copy_u8Command,&Local_u8Temp);
}

static void voidWriteData(u8 copy_u8Data)
{
	u8 Local_u8Temp;
		/* Set A0 Pin to HIGH*/
	MGPIO_voidSetPinValue(TFT_A0_PIN,HIGH);
		/*send over over SPI*/
	MSPI1_voidSendReceiveSynch(copy_u8Data,&Local_u8Temp);
}
