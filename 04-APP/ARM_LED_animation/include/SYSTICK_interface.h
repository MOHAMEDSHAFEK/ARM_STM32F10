/*************************************************************/
/* SYSTICK_interface.h
*creat on August 25,2020
*	Auther : Mohamed Shafek
*	version: V01
*
*
*/
/************************************************************/
#ifndef SYSTICK_interface_c_
#define SYSTICK_interface_c_


#define  AHB_8 													 0
#define  PROCESSOR_CLOCK_AHB					 1
#define CLEAR_REGISTER 									 0X00000000
#define MAX_NUMBER_OF_LOAD_SYSTICK     16777216
#define FACTOR_OF_CONVERT_NS_TO_MS       1000

void MSYSTICK_voidEnabled(void);
void MSYSTICK_voidDisabled(void);
void _delay_ms(u32 copy_u32SysticTime);

#endif  /*SYSTICK_interface_c_*/
