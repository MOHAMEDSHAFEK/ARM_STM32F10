#include ""


void LED0(void);
void LED1(void)
void LED2(void)
int main(void)
{
	/*intialization */
	//RCC_Intialiazation
	//Enable GPIO RCCC  PORTA
	
	//GPIO Intialiazation
	SOS_voidCreateTask(0,1000, LED0);
	SOS_voidCreateTask(1,2000, LED1);
	SOS_voidCreateTask(2,3000, LED2);
	SOS_voidStart();
	while(1)
	{
		
		
	}
	return 0;
}

void LED0(void)
{
	static u8 copy_u8LocalPin0=0;
	TOG_BIT(copy_u8LocalPin0,0);
	MGPIO_voidSetPinValue(GPIOA,PIN0,copy_u8LocalPin0);
}
void LED1(void)
{
	static u8 copy_u8LocalPin0=0;
	TOG_BIT(copy_u8LocalPin0,0);
	MGPIO_voidSetPinValue(GPIOA,PIN1,copy_u8LocalPin0);
}
void LED2(void)
{
	static u8 copy_u8LocalPin0=0;
	TOG_BIT(copy_u8LocalPin0,0);
	MGPIO_voidSetPinValue(GPIOA,PIN2,copy_u8LocalPin0);
}