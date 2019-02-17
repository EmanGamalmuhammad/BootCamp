/*********************************************************************************
 *
 *  Binary_Search.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/



/****************************[Problem Description]*********************************
 *
 * Binary search is one of the best searching algorithms. Binary search algorithm
 * works as follows:
 * Assume having a sorted array arr = [1, 2, 3, 4, 5, 6, 7] and you want to search
 * for the number "2" the algorithm starts by comparing your target number "2" to
 * the middle number in the array which is "4" if this is the desired number then
 * return the index of it, if not, is 2 greater than 4 ? no then is it less than 4?
 * Yes, then start looking in the sub array starting from the first element in the
 * array to the elment right before the middle element "4", i.e (1..arr[mid-1]).
 * Get the middle element in this sub-array and compare it to 2, is 2 equal to 2?
 * Yes then return the index of it.
 * As we can see Binary search found this number in 2 iterations only.
 *
 *Notice:: if you try searching for the element "6" you will reach it in only two
 *		   iterations
 ********************************************************************************/
#include <stdio.h>
#include "Binary_Search.h"
#include "Bubble_Sort.h"

#define ARR_SIZE 12

int Linear_search_algo(int arr[], int arr_size, int target){
	/* Your code goes here */
	int i;

	for(i=0;i<arr_size;i++)
	{
		if(arr[i]==target)
		{
			return i;
		}

	}


	return -1;

}
int Binary_search_algo(int arr[], int arr_size, int target){
	/* Your code goes here */

	int first=0,last,mid,i=0;

		last = arr_size -1;
		mid = (last - first)/2;

		while((last >= first) && (mid<= last)  )
		{
	    	//	last = arr_size -1;
			//mid = (last - first)/2;
				if(arr[mid]==target)
				{
					return mid;
				}
				else if(arr[mid] < target)
				{
					first = mid+1;
				mid = ((last - first)/2) + mid ;

				}
				else if(arr[mid]>target)
				{
					last = mid-1;
					mid = ((last - first)/2) ;

				}
				else
				{
					return -1;
				}
		}
		return -1;
}


void main(void){
	int index ;
	int arr[ARR_SIZE] = {1, 55, 10, 23, 6, 12, 44, 2, 0, 15, 43, 7};
	index = Linear_search_algo(arr, ARR_SIZE, 18);
	if(index == -1 ){
		printf("Target not found in the array\n");
	}
	else{
		printf("Target is found in the array at index %d\n", index);
	}
	Bubble_sort_algo(arr,ARR_SIZE);
	//printf("%d\n",arr[12]);
	 index = Binary_search_algo(arr,ARR_SIZE, 18);
	if(index == -1 ){
		printf("Target not found in the array\n");
	}
	else{
		printf("Target is found in the array at index %d\n", index);
	}
}
