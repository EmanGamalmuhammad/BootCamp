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

#include "Schedular.h"

/* #define F_cpu 16000000
   #include <util/delay.h> */

int main(void)
{
	/* Replace with your application code */
	schedulerInit_AndStart();
	

	return NUM_0 ;
}


