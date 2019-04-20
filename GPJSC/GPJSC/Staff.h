#pragma once
#include "User.h"

class Staff : public User {
public:																									//public function			
	Staff(string username, string name);
	virtual string getVehicleType();
	virtual string getPlateNumber();
	virtual double getAccountBalance();
	virtual string getRole();
	virtual void setVehicleType(int tp) {};
	virtual int getVNum() { return -1; };																//getter					
	virtual void setPlateNumber(string pnum) {};
	virtual void setAccountBalance(double balance) {};
	virtual void addAccountBalance(double money) {};


};