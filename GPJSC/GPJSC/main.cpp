
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <memory>																						// For shared_ptr
#include <ctime>
#include <vector>
#include "User.h"
#include "Driver.h"
#include "Staff.h"
#include "CarPark.h"


string toStringACB(int id);																				//function declaration
string doubleToStr(double f);
string left(const string s, const int w);
string center(const string s, const int w);
void printElement(string t, const int& width);
void printElement(string t, const int& width, int x);
int getLastDay();
int getToday();

int login();
void availableList(int cpID, string type, int date, vector<int>& num);
void bookSlot(int userID);
void addACBalance(int userID);

void addCarPark();
void showCarPark();
void editCarPark();
void deldeteCarPark();

void createUser();
void printUser(int id);
void printUser();
void editUser();
void deleteUser();

void printSlot(CarPark &cp, int date);
void printSlot(CarPark &cp, int slotID, int date);
void checkSlot();
void addSlot(int type, int number, int cpID);

void checkCPBalance();

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);														// Changes colour of text
void greentext() { SetConsoleTextAttribute(hConsole, 2); };
void whitetext() { SetConsoleTextAttribute(hConsole, 15); };
void redtext() { SetConsoleTextAttribute(hConsole, 252); };
void bluetext() { SetConsoleTextAttribute(hConsole, 11); };
void yellowtext() { SetConsoleTextAttribute(hConsole, 14); };
void darktext() { SetConsoleTextAttribute(hConsole, 8); };

deque<CarPark> theCarPark;																				//declare gobal variable
deque<shared_ptr<User>> theUser;
int loginUser;

int main() {
	int role = -1, choose = 0;																			//declar varoable
	bool loop = true;																					//loop control

	theUser.push_back(make_shared<Staff>("ken", "Ken Lee"));											//default staff
	theUser.push_back(make_shared<Driver>("aaron", "Aaron Chan", 0, "AC1234"));							//default driver
	theUser.push_back(make_shared<Driver>("ben", "Ben Wong", 2, "BW88"));								//default driver
	theUser.push_back(make_shared<Driver>("carman", "Carman Lam", 1, "CL660"));							//default driver
	theCarPark.push_back(CarPark(1, "Happy Parking", "Happy Valley", 6, 30, 20, 25, 38, 28));			//default car park
	theCarPark.push_back(CarPark(2, "Wealthy Parking", "Mong Kok", 1, 5, 3, 30, 36, 32));				//default car park
	theCarPark.push_back(CarPark(3, "Come Parking", "Kwoloon Tong", 8, 20, 10, 15, 22, 20));			//default car park
	theUser[1]->setAccountBalance(1580);
	theUser[2]->setAccountBalance(805.5);
	theUser[3]->setAccountBalance(50);


	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);																			//stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1100, 500, TRUE);												// 1100 width, 500 height
	do {
		loop = true;
		system("cls");
		role = login();																					//login and get the user role

		whitetext();
		if (role == 1)																					//check if 	user is Driver or not
		{
			do
			{
				system("cls");																			//clean the Console
				cout << endl << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "Driver Function: " << endl << endl;			//print Driver Function
				cout << setw(126 / 2 - 27 / 2) << " " << "(1) Reserve a parking slot" << endl << endl;
				cout << setw(126 / 2 - 27 / 2) << " " << "(2) Check account balance" << endl << endl;
				cout << setw(126 / 2 - 27 / 2) << " " << "(3) Increase account balance" << endl << endl;
				cout << setw(126 / 2 - 27 / 2) << " " << "(4) Logout" << endl << endl << endl;
				cout << setw(126 / 2 - 27 / 2) << " " << "Please choose an option:";
				cin >> choose;																			//ask user to input the choose

				switch (choose)																			//match the function with the choose
				{
				case 1:
					bookSlot(loginUser);																//call the function to book parking slot
					break;
				case 2:
					system("cls");
					cout << endl << endl << endl;
					cout << setw(126 / 2 - 25 / 2) << " " << "Your account balance is " << endl;			//print the user account balance
					greentext();
					cout << setw(126 / 2 - 25 / 2) << " " << "HKD$ " << toStringACB(loginUser) << endl;
					whitetext();
					cout << setw(126 / 2 - 25 / 2) << " ";
					system("pause");
					break;
				case 3:
					addACBalance(loginUser);															//call function to add the user account balance 
					break;
				case 4:
					loop = false;																		//logout to the login page
					break;
				default:
					cout << setw(126 / 2 - 27 / 2) << " ";
					cout << "Please enter a correct menu choice\n\n\t";									//ask user to re enter the choice
					system("pause");
					break;
				}
			} while (loop);
		}
		else if (role == 0)																				//check if user is Staff or not
		{
			do {
				system("cls");
				cout << endl << endl;																	//print staff function
				cout << setw(126 / 2 - 18 / 2) << " " << "Staff functions: " << endl << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(1)  Create a new car park" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(2)  Show car park information" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(3)  Edit car park information" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(4)  Remove a car park" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(5)  Create a new user account" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(6)  Edit user account information" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(7)  Remove a user account" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(8)  Check car parking slot status" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(9)  Check car park balance" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "(10) Logout" << endl;
				cout << setw(126 / 2 - 18 / 2) << " " << "Please choose an option:";					//ask staff to enter the choose
				cin >> choose;
				switch (choose)																			//match the function with choose
				{
				case 1:
					addCarPark();																		//call function to add car park
					break;
				case 2:
					showCarPark();																		//call function to show car park detail
					system("pause");
					break;
				case 3:
					editCarPark();																		//call function to edit Car Park
					break;
				case 4:
					deldeteCarPark();																	//call function to delete car park				
					break;
				case 5:
					createUser();																		//call function to create user
					break;
				case 6:
					editUser();
					break;
				case 7:
					deleteUser();
					break;
				case 8:
					checkSlot();
					break;
				case 9:
					checkCPBalance();
					break;
				case 10:
					loop = false;
					break;
				default:
					cout << "\n\tPlease enter a correct menu choice\n\n\t";
					system("pause");
					break;
				}
			} while (loop);

		}
	} while (true);
	return 0;
}

