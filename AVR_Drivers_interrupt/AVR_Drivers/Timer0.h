/*
 * Timer0.h
 *
 * Created: 2/13/2019 4:05:48 PM
 *  Author: AVE-LABS-50
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"
#include "Interrupt.h"

/* Timer0 Registers Addresses */

#define TCNT0   (*((volatile uint8*) 0x52))
#define TCCR0   (*((volatile uint8*) 0x53))
#define OCR0    (*((volatile uint8*) 0x5C))
/* #define GICR    (*((volatile uint8*) 0x5B))
#define GIFR    (*((volatile uint8*) 0x5A))
#define SREG    (*((volatile uint8*) 0x5F)) */
#define TIMSK   (*((volatile uint8*) 0x59))
#define TIFR    (*((volatile uint8*) 0x58))

#define TIFR_flag 0x02
#define OCR0_8MHZ 124
#define OCR0_16MHZ 249
#define  Prescaler  64

/************************************************************************/
/* FUNCTION NAME: Timer0_CTC_Init                                       */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of CTC Mode in Timer0           */
/************************************************************************/
void Timer0_CTC_Init(void);

/************************************************************************/
/* FUNCTION NAME: Dimer_Delay                                           */
/* @Param: no. of milli seconds                                         */
/* return: void                                                         */
/* FUNCTION Description: Making Delay by using CTC Mode in Timer0       */
/************************************************************************/
void Timer_Delay(uint32 n);

#endif /* TIMER0_H_ */