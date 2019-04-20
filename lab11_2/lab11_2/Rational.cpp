#include <iostream>
#include <sstream>
#include "Rational.h"
using namespace std;

void Rational::initialize(int theNumerator, int theDenominator)
{
	numerator = theNumerator;
	denominator = theDenominator;
	reduce();
}

int Rational::getNumerator() const
{
	return numerator;
}

int Rational::getDenominator() const
{
	return denominator;
}

void Rational::setNumerator(int theNumerator)
{
	numerator = theNumerator;
}

void Rational::setDenominator(int theDenominator)
{
	denominator = theDenominator;
}

Rational* Rational::add(const Rational& right) const
{
	int resultDenominator = denominator * right.denominator;
	int resultNumerator = numerator * right.denominator + right.numerator * denominator;
	Rational* result = new Rational;
	result->initialize(resultNumerator, resultDenominator);
	return result;
}

Rational* Rational::subtract(const Rational& right) const
{
	int resultDenominator = denominator * right.denominator;
	int resultNumerator = numerator * right.denominator - right.numerator * denominator;
	Rational* result = new Rational;
	result->initialize(resultNumerator, resultDenominator);
	return result;
}

Rational* Rational::multiply(const Rational& right) const
{
	int resultNumerator = numerator * right.numerator;
	int resultDenominator = denominator * right.denominator;
	Rational* result = new Rational;
	result->initialize(resultNumerator, resultDenominator);
	return result;
}

Rational* Rational::divide(const Rational& right) const
{
	int resultNumerator = numerator * right.denominator;
	int resultDenominator = denominator * right.numerator;
	Rational* result = new Rational;
	result->initialize(resultNumerator, resultDenominator);
	return result;
}

void Rational::reduce()
{
	int gcd = 0;
	int smaller;
	
	// find the greatest common denominator of the two numbers
	if(numerator < denominator)
		smaller = numerator;
	else
		smaller = denominator;
	
	for(int divisor = smaller; divisor >= 2; divisor--)
	{
		if(numerator % divisor == 0 && denominator % divisor == 0)
		{
			gcd = divisor;
			break;
		}
	}

	if(gcd != 0)
	{
		numerator /= gcd;
		denominator /= gcd;
	}
}

string Rational::getRationalString() const
{
	stringstream s;
	s << numerator << "/" << denominator;
	return s.str();
}

string Rational::getFloatString() const
{
	double value = (double)numerator / denominator;
	stringstream s;
	s << value;
	return s.str();
}