int login() {
	string loginN;																						//declare variable
	int role = 0;

	do {
		if (role == -1) {																				//check the user name vild or not
			system("cls");
			cout << endl;
			cout << setw(126 / 2 - 18 / 2) << " ";
			redtext();
			cout << "Wrong User Name!\n" << endl;
		}
		role = -1;
		whitetext();
		cout << endl << endl << endl;
		cout << setw(126 / 2 - 11) << " " << "=====================" << endl;								//show the login window
		cout << setw(126 / 2 - 11) << " " << "+-------------------+" << endl;
		cout << setw(126 / 2 - 11) << " " << "|**Car Park System**|" << endl;
		cout << setw(126 / 2 - 11) << " " << "|       Login       |" << endl;
		cout << setw(126 / 2 - 11) << " " << "+-------------------+" << endl;
		cout << setw(126 / 2 - 11) << " " << "=====================" << endl;
		cout << setw(126 / 2 - 11) << " " << "User Name: ";												//ask the user input user name
		cin >> loginN;
		for (unsigned int i = 0; i < theUser.size(); i++) {												//check the user name match or not
			if (loginN == theUser[i]->getUsername())
			{
				loginUser = i;
				if (theUser[i]->getRole() == "Driver") {													//check the role of user
					role = 1;
					greentext();
					cout << setw(126 / 2 - 11) << " " << "User Name Correct!\n" << endl;
					cout << setw(126 / 2 - 11) << " ";

				}
				if (theUser[i]->getRole() == "Staff")													//check the role of user
				{
					role = 0;
					greentext();
					cout << setw(126 / 2 - 11) << " " << "User Name Correct!\n" << endl;
					cout << setw(126 / 2 - 11) << " ";
				}
				system("pause");
			}
		};

	} while (role == -1);
	return role;
}

void availableList(int cpID, string type, int date, vector<int>& num) {
	const string time[] = { "00:00", "01:00", "02:00", "03:00","04:00","05:00","06:00","07:00","08:00","09:00",		//declare varable
		"10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00","21:00","22:00","23:00","00:00" };
	int count = 0;

	system("cls");
	bluetext();																										//print the available list
	cout << setw(126 / 2 - 42 / 2) << " " << type << " Slot available list at date " << date << endl;
	whitetext();
	cout << setw(126 / 2 - 70 / 2) << " " << string(70, '_') << endl << endl;
	cout << setw(126 / 2 - 70 / 2) << " " << string(70, '-') << endl;
	cout << setw(126 / 2 - 70 / 2) << " " << "|" << center("Car Park Name: " + theCarPark[cpID].getName(), 68) << "|" << endl;
	cout << setw(126 / 2 - 70 / 2) << " " << string(70, '-') << endl;
	cout << setw(126 / 2 - 70 / 2) << " " << "|" << center("Time: ", 28) << "|";
	cout << center("available " + type + " list", 39) << "|" << endl;
	cout << setw(126 / 2 - 70 / 2) << " " << string(70, '-') << endl;
	for (int i = 0; i < 24; i++)
	{
		cout << setw(126 / 2 - 70 / 2) << " ";
		cout << "|" << center(time[i] + " - " + time[i + 1], 28) << "|";

		for (unsigned int x = 0; x < theCarPark[cpID].cpSlot_List.size(); x++)
		{
			if (theCarPark[cpID].cpSlot_List[x].getVehicleType() == type) {
				if (theCarPark[cpID].cpSlot_List[x].status[date][i] == 0)
				{
					count++;
				}
			}
		}
		cout << center(to_string(count), 39) << "|" << endl;
		num.push_back(count);
		count = 0;
	}
	cout << setw(126 / 2 - 70 / 2) << " ";
	cout << string(70, '-') << endl << endl;
}

