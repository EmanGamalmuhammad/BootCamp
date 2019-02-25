/*
 * Schedular_Preemptive.c
 *
 * Created: 2/24/2019 3:01:27 PM
 *  Author: AVE-LABS-50
 */ 

#include "Schedular_Preemptive.h"

uint32 volatile ArrayIndex = NUM_0;
uint32 volatile indexa = NUM_0;
uint32 volatile j ;



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
	SchedulerStruct temp ; /* temperory struct */
	
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
		
		/************************************************************************/
		/* sorting the array of tasks depends on it's priority                  */
		/************************************************************************/
		for(j=NUM_0; j < ArrayIndex; j++)
		{
			for(indexa=j+1; indexa < ArrayIndex; indexa++)
			{
				if ((StructArray[indexa].Priority) < (StructArray[j].Priority))
				{
					temp = StructArray[indexa] ;
					StructArray[indexa] = StructArray[j];
					StructArray[j] = temp ;
				}
			}
			
		}
	}
	
	else
	{
		return False ;
	}
	
}

/************************************************************************/
/* FUNCTION NAME: scheduler_Remove_Task                                 */
/* @Param: pointer to task that will be removed                         */
/* return: void                                                         */
/* FUNCTION Description: remove task                                    */
/************************************************************************/
void scheduler_Remove_Task (FuncPtr Task)
{

	for(indexa=NUM_0; indexa<(ArrayIndex); indexa++)
	{
		if((StructArray[indexa].Func_Ptr) == Task)
		{
			for(j=indexa; j< (ArrayIndex); j++)
			{
				StructArray[j] = StructArray[j+1];
			}
			ArrayIndex--;
		}
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
	/* call Pree_Set_Flag func. that sets the flag  */
	Set_Call_Back(Pree_Set_Flag);
	
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
	
			for(indexa=NUM_0; indexa < ArrayIndex; indexa++)
			{
				/* decrement the remaining ticks of task */
				(StructArray[indexa].Remaining_Ticks)-- ;
				
				if (( NUM_0 == (StructArray[indexa].Remaining_Ticks) ) )
				{
			
					/* implement the task */
					StructArray[indexa].Func_Ptr() ;
					
					StructArray[indexa].Remaining_Ticks = StructArray[indexa].periodicity ;

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
			/* call func. to remove certain task  */
			scheduler_Remove_Task(Task2);

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

