/*
 * LCD.h
 *
 * Created: 2/19/2019 11:40:24 AM
 *  Author: AVE-LABS-50
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "Types.h"
#include "BitwiseOperations.h"

#include "DIO.h"
#include "LCD_cfg.h"

/* LCD Commands Addresses */

#define Function_Set     0x38
#define DisplayOn        0x0E
#define DisplayClr       0x01
#define EntryMode        0x06
#define ReturnHome       0x02
#define BIT4_MODE        0x28
#define Line2_BIT4_MODE  0x32
#define SetBIT4_MODE     0x33
#define CGRAM            0x40

/* Commands PINS */

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

/* LCD Cells */
#define digit0 0
#define digit16 16

/* Milliseconds */
#define ONE_MS 1
#define TWO_MS 2
#define FIVE_MS 5
#define TEN_MS 10
#define THIRTY_MS 30
#define OneHundred_MS 100
#define OneThousand_MS 1000

/* LCD Lines */

#define FirstLine 0
#define SecondLine 1

#define FirstLineADD  0x80
#define SecondLineADD 0xC0

/* APIS */

/************************************************************************/
/* FUNCTION NAME: LCD_init                                              */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of LCD                          */
/************************************************************************/
void LCD_init(void);

/************************************************************************/
/* FUNCTION NAME: LCD_sendCommand                                       */
/* @Param: Command                                                      */
/* return: void                                                         */
/* FUNCTION Description: Sending LCD Commands                           */
/************************************************************************/
void LCD_sendCommand(uint8 COM);

/************************************************************************/
/* FUNCTION NAME: LCD_displayChar                                       */
/* @Param: Character                                                    */
/* return: void                                                         */
/* FUNCTION Description: Display Character on LCD                       */
/************************************************************************/
void LCD_displayChar(uint8 Char);

/************************************************************************/
/* FUNCTION NAME: LCD_displayString                                     */
/* @Param: Array of String and it's size                                */
/* return: void                                                         */
/* FUNCTION Description: Display String on LCD                          */
/************************************************************************/
void LCD_displayString(uint8* ARR, uint8 SIZE);

/************************************************************************/
/* FUNCTION NAME: LCD_displayStringRowColumn                            */
/* @Param: Array of String, it's size And the row, column of LCD cell   */
/* return: void                                                         */
/* FUNCTION Description: Display String on certain LCD cell             */
/************************************************************************/
void LCD_displayStringRowColumn(uint8 line, uint8 digit, uint8* ARR, uint8 SIZE);

/************************************************************************/
/* FUNCTION NAME: LCD_clear                                             */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Clear the LCD                                  */
/************************************************************************/
void LCD_clear(void);

/************************************************************************/
/* FUNCTION NAME: LCD_gotoRowColumn                                     */
/* @Param: the row and column of LCD cell                               */
/* return: void                                                         */
/* FUNCTION Description: go to certain the row, column on LCD           */
/************************************************************************/
void LCD_gotoRowColumn(uint8 COL, uint8 ROW);

/* Test APIS */
void TestWriteChar (void);
void TestGotoLineDigitStr(void);
void TestGotoLineDigit(void);
void TestWriteStr(void);

#endif /* LCD_H_ */