void bookSlot(int userID) {
	bool isEqual = false, canBook = true, wrongDay = false;																//declare variable
	int cpID = 0, date = 0, slot = -1, choose = -1, num = 0;
	vector<int> availableNum;																							//user vector to store the available number

	system("cls");
	showCarPark();																										//show the car park information
	cout << "Please select a car park by car part id: ";																//ask user to input car park id
	cin >> cpID;

	for (unsigned int i = 0; i<theCarPark.size(); i++) {																//check if the car park id match or not
		if (theCarPark[i].getID() == cpID) {																			// set isEqual to true if they are equal
			num = i;
			isEqual = true;
		}
	}
	if (!isEqual) {																										//print id not found if user input wrong id
		cout << "ID not found!" << endl;
		system("pause");
	}
	else
	{
		do {
			cout << "Please select the date in this month you want to book: ";											//ask user to enter the date of booking

			cin >> date;

			if (getToday() > date || getLastDay() < date) {																//check if the driver enter the correct date
				cout << "Fail !! You can only book form today till the end of the current month.";
				cout << endl;
				wrongDay = true;
			}
			else
			{
				wrongDay = false;
			}
		} while (wrongDay);


		availableList(num, theUser[userID]->getVehicleType(), date, availableNum);										//print available slot table

		cout << "(0) 00:00 - 01:00		(6)  06:00 - 07:00		(12) 12:00 - 13:00		(18) 18:00 - 19:00" << endl;
		cout << "(1) 01:00 - 02:00		(7)  07:00 - 08:00		(13) 13:00 - 14:00		(19) 19:00 - 20:00" << endl;
		cout << "(2) 02:00 - 03:00		(8)  08:00 - 09:00		(14) 14:00 - 15:00		(20) 20:00 - 21:00" << endl;
		cout << "(3) 03:00 - 04:00		(9)  09:00 - 10:00		(15) 15:00 - 16:00		(21) 21:00 - 22:00" << endl;
		cout << "(4) 04:00 - 05:00		(10) 10:00 - 11:00		(16) 16:00 - 17:00		(22) 22:00 - 23:00" << endl;
		cout << "(5) 05:00 - 06:00		(11) 11:00 - 12:00		(17) 17:00 - 18:00		(23) 23:00 - 00:00" << endl;
		cout << "Please input the number of the time slot: ";															// ask user to choose the time slot;
		cin >> choose;

		cout << endl;
		if (availableNum[choose] == 0) {																				//check the slot available or not
			cout << "Fail !! Please check the slot status again. There is no slot provide in this time slot." << endl;
			canBook = false;
		}
		for (size_t i = 0; i < theCarPark[num].cpSlot_List.size(); i++)													//check driver book te same time slot or not in this car park
		{
			if (theCarPark[num].cpSlot_List[i].bookedList[date][choose] == userID)
			{
				cout << "Fail !! Each driver can only reserve one parking slot for each time slot." << endl;
				canBook = false;
			}
		}
		if ((theUser[userID]->getAccountBalance() < theCarPark[num].getFeeByType(theUser[userID]->getVNum()))) {		//check the driver account blance enough or not
			cout << "Fail !! Your balance is not enough to paid." << endl;
			canBook = false;
		}

		if (canBook) {																									//check valid book
			theUser[userID]->addAccountBalance(theCarPark[num].getFeeByType(theUser[userID]->getVNum())*-1.0);			//deduce the fee from driver account balance

			for (size_t i = 0; i < theCarPark[num].cpSlot_List.size(); i++)												//search and book the free slot 
			{

				if (theCarPark[num].cpSlot_List[i].status[date][choose] == 0 && theCarPark[num].cpSlot_List[i].getVehicleType() == theUser[userID]->getVehicleType()) {
					slot = i;
					i = theCarPark[num].cpSlot_List.size();
					cout << "Booking Success!" << endl;
				}
			}

			theCarPark[num].cpSlot_List[slot].status[date][choose] = 1;													//change the slot stus at that time to Occupied 
			theCarPark[num].cpSlot_List[slot].bookedList[date][choose] = userID;										//record user id to the booked list
			theCarPark[num].addBalance(theCarPark[num].getFeeByType(theUser[userID]->getVNum()));						//inrease the car park balance
		}
	}
	system("pause");
}

void addACBalance(int userID) {																							//function to add user acount balance
	double money;																										//declare variable

	system("cls");																										//clean the console

	if (toStringACB(userID) != "/")																						//check the user is Driver
	{
		cout << endl << endl;
		cout << setw(126 / 2 - 63 / 2) << " " << "Please input the amount you want to increase to your balance: ";		//ask driver enter the value
		cin >> money;
		theUser[userID]->addAccountBalance(money);																		//call addbalance function from the class user
		cout << setw(126 / 2 - 63 / 2) << " " << "sucess!" << endl;
		cout << setw(126 / 2 - 63 / 2) << " ";
		system("pause");
	}
}

