#include "FileHandler.h"
#include <chrono>
#include <ctime>
#include <algorithm>

void FileHandler::ReadUser() {
	txtInput.open("user.txt");
	if (txtInput.is_open())
	{
		while (getline(txtInput, line)) {

			std::string tempPtr;
			int ctrOfLine = 1;
			using reg_itr = std::regex_token_iterator<std::string::iterator>;
			for (reg_itr it{ line.begin(), line.end(), re, 1 }, end{}; it != end;) {
				tempPtr = *it;
				if (regex_match(tempPtr, reVEN)) {
					ctrOfLine = 5;
				}
				else if (regex_match(tempPtr, reROV)) {
					ctrOfLine = 5;
				}
				else if (regex_match(tempPtr, reSCT)) {
					ctrOfLine = 6;
				}
				else if (regex_match(tempPtr, reSCM)) {
					ctrOfLine = 6;
				}
				else std::cout << std::endl << "wrong syntax" << std::endl;
				for (int i = 0; i < ctrOfLine; i++) {
					tempPtr = *it;
					//std::cout << tempPtr << " ";
					switch (i) {
					case(0):id = tempPtr;
					case(1):name = tempPtr;
					case(2):section = tempPtr;
					case(3):dateOfBirth = tempPtr;
					case(4):address = tempPtr;
					case(5):rank = tempPtr;
					}
					it++;
				}
				//std::cout << section;
				if (section == "Scout")
					allUsers.push_back(std::make_shared<sct>(id, name, section, dateOfBirth, address, rank));
				else if (section == "Venture Scout")
					allUsers.push_back(std::make_shared<ven>(id, name, section, dateOfBirth, address));
				else if (section == "Rover Scout")
					allUsers.push_back(std::make_shared<rov>(id, name, section, dateOfBirth, address));
				else if (section == "Scouter")
					allUsers.push_back(std::make_shared<scm>(id, name, section, dateOfBirth, address, rank));
				else
					std::cout << "User's section is incorrect" << std::endl;
			}
		}

		txtInput.close();
	}
}

void FileHandler::ReadUserInfo() {
	// print all users info
	std::cout << std::endl << "~ Print users info ~" << std::endl;

	for (int i = 0; i < std::size(allUsers); i++)
		std::cout << allUsers[i]->getUserInfo() << std::endl << std::endl;
}

void FileHandler::ReadEquipment() {


	txtInput.open("camp_equipment.txt");
	if (txtInput.is_open())
	{
		while (getline(txtInput, line)) {

			std::string tempPtr;
			int ctrOfLine = 1;
			using reg_itr = std::regex_token_iterator<std::string::iterator>;
			for (reg_itr it{ line.begin(), line.end(), re, 1 }, end{}; it != end;) {
				tempPtr = *it;
				if (regex_match(tempPtr, reT)) {
					ctrOfLine = 16;
				}
				else if (regex_match(tempPtr, reS)) {
					ctrOfLine = 23;
				}
				else if (regex_match(tempPtr, reL)) {
					ctrOfLine = 34;
				}
				else std::cout << std::endl << "wrong syntax" << std::endl;
				for (int i = 0; i < ctrOfLine; i++) {
					tempPtr = *it;
					//std::cout << tempPtr << " ";
					switch (i) {
					case(0): { itemCode = tempPtr; break; }
					case(1): { itemName = tempPtr; break; }
					case(2): { brand = tempPtr; break; }
					case(3): { equipmentType = tempPtr; break; }
					case(4): { dateOfPurchase = tempPtr; break; }
					case(5): { condition = tempPtr; break; }
					case(6): { status = tempPtr; if (ctrOfLine == 16) { i = 10; }
							 else if (ctrOfLine == 23) { i = 20; }
							 else if (ctrOfLine == 34) { i = 30; } break; }
							 //tent
					case(11): { std::string tempNum = tempPtr; numOfPeopleUse = std::stoi(tempNum); break; }
					case(12): { tentType = tempPtr; break; }
					case(13): { std::string tempNum = tempPtr; numOfDoors = std::stoi(tempNum); break; }
					case(14): { doubleLayer = (tempPtr == "true" ? true : false); break; }
					case(15): { color = tempPtr; break; }
							  //stove
					case(21): { stoveType = tempPtr; break; }
					case(22): {  fuelType = tempPtr; break; }
							  //lantern
					case(31): { lanternSize = tempPtr; break; }
					case(32): { lanternType = tempPtr; break; }
					case(33): { fuelType = tempPtr; break; }
					}
					it++;
				}
				//std::cout << section;
				if (equipmentType == "tent")
					allEquipments.push_back(std::make_shared<tent>(itemCode, itemName, brand, equipmentType, dateOfPurchase, condition, status, numOfPeopleUse, tentType, numOfDoors, doubleLayer, color));
				else if (equipmentType == "stove")
					allEquipments.push_back(std::make_shared<stove>(itemCode, itemName, brand, equipmentType, dateOfPurchase, condition, status, stoveType, fuelType));
				else if (equipmentType == "lantern")
					allEquipments.push_back(std::make_shared<lantern>(itemCode, itemName, brand, equipmentType, dateOfPurchase, condition, status, lanternSize, lanternType, fuelType));
				else
					std::cout << "User's section is incorrect" << std::endl;
			}
		}
		txtInput.close();

	}
	std::sort(allEquipments.begin(), allEquipments.end(), Equipment::sortByName);
}



