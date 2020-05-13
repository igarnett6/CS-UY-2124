///*
//	testRational.cpp
//	CS2124
//	Implement the class Rational, so that the following program works.
// */
//
//#include <iostream>
//
//// If time allows use  separate compilation, otherwise just define the class below
////#include "Rational.h"
//
//using namespace std;
//
//int greatestCommonDivisor(int x, int y) {
//	while (y != 0) {
//		int temp = x % y;
//		x = y;
//		y = temp;
//	}
//	return x;
//}
//
//class Rational {
//	friend istream& operator>>(istream& is, Rational& rhs) {
//		char delim;
//		is >> rhs.numer >> delim >> rhs.denom;
//		return is;
//	}
//	friend ostream& operator<<(ostream& os, const Rational& rhs) {
//		os << rhs.numer << "/" << rhs.denom;
//		return os;
//	}
//	friend bool operator==(const Rational& lhs, const Rational& rhs) {
//		return lhs.numer == rhs.numer && lhs.denom == rhs.denom;
//	}
//
//	friend bool operator<(const Rational& lhs, const Rational& rhs) {
//		return (lhs.numer / (double) lhs.denom) < (rhs.numer / (double)rhs.denom);//casting
//	}
//public:
//	Rational(int numer = 1, int denom = 1) : numer(numer), denom(denom) { normalize(); }
//	Rational& operator+=(const Rational& rhs) {
//		int newLNumer = numer * rhs.denom;
//		int newRNumer = rhs.numer * denom;
//		numer = newLNumer + newRNumer;
//		denom *= rhs.denom;
//		normalize();
//		return *this;
//	}
//	Rational& operator+=(int x) {
//		numer += x;
//		normalize();
//		return *this;
//	}
//
//	Rational& operator++() {
//		*this += 1;
//		return *this;
//	}
//	Rational operator++(int) {
//		Rational temp = *this;
//		*this += 1;
//		return temp;
//	}
//
//	explicit operator bool() const {
//		return (numer == 0);
//	}
//
//private:
//	void normalize() {
//		//cout << "entered normalize" << endl;
//		//cout << "numer: " << numer << " denom: " << denom << endl;
//		int gcd = greatestCommonDivisor(numer, denom);
//		numer /= gcd;
//		denom /= gcd;
//		if (denom < 0) {
//			numer *= -1;
//			denom *= -1;
//		}
//		
//		//cout << "exiting normalize()" << endl;
//		//cout << "numer: " << numer << " denom: " << denom << endl;
//	}
//	int numer;
//	int denom;
//};
//
//
////
////Rational operator+(const Rational& lhs, const Rational& rhs) {
////	Rational result;
////	result += lhs;
////	result += rhs;
////	return result;
////}
////
////bool operator!=(const Rational& lhs, const Rational& rhs) {
////	return !(lhs == rhs);
////}
////
////Rational& operator--(Rational& ratio) {
////	ratio += -1;
////	return ratio;
////}
////Rational operator--(Rational& ratio, int) {
////	Rational temp = ratio;
////	ratio += -1;
////	return temp;
////}
////bool operator>(const Rational& lhs, const Rational& rhs) {
////	return !(lhs < rhs);
////}
////bool operator<=(const Rational& lhs, const Rational& rhs) {
////	return (lhs < rhs) || (lhs == rhs);
////}
////bool operator>=(const Rational& lhs, const Rational& rhs) {
////	return !(lhs < rhs);
////}
////
////
////// If time allows after implementing separate compilation, then wrap the class in a namespace.
//////using namespace CS2124;
////
////int main() {
////    Rational twoThirds(2,3);
////    cout << twoThirds << endl;
////    
////    Rational a, b;
////    cout << "Input a rational number, e.g. 6/9.\n";
////    cout << "a: ";
////    cin >> a;
////    cout << "Input a rational number, e.g. 6/9.\n";
////    cout << "b: ";
////    cin >> b;
////    const Rational one = 1;
////	
////    cout << "a = " << a << endl;
////    cout << "b = " << b << endl;
////    cout << "one = " << one << endl;
////    cout << "a += b: " << (a += b) << endl;	// Implement as member
////    cout << "a = " << a << endl;
////    
////    // Implement as non-member, but not a friend
////    cout << "a + one: " << (a + one) << endl;
////    cout << "a == one: " << boolalpha << (a == one) << endl;
////    
////    // How does this manage to work?
////    // It does NOT require writing another == operator. 
////    cout << "1 == one: " << boolalpha << (1 == one) << endl;
////    
////    // Do not implement as friend.
////    cout << "a != one: " << boolalpha << (a != one) << endl;
////	
////    cout << "a = " << a << endl;
////    cout << "++a = " << (++a) << endl;
////    cout << "a = " << a << endl;
////    cout << "a++ = " << (a++) << endl;
////    cout << "a = " << a << endl;
////    cout << "--a = " << (--a) << endl;
////    cout << "a = " << a << endl;
////    cout << "a-- = " << (a--) << endl;
////    cout << "a = " << a << endl;
////	
////    cout << "++ ++a = " << (++ ++a) << endl;
////    cout << "a = " << a << endl;
////    cout << "-- --a = " << (-- --a) << endl;
////    cout << "a = " << a << endl;
////	
////    cout << "a++ ++ = " << (a++ ++) << endl;
////    cout << "a = " << a << endl;
////
////    // Even though the above example, (a++ ++), compiled, the
////    // following shouldn't.
////    // But some compiler vendors might let it...  Is your compiler
////    // doing the right thing?
////   // cout << "a-- -- = " << (a-- --) << endl;
////   // cout << "a = " << a << endl;
////
////
////    // Should report that 1 is true
////    if (Rational(1)) {
////        cout << "1 is true" << endl;
////    } else {
////        cout << "1 is false" << endl;
////    } 
////
////    // Should report that 0 is false
////    if (Rational(0)) {
////        cout << "0 is true" << endl;
////    } else {
////        cout << "0 is false" << endl;
////    } 
////	
////}
//
//
