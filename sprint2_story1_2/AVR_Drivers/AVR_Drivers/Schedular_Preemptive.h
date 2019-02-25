/*
 * Schedular_Preemptive.h
 *
 * Created: 2/24/2019 3:01:52 PM
 *  Author: AVE-LABS-50
 */ 


#ifndef SCHEDULAR_PREEMPTIVE_H_
#define SCHEDULAR_PREEMPTIVE_H_

#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"

#include "Timer0.h"

#define Max_Size 3
#define False  0
#define True   1

/* create pointer to function */
typedef void (* FuncPtr)(void);

/*create struct with the struct elements are:
element 1: pointer to task function (void/void).
element 2: task periodicity (in OS_ticks unit) (Never changes at runtime)
element 3: runtime processing variable to detect remaining ticks before task execution at runtime to satisfy task periodicity
The scheduler shall execute the task function only at it's periodicity.
 */  
typedef struct{
	
	FuncPtr Func_Ptr ;
	uint16 periodicity ;
	uint16 Remaining_Ticks ;
	uint16 Priority ;
	
	}SchedulerStruct;

/* create array of structs */
SchedulerStruct StructArray[Max_Size]; 

/************************************************************************/
/* FUNCTION NAME: scheduler_Add_Task                                    */
/* @Param: pointer to function of task                                  */
/* return: true or false status                                         */
/* FUNCTION Description: add struct of task to array of structs         */
/************************************************************************/
uint8 scheduler_Add_Task (FuncPtr);

/************************************************************************/
/* FUNCTION NAME: SchedulerStruct_Add_Task                              */
/* @Param: struct of task                                               */
/* return: true or false status                                         */
/* FUNCTION Description: add struct of task to array of structs         */
/************************************************************************/
uint8 SchedulerStruct_Add_Task (SchedulerStruct TaskStruct);

/************************************************************************/
/* FUNCTION NAME: schedulerStart                                        */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Start scheduler                                */
/************************************************************************/
void schedulerStart (void);

/************************************************************************/
/* FUNCTION NAME: schedulerInit                                         */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of scheduler                    */
/************************************************************************/
void schedulerInit (void);

/************************************************************************/
/* FUNCTION NAME: schedulerInit_AndStart                                */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of scheduler And Start          */
/************************************************************************/
void PreeschedulerInit_AndStart(void) ;

//***********************************************************************************/
/* FUNCTION NAME: scheduler                                                         */
/* @Param: takes a prefilled array of structs to void/void functions                */
/* return: void                                                                     */
/* FUNCTION Description: execute the array of tasks                                 */
/************************************************************************************/
void Preescheduler(void);

/************************************************************************/
/* FUNCTION NAME: Set_Flag                                              */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Set_Flag when interrupt occurs                 */
/************************************************************************/
void Pree_Set_Flag(void);

extern uint8 volatile i ;
extern uint8 volatile flag;


#endif /* SCHEDULAR_PREEMPTIVE_H_ */