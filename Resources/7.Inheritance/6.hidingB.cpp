/*
  6.hidingB.cpp
  der.foo(17) now calls Derived::foo(int) as Derived redefines foo(int)
  Inclass Base 
 */

#include <iostream>
using namespace std;

class Base {
public:
    void foo(int n) const { cout << "Base::foo(n)\n"; }
};

class Derived : public Base {
public:
    //void foo(int n) const { cout << "Base::foo(n)\n"; }
    //void foo(int n) const { Base::foo(n); }
    using Base::foo;
    void foo() const { cout << "Derived::foo()\n"; }
};

int main() {
    Derived der;
    der.foo(17);
    //der.Base::foo(17);
}
