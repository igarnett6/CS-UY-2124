/*
  into2.cpp
  CS2124 Sec D
  2019 Spring

 */

#include <string>
#include <iostream>
using namespace std;

struct Motorcycle {
    int numCyl;
    string brand;
    string model;
};

void printMotorcycle(const Motorcycle& someBike);

int main() {
    Motorcycle aBike;
    printMotorcycle(aBike);
    aBike.brand = "Suzuki";
    aBike.model = "Vstrom";
    aBike.numCyl = 2;
    printMotorcycle(aBike);
    // cout << aBike << endl; // won't compile

    ifstream ifs("bikes.txt");
    
    vector<Motorcycle> vm;

    Motorcycle someBike;
    while (ifs >> someBike.brand >> someBike.model>> someBike.numCyl) {    
        vm.push_back(someBike);
    }
        
}

void printMotorcycle(const Motorcycle& someBike) {
    cout << "Motorcycle: " << someBike.brand << ' ' 
         << someBike.model << ' ' << someBike.numCyl << endl;
}
