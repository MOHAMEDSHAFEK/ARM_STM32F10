/*
 * STP_interface.h
 *
 *  Created on: September 14, 2020
 *      Author: Mohamed shafek
 *     Version: V01
 */
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

HSTP_voidSendSynchronus(u8 copy_u8DataToSend)
{
	s8 Local_u8Counter;
	u8 Local_u8Bit;
	for(Local_u8Counter=7; Local_u8Counter>=0;i--)
	{
		/* send bit by bit  starting from MSB*/
		Local_u8Bit=GEt_BIT(copy_u8DataToSend,Local_u8Counter);
		MGBIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);
		
		/*Send pulse to send clock*/
		MGBIO_voidSetPinValue(HSTP_SHIFT_CLOCK,HIGI);
		MSTK_voidSetBusyWait(1);
		MGBIO_voidSetPinValue(HSTP_SHIFT_CLOCK,LOW);
		MSTK_voidSetBusyWait(1);		
	}
				/*Send pulse to store clock*/
		MGBIO_voidSetPinValue(HSTP_STORE_CLOCK,HIGI);
		MSTK_voidSetBusyWait(1);
		MGBIO_voidSetPinValue(HSTP_STORE_CLOCK,LOW);
		MSTK_voidSetBusyWait(1);
}