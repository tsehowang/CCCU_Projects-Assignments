#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
	string* monthNames;
	int* monthDays;

public:
	void initialize();
	void setDay(int dd);
	void setMonth(int mm);
	void setYear(int yyyy);
	void convertFromMonthName(string monthName);
	string toMonthDayYear();
	string toMonthNameDate();
	bool leapYear();
	int daysInMonth();
};
#endif // !DATE_H

