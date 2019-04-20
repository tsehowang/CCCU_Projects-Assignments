// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #06

#include "DataEntry.h"
#include <iostream>

using namespace std;
/* Read n marks from keyboard, where n is a user-specified value */

void performDataEntry(int*& arr, int& n)
{
	system("cls");
	cout << "-------------" << endl;
	cout << "    Input    " << endl;
	cout << "-------------" << endl;
	cout << "How many marks to store? ";
	cin >> n;
	arr = new int[n];
	cout << "Input marks: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}