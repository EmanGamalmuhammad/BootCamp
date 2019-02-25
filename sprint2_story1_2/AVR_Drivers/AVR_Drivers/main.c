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
//#include "Tasks.h"

/* #define F_cpu 16000000
   #include <util/delay.h> */

int main(void)
{
	/* Replace with your application code */
	//schedulerInit_AndStart();
	
	/* scheduler_Add_Task(Task1);
	scheduler_Add_Task(Task2);
	scheduler_Add_Task(Task3); */
	
	SchedulerStruct Task_1 = {Task1, NUM_1000, NUM_1000};
	SchedulerStruct Task_2 = {Task2, NUM_2000, NUM_2000};
	SchedulerStruct Task_3 = {Task3, NUM_3000, NUM_3000};
	schedulerInit();
	
	SchedulerStruct_Add_Task(Task_1);
	SchedulerStruct_Add_Task(Task_2);
	SchedulerStruct_Add_Task(Task_3);
	
	//PreeschedulerInit_AndStart();
	
	schedulerStart();

	return NUM_0 ;
}


