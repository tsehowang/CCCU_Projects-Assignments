#pragma once
#include "user.h"

class Driver : public User {
public:																					//the public function 
public:
	Driver(string username, string name, int vehicleType, string plateNumber);
	virtual string getRole();
	virtual string getVehicleType();
	virtual string getPlateNumber();
	virtual double getAccountBalance();
	virtual void setVehicleType(int tp);
	virtual int getVNum() { return vehicleType; };
	virtual void setPlateNumber(string pnum);
	virtual void setAccountBalance(double balance);
	virtual void addAccountBalance(double money);


private:																				//the private variable
	int vehicleType;
	double accountBalance;
	string plateNumber;
};