#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Person {
    friend ostream& operator<<(ostream& os, const Person& someone) {
        os << "Person: " << someone.name << ", " << someone.age;
        return os;
    }
public:
    Person(const string& name, int age) : name(name), age(age) {}
    const string& getName() const { return name; }
private:
    string name;
    int age;
};

int main() {
    ifstream ifs("stooges.txt");

    vector<Person*> stooges;
    
    string name;
    int age;
    while (ifs >> name >> age) {
        //Person someone(name, age);
        //stooges.push_back(&someone);
        Person* p = new Person(name, age);
        stooges.push_back( p );
        //stooges.push_back( new Person(name, age) );
        cout << stooges.back() << endl;
        // for (Person* p : stooges) {
        //     cout << p->getName() << endl;
        // }
        cout << "===========\n";
    }

    ifs.close();

    //    for (Person* p : stooges) {
    for (const Person* p : stooges) {
        cout << p << ' ' << p->getName() << endl;
    }

    //for (Person* p : stooges) {
    for (const Person* p : stooges) {
        //for (const Person* const p : stooges) {
        cout << *p << endl;
    }
    
    //for (Person* p : stooges) {
    for (Person*& p : stooges) {
        delete p;
        p = nullptr;
    }
}
