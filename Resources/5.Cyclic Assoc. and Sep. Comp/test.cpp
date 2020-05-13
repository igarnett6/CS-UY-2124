/*
    testPrincess.cpp
    Cyclic Association
    Sec D - 19S
*/

//#include "Princess.h"
#include "Princess.h"
#include "FrogPrince.h"
#include <iostream>
#include <string>
#include <string>
using namespace std;
using namespace Fantasy;

int main() {
    Princess snowy("Snow White");
    cout << snowy << endl;
    FrogPrince froggy("Froggy");
    cout << froggy << endl;
    snowy.marries(froggy);
    cout << snowy << endl;

    // int x = 17;
    // int x = 17;
}

