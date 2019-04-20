// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #1b

// Description:
// This program compute the sum of numbers
// displays output to a console window using the C++ iostream library.

#include <iostream>
using namespace std;

int main()
{
	int inputTime = 0;
	int input;
	int sum;
	do {
		cout << "Enter input: ";
		cin >> inputTime;
		sum = 0;
		input = 0;
		for (int i = 0; i < inputTime; i++) {
			cin >> input;
			sum += input;
		}
		if (inputTime != -1)
			cout << "Output total: " << sum << endl;
	} while (inputTime != -1);
	system("pause");
	return 0;
}