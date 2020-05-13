#include "FrogPrince.h"
#include <iostream>
#include <string>
using namespace std;

namespace Fantasy {

    class Princess;

    //
    // FrogPrince implementation code
    //
    FrogPrince::FrogPrince(const string& name)
        : name(name), spouse(nullptr) {}

    const string& FrogPrince::getName() const { return name; }

    ostream& operator<<(ostream& os, const FrogPrince& rhs) {
        os << "FrogPrince: " << rhs.name;
        return os;
    }

    void FrogPrince::setSpouse(Princess* betrothed) { 
        spouse = betrothed;
    }

}
