// Name: Tse ho wang
// Student ID: 55721980
// Assignment: Lab #11

#include "Rational.h"

#ifndef RATIONAL2_H
#define RATIONAL2_H

class Rational2 :
	public Rational
{
	public:
		Rational2() {};
		Rational2(int n, int d) {
			initialize(n, d);
		};
		Rational2(const Rational2& r) {
			initialize(r.getNumerator(), r.getDenominator());
		};
		void operator = (const Rational2& r) {
			setNumerator(r.getNumerator());
			setDenominator(r.getDenominator());
		};
		Rational2 operator + (const Rational2& r) const {
			Rational2 ra2(this->add(r)->getNumerator(), this->add(r)->getDenominator());
			ra2.reduce();
			return ra2;
		};
		Rational2 operator - (const Rational2& r) const {
			Rational2 ra2(this->subtract(r)->getNumerator(), this->subtract(r)->getDenominator());
			ra2.reduce();
			return ra2;
		};
		Rational2 operator * (const Rational2& r) const {
			Rational2 ra2(this->multiply(r)->getNumerator(), this->multiply(r)->getDenominator());
			ra2.reduce();
			return ra2;
		};
		Rational2 operator / (const Rational2& r) const {
			Rational2 ra2(this->divide(r)->getNumerator(), this->divide(r)->getDenominator());
			ra2.reduce();
			return ra2;
		};
		Rational2 operator - () const {
			return Rational2(0 - this->getNumerator(), this->getDenominator());
		};
		bool operator < (const Rational2& r) const {
			return stof(this->getFloatString()) < stof(r.getFloatString());
		};
		bool operator > (const Rational2& r) const {
			return stof(this->getFloatString()) > stof(r.getFloatString());
		};
		bool operator == (const Rational2& r) const {
			return stof(this->getFloatString()) == stof(r.getFloatString());
		};
		friend std::ostream & operator << (std::ostream& out, const Rational2& r) {
			out << r.getRationalString();
			return out;
		};
		friend std::istream & operator >> (std::istream& in, Rational2& r) {
			string ra2;
			in >> ra2;
			r.setNumerator(stoi(ra2.substr(0, ra2.find("/"))));
			r.setDenominator(stoi(ra2.substr(ra2.find("/") + 1, ra2.length())));
			return in;
		};
};

#endif // !RATIONAL2_H

