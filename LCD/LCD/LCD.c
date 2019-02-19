/*
 * LCD.c
 *
 * Created: 2/19/2019 11:41:37 AM
 *  Author: AVE-LABS-50
 */ 
#define  F_CPU 16000000
#include <util/delay.h>

#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"

#include "LCD.h"
#include "LCD_cfg.h"

void LCD_init(void)
{
	/* power on */
	DIO_SetPinDirection(PIN1, OUTPUT);
	DIO_SetPinDirection(PIN2, OUTPUT);
	DIO_SetPinDirection(PIN3, OUTPUT);
	DIO_SetPinDirection(PIN4, OUTPUT);
	DIO_SetPinDirection(PIN5, OUTPUT);
	DIO_SetPinDirection(PIN6, OUTPUT);
	DIO_SetPinDirection(PIN7, OUTPUT);
	
	_delay_ms(THIRTY_MS);
	
	/* 4_bit MODE */
	LCD_sendCommand(SetBIT4_MODE);
	LCD_sendCommand(Line2_BIT4_MODE);
	LCD_sendCommand(BIT4_MODE);
	_delay_ms(ONE_MS);
	
	/* Display on/off */
	LCD_sendCommand(DisplayOn);
	_delay_ms(ONE_MS);
	
	/* DisplayClr */
	LCD_sendCommand(DisplayClr);
	_delay_ms(TWO_MS);
	
	/* EntryMode */
	LCD_sendCommand(EntryMode);
	_delay_ms(TWO_MS);
}

void LCD_sendCommand(uint8 COM)
{
	/*uint8 COM1,COM2;
	PORTA = (PORTA & 0x0f)|(Char & 0xf0);
	DIO_WritePort(Aport, 0xf0);
	COM1 = Char | 0x0f;
	DIO_WritePort(Aport, COM1);*/
	
	/* send most significant pit of command */
	DIO_WritePin(LCD_D7, Get_Bit(COM, PIN_7));
	DIO_WritePin(LCD_D6, Get_Bit(COM, PIN_6));
	DIO_WritePin(LCD_D5, Get_Bit(COM, PIN_5));
	DIO_WritePin(LCD_D4, Get_Bit(COM, PIN_4));
	
	DIO_WritePin(RS, LOW);
	DIO_WritePin(RW, LOW);
	DIO_WritePin(E, HIGH);
	_delay_ms(TEN_MS);

	DIO_WritePin(E, LOW);
	_delay_ms(FIVE_MS);
	
	/*PORTA = (PORTA & 0x0f)|(Char << 4);
	DIO_WritePort(Aport, 0x0f);
	COM2 =((COM << 4) | 0xf0);
	DIO_WritePort(Aport, COM2);*/
	
	/* send least significant pit of command */
	DIO_WritePin(LCD_D7, Get_Bit(COM, PIN_3));
	DIO_WritePin(LCD_D6, Get_Bit(COM, PIN_2));
	DIO_WritePin(LCD_D5, Get_Bit(COM, PIN_1));
	DIO_WritePin(LCD_D4, Get_Bit(COM, PIN_0));
	
	
	DIO_WritePin(E, HIGH);
	_delay_ms(TEN_MS);
	DIO_WritePin(E, LOW);
	_delay_ms(FIVE_MS);
}

void LCD_displayChar(uint8 Char)
{
	/*uint8 COM1,COM2;
	PORTA = (PORTA & 0x0f)|(Char & 0xf0);
	DIO_WritePort(Aport, 0xf0);
	COM1 = Char | 0x0f;
	DIO_WritePort(Aport, COM1);*/
	
	/* send most significant pit of command */
	DIO_WritePin(LCD_D7, Get_Bit(Char, PIN_7));
	DIO_WritePin(LCD_D6, Get_Bit(Char, PIN_6));
	DIO_WritePin(LCD_D5, Get_Bit(Char, PIN_5));
	DIO_WritePin(LCD_D4, Get_Bit(Char, PIN_4));
	
	DIO_WritePin(RS, HIGH);
	DIO_WritePin(RW, LOW);
	DIO_WritePin(E, HIGH);
	_delay_ms(TEN_MS);

	DIO_WritePin(E, LOW);
	_delay_ms(FIVE_MS);
	
	/*PORTA = (PORTA & 0x0f)|(Char << 4);
	DIO_WritePort(Aport, 0x0f);
	COM2 =((COM << 4) | 0xf0);
	DIO_WritePort(Aport, COM2);*/
	
	/* send least significant pit of command */
	DIO_WritePin(LCD_D7, Get_Bit(Char, PIN_3));
	DIO_WritePin(LCD_D6, Get_Bit(Char, PIN_2));
	DIO_WritePin(LCD_D5, Get_Bit(Char, PIN_1));
	DIO_WritePin(LCD_D4, Get_Bit(Char, PIN_0));
	
	DIO_WritePin(E, HIGH);
	_delay_ms(TEN_MS);
	DIO_WritePin(E, LOW);
	_delay_ms(FIVE_MS);
}

void LCD_displayString(uint8* ARR, uint8 SIZE)
{
	uint8 i;
	for(i=0; i<SIZE; i++)
	{
		LCD_displayChar(ARR[i]);
		_delay_ms(TWO_MS);
		
	}
}

void LCD_displayStringRowColumn(uint8 line, uint8 digite, uint8* ARR, uint8 SIZE)
{
	LCD_gotoRowColumn( line,  digite);
	LCD_displayString( ARR,  SIZE);
}
void LCD_clear(void)
{
	LCD_sendCommand(DisplayClr);
	_delay_ms(TWO_MS);
}
void LCD_gotoRowColumn(uint8 line, uint8 digit)
{
	if ((digit>=digit0) && (digit<digit16))
	{
		switch(line)
		{
			case firstline : LCD_sendCommand(firstlineADD + digit); break;
			case secondline : LCD_sendCommand(secondlineADD + digit); break;
			default:  break;
		}
	}
	
}

void TestWriteChar (void)
{
	LCD_displayChar('A'); 
}

void TestGotoLineDigitStr(void)
{
	LCD_displayStringRowColumn(1, 2,arr, 4);
}

void TestGotoLineDigit(void)
{
	LCD_gotoRowColumn(1, 2);
}

void TestWriteStr(void)
{
	LCD_displayString(arr, 4);
}