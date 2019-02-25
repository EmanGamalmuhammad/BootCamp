/*
 * Schedular_Preemptive.c
 *
 * Created: 2/24/2019 3:01:27 PM
 *  Author: AVE-LABS-50
 */ 

#include "Schedular_Preemptive.h"

uint32 volatile ArrayIndex = NUM_0;

static uint16 volatile Tickcounter = NUM_0 ;

FuncPtr func ;
FuncPtr DynamicArray[Max_Size] ;

/************************************************************************/
/* FUNCTION NAME: scheduler_Add_Task                                    */
/* @Param: pointer to function of task                                  */
/* return: true or false status                                         */
/* FUNCTION Description: add struct of task to array of structs         */
/************************************************************************/
uint8 scheduler_Add_Task (FuncPtr func)
{
	if (Max_Size > ArrayIndex )
	{
		if (NUM_0 == ArrayIndex)
		{
			DynamicArray[NUM_0] = func ;
			ArrayIndex++;
		} 
		else
		{
			DynamicArray[ArrayIndex] = func ;
			ArrayIndex++;
		}
		return True ;
	} 
	
	else
	{
		return False ;
	}
}

/************************************************************************/
/* FUNCTION NAME: SchedulerStruct_Add_Task                              */
/* @Param: struct of task                                               */
/* return: true or false status                                         */
/* FUNCTION Description: add struct of task to array of structs         */
/************************************************************************/
uint8 SchedulerStruct_Add_Task (SchedulerStruct TaskStruct)
{
	if (Max_Size > ArrayIndex )
	{
		if (NUM_0 == ArrayIndex)
		{
			StructArray[NUM_0] = TaskStruct ;

			ArrayIndex++;
		}
		else
		{
			StructArray[ArrayIndex] = TaskStruct ;

			ArrayIndex++;
		}
		return True ;
	}
	
	else
	{
		return False ;
	}
}

/************************************************************************/
/* FUNCTION NAME: PreeschedulerInit_AndStart                            */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of scheduler And Start          */
/************************************************************************/
void PreeschedulerInit_AndStart(void) 
{
	/* Initialization of Timer0  */
	Timer0_CTC_Init();
	Set_Call_Back(Pree_Set_Flag);
	
	while(NUM_1)
	{
		if (NUM_1 == flag)
		{
			
			Preescheduler();
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
void Pree_Set_Flag(void)
{
	/* Set_Flag when interrupt occurs */
	flag = NUM_1;
}

/************************************************************************************/
/* FUNCTION NAME: scheduler                                                         */
/* @Param: takes a prefilled array of structs to void/void functions                */
/* return: void                                                                     */
/* FUNCTION Description: execute the array of tasks                                 */
/************************************************************************************/
void Preescheduler(void )
{
		/* DynamicArray[i](); */

				for(i=NUM_0; i<Max_Size; i++)
				{
					/* decrement the remaining ticks of task */
					(StructArray[i].Remaining_Ticks)-- ;
				
					if (( NUM_0 == (StructArray[i].Remaining_Ticks) ) )
					{
						/* clear counter */
					
						/* implement the task */
						StructArray[i].Func_Ptr() ;
					
						StructArray[i].Remaining_Ticks = StructArray[i].periodicity ;

					}
				}


}

/************************************************************************/
/* FUNCTION NAME: schedulerStart                                        */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Start scheduler                                */
/************************************************************************/
void schedulerStart (void)
{
	/* Initialization of Timer0  */
	Timer0_CTC_Init();
	
	
	while(NUM_1)
	{
		/* Check if Flag raise when interrupt occurs */
		if (NUM_1 == flag)
		{
			/* call func. of execution the array of tasks  */
			Preescheduler();
			/* clear the flag */
			flag = NUM_0 ;
		}
	}
	
	
}

/************************************************************************/
/* FUNCTION NAME: schedulerInit                                         */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of scheduler                    */
/************************************************************************/
void schedulerInit (void)
{

	/* call Pree_Set_Flag func. that sets the flag  */
	Set_Call_Back(Pree_Set_Flag);
	
}

