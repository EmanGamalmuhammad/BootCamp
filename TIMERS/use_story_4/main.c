 
#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"
#include "Timer0.h"

#define F_cpu 16000000
#include <util/delay.h>

int main(void)
{
	/* Replace with your application code */
	
	DIO_SetPinDirection(PIN10,INPUT);
	//DIO_WritePin(PIN10,HIGH);
	
	DIO_SetPinDirection(PIN13,OUTPUT);
	DIO_SetPinDirection(PIN14,OUTPUT);
	DIO_SetPinDirection(PIN15,OUTPUT);
	timer0_CTC_init();
	uint8 i;
	while (1)
	{
		DIO_WritePin(PIN13,HIGH);
		for (i=0;i<20;i++)
		{
			timer_delay(50);
			while(DIO_ReadPin(10))
			{
				DIO_WritePin(PIN14,LOW);
				DIO_WritePin(PIN13,LOW);
				DIO_WritePin(PIN15,HIGH);
				timer_delay(1000);
				DIO_WritePin(PIN15,LOW);
				
			}
		}
		
		DIO_WritePin(PIN13,LOW);
		DIO_WritePin(PIN15,HIGH);
		for (i=0;i<20;i++)
		{
			timer_delay(50);
			while(DIO_ReadPin(10))
			{
				DIO_WritePin(PIN14,LOW);
				DIO_WritePin(PIN13,LOW);
				DIO_WritePin(PIN15,HIGH);
				timer_delay(1000);
				DIO_WritePin(PIN15,LOW);
				
			}
		}
		DIO_WritePin(PIN15,LOW);
		DIO_WritePin(PIN14,HIGH);
    	for (i=0;i<20;i++)
    	{
	    	timer_delay(50);
	    	while(DIO_ReadPin(10))
	    	{
		    	DIO_WritePin(PIN14,LOW);
		    	DIO_WritePin(PIN13,LOW);
		    	DIO_WritePin(PIN15,HIGH);
		    	timer_delay(1000);
		    	DIO_WritePin(PIN15,LOW);
		    	
	    	}
    	}
		DIO_WritePin(PIN14,LOW);
		
		

	}
	return 0;
}