void FileHandler::ReadEquipmentInfo() {
	// print all equipments info
	std::cout << std::endl << "~ Print equipments info ~" << std::endl;

	for (int i = 0; i < std::size(allEquipments); i++)
		std::cout << allEquipments[i]->getEquipmentInfo() << std::endl << std::endl;

}

void FileHandler::WriteEquipment() {
	std::string* itemCode = new std::string[std::size(allEquipments)];
	std::string* borrower = new std::string[std::size(allEquipments)];
	std::string* returnDateArr = new std::string[std::size(allEquipments)];
	std::string* borrowDateArr = new std::string[std::size(allEquipments)];
	txtInput.open("currentStatus.txt");
	int tempLine = 0;
	if (txtInput.is_open())
	{
		while (getline(txtInput, line)) {

			std::string tempPtr;
			int ctrOfLine = 4;
			using reg_itr = std::regex_token_iterator<std::string::iterator>;

			for (reg_itr it{ line.begin(), line.end(), re, 1 }, end{}; it != end;) {
				for (int i = 0; i < ctrOfLine; i++) {
					tempPtr = *it;
					switch (i) {
					case(0): {itemCode[tempLine] = tempPtr; break; }
					case(1): {borrower[tempLine] = tempPtr; break; }
					case(2): {returnDateArr[tempLine] = tempPtr; break; }
					case(3): {borrowDateArr[tempLine] = tempPtr; tempLine = tempLine + 1; break; }
					}
					it++;
				}

				//std::cout << section;
			}
		}
		txtInput.close();
	}

	for (int i = 0; i < std::size(allEquipments); i++) {
		if (borrower[i] == "available") {
			allEquipments[i]->setStatus("in");
		}
		else allEquipments[i]->setStatus("out");
	}

	if (!allEquipments.empty()) {
		std::string outputStorer;
		outputStorer += allEquipments.at(0)->getEquipmentInfo();
		for (int i = 1; i < allEquipments.size(); i++) {
			outputStorer += "\n" + allEquipments.at(i)->getEquipmentInfo();
		}

		txtOutput.open("camp_equipment.txt");
		txtOutput << outputStorer;
		txtOutput.close();
	}
	else std::cout << "Error: no data in allEquipments" << std::endl;
	delete[] itemCode;
	delete[] borrower;
	delete[] returnDateArr;
	delete[] borrowDateArr;
}

void FileHandler::getCurrentStatusInfo() {
	std::string* borrower = new std::string[std::size(allEquipments)];
	txtInput.open("currentStatus.txt");
	int tempLine = 0;
	if (txtInput.is_open())
	{
		while (getline(txtInput, line)) {

			std::string tempPtr;
			int ctrOfLine = 4;
			using reg_itr = std::regex_token_iterator<std::string::iterator>;

			for (reg_itr it{ line.begin(), line.end(), re, 1 }, end{}; it != end;) {
				for (int i = 0; i < ctrOfLine; i++) {
					tempPtr = *it;
					switch (i) {
					case(0): {break; }
					case(1): {borrower[tempLine] = tempPtr; break; }
					case(2): {break; }
					case(3): {tempLine = tempLine + 1; break; }
					}
					it++;
				}

				//std::cout << section;
			}
		}
		txtInput.close();
	}
	for (int i = 0; i < std::size(allEquipments); i++) {
		if (borrower[i] != "available") {
			for (int j = 0; j < std::size(allUsers); j++) {
				if (allUsers[j]->getId() == borrower[i]) {
					allUsers[j]->reduceLoanLimit();
				}
			}
		}
	}

	delete[] borrower;
}

