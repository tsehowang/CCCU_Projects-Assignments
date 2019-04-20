#ifndef LOANCONTROL_H
#define LOANCONTROL_H
#include <string>
#include <iostream>
using namespace std;


class LoanControl
{
private:
	string out = "out";
public:
	string equipmentSelection();
	void loan(string loginID);
	void checkLimit(string loginID);
	void displayLoanRecord(string loginID);
	void returnEquipment(string loginID);
	LoanControl() {};
};


#endif
