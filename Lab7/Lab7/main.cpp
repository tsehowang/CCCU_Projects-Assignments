#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

int getMenuChoice()
{
	int option;
	cout << "Enter 1 for format: MM/DD/YYYY" << endl;
	cout << "Enter 2 for format: Month DD, YYYY" << endl;	
	cout << "Enter 3 to exit" << endl;
	cout << endl;
	cout << "Choice: ";
	cin >> option;
	cout << endl;
	return option;
}

int main()
{
	Date date;
	date.initialize();
	int choice = getMenuChoice();
	while(choice != 3)
	{
		int month;
		int day;
		int year;
		string monthName;		

		switch(choice)
		{
			case 1:
				cout << "Enter Month (1-12): ";
				cin >> month;
				cout << "Enter Day of Month: ";
				cin >> day;
				cout << "Enter Year: ";
				cin >> year;
				date.setYear(year);
				date.setMonth(month);				
				date.setDay(day);				
				break;
			case 2:
				cout << "Enter Month Name: ";
				cin >> monthName;
				cout << "Enter Day of Month: ";
				cin >> day;
				cout << "Enter Year: ";
				cin >> year;
				date.setYear(year);
				date.convertFromMonthName(monthName);
				date.setDay(day);
				break;
		}
		string date1 = date.toMonthDayYear();
		string date2 = date.toMonthNameDate();		
		cout << date1 << endl;
		cout << date2 << endl;		
		system("pause");
		system("cls");
		choice = getMenuChoice();
	}
	return 0;
}