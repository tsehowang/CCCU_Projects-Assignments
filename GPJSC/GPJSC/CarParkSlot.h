
#ifndef CarParkSlot_h
#define CarParkSlot_h

#include <iostream>
#include <deque>
#include <string>

using namespace std;

class CarParkSlot {
public:																							//the public function
	deque<deque<int>> status;
	deque<deque<int>> bookedList;

	CarParkSlot(int vehicleType);
	string getVehicleType();
	string getSlotStates(int date, int slotId);
	void setVechicleType(int vType);

private:																						//the private variable
	int vehicleType;

};

#endif /* CarParkSlot_h */