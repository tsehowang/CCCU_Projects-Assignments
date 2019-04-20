#include "CarParkSlot.h"

//type constroctor
CarParkSlot::CarParkSlot(int vehicleType) {
	deque<int> time(24, 0);
	deque<int> booked(24, -1);
	this->vehicleType = vehicleType;
	for (int i = 0; i<32; i++) {
		status.push_back(time);
		bookedList.push_back(booked);
	}
}

//getter
string CarParkSlot::getVehicleType() {
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
string CarParkSlot::getSlotStates(int date, int slotId) {
	switch (status[date][slotId]) {
	case 0:
		return "Free";
		break;
	case 1:
		return "Occupied";
		break;
	case 2:
		return "Out of service";
		break;
	}
	return "error";

}

//setter
void CarParkSlot::setVechicleType(int vType) { vehicleType = vType; };