// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #1a

// Description:
// This program demonstrates the use of a simple main() function, and
// displays output to a console window using the C++ iostream library.
#include <iostream>
#include <cmath>
using namespace std;

int convertBinaryToDecimal(long long n)
{
	int decimalNumber = 0, i = 0, remainder;
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}
	return decimalNumber;
}

long long convertDecimalToBinary(int n)
{
	long long binaryNumber = 0;
	int remainder, i = 1, step = 1;

	while (n != 0)
	{
		remainder = n % 2;
		cout << "Step " << step++ << ": " << n << "/2, Remainder = " << remainder << ", Quotient = " << n / 2 << endl;
		n /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
}
int main()
{
	int temp, temp1, shift;
	cout << "Welcome to AST21105 - OO Programming and Design" << endl;
	cin >> temp;
	cin >> shift;
	temp1 = temp;
	temp = temp >> shift;
	temp1 = temp1 / pow(2,shift);
	cout << endl << temp;
	cout << endl << temp1;
	system("pause");
	return 0;
}