/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:01:19 PM
 *  Author: AVE-LABS-50
 */ 
#include "Tasks.h"

//task_type Array[] = { Task1 , Task2 , Task3};
	
/*
 extern uint8 volatile flag  ; */

void Task1(void)
{
	
	DIO_SetPinDirection(LED1 ,OUTPUT);
	
	DIO_WritePin(LED3 ,LOW);
	DIO_WritePin(LED1 ,HIGH);


	
}
void Task2(void)
{
	DIO_SetPinDirection(LED2 ,OUTPUT);
		//DIO_WritePin(LED1 ,LOW);
	DIO_WritePin(LED2 ,HIGH);


}
void Task3(void)
{
	DIO_SetPinDirection(LED3 ,OUTPUT);
	DIO_WritePin(LED1 ,LOW);
	DIO_WritePin(LED2 ,LOW);
	DIO_WritePin(LED3 ,HIGH);

}


//void (* Array[NUM_3])(void) = { &Task1 , &Task2 , &Task3};