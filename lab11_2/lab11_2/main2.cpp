#include <iostream>
#include <string>
#include "Rational2.h"
using namespace std;

// Function declaration
int getMenuChoice();

// Main program
int main()
{

	//int numerator;
	//int denominator;
	//char sep;
	//
	//// Read first fraction
	//cout << "Rational A (numerator/denominator): ";
	//cin >> numerator >> sep >> denominator;
	//Rational2 a(numerator, denominator);

	//// Read second fraction
	//cout << "Rational B (numerator/denominator): ";
	//cin >> numerator >> sep >> denominator;
	//Rational2 b(numerator, denominator);

    Rational2 a, b;
    
    // Read first fraction
    cout << "Rational A (numerator/denominator): ";
    cin >> a;
    
    // Read second fraction
    cout << "Rational B (numerator/denominator): ";
    cin >> b;
    
    //Using Copy Constructor
    Rational2 copyA(a);
    
    //Using =operator
    Rational2 assignB;
    assignB = b;
    
    //Result of operations
    Rational2 result;

    //Using >> & << operators
    Rational2 c;

	//system("cls");

	// User's choice in the menu
	int choice = getMenuChoice();

	while(choice != 9)
	{
		system("cls");
		switch(choice)
		{
			case 1:
				result = a + b;
				cout << "a + b = " << result << endl;				
				break;
			case 2:
				result = a - b;
				cout << "a - b = " << result << endl;
				break;
			case 3:
				result = a * b;
				cout << "a * b = " << result << endl;
				break;
			case 4:
				result = a / b;
				cout << "a / b = " << result << endl;
				break;
			case 5:
                result = -a;
				cout << "-a = " << result << endl;
				break;
			case 6:
				cout << "A is " ;
                if (a < b) 
                   cout << "smaller than ";
                else if (a == b)
                   cout << "equal to ";
                else
                   cout << "larger than ";
                cout << "B." << endl;
				break;
			case 7:
				cout << "Rational C (numerator/denominator): ";
                cin >> c;
				break;
			case 8:
				cout << "A: " << a << endl;
				cout << "B: " << b << endl;
				cout << "Copy A  : " << copyA << endl;
				cout << "Assign B: " << assignB << endl;
				cout << "C: " << c << endl;
				break;
		}

		//system("pause");
		//system("cls");
		choice = getMenuChoice();
	}
}

int getMenuChoice()
{
	cout << "--------------" << endl;
	cout << " Operation:" << endl;
	cout << "--------------" << endl;
	cout << " 1. A + B" << endl;
	cout << " 2. A - B" << endl;
	cout << " 3. A x B" << endl;
	cout << " 4. A / B" << endl;
	cout << " 5. -A" << endl;
	cout << " 6. Compare A and B" << endl;
	cout << " 7. Input C" << endl;
	cout << " 8. Show A, B and C" << endl;
	cout << " 9. Exit" << endl;
	cout << "--------------" << endl;
	cout << endl;
	cout << " Choice: ";
	int choice;
	cin >> choice;
	return choice;
}
