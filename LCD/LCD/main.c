/*
 * LCD.c
 *
 * Created: 2/19/2019 10:20:07 AM
 * Author : AVE-LABS-50
 */ 

#define  F_CPU 16000000
#include <util/delay.h>
#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"
#include "Timer0.h"
#include "LCD.h"

int main(void)
{
    /* Replace with your application code */
	uint8 arr[] = {'e','m','a','n'};
	LCD_init();
	LCD_displayChar('A'); //display
	LCD_displayChar('B');
	//LCD_gotoRowColumn(1, 2);
	//LCD_displayString(arr, 4);
	LCD_displayStringRowColumn(1, 2,arr, 4);
    while (1) 
    {
		
    }
	return 0;
}

