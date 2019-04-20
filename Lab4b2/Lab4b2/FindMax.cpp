// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #4b2

// Description:
// This program find the position of array element with the maximum value.
// Instead of returning the array index, a pointer to the maximum element should be returned

#include <iostream>
using namespace std;

const double *FindMax(const double* const jacky, int n) {
	// initialize temp as the first element of array jacky
	double temp = jacky[0];
	// set temp as jacky[i] if greater than temp
	for (int i = 0; i < n; i++) {
		if (jacky[i] > temp)
		{
			temp = jacky[i];
		}
	}
	const double *max = &temp;
	return max;
}
int main() {
	double *howard;
	int n;
	cout << "How many numbers do you like to enter? ";
	cin >> n;
	cout << "Enter values: ";
	howard = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> howard[i];
	}
	// print the value that the pointer point to
	cout << "The maximum value: " << *FindMax(howard, n) << endl;
	double max = *FindMax(howard, n);
	cout << "1: " << max << endl;
	delete[] howard;
	system("pause");
	return 0;
}