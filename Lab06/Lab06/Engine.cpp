// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #06

#include "Engine.h"
#include "Sort.h"
#include "Search.h"

void performSortMarks(int arr[], const int& size)
{
	system("cls");
	cout << "size: " << size << endl;
	cout << "-------------" << endl;
	cout << "   Sorting   " << endl;
	cout << "-------------" << endl;
	cout << "Marks sorted in ascending order: ";
	performQuickSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
}

void performSearchMark(int arr[], const int& size)
{
	system("cls");
	cout << "-------------" << endl;
	cout << "  Searching  " << endl;
	cout << "-------------" << endl;
	do {
		int noFind;
		cout << "Mark to find (-1 to quit)? ";
		cin >> noFind;
		if (noFind == -1)
			break;
		int index = performBinarySearch(arr, 0, size - 1, noFind);
		if (index != -1)
			cout << "The mark " << noFind << " is found at index " << index << endl;
		else
			cout << "The mark is not found" << endl;
	} while (true);
}

/* Compute the statistics of marks (mean and unbiased variance */
void performComputation(int arr[], int size)
{
	system("cls");
	double sum = 0;
	double sumSquared = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
		cout << arr[i] << " ";
	}
	cout << endl;
	double mean = sum / size;
	for (int i = 0; i < size; i++)
		sumSquared += (arr[i] - mean)*(arr[i] - mean);
	double variance = sumSquared / (size - 1);
	cout << "Mean : " << mean << endl;
	cout << "Unbiased variance : " << variance << endl;
	system("pause");
}
