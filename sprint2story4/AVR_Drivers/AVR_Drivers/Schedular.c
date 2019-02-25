/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:27:31 PM
 *  Author: AVE-LABS-50
 */ 

#include "Schedular.h"
uint8 volatile i = NUM_0;
uint8 volatile flag =0 ;

/************************************************************************/
/* FUNCTION NAME: schedulerInit_AndStart                                */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of scheduler And Start          */
/************************************************************************/
void schedulerInit_AndStart(void) 
{
	/* Initialization of Timer0  */
	Timer0_CTC_Init();
	/* call Set_Flag func. that sets the flag  */
	Set_Call_Back(Set_Flag);
	while(1)
	{
		/* Check if Flag raise when interrupt occurs */
		if (flag == NUM_1)
		{
			/* call func. of execution the array of tasks  */
			scheduler(Array,NUM_3);
			/* clear the flag */
			flag = NUM_0 ;
		}
	}
	
	
}

/************************************************************************/
/* FUNCTION NAME: Set_Flag                                              */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Set_Flag when interrupt occurs                 */
/************************************************************************/
void Set_Flag(void)
{
	/* Set_Flag when interrupt occurs */
	flag = NUM_1;
}

/************************************************************************************/
/* FUNCTION NAME: scheduler                                                         */
/* @Param: takes a prefilled array of pointers to void/void functions and it's size */
/* return: void                                                                     */
/* FUNCTION Description: execute the tasks in array                                 */
/************************************************************************************/
void scheduler(void (*Ptr[])(void),uint8 size )
{
	/* loop for execution the array of tasks  */
	for(i=NUM_0; i<size; i++)
	{
		Ptr[i]();
	}
	
	if(i >= NUM_3)
	i = NUM_0;
	
		
}