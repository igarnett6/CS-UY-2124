/*Isaiah Garnett
hw03 
Encapsulation, data hiding
delegation, operator overloading*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

ifstream openfile();
void status(vector<Warrior>& warriorsList);
void display(const Warrior& thisWarrior);
size_t findWarrior(const string& name, vector<Warrior>& warriorsList);


class Warrior {
private:
	class Weapon {
		friend Warrior;
	public:
		Weapon(const string& name, int strength) :name(name), strength(strength) {}

		int getStrength() const {
			return strength;
		}
		string getName() const {
			return this->name;
		}
		

	private:
		const string name;
		int strength;
	};



public:
	Warrior(const string& name, Weapon& weap) : name(name), weap(weap) {}
	Weapon getWeapon() const {
		return weap;
	}

	string getName() const {
		return name;
	}

	void setStrength(int newStrength) {
		weap.strength = newStrength;
	}

	void battle(const string& warrior1, const string& warrior2, vector<Warrior>& warriorsList) {
		Warrior& w1 = warriorsList[findWarrior(warrior1, warriorsList)];
		Warrior& w2 = warriorsList[findWarrior(warrior2, warriorsList)];
		int w1NewStrength;
		int w2NewStrength;
		//Weapon& weap1 = w1.getWeapon();
		//Weapon& weap2 = w2.getWeapon();

		//battle starts
		cout << w1.getName() << " battles " << w2.getName() << "." << endl;
		if (w1.getWeapon().getStrength() == 0 || w2.getWeapon().getStrength() == 0) {
			if (w1.getWeapon().getStrength() == 0 && w2.getWeapon().getStrength() == 0) {
				cout << "Oh, NO!, They're both dead! Yuck!" << endl;
				return;
			}
			else if (w1.getWeapon().getStrength() == 0) {
				cout << "He's dead, " << w2.getName() << "." << endl;
				return;
			}
			else if (w2.getWeapon().getStrength() == 0) {
				cout << "He's dead, " << w1.getName() << "." << endl;
				return;
			}
			else {
				cout << "something broke1" << endl;
				return;
			}
		}
		//update weapon strengths


		if (w1.getWeapon().getStrength() != 0 || w2.getWeapon().getStrength() != 0) {
			w1NewStrength = w1.getWeapon().getStrength() - w2.getWeapon().getStrength();
			w2NewStrength = w2.getWeapon().getStrength() - w1.getWeapon().getStrength();
			if (w1NewStrength < 0) {
				w1NewStrength = 0;
				w1.setStrength(0);
			}
			else if (w2NewStrength < 0) {
				w2NewStrength = 0;
				w2.setStrength(0);
			}
			w1.setStrength(w1NewStrength);
			w2.setStrength(w2NewStrength);
		}


		//determine victor
		if (w1NewStrength == 0 && w2NewStrength == 0) {
			cout << "Mutual annihilation: " << w1.getName() << " and " << w2.getName() << " die at each other's hands." << endl;
		}
		else if (w1NewStrength == 0) {
			cout << w2.getName() << " defeats " << w1.getName() << endl;
		}
		else if (w2NewStrength == 0) {
			cout << w1.getName() << " defeats " << w2.getName() << endl;
		}
		else {
			cerr << "something broke." << endl;
		}

		return;
	}

private:
	
	const string name;
	Weapon weap;
};


ifstream openfile() {
	ifstream warriorFile("warriors.txt");
	if (!warriorFile) {
		cerr << "Failed to open \'warriors.txt\'" << endl;
		exit(1);
	}
	return warriorFile;
}

void display(const Warrior& thisWarrior) {
	cout << "Warrior: " << thisWarrior.getName() << ", Weapon: " << thisWarrior.getWeapon().getName() << ", " << thisWarrior.getWeapon().getStrength() << endl;
}

void status(vector<Warrior>& warriorsList) {
	cout << "There are: " << warriorsList.size() << " warriors." << endl;
	for (size_t i = 0; i < warriorsList.size(); i++) {
		display(warriorsList[i]);
	}
}

size_t findWarrior(const string& name, vector<Warrior>& warriorsList) {
	for (size_t i = 0; i < warriorsList.size(); i++) {
		if (warriorsList[i].getName() == name) {
			return i;
		}
	}
	cerr << "Warrior not found." << endl;
	exit(1);

}





int main() {
	ifstream warriorsFile = openfile();
	vector<Warrior> warriorsList;
	string name;
	string warrior1;
	string warrior2;
	string weapName;
	int strength;
	string command;


	// begin parsing file
	while (warriorsFile >> command) {
		if (command == "Warrior") {
			warriorsFile >> name >> weapName >> strength;
			Weapon newWeapon = Weapon(weapName, strength);
			warriorsList.emplace_back(name, newWeapon);
		}
		else if (command == "Battle") {
			warriorsFile >> warrior1 >> warrior2;
			Warrior& w1 = warriorsList[findWarrior(warrior1, warriorsList)];

			battle(warrior1, warrior2, warriorsList);
		}
		else if (command == "Status") {
			status(warriorsList);
		}
		else {
			cerr << "Invalid command recieved." << endl;
			exit(1);
		}
	}
	warriorsFile.close();

}







