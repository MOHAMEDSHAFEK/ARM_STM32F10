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
//void (*Callback) (void)

#define  AHB_8 					0
#define  PROCESSOR_CLOCK_AHB	1
/*Apply clock chice fron configuration file
Disable SysTick intirrupt 
Disable SysTick*/
void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 copy_u32Ticks);

void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks,void (*copy_ptr)(void));
	/*
{

	load_reg =copy_u32Ticks
	//Enable of enterrupt 
	callbak = ptr;
}
*/
/*
void SysTick_Handler(void)
{
	Callback();
}
*/
/*
main()
-----
MSTK_voidSetIntervalSingle(10000,func1)
MSTK_voidSetIntervalSingle(20000,func2)

void func(void)
{
	/*code
}
*/

void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks,void (*copy_ptr)(void));

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTimer(void);

u32 MSTK_u32GetRemainingTimer(void);

void MSYSTICK_voidEnabled(void);
void MSYSTICK_voidDisabled(void);
void _delay_ms(u32 copy_u32SysticTime);

#endif  /*SYSTICK_interface_c_*/