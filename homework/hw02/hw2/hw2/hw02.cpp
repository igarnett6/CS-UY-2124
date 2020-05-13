/*Isaiah Garnett
hw02
Medeival Times Simulator*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct Warrior {
public:
	Warrior() {}
	Warrior(const string& name, int& strength) : name(name), strength(strength) {}

	string name;
	int strength;
};

ifstream openfile();
void status(const vector<Warrior>& warriorsList);
void battle(const string& warrior1, const string& warrior2, vector<Warrior>& warriorsList);
Warrior warrior(const string& name, int& strength);






int main() {
	ifstream warriorsFile = openfile();
	vector<Warrior> warriorsList;
	string name;
	int strength;
	string warrior1;
	string warrior2;


	//read file
	string command;
	while (warriorsFile >> command) {
		if (command == "Warrior") {
			warriorsFile >> name >> strength;
			Warrior newWarrior = warrior(name, strength);
			warriorsList.push_back(newWarrior);
		}
		else if (command == "Status") {
			status(warriorsList);
		}
		else if (command == "Battle") {
			warriorsFile >> warrior1 >> warrior2;
			battle(warrior1, warrior2, warriorsList);

		}
		else {
			cerr << "Invalid command given.";
			exit(1);
		}
	}
	warriorsFile.close();
}





ifstream openfile() {
	ifstream warriorFile("warriors.txt");
	if (!warriorFile) {
		cerr << "Failed to open warriors.txt" << endl;
		exit(1);
	}
	return warriorFile;
}

void display(Warrior thisWarrior) {
	cout << "Warrior: " << thisWarrior.name << ", strength: " << thisWarrior.strength << endl;
}

void status(const vector<Warrior>& warriorsList) {
	cout << "There are: " << warriorsList.size() << " warriors." << endl;
	for (size_t i = 0; i < warriorsList.size(); i++) {
		display(warriorsList[i]);
	}
}

Warrior warrior(const string& name, int& strength) {
	Warrior newWarrior = Warrior(name, strength);
	return newWarrior;
}

void battle(const string& warrior1, const string& warrior2, vector<Warrior>& warriorsList) {
	Warrior w1;
	Warrior w2;
	//access warrior objects
	for (Warrior& thisWarrior : warriorsList) {
		if (thisWarrior.name == warrior1) {
			w1 = thisWarrior;
		}
		if (thisWarrior.name == warrior2) {
			w2 = thisWarrior;
		}
	}


	//battle start!
	cout << w1.name << " battles " << w2.name << "." << endl;


	//compare strengths and fight
	const int w1OldStrength = w1.strength;
	const int w2OldStrength = w2.strength;

	//check that both are living
	if (w1.strength != 0 || w2.strength != 0) {
		w1.strength = w1OldStrength - w2OldStrength;
		w2.strength = w2OldStrength - w1OldStrength;
	}
	
	if (w1.strength < 0) {
		w1.strength = 0;
	}
	if (w2.strength < 0) {
		w2.strength = 0;
	}

	//check and print outcome of battle
	if (w1OldStrength == 0 && w2OldStrength == 0) {
		cout << "Oh, NO! They're both dead! Yuck!" << endl;
	}
	else if (w1OldStrength == 0 && w2OldStrength != 0) {
		cout << "He's dead, " << w2.name << endl;
	}
	else if (w1OldStrength != 0 && w2OldStrength == 0) {
		cout << "He's dead, " << w1.name << endl;
	}
	else if (w1.strength == 0 && w2.strength != 0) {
		cout <<  w2.name << " defeats " << w1.name << "." << endl;
	}
	else if (w1.strength == 0 && w2.strength == 0) {
		cout << "Mutual annihilation: " << w1.name << " and " << w2.name << " die at each other's hands." << endl;
	}
	else if (w1.strength != 0 && w2.strength == 0) {
		cout << w1.name << " defeats " << w2.name << "." << endl;
	}


	//update original Warrior objects
	//this is kind of janky, but I wasn't sure how to fix the scope issue of w1 and w2 in line 97's loop.
	for (Warrior& thisWarrior : warriorsList) {
		if (thisWarrior.name == w1.name) {
			thisWarrior.strength = w1.strength;
		}
		if (thisWarrior.name == w2.name) {
			thisWarrior.strength = w2.strength;
		}
	}
}