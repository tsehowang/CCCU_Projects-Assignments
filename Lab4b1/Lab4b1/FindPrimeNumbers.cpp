// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #4b1

// Description:
// This program uses an array of n elements (where n is a user input) to determine and
// display the prime numbers between 2 and n, including n using the method described below.
// Ignore array elements 0 and 1.

#include <iostream>
using namespace std;

int main() {
	bool *mukul;
	int num = 0;
	int count = 0;
	cout << "Enter the value of n: ";
	cin >> num;
	mukul = new bool[num];
	// set all the elements inside the bool array mukul as true
	for (int i = 0; i < num; i++) {
		mukul[i] = true;
	}
	// start looping from 2
	// set element of array position i*j as false
	// example: mukul[2*3] and mukul[4*5] and mukul[5*6] are false
	for (int i = 2; i < num; i++) {
		for (int j = 2; i*j < num; j++) {
			mukul[i*j] = false;
		}
	}
		cout << "Prime numbers: ";
	// count and print the positon if true
	for(int i = 2; i < num; i++){
		if (mukul[i] == 1) {
			count++;
			if (count == 1) {
				cout << i;
			}
			else {
				cout << ", " <<i;
			}
		}
	}
	cout << endl << count << " primes found." << endl;
	delete[] mukul;
	system("pause");
	return 0;
}
