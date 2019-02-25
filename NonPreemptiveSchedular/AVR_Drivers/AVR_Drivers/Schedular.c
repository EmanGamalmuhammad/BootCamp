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
	
	Timer0_CTC_Init();
	Set_Call_Back(Set_Flag);
	while(1)
	{
		if (flag == NUM_1)
		{
			
			scheduler(Array,NUM_3);
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
	for(i=NUM_0; i<size; i++)
	{
		Array[i]();
	}
	if(i >= NUM_3)
	i = NUM_0;
	/*
	if (i<NUM_3)
	{
		Set_Call_Back(Ptr[i]);
		
	}
	if(i>= 3)
		i=0;
				*/			
}