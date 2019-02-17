/*********************************************************************************
 *
 *  problem_two.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * Modify the Binary Search algorithm to find an element in a circularly sorted
 * array.
 * The array is sorted in an ascending order and rotated in clockwise
 *
 * Sample Input: arr = [8, 9, 10, 2, 5, 6]
 * 				 target = 10
 * Sample Output: The number is found at index 2
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_two.h"

/*********************************************************************************
 *
 * Function: circularArraySearch
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: element_to_be_found, The elment to be searcher for
 * @return: int, the index of the element to be found
 *
 * Description: Function to find the number of times the array is rotated, if the
 * element was not found it should return -1
 *
 ********************************************************************************/
int circularArraySearch(int arr[], int arr_size, int element_to_be_found)
{
	/* Your code goes here */
	    int start , end , i , index , nOfRotates ;
		start = 0 ;
	/*Find number of rotations*/
		nOfRotates = findRotationCount(arr , arr_size);
	/*Bring array back to its sorten version*/
		for(i=1 ; i<= arr_size - nOfRotates ; i++)
		{
			rotateByOne(arr,arr_size);
		}
	/*Binary Search*/
		end = arr_size-1;
		for (i = 0 ; i < arr_size/2 ; i++)
		{
			index = (end-start)/2 + start ;
			if(element_to_be_found == arr[index])
			{	if(index+nOfRotates > arr_size-1)
					index = index+nOfRotates - arr_size ;
				else
					index = index + nOfRotates;
				return index ;
			}
			else if(element_to_be_found > arr[index])
				start = index + 1 ;

			else
				end = index -1 ;
		}
		return -1 ;
}

void rotateByOne(int arr[],int SIZE)
{
    int i, last;

    /* Store last element of array */
    last = arr[SIZE - 1];

    for(i=SIZE-1; i>0; i--)
    {
        /* Move each array element to its right */
        arr[i] = arr[i - 1];
    }

    /* Copy last element of array to first */
    arr[0] = last;
}

int findRotationCount(int arr[], int arr_size) {
	/* Your code goes here  */
	int i , index=0 ;
	int min = arr[0] ;
	for(i=0 ; i<arr_size ;i++)
	{
		if(arr[i] <= min && (arr[i] != arr[i-1]))
		{
			min = arr[i];
			index = i ;
		}

	}
	return index ;
}

/* circularArraySearch_test */
void main(void)
{
	//int RotationCount = 0 ;
	int A[] = {9, 10, 2, 5, 6, 8};
	int target = 10;
	int n = sizeof(A)/sizeof(A[0]);
	int index = circularArraySearch(A, n, target);
	if(index != -1){
		printf("Element found at index %d", index);
	}
	else{
		printf("Element not found in the array");
	}
}
