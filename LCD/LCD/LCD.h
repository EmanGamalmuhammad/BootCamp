/*
 * LCD.h
 *
 * Created: 2/19/2019 11:40:24 AM
 *  Author: AVE-LABS-50
 */ 


#ifndef LCD_H_
#define LCD_H_

#define Function_Set 0x38
#define DisplayOn 0x0E
#define DisplayClr 0x01
#define EntryMode 0x06
#define ReturnHome 0x02
#define BIT4_MODE 0x28
#define Line2_BIT4_MODE 0x32
#define SetBIT4_MODE 0x33

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

#define digit0 0
#define digit16 16

/* Milliseconds */
#define ONE_MS 1
#define TWO_MS 2
#define FIVE_MS 5
#define TEN_MS 10
#define THIRTY_MS 30

#define firstline 0
#define secondline 1
#define firstlineADD 0x80
#define secondlineADD 0xC0

/* APIS */
void LCD_init(void);
void LCD_sendCommand(uint8 COM);
void LCD_displayChar(uint8 Char);
void LCD_displayString(uint8* ARR, uint8 SIZE);
void LCD_displayStringRowColumn(uint8 line, uint8 digit, uint8* ARR, uint8 SIZE);
void LCD_clear(void);
void LCD_gotoRowColumn(uint8 COL, uint8 ROW);

/* Test APIS */
void TestWriteChar (void);
void TestGotoLineDigitStr(void);
void TestGotoLineDigit(void);
void TestWriteStr(void);

#endif /* LCD_H_ */