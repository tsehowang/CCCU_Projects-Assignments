#include "Admin.h"
#include "FileHandler.h"

#include <string>

// admin class
Admin::Admin() {
	adminId = "admin";
	adminPassword = "admin";
}

// getters
std::string Admin::getAdminId() {
	return adminId;
}

std::string Admin::getAdminPassword() {
	return adminPassword;
}

// functions
void Admin::UpdateEquipment() {
	system("cls");
	FileHandler txt;
	txt.ReadEquipmentInfo();
	std::string numOfEquipment;
	int numOfStatus;
	std::cout << "which status of equipments do you want to change: ";
	std::cin >> numOfEquipment;

	for (int i = 0; i < std::size(allEquipments); i++) {
		if (allEquipments[i]->getItemCode() == numOfEquipment) {
			std::cout << "1. damage " << std::endl;
			std::cout << "2. good " << std::endl;
			std::cout << "3. being prepared " << std::endl;
			std::cout << "4. disposed: " << std::endl;
			std::cout << "choose the status you want to change :";
			std::cin >> numOfStatus;

			switch (numOfStatus)
			{
			case 1:
				allEquipments[i]->setCondition("damage");
				txt.WriteEquipment();
				std::cout << "changed successfully." << std::endl;
				break;
			case 2:
				allEquipments[i]->setCondition("good");
				txt.WriteEquipment();
				std::cout << "changed successfully." << std::endl;
				break;
			case 3:
				allEquipments[i]->setCondition("being prepared");
				txt.WriteEquipment();
				std::cout << "changed successfully." << std::endl;
				break;
			case 4:
				allEquipments[i]->setCondition("disposed");
				txt.WriteEquipment();
				std::cout << "changed successfully." << std::endl;
				break;
			default:
				std::cout << "you enter the default number. Please enter again.";
			}
		}
	}
}

Admin::~Admin()
{
}
