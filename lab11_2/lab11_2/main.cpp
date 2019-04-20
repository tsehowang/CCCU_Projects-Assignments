//#include <iostream>
//#include <string>
//#include "Rational.h"
//using namespace std;
//
//// Function declaration
//int getMenuChoice();
//
//// Main program
//int main()
//{
//	int numerator;
//	int denominator;
//	Rational* rational1 = NULL;
//	Rational* rational2 = NULL;
//	Rational* result = NULL;
//
//	// Read first fraction
//	cout << "Enter numerator 1: ";
//	cin >> numerator;
//	cout << "Enter denominator 1: ";
//	cin >> denominator;
//	rational1 = new Rational;
//	rational1->initialize(numerator, denominator);
//
//	// Read second fraction
//	cout << "Enter numerator 2: ";
//	cin >> numerator;
//	cout << "Enter denominator 2: ";
//	cin >> denominator;
//	rational2 = new Rational;
//	rational2->initialize(numerator, denominator);
//
//	system("cls");
//
//	// User's choice in the menu
//	int choice = getMenuChoice();
//
//	while(choice != 5)
//	{
//		system("cls");
//		switch(choice)
//		{
//			case 1:
//				result = rational1->add(*rational2);
//				cout << "a + b = " << result->getRationalString() << endl;
//				cout << "a + b = " << result->getFloatString() << endl;				
//				break;
//			case 2:
//				result = rational1->subtract(*rational2);
//				cout << "a - b = " << result->getRationalString() << endl;
//				cout << "a - b = " << result->getFloatString() << endl;
//				break;
//			case 3:
//				result = rational1->multiply(*rational2);
//				cout << "a * b = " << result->getRationalString() << endl;
//				cout << "a * b = " << result->getFloatString() << endl;
//				break;
//			case 4:
//				result = rational1->divide(*rational2);
//				cout << "a / b = " << result->getRationalString() << endl;
//				cout << "a / b = " << result->getFloatString() << endl;
//				break;
//		}
//		if(result != NULL)
//		{
//			delete result;
//			result = NULL;
//		}
//		system("pause");
//		system("cls");
//		choice = getMenuChoice();
//	}
//
//	if(rational1 != NULL)
//		delete rational1;
//	if(rational2 != NULL)
//		delete rational2;	
//}
//
//int getMenuChoice()
//{
//	cout << "--------------" << endl;
//	cout << " Operation:" << endl;
//	cout << "--------------" << endl;
//	cout << " 1. Add" << endl;
//	cout << " 2. Subtact" << endl;
//	cout << " 3. Multiply" << endl;
//	cout << " 4. Divide" << endl;
//	cout << " 5. Exit" << endl;
//	cout << "--------------" << endl;
//	cout << endl;
//	cout << " Choice: ";
//	int choice;
//	cin >> choice;
//	return choice;
//}