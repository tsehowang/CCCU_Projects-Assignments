// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #06

#include "Sort.h"

using namespace std;
/*
   [ Quicksort Algorithm ]

   1. Choose a pivot value
	  We take the the middle element as pivot value.
   2. Partition
	  Rearrange elements in the array, such that all elements that
	  are less than the pivot are moved to the left part of the array
	  and all elements greater than the pivot moved to the right
	  part of the array.
	  Note:
	  The pivot should now be placed in its final position in the sorted array.
   3. Sort the left unsorted array and right unsorted array
	  Apply quicksort algorithm recursively for the left and the right parts.
*/

void performQuickSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		performQuickSort(arr, left, j);
	if (i < right)
		performQuickSort(arr, i, right);
}

