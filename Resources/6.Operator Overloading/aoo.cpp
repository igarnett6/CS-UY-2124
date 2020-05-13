/*
   Arithmetic Operator Overloading
   Sec D
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Complex {
    // op<< as a friend
    friend ostream& operator<<(ostream& os, const Complex& rhs) {
        os << rhs.real;
        os << showpos << rhs.imag << 'i' << noshowpos;
        return os;
    }

    friend bool operator==(const Complex& lhs, const Complex& rhs);

public:
    // Complex() : real(0), imag(0) {}
    // Complex(double real) : real(real), imag(0) {}
    // Complex(double real, double imag) : real(real), imag(imag) {}
    Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}

    //c1 += c2;
    //c1.operator+=(c2);
    Complex& operator+=(const Complex& rhs) {
        real += rhs.real;
        imag += rhs.imag;
        return *this;
    }

private:
    double real, imag;
};

bool operator==(const Complex& lhs, const Complex& rhs) {
    return lhs.real == rhs.real && lhs.imag == rhs.imag;
}

bool operator!=(const Complex& lhs, const Complex& rhs) {
    return !(lhs == rhs);
}

// c1 = c2 + c3;
//operator+(c2, c3);
Complex operator+(const Complex& lhs, const Complex& rhs){ 
    Complex result;
    
}


// Test code
int main() {
    Complex c1;         // 0+0i
    Complex c2(17);     // 17+0i
    Complex c3(3, -5);  // 3-5i
    cout << "c1: " << c1 << endl
         << "c2: " << c2 << endl
         << "c3: " << c3 << endl;

    // Testing equality and inequality operators
    cout << "c1 " << (c1 == c2 ? "==" : "!=") << " c2\n"; 
    cout << "c1 " << (c1 == c1 ? "==" : "!=") << " c1\n"; 



    // Testing "combination operator" op+=
    c1 += c2;
    //c1.operator+=(c2);

    // Testing op+
    c1 = c2 + c3;
    //operator+(c2, c3);

    /*
    Complex one(1);
    cout << "one " << (one == 1 ? "==" : "!=") << " 1\n"; 

    // Testing pre-increment
    cout << ++c1 << ' ' << c1 << endl;

    // Testing post-increment
    cout << c1++ << ' ' << c1 << endl;

    Complex zero(0);
    cout << "zero is " << (zero ? "true" : "false") << endl;
    cout << "one is " << (one ? "true" : "false") << endl;
    */

}
