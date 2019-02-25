/*
 * Tasks.h
 *
 * Created: 2/23/2019 3:01:39 PM
 *  Author: AVE-LABS-50
 */ 


#ifndef TASKS_H_
#define TASKS_H_

#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"

#include "Schedular_Preemptive.h"

typedef void (* task_type)(void);

void Task_Init(void);
void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);



#endif /* TASKS_H_ */