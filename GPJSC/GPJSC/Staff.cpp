#include "Staff.h"

//type constructor
Staff::Staff(string username, string name) : User(username, name) {
}

//getter
string Staff::getRole() {
	return "Staff";
}

//getter
string Staff::getPlateNumber() {
	return "/";
}

//getter
string Staff::getVehicleType() {
	return "/";
}

//getter
double Staff::getAccountBalance() {
	return -1;
}