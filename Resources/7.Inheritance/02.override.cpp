#include <iostream>
using namespace std;

class Base {
public:
    // void whereAmI() { cout << "Base\n"; }
    virtual void whereAmI() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    //void whereamI() override { cout << "Derived\n"; }
    void whereAmI() override { cout << "Derived\n"; }
};

void foo(Base& thing) {
    thing.whereAmI();
}

int main() {
    Base base;
    foo(base);
    Derived der;
    foo(der);
}

