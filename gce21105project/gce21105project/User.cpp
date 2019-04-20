#include "User.h"

#include <sstream>

// ~ Constructors ~

// Base class User constructor
User::User(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address)
{
	this->id = id;
	this->name = name;
	this->section = section;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
	loanLimit = 1;
	//std::cout << "user created" << std::endl;                            	// used for debug, will be deleted
}


// Scouts constructor
sct::sct(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address, std::string rank) : User(id, name, section, dateOfBirth, address)
{
	loanLimit = 1;
	this->rank = rank;
	//std::cout << "scout created" << std::endl;                            	// used for debug, will be deleted
}


// Venture scouts constructor
ven::ven(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address) : User(id, name, section, dateOfBirth, address)
{
	loanLimit = 3;
	//std::cout << "ven created" << std::endl;                            	// used for debug, will be deleted
}


// Rover scouts constructor
rov::rov(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address) : User(id, name, section, dateOfBirth, address)
{
	loanLimit = 5;
	//std::cout << "rov created" << std::endl;                            	// used for debug, will be deleted
}



// Scouters constructor
scm::scm(std::string id, std::string name, std::string section, std::string dateOfBirth, std::string address, std::string rank) : User(id, name, section, dateOfBirth, address)
{
	loanLimit = 5;
	this->rank = rank;
	//std::cout << "scouter created" << std::endl;                            	// used for debug, will be deleted
}





// getters
std::string User::getId() {
	//std::cout << "id got" << ", ";                                            	// used for debug, will be deleted
	return id;
}
std::string User::getName() {
	//std::cout << "name got" << ", ";                                        	// used for debug, will be deleted
	return name;
}
std::string User::getSection() {
	//std::cout << "section got" << ", ";                                        	// used for debug, will be deleted
	return section;
}
std::string User::getDateOfBirth() {
	//std::cout << "date of birth got" << ", ";                                	// used for debug, will be deleted
	return dateOfBirth;
}
std::string User::getAddress() {
	//std::cout << "address got" << ", ";                                        	// used for debug, will be deleted
	return address;
}
std::string sct::getRank() {
	//std::cout << "rank got" << ", ";                                        	// used for debug, will be deleted
	return rank;
}
std::string scm::getRank() {
	//std::cout << "rank got" << ", ";                                        	// used for debug, will be deleted
	return rank;
}
int User::getLoanLimit() {
	//std::cout << "Limit got" << ", ";
	return loanLimit;
}

std::string User::getUserInfo() {
	std::stringstream ss;
	ss << std::endl << getId() << "|" << getName() << "|" << getSection() << "|" << getDateOfBirth() << "|" << getAddress() << "|" << getLoanLimit();
	std::string info = ss.str();
	return info;
}


std::string sct::getUserInfo() {
	std::stringstream ss;
	ss << std::endl << getId() << "|" << getName() << "|" << getSection() << "|" << getDateOfBirth() << "|" << getAddress() << "|" << getRank() << "|" << getLoanLimit();
	std::string info = ss.str();
	return info;
}

std::string scm::getUserInfo() {
	std::stringstream ss;
	ss << std::endl << getId() << "|" << getName() << "|" << getSection() << "|" << getDateOfBirth() << "|" << getAddress() << "|" << getRank() << "|" << getLoanLimit();
	std::string info = ss.str();
	return info;
}

void User::addLoanLimit() {
	loanLimit++;
}

void User::reduceLoanLimit() {
	loanLimit--;
}


// ~ Destructors ~

// Base class User destructor
User::~User()
{

}


// scouts destructor
sct::~sct()
{

}


// Venture scouts destructor
ven::~ven()
{

}


// Rover scouts destructor
rov::~rov()
{

}


// Scouters destructor
scm::~scm()
{

}
