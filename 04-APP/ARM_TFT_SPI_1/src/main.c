
/************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***************************************************/
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"
/************************************************/
#include "TFT_interface.h"
#include "image.h"

void main (void)
{
	/*Initialize*/
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2,GPIOA_ENABLE);
	 RCC_voidEnableClock(RCC_APB2,12); //spi1 enable clock
	 
	 /*Pin Initialization*/
	 MGPIO_voidSetPinDirection(GPIOA,PIN1,0b0010);        //A0
	 MGPIO_voidSetPinDirection(GPIOA,PIN2,0b0010);        //Rest
	 MGPIO_voidSetPinDirection(GPIOA,PIN5,0b1001);       //CLK
	 MGPIO_voidSetPinDirection(GPIOA,PIN7,0b1001);      //MOSI

	 MSPI1_voidInit();
	 MSTK_voidInit();
	 HTFT_voidInitialize();
	 HTFT_voidDisplayImage(image);

	 while(1)
	 {
	 }
}
