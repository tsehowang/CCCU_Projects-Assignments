#include "Admin.h"
#include "LoanControl.h"
#include "FileHandler.h"

#include <iostream>

using namespace std;

void loginSystem() {
	LoanControl Loan;
	FileHandler txt;
	Admin superUser;
	int num;
	bool Logining = true;
	while (Logining) {
		system("cls");
		int admin = 0;
		int normalUser = 0;
		string loginID, password;
		cout << "the User name is: ";	//Enter the user name
		cin >> loginID;
		if (loginID == "-1") {
			Logining = false;
			break;
		}
		cout << "the password is: ";	//Enter the password
		cin >> password;
		for (int i = 0; i < std::size(allUsers); i++) {
			if ((loginID == allUsers[i]->getId()) && (password == allUsers[i]->getDateOfBirth()) || loginID == superUser.getAdminId() && password == superUser.getAdminPassword()) {
				if (loginID == superUser.getAdminId() && password == superUser.getAdminPassword())
					admin = 1;
				else
					normalUser = 1;
				Logining = false;
				break;
			}
			else
			{
				if (i == (std::size(allUsers) - 1)) {
					cout << "Sorry, we can't verify your User ID or password. Please try again." << endl;
					system("pause");
				}
			}
		}
		if (admin == 1) {
			system("cls");
			int num = 0;
			while (num != -1) {
				//cout << "Hello admin" << endl << "Enter -1 to exit: " << endl;
				system("cls");
				cout << "=============================================" << endl;
				cout << "Hello admin, welcome for using the programe" << endl;
				cout << "=============================================" << endl;
				cout << " 1. Import the txt" << endl;
				cout << " 2. Display loan record" << endl;
				cout << " 3. Display list of camp equipment" << endl;
				cout << " 4. Update condition of equipment." << endl;
				cout << " 5. Produce txt record" << endl;
				cout << "-1. fake logout" << endl;
				cout << "=============================================" << endl;

				cout << "Choose:";
				cin >> num;
				switch (num) {
				case 1:
					cout << "import txt" << endl;
					system("pause");
					break;
				case 2:
					txt.displayLoanRecord();
					system("pause");
					break;
				case 3:
					txt.ReadEquipmentInfo();
					system("pause");
					break;
				case 4:
					superUser.UpdateEquipment();
					system("pause");
					break;
				case 5:
					system("loanRecord.txt");
					break;
				case -1:
					Logining = true;
					break;
				default:
					cout << "It is an invalid number, please enter again." << endl;
					system("pause");
					break;
				}
			}
		}
		if (normalUser == 1) {
			int num = 0;
			while (num != -1) {
				system("cls");
				if (txt.currentStatusHas(loginID)) {
					cout << "=============================================" << endl;
					cout << "Hello user, welcome for using the programe" << endl;
					cout << "=============================================" << endl;
					cout << " 1. display list of available equipment" << endl;
					cout << " 2. checking the loan limit" << endl;
					cout << " 3. display your loan record" << endl;
					cout << " 4. return camp equipment" << endl;
					cout << "-1. fake logout" << endl;
					cout << "=============================================" << endl;

					cout << "Choose:";
					cin >> num;
					switch (num) {
					case 1:
						Loan.loan(loginID);
						break;
					case 2:
						Loan.checkLimit(loginID);
						break;
					case 3:
						Loan.displayLoanRecord(loginID);
						break;
					case 4:
						Loan.returnEquipment(loginID);
						break;
					case -1:
						Logining = true;
						break;
					default:
						cout << "It is an invalid number, please enter again." << endl;
						system("pause");
						break;
					}
					if (cin.fail())
					{
						// clear error state
						cin.clear();
						// discard 'bad' character(s)
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}

				}
				else {
					cout << "=============================================" << endl;
					cout << "Hello user, welcome for using the programe" << endl;
					cout << "=============================================" << endl;
					cout << " 1. display list of available equipment" << endl;
					cout << " 2. checking the loan limit" << endl;
					cout << "-1. fake logout" << endl;
					cout << "=============================================" << endl;

					cout << "Choose:";
					cin >> num;
					switch (num) {
					case 1:
						Loan.loan(loginID);
						break;
					case 2:
						Loan.checkLimit(loginID);
						break;
					case -1:
						Logining = true;
						break;
					default:
						cout << "It is an invalid number, please enter again." << endl;
						system("pause");
						break;
					}
					if (cin.fail())
					{
						// clear error state
						cin.clear();
						// discard 'bad' character(s)
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}

			}
		}
	}
}

int main() {

	FileHandler txt;
	txt.ReadUser();
	//txt.ReadUserInfo();
	txt.ReadEquipment();
	txt.CurrentStatusChecking();
	//txt.ReadEquipmentInfo();
	txt.getCurrentStatusInfo();
	txt.WriteEquipment();
	loginSystem();
	cout << "Quiting program" << endl;
	system("Pause");
	return 0;

}
