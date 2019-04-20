// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #9

// Description:
// This program has a class WordData that has the following features.
// A WordData object should be able to store a character string and a number of integers representing:
// the number of vowels, the number of consonants, the number of digits and the number of special characters in the character string.
// It also consists of a number of functions to manipulate the data.

#include "WordData.h"

#include<iostream>
#include<string>

WordData::WordData() {
	word = new char[1];
	word[0] = '\0';
	vowels = 0;
	consonants = 0;
	digits = 0;
	specialChars = 0;
}

WordData::~WordData() {
	delete[] word;
	word = NULL;
}

void WordData::setWord(const std::string& inWord) {
	int wordLength = size(inWord);
	word = new char[wordLength + 1];

	for (int i = 0; i < wordLength; i++)
		word[i] = inWord[i];
	word[wordLength] = '\0';

	for (int i = 0; i < wordLength; i++)
		if ((inWord[i] >= 48 && inWord[i] <= 57) || (inWord[i] >= 65 && inWord[i] <= 90) || (inWord[i] >= 97 && inWord[i] <= 122))
			if (inWord[i] >= 48 && inWord[i] <= 57) digits++;
			else if (inWord[i] == 'a' || inWord[i] == 'e' || inWord[i] == 'i' || inWord[i] == 'o' || inWord[i] == 'u' || inWord[i] == 'A' || inWord[i] == 'E' || inWord[i] == 'I' || inWord[i] == 'O' || inWord[i] == 'U') vowels++;
			else consonants++;
		else specialChars++;
}

std::string WordData::getWord() const {
	std::string str(word);
	return str;
}

void WordData::displayData() const {
	std::cout << getWord() << "		" << vowels << "	" << consonants << "	" << digits << "	" << specialChars << std::endl;
}