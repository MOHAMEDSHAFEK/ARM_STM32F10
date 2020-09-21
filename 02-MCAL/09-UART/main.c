
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
	 MGPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_50MHZ_PP); //output UART TX
	 MGPIO_voidSetPinDirection(GPIOA,PIN9,INPUT_FLOATING);       //Input UART RX
	 MUSART_voidInit();
	 
	 
	 while(1)
	 {
		 
	 }
}
