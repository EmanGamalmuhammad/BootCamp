/*
 * AVR_Drivers.c
 *
 * Created: 2/20/2019 11:41:46 PM
 * Author : AVE-LABS-50
 */ 


#include "Types.h"
#include "BitwiseOperations.h"

#include "DIO.h"
#include "Timer0.h"
#include "LCD.h"

#include "Schedular_Preemptive.h"

int main(void)
{
	/* Replace with your application code */
	
	Task_Init();
	
	#if 0
	schedulerInit_AndStart();
	
	scheduler_Add_Task(Task1);
	scheduler_Add_Task(Task2);
	scheduler_Add_Task(Task3); 
#endif
	
	
	SchedulerStruct Task_1 = {Task1, NUM_3000, NUM_3000, 3};
	SchedulerStruct Task_2 = {Task2, NUM_2000, NUM_2000, 2};
	SchedulerStruct Task_3 = {Task3, NUM_1000, NUM_1000, 1};
	schedulerInit();
	
	SchedulerStruct_Add_Task(Task_1);
	SchedulerStruct_Add_Task(Task_2);
	SchedulerStruct_Add_Task(Task_3);
	
	schedulerStart();

	return NUM_0 ;
}


