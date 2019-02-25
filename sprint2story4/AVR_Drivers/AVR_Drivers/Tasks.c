/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:01:19 PM
 *  Author: AVE-LABS-50
 */ 
#include "Tasks.h"

#if 0
task_type Array[] = { Task1 , Task2 , Task3};
 extern uint8 volatile flag  ;
#endif

void Task_Init(void)
{
	DIO_SetPinDirection(LED1 ,OUTPUT);
	DIO_SetPinDirection(LED2 ,OUTPUT);
	DIO_SetPinDirection(LED3 ,OUTPUT);
}

void Task1(void)
{
	

	#if 0
	DIO_WritePin(LED3 ,LOW);
	DIO_WritePin(LED1 ,HIGH);
	#endif
	Toggle_Bit(PORTB, BIT_5);

	
}
void Task2(void)
{
	
	#if 0
	DIO_WritePin(LED1 ,LOW);
	DIO_WritePin(LED2 ,HIGH);
	#endif
	Toggle_Bit(PORTB, BIT_6);


}
void Task3(void)
{
	
	#if 0
	DIO_WritePin(LED1 ,LOW);
	DIO_WritePin(LED2 ,LOW);
	DIO_WritePin(LED3 ,HIGH);
	#endif
	Toggle_Bit(PORTB, BIT_7);

}