void addCarPark() {
	string name, location;																								//declare variable
	int id, motorCycleSlot, privateCarSlot, lightGoodsVehicleSlot;
	double motorCycleFee, privateCarFee, lightGoodsVehicleFee;

	system("cls");
	cout << "Please input the car park ID: ";																				//ask user to input car park id
	cin >> id;
	cin.ignore();
	cout << "Please input the car park name: ";																			//ask user to input car park name
	getline(cin, name);
	cout << "Please input the car park location: ";																		//ask user to input car park location
	getline(cin, location);
	cout << "Please input the motor cycle slot of car park : ";															//ask user to input the motor cycle slot of car park
	cin >> motorCycleSlot;
	cout << "Please input the private car slot of car park : ";															//ask staff to input car park detail
	cin >> privateCarSlot;
	cout << "Please input the light goods vehicle slot of car park : ";													//ask staff to input car park detail
	cin >> lightGoodsVehicleSlot;
	cout << "Please input the motor cycle slot fee of car park : ";														//ask staff to input car park detail
	cin >> motorCycleFee;
	cout << "Please input the private car slot fee of car park : ";														//ask staff to input car park detail
	cin >> privateCarFee;
	cout << "Please input the light goods vehicle slot fee of car park : ";												//ask staff to input car park detail
	cin >> lightGoodsVehicleFee;

	CarPark newCp(id, name, location, motorCycleSlot, privateCarSlot, lightGoodsVehicleSlot, motorCycleFee, privateCarFee, lightGoodsVehicleFee);
	theCarPark.push_back(newCp);																						//creat Car Park and push it into the deque
	cout << endl;
	cout << "Success" << endl;
	system("pause");
}

void editCarPark() {
	bool isID = false, loop = true;																		//declare variable
	int cpID = 0, id, choose = 0;
	string var;

	system("cls");

	showCarPark();
	cout << "Please enter the id of the car park you want to edit: ";										//ask user to enter the car park id
	cin >> id;
	for (unsigned int i = 0; i<theCarPark.size(); i++) {												//check carpark id vaid or not
		if (id == theCarPark[i].getID()) {
			cpID = i;
			isID = true;
		}
	}
	if (isID) {																							//show the edit menue if the car park id correct
		do {
			system("cls");
			cout << setw(126 / 2 - 19 / 2) << " ";
			cout << "Edit Car Park menu" << endl;
			cout << setw(126 / 2 - 100 / 2) << " ";
			cout << string(100, '_');
			cout << endl << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(1) Edit ID" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(2) Edit Name" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(3) Edit Location" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(4) Add Motor cycles slots" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(5) Add Private cars slots" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(6) Add Light goods vehicles slots" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(7) Edit Motor cycles parking fees" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(8) Edit Private cars parking fees" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(9) Edit Light goods vehicles parking fees" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(10) Delete specific slot" << endl;
			cout << setw(126 / 2 - 35 / 2) << " " << "(11) Exit" << endl << endl;

			cout << setw(126 / 2 - 35 / 2) << " ";
			cout << "Please enter the number of the function(1-11): ";									//ask user to choose
			cin >> choose;
			switch (choose) {																			//match the choose
			case 1:
				system("cls");
				cout << "Please enter the new car park id: ";											//ask user to enter new car park id	and set 
				cin >> var;
				theCarPark[cpID].setID(stoi(var));
				cout << "Success" << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "Please enter the new name: ";													//ask user to enter new nameand set 
				cin.ignore();
				getline(cin, var);
				theCarPark[cpID].setName(var);
				cout << "Success" << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "Please enter the new Location: ";												//ask user to enter new Location id	and set 
				cin.ignore();
				getline(cin, var);
				theCarPark[cpID].setLocation(var);
				cout << "Success" << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "Please enter the number of Motor cycles slots you want to add: ";				//ask user to enter new Motor cycles slots number and set
				cin >> var;
				theCarPark[cpID].addSlot(0, stoi(var));
				theCarPark[cpID].setMotorCycleSlot(theCarPark[cpID].getMotorCycleSlot() + stoi(var));
				cout << "Success" << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "Please enter the number of Private cars slots you want to add: ";
				cin >> var;
				theCarPark[cpID].addSlot(1, stoi(var));
				theCarPark[cpID].setPrivateCarSlot(theCarPark[cpID].getPrivateCarSlot() + stoi(var));	//ask user to enter new Private cars slots number and set
				cout << "Success" << endl;
				system("pause");
				break;
			case 6:
				system("cls");
				cout << "Please enter the number of Light goods vehicles slots you want to add: ";		//ask user to enter new Light goods vehicles slots number and set
				cin >> var;
				theCarPark[cpID].addSlot(2, stoi(var));
				theCarPark[cpID].setLightGoodsVehicleSlot(theCarPark[cpID].getLightGoodsVehicleSlot() + stoi(var));
				cout << "Success" << endl;
				system("pause");
				break;
			case 7:
				system("cls");
				cout << "Please enter the new Motor cycles parking fees: ";								//ask user to input new fee
				cin >> var;
				theCarPark[cpID].setMotorCycleFee(stod(var));
				cout << "Success" << endl;
				system("pause");
				break;
			case 8:
				system("cls");
				cout << "Please enter the new Private cars parking fees: ";								//ask user to input new fee
				cin >> var;
				theCarPark[cpID].setPrivateCarFee(stod(var));
				cout << "Success" << endl;
				system("pause");
				break;
			case 9:
				system("cls");
				cout << "Please enter the new Light goods vehicles parking fees: ";						//ask user to input new fee
				cin >> var;
				theCarPark[cpID].setLightGoodsVehicleFee(stod(var));
				cout << "Success" << endl;
				system("pause");
				break;
			case 10:
				system("cls");
				cout << setw(60 / 2 - 18 / 2) << " ";
				cout << "Car Park: " << theCarPark[cpID].getName();
				cout << string(60, '_');
				for (unsigned int i = 0; i < theCarPark[cpID].cpSlot_List.size(); i++) {				//show the all the slot and their type of this car park
					cout << string(60, '-') << endl;
					cout << "|" << center("Slot ID: ", 28) << "|";										//reight side table
					cout << center("Vehicle type: ", 29) << "|" << endl;								//left side table

					cout << "|" << center(to_string(i), 28) << "|";
					cout << center(theCarPark[cpID].cpSlot_List[i].getVehicleType(), 29) << "|" << endl;
				}
				cout << string(60, '-') << endl;

				cout << endl << "Please enter the slot ID that you want to delete: ";					//ask user to tnter the slot id he want to delete
				cin >> var;
				if (theCarPark[cpID].cpSlot_List[stoi(var)].getVehicleType() == "Motor cycles") {		//mathe the type of slot and delete
					theCarPark[cpID].setMotorCycleSlot(theCarPark[cpID].getMotorCycleSlot() - 1);
					cout << "Success" << endl;
				}
				else if (theCarPark[cpID].cpSlot_List[stoi(var)].getVehicleType() == "Private cars") {
					theCarPark[cpID].setPrivateCarSlot(theCarPark[cpID].getPrivateCarSlot() - 1);
					cout << "Success" << endl;
				}
				else if (theCarPark[cpID].cpSlot_List[stoi(var)].getVehicleType() == "Light goods vehicles") {
					theCarPark[cpID].setLightGoodsVehicleSlot(theCarPark[cpID].getLightGoodsVehicleSlot() - 1);
					cout << "Success" << endl;
				}
				theCarPark[cpID].cpSlot_List.erase(theCarPark[cpID].cpSlot_List.begin() + stoi(var));
				system("pause");
				break;
			case 11:																					//end the menu
				loop = false;
				break;
			default:
				cout << "\n\tPlease enter a correct choice\n\n\t";										//check user input
				system("pause");
				break;
			}
		} while (loop);
	}
}

