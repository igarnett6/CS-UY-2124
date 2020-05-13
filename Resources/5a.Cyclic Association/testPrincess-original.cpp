/*
    testPrincess.cpp
    Cyclic Association
    Sec D
*/

#include <iostream>
#include <string>
using namespace std;

class FrogPrince;

class Princess {
    friend ostream& operator<<(ostream& os, const Princess rhs);
public:
    Princess(const string& name); // : name(name), spouse(nullptr) {}
    void display() const;
    // void display() const { 
    //     cout << "Princess: " << name;
    //     //if (spouse)
    //     if (spouse != nullptr) {
    //         cout << ", spouse: " << spouse->getName(); 
    //     }
    //     cout << endl;
    // }
private:
    string name;
    FrogPrince* spouse;
    //FrogPrince spouse;
};

class FrogPrince {
public:
    FrogPrince(const string& name); // : name(name) {}
    void display() const; // { cout << "Frog: " << name << endl;}
    const string& getName() const; // { return name; }
private:
    string name;
    Princess* spouse;
};


int main() {
    Princess snowy("Snow White");
    snowy.display();
    FrogPrince froggy("Froggy");
    froggy.display();
    snowy.marries(froggy);
    snowy.display();
}


Princess::Princess(const string& name) : name(name), spouse(nullptr) {}


void Princess::display() const { 
    cout << "Princess: " << name;
    //if (spouse)
    if (spouse != nullptr) {
        cout << ", spouse: " << spouse->getName(); 
    }
    cout << endl;
}


FrogPrince::FrogPrince(const string& name) : name(name) {}

void FrogPrince::display() const { cout << "Frog: " << name << endl;}

const string& FrogPrince::getName() const { return name; }


ostream& operator<<(ostream& os, const Princess& rhs) {
    os << "Princess: " << name;
    if (spouse != nullptr) {
        os << ", spouse: " << spouse->getName(); 
    }
    return os;
}