bool FileHandler::currentStatusHas(std::string userID) {
	std::string* borrower = new std::string[std::size(allEquipments)];
	txtInput.open("currentStatus.txt");
	int tempLine = 0;
	if (txtInput.is_open())
	{
		while (getline(txtInput, line)) {

			std::string tempPtr;
			int ctrOfLine = 4;
			using reg_itr = std::regex_token_iterator<std::string::iterator>;

			for (reg_itr it{ line.begin(), line.end(), re, 1 }, end{}; it != end;) {
				for (int i = 0; i < ctrOfLine; i++) {
					tempPtr = *it;
					switch (i) {
					case(0): {break; }
					case(1): {borrower[tempLine] = tempPtr; break; }
					case(2): {break; }
					case(3): {tempLine = tempLine + 1; break; }
					}
					it++;
				}

				//std::cout << section;
			}
		}
		txtInput.close();
	}
	for (int i = 0; i < std::size(allEquipments); i++) {
		if (borrower[i] == userID) {
			delete[] borrower;
			return true;
		}
	}
	delete[] borrower;
	return false;
}

void FileHandler::displayCurrentStatusToUser(std::string userID) {
	std::string* itemCode = new std::string[std::size(allEquipments)];
	std::string* borrower = new std::string[std::size(allEquipments)];
	std::string* returnDateArr = new std::string[std::size(allEquipments)];
	std::string* borrowDateArr = new std::string[std::size(allEquipments)];
	bool flag = true;
	txtInput.open("currentStatus.txt");
	int tempLine = 0;
	if (txtInput.is_open())
	{
		while (getline(txtInput, line)) {

			std::string tempPtr;
			int ctrOfLine = 4;
			using reg_itr = std::regex_token_iterator<std::string::iterator>;

			for (reg_itr it{ line.begin(), line.end(), re, 1 }, end{}; it != end;) {
				for (int i = 0; i < ctrOfLine; i++) {
					tempPtr = *it;
					switch (i) {
					case(0): {itemCode[tempLine] = tempPtr; break; }
					case(1): {borrower[tempLine] = tempPtr; break; }
					case(2): {returnDateArr[tempLine] = tempPtr; break; }
					case(3): {borrowDateArr[tempLine] = tempPtr; tempLine = tempLine + 1; break; }
					}
					it++;
				}

				//std::cout << section;
			}
		}
		txtInput.close();
		std::string outputStorer = "";
		for (int i = 0; i < std::size(allEquipments); i++) {
			if (borrower[i] == userID) {
				for (int j = 0; j < std::size(allEquipments); j++) {
					if (itemCode[i] == allEquipments[j]->getItemCode()) {
						flag = false;
						std::cout << "Loan Date: " << borrowDateArr[i] << "|";
						std::cout << "Camp Equipment ID: " << itemCode[i] << "|";
						std::cout << "Camp Equipment name: " << allEquipments[j]->getItemName() << "|";
						std::cout << "Date of return: " << returnDateArr[i] << std::endl;
					}
				}
			}
		}


		if (flag) { std::cout << "You have not loaned any camp equipment" << std::endl; }
		delete[] itemCode;
		delete[] borrower;
		delete[] returnDateArr;
		delete[] borrowDateArr;
	}
}

