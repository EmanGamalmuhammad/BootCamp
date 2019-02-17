/*********************************************************************************
 *
 *  problem_ten.h
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/
/****************************[Problem Description]****************************************************
 *
 * Given a number "N" find four integer numbers a, b, c and d such that b, c and d are prime numbers,
 * and a & N are odd knowing that a^3 + b^3 + c^3 + d^3 = N and a <= b <= c <= d
 *
 * Sample Input: N = 161
 * Sample Output: Numbers are 1, 2, 3 and 5
 *
 * @return: Array containing a, b, c and d respectively that satisfy the equation
 *
 * Note: 1 <= N <= 10^18
 *
 *******************************************************************************************************/
#include <stdio.h>
#include "problem_nine.h"

int* findPrimeNumbers(int N){
	/* Your Code Goes here*/
}


void main(void){
	int* ptrToPrimes = findPrimeNumbers(161);
	printf("The numbers are: %d, %d, %d and %d\n",ptrToPrimes[0],ptrToPrimes[1],ptrToPrimes[2],ptrToPrimes[3]);
}
