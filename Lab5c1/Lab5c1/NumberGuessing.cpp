// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #5c1

// Description:
// This program is implemented as a number guessing game. 
// The task is to crack a code which has been randomly created by the computer.
// To crack the code, player make guesses and the computer responds with clues.

#include <iostream>
#include <ctime>
using namespace std;

// "randNoArr" is a constant pointer to a dynamically created array
// "size" is the size of the dynamic array pointed by randNoArr
void shuffle(int* const randNoArr, int size)
{
	for (int i = 0; i < (size - 1); i++)
	{
		int r = i + (rand() % (size - i));
		int temp = randNoArr[i];
		randNoArr[i] = randNoArr[r];
		randNoArr[r] = temp;
	}
}

void printTitle(int n, int round)
{
	cout << "Number Guessing" << endl << "Enter " << n << " digits (1-" << n << ") separated by a space" << endl << "-----------------------------------------------------------" << endl;
	cout << "Round " << round;
	cout << endl << "Enter guess:    ";
}

// accept a input from user
// return true if "guess" matches corresponding number, false if not match
bool guess(int* randNoArr, int size, int i) {
	int guess;
	cin >> guess;
	if (randNoArr[i] == guess)
		return true;
	return false;
}

int main() {
	int n = 0;
	int round = 0;
	bool guessing = true;
	int count;
	srand(time(NULL));

	cout << "Enter total number: ";
	cin >> n;

	int *ryan = new int[n];
	// initailize "ryan" array
	for (int i = 0; i < n; i++) {
		ryan[i] = i + 1;
	}
	// shuffle "ryan" array
	shuffle(ryan, n);

	// break the loop if all correct
	while(guessing) {
		round++;
		count = 0;
		// print the title
		printTitle(n, round);
		// print "O" if correct, "X" if incorrect
		for (int i = 0; i < n; i++) {
			if (guess(ryan, n, i) == true) {
				count++;
				if (i == 0)
					cout << "                ";
				cout << "O ";
			}
			else {
				if (i == 0)
					cout << "                ";
				cout << "X ";
			}
		}
		// if "count" equals "n", "guessing" turns to false
		if (count == n) {
			guessing = false;
		}
		cout << endl << "-----------------------------------------------------------" << endl;
	}
	cout << "Congratulations! You win in " << round << " steps" << endl;
	delete[] ryan;
	system("pause");
	return 0;
}
