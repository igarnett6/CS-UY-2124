/*
  Vector Class
  Templated  vector
  Sec D
 */
#include <iostream>
using namespace std;

struct Cat{};
ostream& operator<<(ostream& os, const Cat& rhs) {
    os << "meow";
    return os;
    
    //return os << "meow";
}

template <typename Fred>
class Vector {
public:
    
    explicit Vector(size_t howMany=0, Fred val = Fred())
    {
        theSize = howMany;
        theCapacity = howMany;
        data = new Fred[howMany];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = val;
        }
    }

    //
    // Copy control
    //
    //   Destructor
    ~Vector() {
        delete [] data;
    }

    //   Copy Constructor
    Vector(const Vector& rhs) {
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new Fred[theCapacity];
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
            data = new Fred[rhs.theCapacity];
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


    void push_back(const Fred& val) {
        if (theSize == theCapacity) {
            if (theCapacity == 0) {
                delete [] data;
                data = new Fred[1];
                theCapacity = 1;
            } else {
                Fred* oldData = data;
                theCapacity *= 2;
                data = new Fred[theCapacity];
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
    const Fred& operator[](size_t index) const {
        return data[index];
    }
    Fred& operator[](size_t index) {
        return data[index];
    }
    
private:
    Fred* data;
    size_t theSize;
    size_t theCapacity;
};


void printVector(const Vector<int>& v) {
    cout << "Print vector of ints: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

//template <typename T, typename U>
template <typename T>
void printVector(const Vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main() {

    // Template!!
    Vector<int> v;  

    v.push_back(17);
    v.push_back(42);
    v.push_back(6);
    v.push_back(28);
    printVector(v);
    
    v[0] = 100;

    Vector<int> v2 = v;
    printVector(v2);

    Vector<int> v3;
    v3 = v;
    printVector(v3);

    v3 = Vector<int>(17);
    printVector(v2);


    Vector<Cat> cats(4);
    printVector(cats);

}

