#ifndef CarPark_hpp
#define CarPark_hpp

#include <iostream>
#include "CarParkSlot.h"
#include <deque>

using namespace std;

class CarPark {
public:																							//the public function of car park
	deque<CarParkSlot> cpSlot_List;
	CarPark(int id, string name, string location, int motorCycleSlot, int privateCarSlot, int lightGoodsVehicleSlot, double motorCycleFee, double privateCarFee, double lightGoodsVehicleFee);
	int getID();
	void setID(int id);
	string getName();
	void setName(string name);
	string getLocation();
	void setLocation(string location);
	void setBalance(double bal) { balance = bal; };
	double getBalance() { return balance; };
	void addBalance(double bal) { balance += bal; };
	int getMotorCycleSlot();
	void setMotorCycleSlot(int motorCycleSlot);
	int getPrivateCarSlot();
	void setPrivateCarSlot(int privateCarSlot);
	int getLightGoodsVehicleSlot();
	void setLightGoodsVehicleSlot(int lightGoodsVehicleSlot);
	double getMotorCycleFee();
	void setMotorCycleFee(double fee);
	double getPrivateCarFee();
	void setPrivateCarFee(double fee);
	double getLightGoodsVehicleFee();
	void setLightGoodsVehicleFee(double fee);
	double getFeeByType(int type);
	void addSlot(int type, int number);

private:
	string name, location;																			//the private variable of car park
	int id, motorCycleSlot, privateCarSlot, lightGoodsVehicleSlot;
	double motorCycleFee, privateCarFee, lightGoodsVehicleFee, balance;

};

#endif /* CarPark_hpp */
