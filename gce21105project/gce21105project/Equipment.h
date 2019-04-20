#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <deque>

// Base class Equipment
class Equipment
{
protected:
	std::string itemCode;
	std::string itemName;
	std::string brand;
	std::string equipmentType;
	std::string dateOfPurchase;
	std::string condition;
	std::string status;

public:
	Equipment(std::string itemCode, std::string itemName, std::string brand, std::string equipmentType, std::string dateOfPurchase, std::string condition, std::string status);
	~Equipment();
	virtual std::string getItemCode();
	virtual std::string getItemName();
	virtual std::string getBrand();
	virtual std::string getEquipmentType();
	virtual std::string getDateOfPurchase();
	virtual std::string getCondition();
	virtual std::string getStatus();
	virtual std::string getEquipmentInfo();
	void setStatus(std::string newState);
	void setCondition(std::string newCondition);
	static bool sortByName(const std::shared_ptr<Equipment>& d1, const std::shared_ptr<Equipment>& d2);
};


// Equipment: tent
class tent :
	public Equipment
{
private:
	int numOfPeopleUse;
	std::string tentType;
	int numOfDoors;
	bool doubleLayer;
	std::string color;

public:
	tent(std::string itemCode, std::string itemName, std::string brand, std::string equipmentType, std::string dateOfPurchase, std::string condition, std::string status, int numOfPeopleUse, std::string tentType, int numOfDoors, bool doubleLayer, std::string color);

	~tent();
	int getNumOfPeopleUse();
	std::string getTentType();
	int getNumOfDoors();
	bool getDoubleLayer();
	std::string getColor();
	std::string getEquipmentInfo();
};


// Equipment: stove
class stove :
	public Equipment
{
private:
	std::string stoveType;
	std::string fuelType;

public:
	stove(std::string itemCode, std::string itemName, std::string brand, std::string equipmentType, std::string dateOfPurchase, std::string condition, std::string status, std::string stoveType, std::string fuelType);
	~stove();
	std::string getStoveType();
	std::string getFuelType();
	std::string getEquipmentInfo();
};


// Equipment: lantern
class lantern :
	public Equipment
{
private:
	std::string lanternSize;
	std::string lanternType;
	std::string fuelType;

public:
	lantern(std::string itemCode, std::string itemName, std::string brand, std::string equipmentType, std::string dateOfPurchase, std::string condition, std::string status, std::string lanternSize, std::string lanternType, std::string fuelType);
	~lantern();
	std::string getLanternSize();
	std::string getLanternType();
	std::string getFuelType();
	std::string getEquipmentInfo();
};

#endif // !EQUIPMENT_H
