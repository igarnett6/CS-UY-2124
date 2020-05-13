/*
  1.inheritance.cpp
  Section D

  Code reuse, principle of substitutibility, polymorphism
   */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pet {
public:
    //void eat() { cout << "eating" << endl; }}
    virtual void eat() { cout << "eating" << endl; } // polymorphism
};

class Cat : public Pet {
public:
    //void eat() { cout << "Cat eating" << endl; }
    void eat() { 
        cout << "Cat ";
        Pet::eat();
        //this->Pet::eat();
    }
    void purr() { cout << "purr\n"; }
};

class Slug : public Pet { };

class Roach : public Pet { };

// Liskov's Principal of Substitutibility
//void someFunc(Pet aPet) { // Slicing
void someFunc(Pet& aPet) {
    cout << "someFunc: ";
    aPet.eat();
}

void foo (Pet& aPet) {
    //    aPet.purr();
}


int main() {
    Pet peeve;
    peeve.eat();
    someFunc(peeve);

    Cat felix;
    felix.eat();
    someFunc(felix);
    foo(felix);

    peeve = felix;
    felix = peeve;

    Pet* pp = &peeve;

    pp = &felix;
    //pp->purr();
    pp->eat();

}
