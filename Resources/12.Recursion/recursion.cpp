/*
  Recursion
  Sec D
*/

#include <iostream>
using namespace std;

void recursiveFunction(int n) {
    if (n == 1) cout << n << endl;
    else {
        cout << n << endl;
        recursiveFunction(n-1);  // Infinite loop
    }
}

void recursiveFunction(int n) {
    if (n == 0) {
        return;
    } else {
        cout << n << endl;
        recursiveFunction(n-1);  // Infinite loop
    }
}

void recursiveFunction(int n) {
    if (n > 0) {
        cout << n << endl;
        recursiveFunction(n-1);  // Infinite loop
    }
}


int main() {
    recursiveFunction();
}
