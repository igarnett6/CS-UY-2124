/*
  Vector Class
  Demonstrates:
     Good example of copy control
     Dynamic arrays and pointer arithmetic
     Square bracket operator
     Implementation of an important data structure
  Sec 
 */
#include <iostream>
using namespace std;

class Vector {
public:
    Vector() : data(new int[1]), theSize(0), theCapacity(1) {}

    // Copy control
    ~Vector() { delete [] data; }
    
    Vector(const Vector& rhs) {
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = rhs.data[i];
        }
    }
    
    Vector& operator=(const Vector& rhs) {
        // 0. check for self assignment
        if (this != &rhs) {

            // 1. Free up
            delete [] data;

            // 2. Allocate
            data = new int[rhs.theCapacity];

            // 3. copy over all the data
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            for (size_t i = 0; i < theSize; ++i) {
                data[i] = rhs.data[i];
            }
        }

        // 4. return yourself
        return *this
    }

    void push_back(int val) {
        if (theCapacity == 0) {
            data = new int[1];
            theCapacity = 1;
        }
        else if (theSize == theCapacity) {
            int* oldArray = data;
            data = new int[theCapacity*2];
            for (size_t i = 0; i < theSize; ++i) {
                data[i]  = oldArray[i];
            }
            delete [] oldArray;
            theCapacity *= 2;
        }

        data[theSize] = val;
        ++theSize;
    }
    

    size_t size() const { return theSize; }
    void clear() { theSize = 0; }
    void pop_back() { --theSize; }

    // Square brackets?
    int operator[](size_t index) const { return data[index]; }
    
private:
    size_t theSize;
    size_t theCapacity;
    int* data;
};


int main() {

    Vector v;  // Not templated.  Our Vector class can only hold ints.
    // v.push_back(17);
    // v.push_back(42);
    // v.push_back(6);
    // v.push_back(28);

    Vector v2(v);
    Vector v3;
    v3 = v;

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    //v[0]
    //v.operator[](0)    

    // v[0] = 100;

}

