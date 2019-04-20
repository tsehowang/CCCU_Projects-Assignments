// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #06

#include "Search.h"
#include <iostream>

using namespace std;

/*
   [ Binary Search Algorithm ]

   Check the middle element of the sorted array to see if it is equal to
   the key. If it is, then the position is found.
   Otherwise, the left half or right half is chosen for further searching
   based on whether the key is greater than or less than the middle element.
*/

int performBinarySearch(int arr[], int left, int right, int key)
{
	if (left > right)
		return -1;
	else
	{
		int mid = (left + right) / 2;
		if (key == arr[mid])
			return mid;
		else if (key < arr[mid])
			return performBinarySearch(arr, left, mid - 1, key);
		else
			return performBinarySearch(arr, mid + 1, right, key);
	}
}

