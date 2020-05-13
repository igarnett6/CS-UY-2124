/*
Isaiah Garnett
  Recitation 06
  CS2124

  Focus: Dynamic arrays and copy control
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
	friend ostream& operator<<(ostream& os, const Position& rhs) {
		os << '[' << rhs.title << ',' << rhs.salary << ']';
		return os;
	}
public:
	Position(const string& aTitle, double aSalary)
		: title(aTitle), salary(aSalary) {}
	const string& getTitle() const { return title; }
	double getSalary() const { return salary; }
	void changeSalaryTo(double d) { salary = d; }
private:
	string title;
	double salary;
}; // class Position

class Entry {
	friend ostream& operator<<(ostream& os, const Entry& rhs) {
		os << rhs.name << ' ' << rhs.room
			<< ' ' << rhs.phone << ", " << *rhs.pos;
		return os;
	}

public:
	Entry(const string& name, unsigned room, unsigned phone, Position& position)
		: name(name), room(room), phone(phone), pos(&position) {
	}
	const string& getName() const { return name; }
	unsigned getPhone() const { return phone; }
private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
}; // class Entry

class Directory {
	// Overload output operator
	friend ostream& operator<<(ostream& os, const Directory& rhs) {
		os << "Directory Entries: " << endl;
		for (size_t i = 0; i < rhs.size; i++) {
			os << *rhs.entries[i] << endl;
		}
		os << endl;
		return os;
	}


public:
	// Of course the first function you need to write for this (or
	// any) class is...
	// ???
	// ...uh, that'd be the constructor my guy.
	//Directory(Directory& existingDirectory) :entries(existingDirectory.entries), capacity(existingDirectory.capacity), size(existingDirectory.size) { 
	//	cout << " entered Directory copy constructor." << endl; 
	//}
	Directory(const Directory& existingDirectory) : capacity(existingDirectory.capacity), size(existingDirectory.size),
		entries(new Entry*[existingDirectory.capacity]) {
		cout << "Entered Directory copy constructor." << endl;
		for (size_t i = 0; i < existingDirectory.size; i++) {
			entries[i] = new Entry(*existingDirectory.entries[i]);
		}
		cout << "Leaving copy constructor." << endl;
	}
	Directory() :size(0), capacity(1), entries(new Entry*[1]) { }

	// We'll get you started with the add method, but obviously you
	// have a lot of work to do here.
	void add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if (size == capacity) {
			// something is missing!!!  Add it!
			Entry** oldArray = entries;
			capacity *= 2;
			entries = new Entry*[capacity];
			for (size_t i = 0; i < size; i++) {
				entries[i] = oldArray[i];
			}
			delete[] oldArray;
		} // if
		entries[size] = new Entry(name, room, ph, pos);
		++size;
	} // add


	Directory& operator=(const Directory& rhs) {
		cout << "Entered assignment operator." << endl;
		if (&rhs != this) {
			for (size_t i = 0; i < size; i++) {
				delete entries[i];
			}
			delete[] entries;
			entries = new Entry*[rhs.size];
			for (size_t i = 0; i < size; i++) {
				entries[i] = new Entry(*rhs.entries[i]);
			}
		}
		return *this;
	}

	unsigned operator[](const string& name) const {
		for (size_t i = 0; i < size; i++) {
			if (entries[i]->getName() == name) {
				return entries[i]->getPhone();
			}
		}
		cerr << name << " not found. " << endl;
	}

	~Directory() {
		cout << "Entered Directory destructor." << endl;
		for (size_t i = 0; i < size; i++) {
			delete entries[i];
		}
		delete[] entries;
	}

private:
	size_t size;
	size_t capacity;
	Entry** entries;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {

	// Note that the Postion objects are NOT on the heap.
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	// Create a Directory
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	cout << d << endl;

	Directory d2 = d;	// What function is being used??
	d2.add("Gallagher", 111, 2222, techie);
	d2.add("Carmack", 314, 1592, techie);
	cout << d << endl;

	cout << "Calling doNothing\n";
	doNothing(d2);
	cout << "Back from doNothing\n";

	Directory d3;
	d3 = d2;

	// Should display 1592
	cout << d2["Carmack"] << endl;

} // main
