/*
 * Timer0.h
 *
 * Created: 2/13/2019 4:05:48 PM
 *  Author: AVE-LABS-50
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#define TCNT0 (*((volatile uint8*) 0x52))
#define TCCR0  (*((volatile uint8*) 0x53))
#define OCR0  (*((volatile uint8*) 0x5C))

#define GICR  (*((volatile uint8*) 0x5B))
#define GIFR  (*((volatile uint8*) 0x5A))
#define TIMSK  (*((volatile uint8*) 0x59))
#define TIFR  (*((volatile uint8*) 0x58))

#define  Prescaler  64

void timer0_CTC_init(void);
void timer0_OC_init(void);
void timer_delay(uint32 n);

#endif /* TIMER0_H_ */