#include "Rational.h"
using namespace std;
namespace CS2124 {
	bool operator!=(const Rational& lhs, const Rational& rhs) {
		return !(lhs == rhs);
	}
	Rational& operator--(Rational& ratio) {
		ratio += -1;
		return ratio;
	}
	Rational operator--(Rational& ratio, int) {
		Rational temp = ratio;
		ratio += -1;
		return temp;
	}
	bool operator>(const Rational& lhs, const Rational& rhs) {
		return !(lhs < rhs);
	}
	bool operator<=(const Rational& lhs, const Rational& rhs) {
		return (lhs < rhs) || (lhs == rhs);
	}
	bool operator>=(const Rational& lhs, const Rational& rhs) {
		return !(lhs < rhs);
	}
	Rational operator+(const Rational& lhs, const Rational& rhs) {
		Rational result;
		result += lhs;
		result += rhs;
		return result;
	}

	istream& operator>>(istream& is, Rational& rhs) {
		char delim;
		is >> rhs.numer >> delim >> rhs.denom;
		return is;
	}
	ostream& operator<<(ostream& os, const Rational& rhs) {
		os << rhs.numer << "/" << rhs.denom;
		return os;
	}
	bool operator==(const Rational& lhs, const Rational& rhs) {
		return lhs.numer == rhs.numer && lhs.denom == rhs.denom;
	}

	bool operator<(const Rational& lhs, const Rational& rhs) {
		return (lhs.numer / (double)lhs.denom) < (rhs.numer / (double)rhs.denom);//casting
	}
	Rational::Rational(int numer, int denom) : numer(numer), denom(denom) { normalize(); }
	Rational& Rational::operator+=(const Rational& rhs) {
		int newLNumer = numer * rhs.denom;
		int newRNumer = rhs.numer * denom;
		numer = newLNumer + newRNumer;
		denom *= rhs.denom;
		normalize();
		return *this;
	}
	Rational& Rational::operator+=(int x) {
		numer += x;
		normalize();
		return *this;
	}

	Rational& Rational::operator++() {
		*this += 1;
		return *this;
	}
	Rational Rational::operator++(int) {
		Rational temp = *this;
		*this += 1;
		return temp;
	}

	Rational::operator bool() const {
		return (numer == 0);
	}
}


	


