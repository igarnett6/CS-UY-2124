/*
  CS2124
  Exceptions and Assertions
  Sec. D
*/

#include <iostream>
#include <vector>
#include <cstdlib>

#include <exception>
#include <stdexcept>

//#define NDEBUG
#include <cassert>

using namespace std;

//class MyException {
class MyException : public exception {
    const char* what() const noexcept {
        return "in MyException"; 
    }
};



void bar(int n) {
    assert(n<=200);
    // if (n > 200) {
    //     cerr << "some message\n";
    //     exit(1);
    // }

    if (n > 200) {
        // What to do?
        //throw 17;
        //throw 3.14159;
        //throw exception();
        throw MyException();
    }
}
void foo(int n) { 
    try {
        bar(n); 
    } catch(...) {
        cerr << "caught something but don't know what\n";
        throw;
    }
    
}

void someFunc(int n) {
    vector<int> v(n);
    //v[n] = 42;
    v.at(n) = 42;
}

int main() {
    //    someFunc(10);

    try {
        someFunc(10);
        //} catch (exception ex) {
        foo(300);
    } catch (out_of_range oor) {
        cerr << "Caught an out_of_range exception\n";
        cerr << oor.what() << endl;
        cerr << "So long and thanks for all the fish\n";
        //exit(1);
    } catch (exception& ex) {
        cerr << "Caught an exception\n";
        cerr << ex.what() << endl;
    }

    try {
        foo(300);
    // } catch (exception& ex) {
    //     cout << ex.what() << endl;
    // }
    } catch (...) {
        cerr << "caught something but don't know what\n";
    }

    cerr << "Still running\n";
}
