/*
 * Timer0.c
 *
 * Created: 2/13/2019 4:06:21 PM
 *  Author: AVE-LABS-50
 */ 

#include <avr/interrupt.h>


#include "Timer0.h"

extern uint8 volatile i ;

uint16 volatile counter = NUM_0 ;
void (*ptr_func)(void) ;

/************************************************************************/
/* FUNCTION NAME: Timer0_CTC_Init                                       */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of CTC Mode in Timer0           */
/************************************************************************/
void Timer0_CTC_Init(void)
{
	/* CTC mode */
	
	Clear_Bit(TCCR0,BIT_7);
	Clear_Bit(TCCR0,BIT_6);
	Clear_Bit(TCCR0,BIT_5);
	Clear_Bit(TCCR0,BIT_4);
	Set_Bit(TCCR0,BIT_3);

	/* overflow flag 
	Set_Bit(TIFR,0);
	Set_Bit(TIFR,1); */
	
	/* prescaler /64 */
	Clear_Bit(TCCR0,BIT_2);
	Set_Bit(TCCR0,BIT_1);
	Set_Bit(TCCR0,BIT_0);
	
	/* Interrupt enable */
	Set_Bit( SREG, BIT_7);
	Set_Bit(TIMSK, BIT_1);
	
	TCNT0 = NUM_0;
	OCR0 = OCR0_8MHZ ;
	// OCR0 = 249;
}

/************************************************************************/
/* FUNCTION NAME: Dimer_Delay                                           */
/* @Param: no. of milli seconds                                         */
/* return: void                                                         */
/* FUNCTION Description: Making Delay by using CTC Mode in Timer0       */
/************************************************************************/
void Timer_Delay(uint32 n)
{
	uint32 i;
	for(i=NUM_0; i< n;i++)
	{
		while ((TIFR & TIFR_flag)== NUM_0);
		Set_Bit(TIFR,BIT_1);
	}
}

void Set_Call_Back(void (*ptr)(void))
{
	ptr_func = ptr;
}


/************************************************************************/
/* Interrupt of CTC Mode in Timer0                                      */
/************************************************************************/
ISR(TIMER0_COMP_vect)
{
	/* counter++ ; */
	ptr_func();
	
}