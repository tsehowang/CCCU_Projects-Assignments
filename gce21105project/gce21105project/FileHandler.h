#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <fstream>
#include <regex>
#include <deque>
#include "User.h"
#include "Equipment.h"

__declspec(selectany)std::deque<std::shared_ptr<User>> allUsers;
__declspec(selectany)std::deque<std::shared_ptr<Equipment>> allEquipments;

class FileHandler {
private:

	std::ifstream txtInput;
	std::ofstream txtOutput;
	std::string line;

	//users
	std::string id;
	std::string name;
	std::string section;
	std::string dateOfBirth;
	std::string address;
	std::string rank;

	std::regex re{ "(([^|^\n]+))" };
	std::regex reVEN{ "(([VEN]{3}[0-9]{3}))" };
	std::regex reROV{ "(([ROV]{3}[0-9]{3}))" };
	std::regex reSCT{ "(([SCT]{3}[0-9]{3}))" };
	std::regex reSCM{ "(([SCM]{3}[0-9]{3}))" };

	//eq
	std::string itemCode;
	std::string itemName;
	std::string brand;
	std::string equipmentType;
	std::string dateOfPurchase;
	std::string condition;
	std::string status;

	int numOfPeopleUse;
	std::string tentType;
	int numOfDoors;
	bool doubleLayer;
	std::string color;
	std::string stoveType;
	std::string fuelType;
	std::string lanternSize;
	std::string lanternType;

	std::regex reT{ "(([T]{1}[0-9]{3}))" };
	std::regex reS{ "(([S]{1}[0-9]{3}))" };
	std::regex reL{ "(([L]{1}[0-9]{3}))" };

public:
	FileHandler() { std::string a = "1"; };
	~FileHandler() {};
	void ReadUser();
	void ReadUserInfo();
	void ReadEquipment();
	void ReadEquipmentInfo();
	void WriteEquipment();
	void getCurrentStatusInfo();
	bool currentStatusHas(std::string userID);
	void displayCurrentStatusToUser(std::string userID);
	void writeCurrentStatus(std::string userID, std::string equipment, std::string returnDate, std::string borrowDate);
	bool writeCurrentStatus(std::string equipment, std::string userID);
	void CurrentStatusChecking();
	void WriteLoanRecordIn(std::string userID, std::string equipment, std::string returnDate);
	void displayLoanRecord();
	void WriteLoanRecordOut(std::string userID, std::string equipment);
};


#endif
