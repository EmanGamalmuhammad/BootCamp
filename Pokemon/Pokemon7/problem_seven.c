/*********************************************************************************
 *
 *  problem_seven.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/

/****************************[Problem Description]*********************************
 *
 * Find the number of 1's in a binary array that is sorted
 * Sample Input: arr = [0,0,1,1,1,1]
 * Sample Output: Number of 1s is 4
 *
 ********************************************************************************/

#include <stdio.h>
#include "problem_seven.h"
/*********************************************************************************
 *
 * Function: countOnes
 *
 * @param: arr[], Array that the function is to count the ones in.
 * @param: arr_size, size of the array
 * @return: int, the number of ones in the array
 *
 * Description: function to get the largest number in the array.
 *
 *
 ********************************************************************************/
int countOnes(int arr[], int arr_size){
	/* Your code goes here */
	int i = 0 ;
	int count = 0 ;
	/*Checking that array is binary and sorted if not return -1*/
	for(i =0; i<arr_size ; i++){
		if(arr[i]==0);
		else if (arr[i]==1 )
					count ++ ;
		else if(count > 0 && arr[i]!=1)
			return -1 ;

		else
			return -1;
	}
	return count ;
}


/* countOnes_test function */
void main(void)
{
	int arr[] = { 0,0,0,1,1,1,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Total number of 1's present are %d", countOnes(arr, n));

}
