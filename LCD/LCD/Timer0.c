/*
 * Timer0.c
 *
 * Created: 2/13/2019 4:06:21 PM
 *  Author: AVE-LABS-50
 */ 
#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"
#include "Timer0.h"

void timer0_CTC_init(void)
{
	/* CTC mode */
	
	Clear_Bit(TCCR0,7);
	Clear_Bit(TCCR0,6);
	Clear_Bit(TCCR0,5);
	Clear_Bit(TCCR0,4);
	Set_Bit(TCCR0,3);

	/* overflow flag */
	//Set_Bit(TIFR,0);
	//Set_Bit(TIFR,1);
	
	/* prescaler /64 */
	Clear_Bit(TCCR0,2);
	Set_Bit(TCCR0,1);
	Set_Bit(TCCR0,0);
	
	TCNT0 = 0;
	OCR0 = 249;
}

void timer0_OC_init(void)
{
	/* CTC mode */
	
	Clear_Bit(TCCR0,7);
	Clear_Bit(TCCR0,6);
	Clear_Bit(TCCR0,5);
	Clear_Bit(TCCR0,4);
	Set_Bit(TCCR0,3);

	/* overflow flag */
	//Set_Bit(TIFR,0);
	//Set_Bit(TIFR,1);
	
	/* prescaler /64 */
	Clear_Bit(TCCR0,2);
	Set_Bit(TCCR0,1);
	Set_Bit(TCCR0,0);
	
	TCNT0 = 0;
	OCR0 = 249;
}
void timer_delay(uint32 n)
{
	uint32 i;
	for(i=0; i< n;i++)
	{
		while ((TIFR & 0x02)== 0);
		Set_Bit(TIFR,1);
	}
}