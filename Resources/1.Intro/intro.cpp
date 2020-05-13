#include <iostream>
#include <vector>
using namespace std;

void addOne(int someInt) { // pass by value
    someInt += 1;
    //cout << someInt << endl;
}

int addOneV2(int someInt) {
    someInt += 1;
    //    cout << someInt << endl;
    return someInt;
}

void addOneRef(int& someInt) { // pass by reference
    someInt += 1;
    //cout << someInt << endl;
}

void printVec(vector<int> someVec) {
    for (int item : someVec) {
        cout << item << ' ';
    }
    cout << endl;
}

int main() {

    int x = 17;

    addOne(x);
    cout << x << endl;

    x = addOneV2(x);
    cout << x << endl;

    addOneRef(x);
    cout << x << endl;

    vector<int> vi{1,1,2,3,5,8};
    //cout << vi << endl;

    printVec(vi);
}
