#include "Driver.h"

//type constructer
Driver::Driver(string username, string name, int vehicleType, string plateNumber) : User(username, name) {
	this->vehicleType = vehicleType;
	this->plateNumber = plateNumber;
	accountBalance = 0;
}

//getter
string Driver::getRole() {
	return "Driver";
}

//getter
string Driver::getVehicleType() {
	switch (vehicleType) {
	case 0:
		return "Motor cycles";
		break;
	case 1:
		return "Private cars";
		break;
	case 2:
		return "Light goods vehicles";
		break;
	}
	return "error";
}

//getter
string Driver::getPlateNumber() {
	return plateNumber;
}

//getter
double Driver::getAccountBalance() {
	return accountBalance;
}

//setter
void Driver::setVehicleType(int tp) {
	vehicleType = tp;
}

//setter
void Driver::setPlateNumber(string pum) {
	plateNumber = pum;
}

//setter
void Driver::setAccountBalance(double balance) {
	accountBalance = balance;
}

//setter
void Driver::addAccountBalance(double money) {
	accountBalance += money;
}