#include <iostream>
using namespace std;

class Shape { // Abstract class
public:
    Shape(int x, int y) : x(x), y(y) {}
    void move(int x, int y) { this->x = x;  this->y = y; }
    //virtual void draw() {}

    // "pure" virtual
    virtual void draw() = 0; // abstract method

    //void commonDrawingCode() { cout << "some common drawing code" << endl; }

private:
    int x, y;
};

void Shape::draw() { cout << "some common drawing code" << endl; }



class Triangle : public Shape {
public:
    Triangle(int x, int y) : Shape(x,y) {}
    //void draw() { /* */ }
protected:
};

class Isosceles : public Triangle {
public:
    using Triangle::Triangle;
    void draw() {}
}

class Circle : public Shape {
public:
    Circle(int x, int y) : Shape(x,y) {}
    void draw() {
        // Some Circle drawing code
        //...

        Shape::draw();
    }
    
};

void foo(Shape& aShape) {
    aShape.draw();
}

int main() {
    // Shape aShape(3,4);
    Triangle tri(3,4);
    // tri.draw();
    // Circle circ(10,10);
    // circ.draw();
}