void addSlot(int type, int number, int cpID) {
	switch (type) {																									//add the slot by the input type and number
	case 0:
		for (int i = 0; i<number; i++) {
			theCarPark[cpID].cpSlot_List.push_back(CarParkSlot(0));
		}
		break;
	case 1:
		for (int i = 0; i<number; i++) {
			theCarPark[cpID].cpSlot_List.push_back(CarParkSlot(1));
		}
		break;

	case 2:
		for (int i = 0; i<number; i++) {
			theCarPark[cpID].cpSlot_List.push_back(CarParkSlot(2));
		}
		break;

	default:
		break;
	}
}

void showCarPark() {
	const int nameWidth = 18;																		//declare wide variable
	const int numWidth = 5;
	const int veryWidth = 30;

	system("cls");
	bluetext();
	cout << setw(126 / 2 - 16 / 2) << " " << "Car Park Detail" << endl;									//print all car park information
	whitetext();
	cout << string(117, '_') << endl;
	cout << " " << string(117, '-') << "\n";
	printElement("ID", numWidth, 0);																		//type of the colume
	printElement("Name", nameWidth);
	printElement("Location", nameWidth);
	printElement("Total number of slots", veryWidth);
	printElement("Parking fees", veryWidth);
	cout << endl;
	cout << " " << string(117, '-') << "\n";

	for (unsigned int i = 0; i<theCarPark.size(); i++) {														//print colume data
		printElement(to_string(theCarPark[i].getID()), numWidth, 0);
		printElement(theCarPark[i].getName(), nameWidth);
		printElement(theCarPark[i].getLocation(), nameWidth);
		printElement("Motor cycles: " + to_string(theCarPark[i].getMotorCycleSlot()), veryWidth);
		printElement("Motor cycles: " + doubleToStr(theCarPark[i].getMotorCycleFee()), veryWidth);
		cout << endl;
		printElement("", numWidth, 0);
		printElement("", nameWidth);
		printElement("", nameWidth);
		printElement("Private cars: " + to_string(theCarPark[i].getPrivateCarSlot()), veryWidth);
		printElement("Private cars: " + doubleToStr(theCarPark[i].getPrivateCarFee()), veryWidth);
		cout << endl;
		printElement("", numWidth, 0);
		printElement("", nameWidth);
		printElement("", nameWidth);
		printElement("Light goods vehicles: " + to_string(theCarPark[i].getLightGoodsVehicleSlot()), veryWidth);
		printElement("Light goods vehicles: " + doubleToStr(theCarPark[i].getLightGoodsVehicleFee()), veryWidth);
		cout << endl;
		cout << " " << string(117, '-') << "\n";
	}
}

void deldeteCarPark() {
	bool isEqual = false;																				//declare variable
	int cpID, num = 0;

	system("cls");
	showCarPark();
	cout << "Please enter the id of the car park you want to delete: ";									//ask user input the id of the car park to delete
	cin >> cpID;

	for (unsigned int i = 0; i<theCarPark.size(); i++) {														//check id valid or not
		if (theCarPark[i].getID() == cpID) {
			num = i;
			isEqual = true;
		}
	}
	if (isEqual) {
		theCarPark.erase(theCarPark.begin() + num);
		cout << "Success";
	}
	else {																								//print error
		cout << "ID not correct!";
	}
	system("pause");
}

