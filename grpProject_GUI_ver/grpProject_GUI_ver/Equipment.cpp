#include "Equipment.h"
#include <sstream>

// ~ Constructors ~

// Base class Equipment constructor
Equipment::Equipment(std::string itemCode, std::string itemName, std::string brand, std::string equipmentType, std::string dateOfPurchase, std::string condition, std::string status)
{
	this->itemCode = itemCode;
	this->itemName = itemName;
	this->brand = brand;
	this->equipmentType = equipmentType;
	this->dateOfPurchase = dateOfPurchase;
	this->condition = condition;
	this->status = status;
	//std::cout << "Equipment created" << std::endl;
}


// Tents constructor
tent::tent(std::string itemCode, std::string itemName, std::string brand, std::string equipmentType, std::string dateOfPurchase, std::string condition, std::string status, int numOfPeopleUse, std::string tentType, int numOfDoors, bool doubleLayer, std::string color) : Equipment(itemCode, itemName, brand, equipmentType, dateOfPurchase, condition, status)
{
	this->numOfPeopleUse = numOfPeopleUse;
	this->tentType = tentType;
	this->numOfDoors = numOfDoors;
	this->doubleLayer = doubleLayer;
	this->color = color;
	//std::cout << "Tent created" << std::endl;
}


// Stoves constructor
stove::stove(std::string itemCode, std::string itemName, std::string brand, std::string equipmentType, std::string dateOfPurchase, std::string condition, std::string status, std::string stoveType, std::string fuelType) : Equipment(itemCode, itemName, brand, equipmentType, dateOfPurchase, condition, status)
{
	this->stoveType = stoveType;
	this->fuelType = fuelType;
	//std::cout << "Stove created" << std::endl;
}


// Lanterns construtor
lantern::lantern(std::string itemCode, std::string itemName, std::string brand, std::string equipmentType, std::string dateOfPurchase, std::string condition, std::string status, std::string lanternSize, std::string lanternType, std::string fuelType) : Equipment(itemCode, itemName, brand, equipmentType, dateOfPurchase, condition, status)
{
	this->lanternSize = lanternSize;
	this->lanternType = lanternType;
	this->fuelType = fuelType;
	//std::cout << "Lantern created" << std::endl;
}




// getters

// getters for basic info
std::string Equipment::getItemCode() {
	//std::cout << "item code got" << ", ";                                        	// used for debug, will be deleted
	return itemCode;
}
std::string Equipment::getItemName() {
	//std::cout << "item name got" << ", ";                                        	// used for debug, will be deleted
	return itemName;
}
std::string Equipment::getBrand() {
	//std::cout << "brand got" << ", ";                                            	// used for debug, will be deleted
	return brand;
}
std::string Equipment::getEquipmentType() {
	//std::cout << "type got" << ", ";                                            	// used for debug, will be deleted
	return equipmentType;
}
std::string Equipment::getDateOfPurchase() {
	//std::cout << "date of purchase got" << ", ";                                	// used for debug, will be deleted
	return dateOfPurchase;
}
std::string Equipment::getCondition() {
	//std::cout << "condition got" << ", ";                                        	// used for debug, will be deleted
	return condition;
}
std::string Equipment::getStatus() {
	//std::cout << "status got" << ", ";                                           	// used for debug, will be deleted
	return status;
}

// getters for tent
int tent::getNumOfPeopleUse() {
	//std::cout << "numofppl got" << ", ";                                        	// used for debug, will be deleted
	return numOfPeopleUse;
}
std::string tent::getTentType() {
	//std::cout << "tent type got" << ", ";                                        	// used for debug, will be deleted
	return tentType;
}
int tent::getNumOfDoors() {
	//std::cout << "numofdoor got" << ", ";                                        	// used for debug, will be deleted
	return numOfDoors;
}
bool tent::getDoubleLayer() {
	//std::cout << "double layer got" << ", ";                                    	// used for debug, will be deleted
	return doubleLayer;
}
std::string tent::getColor() {
	//std::cout << "color got" << ", ";                                            	// used for debug, will be deleted
	return color;
}

// getters for stove
std::string stove::getStoveType() {
	//std::cout << "stove type got" << ", ";                                        	// used for debug, will be deleted
	return stoveType;
}
std::string stove::getFuelType() {
	//std::cout << "fuel type got" << ", ";                                        	// used for debug, will be deleted
	return fuelType;
}

// getters for lantern
std::string lantern::getLanternSize() {
	//std::cout << "lantern size got" << ", ";                                    	// used for debug, will be deleted
	return lanternSize;
}
std::string lantern::getLanternType() {
	//std::cout << "lantern type got" << ", ";                                    	// used for debug, will be deleted
	return lanternType;
}
std::string lantern::getFuelType() {
	//std::cout << "fuel type got" << ", ";                                        	// used for debug, will be deleted
	return fuelType;
}

// base getters
std::string Equipment::getEquipmentInfo() {
	return "eq info";
}

std::string tent::getEquipmentInfo()
{
	std::stringstream ss;
	ss /*<< std::endl*/ << getItemCode() << "|" << getItemName() << "|" << getBrand() << "|" << getEquipmentType() << "|" << getDateOfPurchase() << "|" << getCondition() << "|" << getStatus() << "|" << getNumOfPeopleUse() << "|" << getTentType() << "|" << getNumOfDoors() << "|" << getDoubleLayer() << "|" << getColor();
	std::string info = ss.str();
	return info;
}

std::string stove::getEquipmentInfo()
{
	std::stringstream ss;
	ss /*<< std::endl*/ << getItemCode() << "|" << getItemName() << "|" << getBrand() << "|" << getEquipmentType() << "|" << getDateOfPurchase() << "|" << getCondition() << "|" << getStatus() << "|" << getStoveType() << "|" << getFuelType();
	std::string info = ss.str();
	return info;
}

std::string lantern::getEquipmentInfo()
{
	std::stringstream ss;
	ss /*<< std::endl*/ << getItemCode() << "|" << getItemName() << "|" << getBrand() << "|" << getEquipmentType() << "|" << getDateOfPurchase() << "|" << getCondition() << "|" << getStatus() << "|" << getLanternSize() << "|" << getLanternType() << "|" << getFuelType();
	std::string info = ss.str();
	return info;
}

//setter
void Equipment::setStatus(std::string newState) {
	status = newState;
}


// Functions
void Equipment::setCondition(std::string newCondition) {
	condition = newCondition;
}


bool Equipment::sortByName(const std::shared_ptr<Equipment>& d1, const std::shared_ptr<Equipment>& d2) {
	return d1->getItemCode() < d2->getItemCode();
}

// ~ Destructors ~

// Base class Equipment destructor
Equipment::~Equipment()
{

}


// Tents destructor
tent::~tent()
{

}


// Stoves destructor
stove::~stove()
{

}


// Lanterns destructor
lantern::~lantern()
{

}
