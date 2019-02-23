/*
 * Timer1.c
 *
 * Created: 2/21/2019 11:37:31 AM
 *  Author: AVE-LABS-50
 */ 
#include "Timer1.h"

/*****************************************************************************/
/* FUNCTION NAME: Timer1_PWM_Phase_Correct_Init                              */
/* @Param: void                                                              */
/* return: void                                                              */
/* FUNCTION Description: Initialization of PWM_Phase_Correct Mode in Timer1  */
/*****************************************************************************/
void Timer1_PWM_Phase_Correct_Init(void)
{
	/* Set PIN Config */
	
	DIO_SetPinDirection(MOTOR2E ,OUTPUT);
	DIO_SetPinDirection(MOTORdir2A ,OUTPUT);
	DIO_SetPinDirection(MOTORdir2B ,OUTPUT);
	//DIO_SetPinDirection(MOTORdir1B ,OUTPUT);
	
	DIO_WritePin(MOTORdir2A ,HIGH);
	DIO_WritePin(MOTORdir2B ,LOW);
	
	/* PWM_Phase_Correct mode */
	
	Set_Bit(TCCR1A,BIT_7);
	Clear_Bit(TCCR1A,BIT_6);
	
	Set_Bit(TCCR1A,BIT_5);
	Clear_Bit(TCCR1A,BIT_4);
	
	Clear_Bit(TCCR1A,BIT_1);
	Set_Bit(TCCR1A,BIT_0);
	
	Clear_Bit(TCCR1A,BIT_3);
	Clear_Bit(TCCR1A,BIT_2);
	

	Clear_Bit(TCCR1B,BIT_4);
	Set_Bit(TCCR1B,BIT_5);
	
	/* overflow flag 
	
	Set_Bit(TIFR,0);
	Set_Bit(TIFR,1); */
	
	/* Pre_scaler /256 */
	
	Set_Bit(TCCR1B,BIT_2);
	Clear_Bit(TCCR1B,BIT_1);
	Clear_Bit(TCCR1B,BIT_0);
	
	/* Interrupt enable 
	Set_Bit(SREG, BIT_7);
	Set_Bit(TIMSK, BIT_1); */
	
	TCNT1H = NUM_0;
	/*OCR1AH  = 468 >> NUM_8 ;
	//OCR1AL = (uint8)468 ;
	//OCR1AL =250; */
	ICR1H = TOP_ICR >> NUM_8 ;
	ICR1L = (uint8)TOP_ICR;

}

/*****************************************************************************/
/* FUNCTION NAME: Timer1_Fast_PWM_Init                                       */
/* @Param: void                                                              */
/* return: void                                                              */
/* FUNCTION Description: Initialization of PWM_Fast Mode in Timer1           */
/*****************************************************************************/
void Timer1_Fast_PWM_Init(void)
{
	/* Set PIN Config */
	
	DIO_SetPinDirection(MOTOR2E ,OUTPUT);
	DIO_SetPinDirection(MOTORdir2A ,OUTPUT);
	DIO_SetPinDirection(MOTORdir2B ,OUTPUT);
	//DIO_SetPinDirection(MOTORdir1B ,OUTPUT);
	
	DIO_WritePin(MOTORdir2A ,HIGH);
	DIO_WritePin(MOTORdir2B ,LOW);
	
	/* Fast_PWM mode */
	
	Set_Bit(TCCR1A,BIT_7);
	Clear_Bit(TCCR1A,BIT_6);
	
	Set_Bit(TCCR1A,BIT_5);
	Clear_Bit(TCCR1A,BIT_4);
	
	Clear_Bit(TCCR1A,BIT_1);
	Set_Bit(TCCR1A,BIT_0);
	
	Clear_Bit(TCCR1A,BIT_3);
	Clear_Bit(TCCR1A,BIT_2);
	
	Set_Bit(TCCR1B,BIT_4);
	Set_Bit(TCCR1B,BIT_5);
	
	/* overflow flag 
	
	Set_Bit(TIFR,0);
	Set_Bit(TIFR,1); */
	
	/* Pre_scaler /256 */
	Set_Bit(TCCR1B,BIT_2);
	Clear_Bit(TCCR1B,BIT_1);
	Clear_Bit(TCCR1B,BIT_0);
	
	
	/* Interrupt enable 
	
	Set_Bit(SREG, BIT_7);
	Set_Bit(TIMSK, BIT_1); */
	
	TCNT1H = NUM_0;
/*	OCR1AH  = 468 >> NUM_8 ;
	OCR1AL = (uint8) 468 ;*/
	//OCR1AL = 156;
	ICR1H = TOP_ICR >> NUM_8 ;
	ICR1L = (uint8) TOP_ICR ;
	

}

/*****************************************************************************/
/* FUNCTION NAME: Duty_Cycle                                                 */
/* @Param: the value of Duty_Cycle                                           */
/* return: void                                                              */
/* FUNCTION Description: Set the value of Duty_Cycle in Timer1               */
/*****************************************************************************/
void Duty_Cycle(uint8 Duty)
{
	uint16 temp ;
	uint16 OCR,top = TOP_ICR ;
	if(Duty <= NUM_100)
	{
	/*	temp =((100*top) - ((top+1)*Duty)); */
		temp =top*Duty;
		OCR = temp/NUM_100 ;
		OCR1AL = (uint8) OCR ;
		OCR1AH  = OCR >> NUM_8 ;
		
		
		
	}
}