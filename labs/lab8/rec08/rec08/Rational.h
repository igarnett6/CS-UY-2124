#pragma once
#ifndef GUARD
#include <iostream>
#include <string>


namespace CS2124 {
	class Rational {
		friend std::istream& operator>>(std::istream& is, Rational& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
		friend bool operator==(const Rational& lhs, const Rational& rhs);
		friend bool operator<(const Rational& lhs, const Rational& rhs);
	public:
		Rational(int numer = 1, int denom = 1);
		Rational& operator+=(const Rational& rhs);
		Rational& operator+=(int x);
		Rational& operator++();
		Rational operator++(int);
		explicit operator bool() const;

	private:
		int greatestCommonDivisor(int x, int y) {
			while (y != 0) {
				int temp = x % y;
				x = y;
				y = temp;
			}
			return x;
		}
		void normalize() {
			//cout << "entered normalize" << endl;
			//cout << "numer: " << numer << " denom: " << denom << endl;
			int gcd = greatestCommonDivisor(numer, denom);
			numer /= gcd;
			denom /= gcd;
			if (denom < 0) {
				numer *= -1;
				denom *= -1;
			}


			//cout << "exiting normalize()" << endl;
			//cout << "numer: " << numer << " denom: " << denom << endl;
		}
		int numer;
		int denom;
	};
	bool operator!=(const Rational& lhs, const Rational& rhs);
	Rational& operator--(Rational& ratio);
	Rational operator--(Rational& ratio, int);
	bool operator>(const Rational& lhs, const Rational& rhs);
	bool operator<=(const Rational& lhs, const Rational& rhs);
	bool operator>=(const Rational& lhs, const Rational& rhs);
	Rational operator+(const Rational& lhs, const Rational& rhs);


}
#endif GUARD