#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational
{
	protected:
		int numerator;
		int denominator;
	public:		
		void initialize(int theNumerator, int theDenominator);
		int getNumerator() const;
		int getDenominator() const;
		void setNumerator(int theNumerator);
		void setDenominator(int theDenominator);
		Rational* add(const Rational& right) const;
		Rational* subtract(const Rational& right) const;
		Rational* multiply(const Rational& right) const;
		Rational* divide(const Rational& right) const;
		void reduce();
		string getRationalString() const;
		string getFloatString() const;
};

#endif
