
#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if(PinValue == HIGH)
	{
		if((PinNum >= PIN0) && (PinNum <= PIN7) )
		{
			Set_Bit(PORTA,PinNum);
		}
		else if((PinNum >= PIN8) && (PinNum <= PIN15) )
		{
			Set_Bit(PORTB,(PinNum-PIN8));
		}
		else if((PinNum >= PIN16) && (PinNum <= PIN23) )
		{
			Set_Bit(PORTC,(PinNum-PIN16));
		}
		else if((PinNum >= PIN24) && (PinNum <= PIN32) )
		{
			Set_Bit(PORTD,(PinNum-PIN24));
		}
		else
		{
			
		}
	}
	
	else if(PinValue == LOW)
	{
		if((PinNum >= PIN0) && (PinNum <= PIN7) )
		{
			Clear_Bit(PORTA,PinNum);
		}
		else if((PinNum >= PIN8) && (PinNum <= PIN15) )
		{
			Clear_Bit(PORTB,(PinNum-PIN8));
		}
		else if((PinNum >= PIN16) && (PinNum <= PIN23) )
		{
			Clear_Bit(PORTC,(PinNum-PIN16));
		}
		else if((PinNum >= PIN24) && (PinNum <= PIN32) )
		{
			Clear_Bit(PORTD,(PinNum-PIN24));
		}
		else
		{
			
		}
	}
	else
	{
		
	}
	
}
uint8 DIO_ReadPin(uint8 PinNum)
{
	uint8 output;
	if((PinNum >= PIN0) && (PinNum <= PIN7) )
	{
		output = Get_Bit(PINA,PinNum);
		return output;
	}
	else if((PinNum >= PIN8) && (PinNum <= PIN15) )
	{
		output = Get_Bit(PINB,(PinNum-PIN8));
		return output;
	}
	else if((PinNum >= PIN16) && (PinNum <= PIN23) )
	{
		output = Get_Bit(PINC,(PinNum-PIN16));
		return output;
	}
	else if((PinNum >= PIN24) && (PinNum <= PIN32) )
	{
		output = Get_Bit(PIND,(PinNum-PIN24));
		return output;
	}
	else
	{
		
	}
}
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if(PinDirection == OUTPUT)
	{
		if((PinNum >= PIN0) && (PinNum <= PIN7) )
		{
			Set_Bit(DDRA,PinNum);
		}
		else if((PinNum >= PIN8) && (PinNum <= PIN15) )
		{
			Set_Bit(DDRB,(PinNum-PIN8));
		}
		else if((PinNum >= PIN16) && (PinNum <= PIN23) )
		{
			Set_Bit(DDRC,(PinNum-PIN16));
		}
		else if((PinNum >= PIN24) && (PinNum <= PIN32) )
		{
			Set_Bit(DDRD,(PinNum-PIN24));
		}
		else
		{
			
		}
	}
	
	else if(PinDirection == INPUT)
	{
		if((PinNum >= PIN0) && (PinNum <= PIN7) )
		{
			Clear_Bit(DDRA,PinNum);
		}
		else if((PinNum >= PIN8) && (PinNum <= PIN15) )
		{
			Clear_Bit(DDRB,(PinNum-PIN8));
		}
		else if((PinNum >= PIN16) && (PinNum <= PIN23) )
		{
			Clear_Bit(DDRC,(PinNum-PIN16));
		}
		else if((PinNum >= PIN24) && (PinNum <= PIN32) )
		{
			Clear_Bit(DDRD,(PinNum-PIN24));
		}
		else
		{
			
		}
	}
	else
	{
		
	}
	
}

delay(uint32 n)
{
	uint32 i;
	for(i=0;i<n;i++)
	{
	}
} 
