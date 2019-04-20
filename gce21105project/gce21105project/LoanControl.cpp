#include "LoanControl.h"
#include "FileHandler.h"
#include "User.h"

string LoanControl::equipmentSelection() {
	system("cls");
	// print all equipments info
	bool flag = true;
	for (int i = 0; i < std::size(allEquipments); i++) {
		if ((allEquipments[i]->getCondition() == "good") && (allEquipments[i]->getStatus() == "in")) {
			flag = false;
		}
	}
	if (flag) {
		cout << "Sorry, no equipment is available to be loaned.\n";
		system("pause");
		return "";
	}
	else {
		std::cout << std::endl << "~ Print equipments info ~" << std::endl;
		for (int i = 0; i < std::size(allEquipments); i++) {
			if ((allEquipments[i]->getCondition() == "good") && (allEquipments[i]->getStatus() == "in")) {
				std::cout << allEquipments[i]->getEquipmentInfo() << std::endl << std::endl;
			}
		}
		cout << "Which item do you want to loan(Please enter the item code)";
		string selectedCode;
		cin >> selectedCode;

		return selectedCode;
	}
}

void LoanControl::loan(string loginID) {
	string selectedCode = equipmentSelection();
	int UserNo;
	int counter = 0;
	for (int i = 0; i < std::size(allUsers); i++) {
		if (allUsers[i]->getId() == loginID) {
			UserNo = i;
		}
	}
	if (selectedCode != "") {
		if (allUsers[UserNo]->getLoanLimit() > 0) {
			for (int i = 0; i < std::size(allEquipments); i++) {
				if (allEquipments[i]->getItemCode() == selectedCode && allEquipments[i]->getStatus() == "in" && allEquipments[i]->getCondition() == "good") {
					allEquipments[i]->setStatus(out);
					FileHandler tempHandler;
					for (int j = 0; j < std::size(allUsers); j++) {
						if (allUsers[j]->getId() == loginID) {
							allUsers[j]->reduceLoanLimit();
							tempHandler.WriteLoanRecordOut(loginID, selectedCode);
							tempHandler.WriteEquipment();
						}
					}
					cout << allEquipments[i]->getEquipmentInfo() << endl;
				}
				else {
					counter++;
					if (counter == size(allEquipments)) {
						cout << "Sorry, we do not find the equipment ID or the equipment is already been loaned." << endl;
						system("pause");
					}
				}
			}
		}
		else {
			cout << "Sorry, your loan limit is down already. If you want to borrow more books, you can return the left." << endl;
			system("pause");
		}
	}

}

void LoanControl::checkLimit(string loginID) {
	system("cls");
	for (int i = 0; i < std::size(allUsers); i++) {
		if (allUsers[i]->getId() == loginID) {
			cout << "You can only loan " << allUsers[i]->getLoanLimit() << " equipment." << endl;
		}
	}
	system("pause");
}

void LoanControl::displayLoanRecord(string loginID) {
	system("cls");
	FileHandler tempHandler;
	tempHandler.displayCurrentStatusToUser(loginID);
	tempHandler.WriteEquipment();

	system("pause");
}

void LoanControl::returnEquipment(string loginID) {
	system("cls");
	string itemCode = "0";
	FileHandler tempHandler;
	tempHandler.displayCurrentStatusToUser(loginID);
	cout << "Enter the item code to return:";
	while (true) {
		cin >> itemCode;
		if (itemCode == "-1") {
			break;
		}
		else {
			if (tempHandler.writeCurrentStatus(itemCode, loginID)) {
				for (int j = 0; j < std::size(allUsers); j++) {
					if (allUsers[j]->getId() == loginID) {
						allUsers[j]->addLoanLimit();
					}
				}
			}
			tempHandler.WriteEquipment();
			cout << endl;
		}
	}
	system("pause");
}
