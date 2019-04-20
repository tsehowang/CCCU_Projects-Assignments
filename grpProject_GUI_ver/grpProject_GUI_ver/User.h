#ifndef USER_H
#define USER_H

#include <iostream>

// Base Class User
class User
{
protected:
	std::string id;                                            	// id of all types of scouts
	std::string name;                                        	// name of all types of scouts
	std::string section;                                    	// section of the scouts
	std::string dateOfBirth;                                	// date of birth(password) of all types of scouts
	std::string address;                                    	// address of all types of scouts
	int loanLimit;

public:
	User(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address);
	virtual std::string getId();
	virtual std::string getName();
	virtual std::string getSection();
	virtual std::string getDateOfBirth();
	virtual std::string getAddress();
	virtual std::string getUserInfo();
	virtual int getLoanLimit();
	virtual void addLoanLimit();
	virtual void reduceLoanLimit();

	~User();
};


// User: Scouts | level of right: borrow 1
class sct :
	public User
{
private:
	std::string rank;                                        	// ranking of scout: Member, Patrol Leader, Assistant Patrol Leader

public:
	sct(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address, std::string rank);
	std::string getRank();
	std::string getUserInfo();
	~sct();

};


// User: Venture scouts | level of right: borrow 3
class ven :
	public User
{
private:


public:
	ven(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address);
	~ven();

};


// User: Rover scouts | level of right: borrow 5
class rov :
	public User
{
private:


public:
	rov(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address);
	~rov();

};


// User: Scouters | level of right: borrow 5
class scm :
	public User
{
private:
	std::string rank;                                        	// ranking of scouter: Scout Leader, Assistant Scout Leader,
															 // Venture Leader, Assistant venture Leader, Rover leader, Assistant rover leader

public:
	scm(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address, std::string rank);
	std::string getRank();
	std::string getUserInfo();
	~scm();

};
#endif // !USER_H
