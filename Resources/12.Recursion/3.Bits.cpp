/*
  3.Bits
  - What is the recursion involved in splitting a non-negative integer
    "apart" into its digits?
  - What about into its bits?

  - jbs
 */

#include <iostream>
using namespace std;

void printDigits(int n) {
    if (n < 10) cout << n << ' ';
    else {
        printDigits(n/10);
        cout << n % 10 << ' ';
    }
}

void printDigitsReverse(int n) {
    if (n < 10) cout << n << ' ';
    else {
        cout << n % 10 << ' ';
        printDigits(n/10);
    }
}

void printBits(int n) {
    if (n < 2) cout << n << ' ';
    else {
        cout << n % 2 << ' ';
        printDigits(n/2);
    }
}

int countBits(int n) {
    if (n < 2) return n;
    else {
        return n%2 + countBits(n/2);
    }
}

int main() {
    cout << "printDigits(314159);   ";
    printDigits(314159);
    cout << endl;
    cout << "printDigitsR1(314159); ";
    printDigitsR1(314159);
    cout << endl;
    cout << "printDigitsR2(314159); ";
    printDigitsR2(314159);
    cout << endl;


    cout << "printBits(5): ";
    printBits(5);
    cout << endl;

    //cout << "countBits(5): " << countBits(5) << endl;

    cout << "printBits(16): ";
    printBits(16);
    cout << endl;

    //cout << "countBits(16): " << countBits(16) << endl;    

}
