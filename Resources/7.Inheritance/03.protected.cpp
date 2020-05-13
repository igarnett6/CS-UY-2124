#include <iostream>
using namespace std;

class Base {
    friend ostream& operator<<(ostream& os, const Base& base) {
        return os <<  "x: " << base.x; 
    }
public:
    Base(int x) : x(x) {}
protected:
    int getX() const { return x; }
    int setX(int x) { this->x = x; }
private:
    int x;
};

class Derived : public Base {
public:
    Derived(int x) : Base(x) {}
    void derivedSettingX() {
        //x = 42;  
    }
};

int main() {
    Derived d(7);
    cout << d << endl;
}
