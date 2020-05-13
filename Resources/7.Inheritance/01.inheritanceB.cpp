
/*
  1.inheritance.cpp
  Section Base

  Code reuse, principle of substitutibility, polymorphism
   */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pet {
public:
    Pet(const string& name) : name(name) {}

    //void eat() { cout << "eating" << endl; }}

    // polymorphism
    virtual void eat() { cout << name << " eating" << endl; } 

    const string& getName() const { return name; }
private:
    string name;
};

class Cat : public Pet {
public:
    //Cat(const string& name) : name(name) {}
    Cat(const string& name) : Pet(name) {}


    //void eat() { cout << "Cat eating" << endl; }
    void eat() { 
        cout << "Cat ";
        Pet::eat();
        //this->Pet::eat();
    }
};

class Slug : public Pet { 
public:
    Slug(const string& name) : Pet(name) {}

    void eat() { cout << "eating" << endl; } // polymorphism
};

class Roach : public Pet { 
public:
    //Roach(const string& name) : Pet(name) {}
    // "inheriting constructor"
    using Pet::Pet;

    //void eat() { cout << name << "roach eating" << endl; }
    void eat() { cout << getName() << "roach eating" << endl; }
};

// Liskov's Principal of Substitutibility
//void someFunc(Pet aPet) { // Slicing
void someFunc(Pet& aPet) {
    cout << "someFunc: ";
    aPet.eat();
}

int main() {
    Pet peeve("Peeve");
    peeve.eat();
    someFunc(peeve);

    Cat felix("Felix");
    felix.eat();
    someFunc(felix);

    Roach archie("Archie");
    archie.eat();
    someFunc(archie);

    cout << "============\n";

    vector<Pet> menagerie;
    menagerie.push_back(felix);
    menagerie.push_back(peeve);
    menagerie.push_back(archie);
    for (size_t i = 0; i < menagerie.size(); ++i) {
        menagerie[i].eat();
    }
   cout << "============\n";

    vector<Pet*> menagerie2;
    menagerie2.push_back(&felix);
    menagerie.push_back(&peeve);
    menagerie2.push_back(&archie);
    for (size_t i = 0; i < menagerie2.size(); ++i) {
        menagerie2[i]->eat();
    }
}
