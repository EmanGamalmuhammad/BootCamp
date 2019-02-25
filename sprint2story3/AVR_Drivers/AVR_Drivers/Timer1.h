/*
 * Timer1.h
 *
 * Created: 2/21/2019 11:37:47 AM
 *  Author: AVE-LABS-50
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"
#include "Interrupt.h"

/* Timer1 Registers Addresses */

#define TCCR1A   (*((volatile uint8*) 0x4F))
#define TCCR1B   (*((volatile uint8*) 0x4E))

#define TCNT1H   (*((volatile uint8*) 0x4D))
#define TCNT1L   (*((volatile uint8*) 0x4C))
#define TCNT1    (*((volatile uint16*) 0x4D))

#define OCR1AH    (*((volatile uint8*) 0x4B))
#define OCR1AL    (*((volatile uint8*) 0x4A))

#define ICR1H    (*((volatile uint8*) 0x47))
#define ICR1L    (*((volatile uint8*) 0x46))

/*#define GICR    (*((volatile uint8*) 0x5B))
#define GIFR    (*((volatile uint8*) 0x5A))
#define SREG    (*((volatile uint8*) 0x5F)) */

#define TIMSK   (*((volatile uint8*) 0x59))
#define TIFR    (*((volatile uint8*) 0x58))

#define TOP_ICR 1294

/* Config PINs Definitions */ 

#define MOTOR1E     PIN28
#define MOTOR2E     PIN29

#define MOTORdir1A  PIN26
#define MOTORdir1B  PIN27

#define MOTORdir2A  PIN30
#define MOTORdir2B  PIN31

/*****************************************************************************/
/* FUNCTION NAME: Timer1_PWM_Phase_Correct_Init                              */
/* @Param: void                                                              */
/* return: void                                                              */
/* FUNCTION Description: Initialization of PWM_Phase_Correct Mode in Timer1  */
/*****************************************************************************/
void Timer1_PWM_Phase_Correct_Init(void);

/*****************************************************************************/
/* FUNCTION NAME: Timer1_Fast_PWM_Init                                       */
/* @Param: void                                                              */
/* return: void                                                              */
/* FUNCTION Description: Initialization of PWM_Fast Mode in Timer1           */
/*****************************************************************************/
void Timer1_Fast_PWM_Init(void);

/*****************************************************************************/
/* FUNCTION NAME: Duty_Cycle                                                 */
/* @Param: the value of Duty_Cycle                                           */
/* return: void                                                              */
/* FUNCTION Description: Set the value of Duty_Cycle in Timer1               */
/*****************************************************************************/
void Duty_Cycle(uint8 Duty);


#endif /* TIMER1_H_ */