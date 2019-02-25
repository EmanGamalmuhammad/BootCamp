/*
 * Interrupt.h
 *
 * Created: 2/20/2019 7:56:47 PM
 *  Author: AVE-LABS-50
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "Types.h"
#include "BitwiseOperations.h"

#include "DIO.h"

/* Interrupt Registers Addresses 

#define GICR    (*((volatile uint8*) 0x5B))
#define GIFR    (*((volatile uint8*) 0x5A))
#define SREG    (*((volatile uint8*) 0x5F))
#define MCUCR   (*((volatile uint8*) 0x55))
#define MCUCSR  (*((volatile uint8*) 0x54)) */

/* Registers Bits */
#define BIT_0 0
#define BIT_1 1
#define BIT_2 2
#define BIT_3 3
#define BIT_4 4
#define BIT_5 5
#define BIT_6 6
#define BIT_7 7

/************************************************************************/
/* FUNCTION NAME: EXTI2_INIT                                            */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of External interrupt no. 2     */
/************************************************************************/
void EXTI2_INIT(void);

#endif /* INTERRUPT_H_ */