void createUser() {
	int type, vehicleType;																				//declare variable
	string username, name, plateNumber;
	system("cls");
	cout << "(1) Staff                        (2) Driver                   " << endl;						//ask staff to choose the type of user to create
	cout << "Please select account type:";
	cin >> type;

	if (type == 1) {																						//create staff account
		cout << "Please enter the username: ";															//ask staff to enter the username
		cin >> username;
		cin.ignore();
		cout << "Please enter the name: ";																//ask staff to enter the name of the account
		getline(cin, name);
		auto newStaff = make_shared<Staff>(username, name);												//create staff account
		theUser.push_back(newStaff);
		cout << "Success";
		system("pause");
	}

	if (type == 2) {																						//create Driver account
		cout << "Please enter the username: ";															//ask Driver to enter the username
		cin >> username;
		cin.ignore();
		cout << "Please enter your name: ";																//ask Driver to enter the name
		getline(cin, name);
		cout << "(0)Motor cycles      (1) Private cars        (2)Light goods vehicles\n";					//ask Driver to choose the vehicle type of the account
		cout << "Please enter the number of vehicle type: ";
		cin >> vehicleType;
		cout << "Please enter the plate number: ";														//ask Driver to enter the plate number
		cin >> plateNumber;
		auto newDriver = make_shared<Driver>(username, name, vehicleType, plateNumber);					//create driver account
		theUser.push_back(newDriver);
		cout << "Success";
		system("pause");
	}
}

void printUser(int id) {
	const int nameWidth = 18;																		//declare the variable of width
	const int numWidth = 5;
	const int veryWidth = 20;

	cout << " " << string(125, '-') << "\n";																//print user table
	printElement("ID", numWidth, 0);
	printElement("Role", 6);
	printElement("Username", nameWidth);
	printElement("Name", nameWidth);
	printElement("Vehicle Type", veryWidth);
	printElement("Plate Number", nameWidth);
	printElement("Account Balance", nameWidth);
	cout << endl;
	cout << " " << string(125, '-') << "\n";
	printElement(to_string(id), numWidth, 0);
	printElement(theUser[id]->getRole(), 6);
	printElement(theUser[id]->getUsername(), nameWidth);
	printElement(theUser[id]->getName(), nameWidth);
	printElement(theUser[id]->getVehicleType(), veryWidth);
	printElement(theUser[id]->getPlateNumber(), nameWidth);
	printElement(toStringACB(id), nameWidth);
	cout << endl;
	cout << " " << string(125, '-') << "\n";
}

void printUser() {
	const int nameWidth = 18;																			//declare the variable of width
	const int numWidth = 5;
	const int veryWidth = 20;

	cout << " " << string(125, '-') << "\n";																	//print user table
	printElement("ID", numWidth, 0);
	printElement("Role", 6);
	printElement("Username", nameWidth);
	printElement("Name", nameWidth);
	printElement("Vehicle Type", veryWidth);
	printElement("Plate Number", nameWidth);
	printElement("Account Balance", nameWidth);
	cout << endl;
	cout << " " << string(125, '-') << "\n";
	for (unsigned int id = 0; id<theUser.size(); id++) {
		printElement(to_string(id), numWidth, 0);
		printElement(theUser[id]->getRole(), 6);
		printElement(theUser[id]->getUsername(), nameWidth);
		printElement(theUser[id]->getName(), nameWidth);
		printElement(theUser[id]->getVehicleType(), veryWidth);
		printElement(theUser[id]->getPlateNumber(), nameWidth);
		printElement(toStringACB(id), nameWidth);
		cout << endl;
	}
	cout << " " << string(125, '-') << "\n";
}

