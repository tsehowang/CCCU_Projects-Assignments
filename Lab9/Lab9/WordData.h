// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #9

#ifndef WORDDATA_H
#define WORDDATA_H

#include <iostream>

class WordData {

private:
	char* word;
	int vowels;
	int consonants;
	int digits;
	int specialChars;
	
public:
	WordData();
	~WordData();
	void setWord(const std::string& inWord);
	std::string getWord() const;
	void displayData() const;
};

#endif // !WORDDATA_H

