// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #2b

// Description:
// This program test students' ability to find the remainder of a division

#include <iostream>
#include <ctime>
using namespace std;

int main() {
	//set variables
	int numSet1[5];
	int numSet2[5];
	int userInput[5];
	int inCorr = 0;
	int temp1;
	int temp2;
	srand(time(NULL));
	//generate numbers for the questions
	for (int i = 0; i < 5; i++) {
		bool Dup = true;
		do {
			temp1 = rand() % 90 + 10;
			temp2 = rand() % 9 + 1;
			//generate number again if duplicate
			if ((temp1 == numSet1[0] && temp2 == numSet2[0]) || (temp1 == numSet1[1] && temp2 == numSet2[1]) || (temp1 == numSet1[2] && temp2 == numSet2[2]) || (temp1 == numSet1[3] && temp2 == numSet2[3]) || (temp1 == numSet1[4] && temp2 == numSet2[4])) {
				temp1 = rand() % 90 + 10;
				temp2 = temp2 = rand() % 9 + 1;
			}
			else {
				//put into numSet array if no duplicate
				Dup = false;
				numSet1[i] = temp1;
				numSet2[i] = temp2;
			}
		} while (Dup == true);
	}
	// print out the questions and accept user input as answers
	for (int i = 0; i < 5; i++) {
		cout << "Q" << i + 1 << ". What is the remainder of " << numSet1[i] << " divided by " << numSet2[i] << "? ";
		cin >> userInput[i];
		if (userInput[i] == (numSet1[i] % numSet2[i])) {
			inCorr++;
		}
	}
	//print out the number of incorrect answers
	if (inCorr == 1) {
		cout << "\n" << inCorr << " answer out of 5 is correct." << endl;
	}
	else {
		cout << "\n" << inCorr << " answers out of 5 are correct." << endl;
	}
	//show which questions were answered incorrectly
	for (int i = 0; i < 5; i++) {
		if (userInput[i] != (numSet1[i] % numSet2[i])) {
			cout << "Q" << i + 1 << " was answered incorrectly." << endl;
		}
	}
	system("pause");
	return 0;
}