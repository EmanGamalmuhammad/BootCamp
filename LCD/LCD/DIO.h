/*
 * DIO.h
 *
 * Created: 2/13/2019 2:03:41 PM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 

#ifndef __DIO_H__
#define __DIO_H__

//#include "Types.h"

/* PORTA PINS */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/* PORTB PINS */
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

/* PORTC PINS */
#define PIN16 16
#define PIN17 17
#define PIN18 18
#define PIN19 19
#define PIN20 20
#define PIN21 21
#define PIN22 22
#define PIN23 23

/* PORTD PINS */
#define PIN24 24
#define PIN25 25
#define PIN26 26
#define PIN28 28
#define PIN29 29
#define PIN30 30
#define PIN31 31
#define PIN32 32

/* Registers */
#define PORTA (*((volatile uint8*) 0x3B))
#define DDRA  (*((volatile uint8*) 0x3A))
#define PINA  (*((volatile uint8*) 0x39))

#define PORTB (*((volatile uint8*) 0x38))
#define DDRB  (*((volatile uint8*) 0x37))
#define PINB  (*((volatile uint8*) 0x36))

#define PORTC (*((volatile uint8*) 0x35))
#define DDRC  (*((volatile uint8*) 0x34))
#define PINC  (*((volatile uint8*) 0x33))

#define PORTD (*((volatile uint8*) 0x32))
#define DDRD  (*((volatile uint8*) 0x31))
#define PIND  (*((volatile uint8*) 0x30))

/* value */
#define HIGH 1
#define LOW 0
/* DIRvalue */
#define OUTPUT 1
#define INPUT 0

/* ports */
#define Aport 0
#define Bport 1
#define Cport 2
#define Dport 3

/* PUBLIC APIs */
void DIO_WritePin(uint8 PinNum,uint8 PinValue);
void DIO_WritePort(uint8 PortNum,uint8 PortValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);
void DIO_SetPortDirection(uint8 PortNum,uint8 PortDirection);
void delay(uint32 n); 



#endif /* DIO_INTERFACE_H_ */