void editUser() {
	bool isEqual = false, loop = true;																		//declare variable
	int id = 0, choose, tp;
	string username, unameIn, nm, pnum;
	double balance;

	system("cls");
	printUser();																							//show user list
	cout << "Please enter the the user name to edit: ";														//ask user to enter the user name to edit
	cin >> username;
	for (unsigned int i = 0; i<theUser.size(); i++) {															//check username
		if (theUser[i]->getUsername() == username) {
			id = i;
			isEqual = true;
		}
	}
	do {
		if (!isEqual) {																						//print error if username incorrect
			cout << "user name not found!";
			system("pause");
			loop = false;
		}
		else if (theUser[id]->getRole() == "Driver") {
			cout << "success";
			system("cls");																					//print the menue of edit driver 
			cout << "(1) User Name                        (2) Name                       (3)Vehicle Type     " << endl;
			cout << "(4) Plate Number                     (5) Account Balance" << endl << endl;
			cout << "(Enter 6 to finish the change)" << endl;
			cout << "Please enter the informations of the user you want to edit by number(1-5): ";
			cin >> choose;

			switch (choose) {																				//match choose with function
			case 1:
				system("cls");
				cout << "Please enter the new user name: ";													//ask user input data
				cin >> unameIn;
				theUser[id]->setUsername(unameIn);
				cout << "success";
				system("pause");
				break;
			case 2:
				system("cls");
				cin.ignore();
				cout << "Please enter the new name: ";														//ask user input data												
				getline(cin, nm);
				theUser[id]->setName(nm);
				cout << "success";
				system("pause");
				break;
			case 3:
				system("cls");
				cout << "(0) Motor cycles     (1) Private cars         (2) Light goods vehicles\n";			//ask user input data
				cout << "Please enter the new number of vehicle type: ";
				cin >> tp;
				theUser[id]->setVehicleType(tp);
				cout << "success";
				system("pause");
				break;
			case 4:
				system("cls");
				cout << "Please enter the new Plate Number: ";												//ask user input data
				cin >> pnum;
				theUser[id]->setPlateNumber(pnum);
				cout << "success";
				system("pause");
				break;
			case 5:
				system("cls");
				cout << "Please enter the new account Balance: ";					 						//ask user input data
				cin >> balance;
				theUser[id]->setAccountBalance(balance);
				cout << "success";
				system("pause");
				break;
			case 6:
				loop = false;																				//exit menu
				break;
			}
		}
		else if (theUser[id]->getRole() == "Staff") {														//print staff menu
			cout << "(1) User Name                        (2) Name                     " << endl << endl;
			cout << "(Enter 3 to finish the change)" << endl;
			cout << "Please enter the informations of the user you want to edit by number(1-2): ";			//ask user input funcyion choose
			cin >> choose;

			switch (choose) {																				//match choose
			case 1:
				system("cls");
				cout << "Please enter the new user name: ";													//ask user input data										
				cin >> unameIn;
				theUser[id]->setName(unameIn);
				break;
			case 2:
				system("cls");
				cout << "Please enter the new name: ";														//ask user input data
				cin.ignore();
				getline(cin, nm);
				theUser[id]->setName(nm);
				break;
			case 3:
				loop = false;																				//exit menu
				break;
			}
		}
	} while (loop);
	if (isEqual)
	{
		cout << "Update success!" << endl;
		cout << "New information: " << endl;
		printUser(id);																						//show iser table after update
		system("pause");
	}

}

void deleteUser() {
	int id;																								//declare variable
	system("cls");
	printUser();																							//show user table
	cout << "Please enter the id of the user you want to delete: ";											//ask user input id to delete
	cin >> id;
	theUser.erase(theUser.begin() + id);																		//delete user
	cout << "success";
	system("pause");
}

void checkSlot() {
	bool isEqual = false;																					//declare variable
	int cpID, select, num, slotID, date = 0;
	system("cls");
	showCarPark();																							//show car park list
	cout << "Please enter the id of the car park you want to check: ";										//ask user input car park id to edit
	cin >> cpID;
	for (unsigned int i = 0; i<theCarPark.size(); i++) {															//check car park id valid or not
		if (theCarPark[i].getID() == cpID) {
			num = i;
			isEqual = true;
		}
	}
	if (!isEqual) {																							//print error if not valid
		cout << "ID not correct!";
	}
	else {
		cout << "(1) Show all car park slot           (2) select specific parking slot by slot ID" << endl;		//ask user to choose the action
		cout << "Please enter number of action: ";
		cin >> select;
		cout << "Please enter the date of this month you want to check(1-31): ";							//ask user enter the date of this month
		cin >> date;
		switch (select) {																					//match choose
		case 1:
			printSlot(theCarPark[num], date);															//print all car park slot
			break;

		case 2:
			cout << "Please enter the slot ID of the specific parking slot: ";							//ask user to enter the slot id 
			cin >> slotID;
			printSlot(theCarPark[num], slotID, date);													//print specific slot
			break;
		}
	}
	system("pause");
}

void printSlot(CarPark &cp, int date) {
	const string time[] = { "00:00", "01:00", "02:00", "03:00",												//declare variable
		"04:00","05:00","06:00","07:00","08:00","09:00","10:00",
		"11:00","12:00","13:00","14:00","15:00","16:00","17:00",
		"18:00","19:00","20:00","21:00","22:00","23:00","00:00" };
	string user1 = "", user2 = "";

	cout << string(120, '-') << endl;																		//print all slot status
	cout << "|" << center("Car Park Name: " + cp.getName(), 118) << "|" << endl;
	cout << string(120, '-') << endl;

	for (unsigned int i = 0; i<cp.cpSlot_List.size(); i = i + 2) {
		cout << string(120, '-') << endl;
		cout << "|" << center("Slot ID: ", 28) << "|";
		cout << center("Vehicle type: ", 29) << "|";                //left side table
		cout << "|" << center("Slot ID: ", 28) << "|";
		cout << center("Vehicle type: ", 29) << "|" << endl;          //right side table
		cout << "|" << center(to_string(i), 28) << "|";
		cout << center(cp.cpSlot_List[i].getVehicleType(), 29) << "|";
		cout << "|" << center(to_string(i + 1), 28) << "|";
		cout << center(cp.cpSlot_List[i + 1].getVehicleType(), 29) << "|" << endl;
		cout << string(120, '-') << endl;
		cout << "|" << center("TIME", 28) << "|";
		cout << center("Slot status", 29) << "|";
		cout << "|" << center("TIME", 28) << "|";
		cout << center("Slot status", 29) << "|" << endl;
		cout << string(120, '-') << endl;
		for (int x = 0; x<24; x++) {

			if (cp.cpSlot_List[i].bookedList[date][x] != -1) { user1 = "by " + theUser[cp.cpSlot_List[i].bookedList[date][x]]->getUsername(); };
			if (cp.cpSlot_List[i + 1].bookedList[date][x] != -1) { user2 = "by " + theUser[cp.cpSlot_List[i + 1].bookedList[date][x]]->getUsername(); };

			cout << "|" << center(time[x] + " - " + time[x + 1], 28) << "|";
			cout << center(cp.cpSlot_List[i].getSlotStates(date, x) + user1, 29) << "|";
			cout << "|" << center(time[x] + " - " + time[x + 1], 28) << "|";
			cout << center(cp.cpSlot_List[i + 1].getSlotStates(date, x), 29) + user2 << "|" << endl;

			user1 = "";
			user2 = "";
		}
		cout << string(120, '-') << endl << endl;
	}
}

