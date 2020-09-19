#include "STD_TYPES.h"
#include "BIT_MATH.h"
#inclue"SYSTICK_interface.h"


#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"
/*array of tasks   "array of structure"*/
static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 copy_u8IDPriority, u16 copy_u16priodicity,void(*Fptr)(void))
{
	OS_Tasks[copy_u8IDPriority].priodicity=copy_u16priodicity;
	OS_Tasks[copy_u8IDPriority].Fptr=Fptr;
}
void SOS_voidStart(void)
{
	/*intialization   */
	/*tick time systick inti*/
	MSTK_voidInit();
	/*Tick-> 1 msec*/
	/*HSE 8MHz/8  -> 1000 Micro Sec -> 1 msec */
	MSTK_voidSetIntervalPeriodic(1000,Scheduler);
}
volatile u16 TickCounts=0;
/*ordring for tasks*/
void Scheduler(void)
{
	for(u8 i=0;i<NUMBER_OF_TASKS;i++)
	{
		if(TickCounts%OS_Tasks[i].priodicity==0)
		{
			OS_Tasks[i].Fptr();
		}
	}
	TickCounts++;
}