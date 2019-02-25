 
#ifndef __DIO_H__
#define __DIO_H__


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
#define PIN27 27
#define PIN28 28
#define PIN29 29
#define PIN30 30
#define PIN31 31

/* DIO Registers */

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

/* PIN_value */

#define HIGH 1
#define LOW 0

/* DIR_value */

#define OUTPUT 1
#define INPUT 0

/* LED And Switches PINS */

#define LED0 PIN12
#define LED1 PIN13
#define LED2 PIN14
#define LED3 PIN15

#define PushButt0 PIN20
#define PushButt1 PIN10

/* NUMBERS */

#define NUM_0 0
#define NUM_1 1
#define NUM_2 2
#define NUM_3 3
#define NUM_4 4
#define NUM_5 5
#define NUM_6 6
#define NUM_7 7
#define NUM_8 8
#define NUM_9 9
#define NUM_10 10
#define NUM_20 20
#define NUM_50 50
#define NUM_100 100
#define NUM_1000 1000
#define NUM_3000 3000
#define NUM_5000 5000

/* Registers Bits */
#define BIT_0 0
#define BIT_1 1
#define BIT_2 2
#define BIT_3 3
#define BIT_4 4
#define BIT_5 5
#define BIT_6 6
#define BIT_7 7

/* PUBLIC APIs */

/************************************************************************/
/* FUNCTION NAME: DIO_WritePin                                          */
/* @Param: Pin_Num, Pin_Value                                           */
/* return: void                                                         */
/* FUNCTION Description: Set PINs Value                                 */
/************************************************************************/
void DIO_WritePin(uint8 PinNum,uint8 PinValue);

/************************************************************************/
/* FUNCTION NAME: DIO_ReadPin                                           */
/* @Param: Pin_Num                                                      */
/* return: pin_value                                                    */
/* FUNCTION Description: Get PINs Value                                 */
/************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum);

/************************************************************************/
/* FUNCTION NAME: DIO_SetPinDirection                                   */
/* @Param: Pin_Num, Pin_Direction                                       */
/* return: void                                                         */
/* FUNCTION Description: Set PINs Direction                             */
/************************************************************************/
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

void Delay(uint32 n); 



#endif /* DIO_INTERFACE_H_ */