//this use on returning equipment
bool FileHandler::writeCurrentStatus(std::string equipment, std::string userID) {
	std::string* itemCode = new std::string[std::size(allEquipments)];
	std::string* borrower = new std::string[std::size(allEquipments)];
	std::string* returnDateArr = new std::string[std::size(allEquipments)];
	std::string* borrowDateArr = new std::string[std::size(allEquipments)];
	txtInput.open("currentStatus.txt");
	int tempLine = 0;
	if (txtInput.is_open())
	{
		while (getline(txtInput, line)) {

			std::string tempPtr;
			int ctrOfLine = 4;
			using reg_itr = std::regex_token_iterator<std::string::iterator>;

			for (reg_itr it{ line.begin(), line.end(), re, 1 }, end{}; it != end;) {
				for (int i = 0; i < ctrOfLine; i++) {
					tempPtr = *it;
					switch (i) {
					case(0): {itemCode[tempLine] = tempPtr; break; }
					case(1): {borrower[tempLine] = tempPtr; break; }
					case(2): {returnDateArr[tempLine] = tempPtr; break; }
					case(3): {borrowDateArr[tempLine] = tempPtr; tempLine = tempLine + 1; break; }
					}
					it++;
				}

				//std::cout << section;
			}
		}
		txtInput.close();
		bool flag = true;
		for (int i = 0; i < std::size(allEquipments); i++) {
			if (itemCode[i] == equipment && borrower[i] == userID) {
				WriteLoanRecordIn(userID, equipment, returnDateArr[i]);
				itemCode[i] = equipment;
				borrower[i] = "available";
				returnDateArr[i] = "noReturnDate";
				borrowDateArr[i] = "noBorrowDate";
				flag = false;
			}
		}
		if (flag) {
			std::cout << "No item code match with your input";
			delete[] itemCode;
			delete[] borrower;
			delete[] returnDateArr;
			delete[] borrowDateArr;
			return false;
		}
		else {
			std::string innerOutputStorer = "";
			for (int i = 0; i < std::size(allEquipments); i++) {
				innerOutputStorer += itemCode[i];
				innerOutputStorer += "|";
				innerOutputStorer += borrower[i];
				innerOutputStorer += "|";
				innerOutputStorer += returnDateArr[i];
				innerOutputStorer += "|";
				innerOutputStorer += borrowDateArr[i];
				innerOutputStorer += "\n";
			}
			//std::cout << "output InnerOutputStorer:\n" << innerOutputStorer;
			//system("pause");
			txtOutput.open("currentStatus.txt");
			txtOutput << innerOutputStorer;
			txtOutput.close();
			std::cout << "Item " << equipment << " returned";
		}
	}
	delete[] itemCode;
	delete[] borrower;
	delete[] returnDateArr;
	delete[] borrowDateArr;
	return true;
}

//this use on book equipment
void FileHandler::writeCurrentStatus(std::string userID, std::string equipment, std::string returnDate, std::string borrowDate) {
	std::string* itemCode = new std::string[std::size(allEquipments)];
	std::string* borrower = new std::string[std::size(allEquipments)];
	std::string* returnDateArr = new std::string[std::size(allEquipments)];
	std::string* borrowDateArr = new std::string[std::size(allEquipments)];
	txtInput.open("currentStatus.txt");
	int tempLine = 0;
	if (txtInput.is_open())
	{
		while (getline(txtInput, line)) {

			std::string tempPtr;
			int ctrOfLine = 4;
			using reg_itr = std::regex_token_iterator<std::string::iterator>;

			for (reg_itr it{ line.begin(), line.end(), re, 1 }, end{}; it != end;) {
				for (int i = 0; i < ctrOfLine; i++) {
					tempPtr = *it;
					switch (i) {
					case(0): {itemCode[tempLine] = tempPtr; break; }
					case(1): {borrower[tempLine] = tempPtr; break; }
					case(2): {returnDateArr[tempLine] = tempPtr; break; }
					case(3): {borrowDateArr[tempLine] = tempPtr; tempLine = tempLine + 1; break; }
					}
					it++;
				}

				//std::cout << section;
			}
		}
		txtInput.close();

		for (int i = 0; i < std::size(allEquipments); i++) {
			if (itemCode[i] == equipment && borrower[i] == "available") {
				itemCode[i] = equipment;
				borrower[i] = userID;
				returnDateArr[i] = returnDate;
				borrowDateArr[i] = borrowDate;
			}
		}
		std::string innerOutputStorer = "";
		for (int i = 0; i < std::size(allEquipments); i++) {
			innerOutputStorer += itemCode[i];
			innerOutputStorer += "|";
			innerOutputStorer += borrower[i];
			innerOutputStorer += "|";
			innerOutputStorer += returnDateArr[i];
			innerOutputStorer += "|";
			innerOutputStorer += borrowDateArr[i];
			innerOutputStorer += "\n";
		}
		//std::cout << "output InnerOutputStorer:\n" << innerOutputStorer;
		system("pause");
		txtOutput.open("currentStatus.txt");
		txtOutput << innerOutputStorer;
		txtOutput.close();
	}
	delete[] itemCode;
	delete[] borrower;
	delete[] returnDateArr;
	delete[] borrowDateArr;
}

