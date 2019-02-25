/*
 * Schedular.h
 *
 * Created: 2/23/2019 2:26:54 PM
 *  Author: AVE-LABS-50
 */ 


#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_

#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"

#include "Tasks.h"
#include "Timer0.h"

extern task_type Array[];

/************************************************************************/
/* FUNCTION NAME: schedulerInit_AndStart                                */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of scheduler And Start          */
/************************************************************************/
void schedulerInit_AndStart(void) ;

/************************************************************************************/
/* FUNCTION NAME: scheduler                                                         */
/* @Param: takes a prefilled array of pointers to void/void functions and it's size */
/* return: void                                                                     */
/* FUNCTION Description: execute the tasks in array                                 */
void scheduler(void (*Ptr[])(void),uint8 size );

/************************************************************************/
/* FUNCTION NAME: Set_Flag                                              */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Set_Flag when interrupt occurs                 */
/************************************************************************/
void Set_Flag(void);

extern uint8 volatile i ;
extern uint8 volatile flag;

#endif /* SCHEDULAR_H_ */