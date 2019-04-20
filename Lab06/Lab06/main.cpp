// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #06

#include <iostream>
#include "DataEntry.h"
#include "Engine.h"
#include "Histogram.h"
#include "Search.h"
#include "Sort.h"
using namespace std;

bool executeMenu(int choice, int*& arr, int& size)
{
	switch (choice)
	{
	case 1:
		if (arr != NULL)
			delete[] arr;
		performDataEntry(arr, size);
		break;
	case 2:
		performSortMarks(arr, size);
		break;
	case 3:
		performSearchMark(arr, size);
		break;
	case 4:
		performComputation(arr, size);
		break;
	case 5:
		performHistogram(arr, size);
		break;
	case 6:
		return true;
	}
	return false;
}

int selectMenu()
{
	system("cls");
	int choice;
	do {
		cout << "Select function: " << endl;
		cout << "----------------" << endl;
		cout << "1.) Mark Entry" << endl;
		cout << "2.) Sort Marks" << endl;
		cout << "3.) Search Mark" << endl;
		cout << "4.) Compute Statistics " << endl;
		cout << "5.) Plot Histogram " << endl;
		cout << "6.) Quit " << endl;
		cout << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
	} while (choice < 1 || choice > 6);
	return choice;
}

int main()
{
	bool quit;
	int size;
	int* arr = NULL;
	do {
		quit = executeMenu(selectMenu(), arr, size);
	} while (!quit);
	if (arr != NULL)
		delete[] arr;
	system("pause");
	return 0;
}