void FileHandler::CurrentStatusChecking() {
	std::string* itemCode = new std::string[std::size(allEquipments)];
	std::string* borrower = new std::string[std::size(allEquipments)];
	std::string* returnDateArr = new std::string[std::size(allEquipments)];
	std::string* borrowDateArr = new std::string[std::size(allEquipments)];
	txtInput.open("currentStatus.txt");
	int tempLine = 0;
	if (txtInput.is_open())
	{
		while (getline(txtInput, line)) {

			std::string tempPtr;
			int ctrOfLine = 4;
			using reg_itr = std::regex_token_iterator<std::string::iterator>;

			for (reg_itr it{ line.begin(), line.end(), re, 1 }, end{}; it != end;) {
				for (int i = 0; i < ctrOfLine; i++) {
					tempPtr = *it;
					switch (i) {
					case(0): {itemCode[tempLine] = tempPtr; break; }
					case(1): {borrower[tempLine] = tempPtr; break; }
					case(2): {returnDateArr[tempLine] = tempPtr; break; }
					case(3): {borrowDateArr[tempLine] = tempPtr; tempLine = tempLine + 1; break; }
					}
					it++;
				}

				//std::cout << section;
			}
		}
		txtInput.close();
	}



	for (int i = 0; i < std::size(allEquipments); i++) {
		bool hasCode = false;
		for (int j = 0; j < std::size(allEquipments); j++) {
			if (allEquipments[i]->getItemCode() == itemCode[j]) { hasCode = true; break; }
		}
		if (hasCode == false) {
			std::string outputStorer = "";
			outputStorer += allEquipments[i]->getItemCode();
			outputStorer += "|available|noReturnDate|noBorrowDate\n";
			txtOutput.open("currentStatus.txt", std::ios::app);
			txtOutput << outputStorer;
			txtOutput.close();
		}
	}

}

void FileHandler::WriteLoanRecordOut(std::string userID, std::string equipment) {
	int i = 0;
	for (; i < std::size(allUsers); i++) {
		if (userID == allUsers[i]->getId()) {
			break;
		}
		else {}
	}
	int j = 0;
	for (; j < std::size(allEquipments); j++) {
		if (allEquipments[j]->getItemCode() == equipment) {
			break;
		}
	}
	//get time
	time_t now = time(0);
	time_t later = now + 1209600;
	struct tm info;
	char borrowDate[80];
	char returnDate[80];
	localtime_s(&info, &now);
	strftime(borrowDate, 80, "%Y/%m/%d", &info);
	localtime_s(&info, &later);
	strftime(returnDate, 80, "%Y/%m/%d", &info);



	std::string outputStorer = "";
	outputStorer += "loan date:";
	outputStorer += borrowDate;
	outputStorer += "|item code:";
	outputStorer += allEquipments[j]->getItemCode();
	outputStorer += "|item name:";
	outputStorer += allEquipments[j]->getItemName();
	outputStorer += "|borrower:";
	outputStorer += allUsers[i]->getName();
	outputStorer += "|return before:";
	outputStorer += returnDate;
	outputStorer += "|";
	outputStorer += "out";
	outputStorer += "\n";
	txtOutput.open("loanRecord.txt", std::ios::app);
	txtOutput << outputStorer;
	txtOutput.close();
	writeCurrentStatus(userID, equipment, returnDate, borrowDate);
}

void FileHandler::WriteLoanRecordIn(std::string userID, std::string equipment, std::string returnDate) {
	int i = 0;
	for (; i < std::size(allUsers); i++) {
		if (userID == allUsers[i]->getId()) {
			break;
		}
		else {}
	}
	int j = 0;
	for (; j < std::size(allEquipments); j++) {
		if (allEquipments[j]->getItemCode() == equipment) {
			break;
		}
	}

	//get time
	time_t now = time(0);
	time_t later = now + 1209600;
	struct tm info;
	char borrowDate[80];
	char returnDate1[80];
	localtime_s(&info, &now);
	strftime(borrowDate, 80, "%Y/%m/%d", &info);
	localtime_s(&info, &later);
	strftime(returnDate1, 80, "%Y/%m/%d", &info);



	std::string outputStorer = "";
	outputStorer += "return date:";
	outputStorer += borrowDate;
	outputStorer += "|item code:";
	outputStorer += allEquipments[j]->getItemCode();
	outputStorer += "|item name:";
	outputStorer += allEquipments[j]->getItemName();
	outputStorer += "|borrower:";
	outputStorer += allUsers[i]->getName();
	outputStorer += "|return before:";
	outputStorer += returnDate;
	outputStorer += "|";
	outputStorer += "in";
	outputStorer += "\n";
	txtOutput.open("loanRecord.txt", std::ios::app);
	txtOutput << outputStorer;
	txtOutput.close();
}

// for admin
void FileHandler::displayLoanRecord() {
	txtInput.open("loanRecord.txt");
		if (txtInput.is_open()) {
		while (getline(txtInput, line)) {
				std::cout << line << '\n';
		}
		txtInput.close();
	}
}