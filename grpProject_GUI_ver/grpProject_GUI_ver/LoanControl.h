#ifndef LOANCONTROL_H
#define LOANCONTROL_H

#include <string>
#include <iostream>

class LoanControl
{
private:
	std::string out = "out";
public:
	std::string equipmentSelection();
	void loan(std::string loginID);
	void checkLimit(std::string loginID);
	void displayLoanRecord(std::string loginID);
	void returnEquipment(std::string loginID);
	LoanControl() {};
};
#endif
