/*
  Vector Class
  Vector of ints
  Sec D
 */
#include <iostream>
using namespace std;

class Iterator {
    friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
        return lhs.curr != rhs.curr;
    }
public:
    Iterator(int* pointer) : curr(pointer) {}
    Iterator& operator++() {
        ++curr;
        return *this;
    }
    int& operator*() {
        return *curr;
    }    
private:
    int* curr;
};

class Vector {
public:
    
    explicit Vector(size_t howMany=0, int val=0)
    {
        theSize = howMany;
        theCapacity = howMany;
        data = new int[howMany];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = val;
        }
    }

    // Copy control
    //   Destructor
    ~Vector() {
        delete [] data;
    }

    //   Copy Constructor
    Vector(const Vector& rhs) {
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = rhs.data[i];
        }
    }

    //   Assignement Operator
    Vector& operator=(const Vector& rhs) {
        if (this != &rhs) {
            // Free up the old (destructor)
            delete [] data;
            // Allocate new
            data = new int[rhs.theCapacity];
            // Copy all the stuff
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            for (size_t i = 0; i < theSize; ++i) {
                data[i] = rhs.data[i];
            }
        }
        // Return ourselves
        return *this;
    }


    void push_back(int val) {
        if (theSize == theCapacity) {
            if (theCapacity == 0) {
                data = new int[1];
                theCapacity = 1;
            } else {
                int* oldData = data;
                theCapacity *= 2;
                data = new int[theCapacity];
                for (size_t i = 0; i < theSize; ++i) {
                    data[i] = oldData[i];
                }
                delete [] oldData;
            }
        }
        data[theSize++] = val;
    }

    size_t size() const { return theSize; }
    void pop_back() { --theSize; }

    void clear() { theSize = 0; };


    // Square brackets?
    int operator[](size_t index) const {
        return data[index];
    }
    int& operator[](size_t index) {
        return data[index];
    }
    
    //    Iterator begin() { return Iterator(data); }
    Iterator begin() { 
        Iterator result(data); 
        return result;
    }
    Iterator end() { return Iterator(data + theSize); }

    // int* begin() const { return data; }
    // int* end() const { return data + theSize; }

    const int* begin() const { return data; }
    const int* end() const { return data + theSize; }
    
private:
    int* data;
    size_t theSize;
    size_t theCapacity;
};


//void printVector(const Vector& v) {
void printVector(Vector& v) {
    // for (size_t i = 0; i < v.size(); ++i) {
    //     cout << v[i] << ' ';
    // }

    for (int val : v) {
        cout << val << ' ';
    }

    // for (int* p = v.begin(); p != v.end(); ++p) {
    //     *p =42;
    // }

    cout << endl;
}

int main() {

    // Not templated.  Our Vector class can only hold ints.
    Vector v;  

    v.push_back(17);
    v.push_back(42);
    v.push_back(6);
    v.push_back(28);
    printVector(v);
    
    v[0] = 100;

    Vector v2 = v;
    printVector(v2);

    Vector v3;
    v3 = v;
    printVector(v3);

    v3 = Vector(17);
    printVector(v3);

    for (int val : v2) {
        cout << val << ' ';
    }
    cout << endl;

    for (Iterator p = v2.begin(); p != v2.end(); ++p) {
        int val = *p;
        cout << val << ' ';
    }
    cout << endl;

    // for (int& val : v2) {
    //     cout << val << ' ';
    // }
    // cout << endl;

    // for (int* p = v2.begin(); p != v2.end(); ++p) {
    //     int& val = *p;
    //     cout << val << ' ';
    //     //cout << *p << ' ';
    // }
    // cout << endl;
}

