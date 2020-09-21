
/************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***************************************************/
#include "RCC_interface.h"
#include "DIO_interface.h"

#include "UART_Interface.h"



void main(void)
{
	/*Initialize*/
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2,GPIOA_ENABLE);
	 RCC_voidEnableClock(RCC_APB2,14); //uart enable clock 
	 MGPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP); //output UART TX
	 MGPIO_voidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);       //Input UART RX
	 MGPIO_voidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_50MHZ_PP);
	 MGPIO_voidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_50MHZ_PP);
	 MUSART_voidInit();
	 
	 u8 data;
	 while(1)
	 {
		 data=MUSART_voidREceive();
		 MUSART_voidTransmit(&data);
		 MUSART_voidTransmit("\r");
		 MUSART_voidTransmit("\n");
			if(data=='A')
			{
				MGPIO_voidSetPinValue(GPIOA,PIN4,HIGH);
				//MUSART_voidTransmit('A');
			}
			else if(data=='B')
			{
				MGPIO_voidSetPinValue(GPIOA,PIN4,LOW);
				//MUSART_voidTransmit('B');
			}
	 }
}
