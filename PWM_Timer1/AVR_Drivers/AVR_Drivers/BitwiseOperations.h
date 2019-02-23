/*
 * Bitwise_Operations.h
 *
 * Created: 2/13/2019 10:54:34 AM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 
#ifndef __BITWISE_OPERATIONS_
#define __BITWISE_OPERATIONS_

#include "Types.h"

#define Set_Bit(Register,Bit)  (Register |= (1<<Bit))
#define Clear_Bit(Register,Bit) (Register &= ~(1<<Bit))
#define Toggle_Bit(Register,Bit) (Register ^= (1<<Bit))
#define Get_Bit(Register,Bit)  ((Register>>Bit) &(0x01))

#endif