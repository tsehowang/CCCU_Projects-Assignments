// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #3b1

// Description:
// This program is implemented as the game - Mastermind

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int ans[4];
	int input[4];
	int round = 1;
	bool guess = true;

	//generate ans
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 4; i++) {
		ans[i] = rand() % 6 + 1;
	}

	cout << "Mastermind(For checking : " << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << ")"<< endl;
	cout << "Enter four digits (1-6) separated by a space" << endl;

	//break loop if the inputs are correct
	while (guess) {
		cout << "--------------------------------------------" << endl;
		int temp[4];
		int corrNum = 0;

		//make a copy of ans
		for (int i = 0; i < 4; i++) {
			temp[i] = ans[i];
		}

		cout << "Round " << round << ": " << endl;
		cout << "Enter Guess: ";

		//user input
		for (int i = 0; i < 4; i++) {
			cin >> input[i];
		}

		//use 9 to indicate correct input that match number and position
		for (int i = 0; i < 4; i++) {
			if (input[i] == temp[i]) {
				temp[i] = 9;
				input[i] = 9;
			}
		}
		//use 8 to indicate correct input that match number only
		for (int i = 0; i < 4; i++) {
			//no need checking if the element is 9
			if (temp[i] == 9) {
				input[i] = 8;
			}
			else {
				if (input[i] == temp[0]) {
					temp[0] = 8;
					corrNum++;
				}
				else if (input[i] == temp[1]) {
					temp[1] = 8;
					corrNum++;
					}
				else if (input[i] == temp[2]) {
					temp[2] = 8;
					corrNum++;
					}
				else if (input[i] == temp[3]) {
					temp[3] = 8;
					corrNum++;
				}
			}
		}

		//show how many correct input match both number and position
		for (int i = 0; i < 4; i++) {
			if (temp[i] == 9)
				cout << "O";
		}
		//show how many correct input match number only
		for (int i = 0; i < corrNum; i++) {
			cout << "#";
		}
		//Congrate if all inputs are correct
		if (temp[0] == 9 && temp[1] == 9 && temp[2] == 9 && temp[3] == 9) {
			guess = false;
			cout << endl << "--------------------------------------------" << endl;
			cout << "Congratulations!You win the game in " << round << " steps";
		}

		round++;
		cout << endl;
	}

	system("pause");
	return 0;
}