void printSlot(CarPark &cp, int slotID, int date) {
	const string time[] = { "00:00", "01:00", "02:00", "03:00","04:00","05:00",										//declare variable
		"06:00","07:00","08:00","09:00","10:00","11:00","12:00","13:00","14:00",
		"15:00","16:00","17:00","18:00","19:00","20:00","21:00","22:00","23:00","00:00" };
	string user = "";

	cout << string(60, '-') << endl;																					//start print slot status of specific id
	cout << "|" << center("Car Park Name: " + cp.getName(), 58) << "|" << endl;
	cout << string(60, '-') << endl;


	cout << string(60, '-') << endl;
	cout << "|" << center("Slot ID: ", 28) << "|";
	cout << center("Vehicle type: ", 29) << "|" << endl;

	cout << "|" << center(to_string(slotID), 28) << "|";
	cout << center(cp.cpSlot_List[slotID].getVehicleType(), 29) << "|" << endl;

	cout << string(60, '-') << endl;
	cout << "|" << center("TIME", 28) << "|";
	cout << center("Slot status", 29) << "|" << endl;

	cout << string(60, '-') << endl;
	for (int x = 0; x<24; x++) {
		if (cp.cpSlot_List[slotID].bookedList[date][x] != -1) { user = "by " + theUser[cp.cpSlot_List[slotID].bookedList[date][x]]->getUsername(); };

		cout << "|" << center(time[x] + " - " + time[x + 1], 28) << "|";
		cout << center(cp.cpSlot_List[slotID].getSlotStates(date, x) + user, 29) << "|" << endl;
		user = "";
	}
	cout << string(60, '-') << endl << endl;
}

void checkCPBalance() {
	bool isEqual = false;																							//declare variable
	int cpID, num;
	system("cls");
	showCarPark();
	cout << "Please enter the id of the car park: ";																//ask user input the car park id
	cin >> cpID;
	for (unsigned int i = 0; i<theCarPark.size(); i++) {															//check car park id
		if (theCarPark[i].getID() == cpID) {
			num = i;
			isEqual = true;
		}
	}
	if (!isEqual) {
		cout << "ID not correct!" << endl;
	}
	else																											//print the car park balance
	{
		cout << "The account balance in this car park is HKD$" << theCarPark[num].getBalance() << endl;
	}
	system("pause");
}



int getToday() {
	time_t now;																									//decalre variable
	struct tm nowLocal;

	now = time(NULL);																							//get os time

	localtime_s(&nowLocal, &now);																				//cal the date

	return nowLocal.tm_mday;																					//return date of today
}

int getLastDay() {
	time_t now;																									//decalre variable
	struct tm nowLocal;

	now = time(NULL);																							//get os time

	localtime_s(&nowLocal, &now);

	int month = nowLocal.tm_mon + 1;																			//cal the date
	int year = nowLocal.tm_year + 1900;

	switch (month) {																							//return month of this month
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		return 31;
		break;
	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return 29;
		}
		else {
			return 28;
		}
		break;
	default:
		return 30;
	}
}

string doubleToStr(double f) {

	string str = to_string(f);																					//declare variable
	str.erase(str.find_last_not_of('0') + 1);																	//delete 0

	if (str.back() == '.') {
		str.erase(str.find_last_not_of('0'));
	}
	return str;																									//return string 
}

string left(const string s, const int w) {
	stringstream ss, spaces;
	int padding = w - s.size();																					 // count excess room to pad
	for (int i = 0; i<padding; ++i)
		spaces << " ";
	ss << s << spaces.str();																					  // format with padding
	return ss.str();
}

string center(const string s, const int w) {
	stringstream ss, spaces;
	int padding = w - s.size();																				 // count excess room to pad
	for (int i = 0; i<padding / 2; ++i)
		spaces << " ";
	ss << spaces.str() << s << spaces.str();																// format with padding
	if (padding>0 && padding % 2 != 0)																			 // if odd #, add 1 space
		ss << " ";
	return ss.str();
}

void printElement(string t, const int& width) {
	cout << left(t, width) << " | ";																				//print with special patten
}

void printElement(string t, const int& width, int x) {
	cout << " | " << left(t, width) << " | ";																		//print with special patten
}

string toStringACB(int id) {
	double acb = theUser[id]->getAccountBalance();																//decalare variable
	if (acb == -1)																								// check user role
	{
		return "/";
	}
	else {
		return doubleToStr(acb);																				//return the string if the balance of driver
	}
}