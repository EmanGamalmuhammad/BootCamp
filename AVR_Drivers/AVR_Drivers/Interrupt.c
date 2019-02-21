/*
 * Interrupt.c
 *
 * Created: 2/20/2019 7:57:01 PM
 *  Author: AVE-LABS-50
 */ 
#include <avr/interrupt.h> 


#include "Interrupt.h"

uint8 volatile Flag = NUM_0 ;

/************************************************************************/
/* FUNCTION NAME: EXTI2_INIT                                            */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of External interrupt no. 2     */
/************************************************************************/
void EXTI2_INIT(void)
{
	Set_Bit(SREG, BIT_7);
	Set_Bit(GICR, BIT_5);
	Set_Bit(GIFR, BIT_5);
	Set_Bit(MCUCSR, BIT_6);
}

/************************************************************************/
/* External interrupt no. 2                                             */
/************************************************************************/
ISR(INT2_vect)
{
	Flag = NUM_1 ;
}