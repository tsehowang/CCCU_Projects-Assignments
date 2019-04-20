#include <iostream>
#include <cstdio>
#include <string>
#include "WordData.h"
using namespace std;

int main()
{
	cout << "Word\t\tVowels\tConst.\tDigits\tSpecial" << endl;
	cout << "----\t\t------\t------\t------\t-------" << endl;

	char str[] = "This string has 15 words. It has lots of letters and very few special chars!";
	char* cstr;
	char* nstr;

	// strtok is a string tokenizer, which could be used to
	// break down a string into a number of substrings according
	// to the delimiter specified as the second argument.
	// Note: " " is the delimiter in this program
	cstr = strtok_s(str, " ", &nstr);

	while (cstr != NULL)
	{
		WordData word;
		string myStr(cstr);
		word.setWord(myStr);
		word.displayData();
		cstr = strtok_s(NULL, " ", &nstr);
	}
	system("pause");
	return 0;
}