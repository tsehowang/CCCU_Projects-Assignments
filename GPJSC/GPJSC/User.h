
#ifndef User_h
#define User_h

#include <iostream>
using namespace std;

class User {
public:																							//public function
	User(string username, string name);
	virtual string getUsername();
	virtual string getName();
	virtual void setUsername(string uname);
	virtual void setName(string nm);
	//pure - virtual function
	virtual string getVehicleType() = 0;
	virtual string getPlateNumber() = 0;
	virtual double getAccountBalance() = 0;
	virtual string getRole() = 0;
	virtual void setVehicleType(int tp) = 0;
	virtual int getVNum() = 0;
	virtual void setPlateNumber(string pnum) = 0;
	virtual void setAccountBalance(double balance) = 0;
	virtual void addAccountBalance(double money) = 0;


private:																						//private variable
	string username, name;
};


#endif /* User_h */