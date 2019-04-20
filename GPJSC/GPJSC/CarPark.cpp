
#include "CarPark.h"

//type constructor
CarPark::CarPark(int id, string name, string location, int motorCycleSlot, int privateCarSlot, int lightGoodsVehicleSlot, double motorCycleFee, double privateCarFee, double lightGoodsVehicleFee) {

	this->id = id;
	this->name = name;
	this->location = location;
	this->motorCycleSlot = motorCycleSlot;
	this->privateCarSlot = privateCarSlot;
	this->lightGoodsVehicleSlot = lightGoodsVehicleSlot;
	this->motorCycleFee = motorCycleFee;
	this->privateCarFee = privateCarFee;
	this->lightGoodsVehicleFee = lightGoodsVehicleFee;
	balance = 0;
	for (int i = 0; i<motorCycleSlot; i++) {
		cpSlot_List.push_back(CarParkSlot(0));
	}
	for (int i = 0; i<privateCarSlot; i++) {
		cpSlot_List.push_back(CarParkSlot(1));
	}
	for (int i = 0; i<lightGoodsVehicleSlot; i++) {
		cpSlot_List.push_back(CarParkSlot(2));
	}
}

//getter
int CarPark::getID() {
	return id;
}

//setter
void CarPark::setID(int id) {
	this->id = id;
}

//getter
string CarPark::getName() {
	return name;
}

//setter
void CarPark::setName(string name) {
	this->name = name;
}

//getter
string CarPark::getLocation() {
	return location;
}

//setter
void CarPark::setLocation(string location) {
	this->location = location;
}

//getter
int CarPark::getMotorCycleSlot() {
	return motorCycleSlot;
}

//setter
void CarPark::setMotorCycleSlot(int motorCycleSlot) {
	this->motorCycleSlot = motorCycleSlot;
}

//getter
int CarPark::getPrivateCarSlot() {
	return privateCarSlot;
}

//setter
void CarPark::setPrivateCarSlot(int privateCarSlot) {
	this->privateCarSlot = privateCarSlot;
}

//getter
int CarPark::getLightGoodsVehicleSlot() {
	return lightGoodsVehicleSlot;
}

//setter
void CarPark::setLightGoodsVehicleSlot(int lightGoodsVehicleSlot) {
	this->lightGoodsVehicleSlot = lightGoodsVehicleSlot;
}

//getter
double CarPark::getMotorCycleFee() {
	return motorCycleFee;
}

//setter
void CarPark::setMotorCycleFee(double fee) {
	motorCycleFee = fee;
}

//getter
double CarPark::getPrivateCarFee() {
	return privateCarFee;
}

//setter
void CarPark::setPrivateCarFee(double fee) {
	privateCarFee = fee;
}

//getter
double CarPark::getLightGoodsVehicleFee() {
	return lightGoodsVehicleFee;
}

//setter
void CarPark::setLightGoodsVehicleFee(double fee) {
	lightGoodsVehicleFee = fee;
}

//getter
double CarPark::getFeeByType(int type) {
	switch (type)
	{
	case 0:
		return motorCycleFee;
		break;
	case 1:
		return privateCarFee;
		break;
	case 2:
		return lightGoodsVehicleFee;
		break;
	default:
		return -1;
		break;
	}
}

//add slot
void CarPark::addSlot(int type, int number) {
	for (int i = 0; i<number; i++) {
		cpSlot_List.push_back(CarParkSlot(type));
	}
}