/*Isaiah Garnett
hw05, Dynamic Memory*/




#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Warrior;
class Noble;
ifstream openfile();
Noble* findNoble(vector<Noble*>& allNobles, string& name);
Warrior* findWarrior(vector<Warrior*>& unemployedWarriors, string& name);
void status(vector<Noble*>& allNobles, vector<Warrior*>& unemployedWarriors);
ostream& operator<<(ostream& os, vector<Noble*>& allNobles);
ostream& operator<<(ostream& os, vector<Warrior*>& unemployedWarriors);

class Warrior {
public:
	Warrior(const string& name, int strength) : name(name), strength(strength) {}

	string getName() const { return name; }
	void setStrength(int newStrength) {
		strength = newStrength;
	}
	int getStrength() { return strength; }
	Noble* getLord() const { return lord; }
	void setLord(Noble* newLord) { lord = newLord; }

	ostream& operator<<(ostream& os) const {
		os << name << ": " << strength << endl;
		return os;
	}

private:
	const string name;
	int strength;
	Noble* lord;
};


class Noble {
public:
	Noble(const string& name) : name(name) { int armyStrength(0); bool alive(true); }
	int getArmyStrength() const { return armyStrength; }

	string getName() const { return name; };

	void defeated() {
		armyStrength = 0;
		for (Warrior*& thisWarrior : army) {
			thisWarrior->setStrength(0);
		}
		alive = false;
	}

	bool checkAlive() const {
		return alive;
	}

	void updateArmyStrength(const double ratio) {
		int lostStrength;
		for (Warrior* thisPoorSod : army) {
			lostStrength = thisPoorSod->getStrength()*ratio;
			thisPoorSod->setStrength(thisPoorSod->getStrength() - lostStrength);
		}
	}

	void hire(Warrior* thisWarrior) {
		if (thisWarrior->getStrength() != 0) {
			thisWarrior->setLord(this);
			army.push_back(thisWarrior);
			armyStrength += thisWarrior->getStrength();
		}
		else {
			cout << this->name << " failed to hire " << thisWarrior->getName() << ". He's dead " << this->name << endl;
		}
	}

	void fire(vector<Warrior*>& unemployedWarriors, string& warriorName) {
		int i = 0;
		size_t origArmySize = army.size();
		Warrior* thisWarrior = nullptr;
		for (Warrior*& soughtWarrior : army) {
			if (warriorName == soughtWarrior->getName()) {
				cout << soughtWarrior->getName() << ", you're fired! --" << this->name << endl;
				unemployedWarriors.push_back(soughtWarrior);
				army.erase(army.begin() + i);
			}
			i++;
		}
		if (origArmySize == army.size()) {
			cerr << this->getName() << " failed to fire " << warriorName << " they were not their employer." << endl;
		}		
	}

	void battle(Noble& adversary) {
		cout << this->name << " battles " << adversary.getName() << endl;
		if ((this->armyStrength != 0) && (adversary.getArmyStrength() != 0)) {
			if (this->armyStrength > adversary.getArmyStrength()) {
				cout << this->name << " defeats " << adversary.getName() << endl;
				this->updateArmyStrength(adversary.getArmyStrength() / this->armyStrength);
				adversary.defeated();
			}
			else if (adversary.getArmyStrength() > this->armyStrength) {
				cout << adversary.getName() << " defeasts " << this->name << endl;
				adversary.updateArmyStrength(this->armyStrength / adversary.getArmyStrength());
				this->defeated();
			}
			else if (adversary.getArmyStrength() == this->armyStrength) {
				cout << "Mutual Annihilation: " << this->name << " and " << adversary.getName()
					<< " die at each other's hands" << endl;
				this->defeated();
				adversary.defeated();
			}
		}
		else if ((this->armyStrength == 0) && (adversary.getArmyStrength() != 0)) {
			cout << "He's dead " << adversary.getName() << endl;
		}
		else if ((this->armyStrength != 0) && adversary.getArmyStrength() == 0) {
			cout << "He's dead " << this->name << endl;
		}
		else {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
	}

	ostream& operator<<(ostream& os) const {
		os << name << " has an army of " << army.size() << endl;
		for (size_t i = 0; i < army.size(); i++) {
			army[i]->operator<<(os);
		}
		return os;
	}

	~Noble() {
		for (size_t i = 0; i < army.size(); i++){
			delete army[i];
		}
	}

private:
	const string name;
	int armyStrength;
	vector<Warrior*> army;
	bool alive;
};



int main() {
	vector<Warrior*> unemployedWarriors;
	vector<Noble*> allNobles;
	string command = "";
	string name = "";
	string nobleName = "";
	string warriorName = "";
	Noble* thisNoble = nullptr;
	Warrior* thisWarrior = nullptr;
	Noble* n1 = nullptr;
	Noble* n2 = nullptr;
	int strength;
	ostream os();
	ifstream ifile = openfile();
	while (ifile >> command)
	{
		if (command == "Noble") {
			ifile >> name;
			Noble* newNoble;
			newNoble = new Noble(name);
			allNobles.push_back(newNoble);
		}
		else if (command == "Warrior") {
			ifile >> name >> strength;
			Warrior* newWarrior;
			newWarrior = new Warrior(name, strength);
			unemployedWarriors.push_back(newWarrior);
		}
		else if (command == "Hire") {
			ifile >> nobleName >> warriorName;
			thisNoble = findNoble(allNobles, nobleName);
			thisWarrior = findWarrior(unemployedWarriors, warriorName);
			thisNoble->hire(thisWarrior);
			thisNoble = nullptr;
			thisWarrior = nullptr;
		}
		else if (command == "Fire") {
			ifile >> nobleName >> warriorName;
			thisNoble = findNoble(allNobles, nobleName);
			thisNoble->fire(unemployedWarriors, warriorName);
			thisNoble = nullptr;
			thisWarrior = nullptr;
		}
		else if (command == "Status") {
			status(allNobles, unemployedWarriors);
		}
		else if (command == "Battle") {
			string n1Name = "";
			string n2Name = "";
			ifile >> n1Name >> n2Name;
			n1 = findNoble(allNobles, n1Name);
			n2 = findNoble(allNobles, n2Name);
			n1->battle(*n2);
		}
		else if (command == "Clear") {
			for (size_t i = 0; i < unemployedWarriors.size(); i++) {
				delete unemployedWarriors[i];
			}
			for (size_t i = 0; i < allNobles.size(); i++) {
				delete allNobles[i];
			}
		}
		else {
			cerr << "Invalid command recieved. Unable to parse command: " << command << endl;
			exit(1);
		}
	}

}


ifstream openfile() {
	ifstream ifile("nobleWarriors.txt");
	if (!ifile) {
		cerr << "Failed to open nobleWarriors.txt" << endl;
		exit(1);
	}
	return ifile;
}




Noble* findNoble(vector<Noble*>& allNobles, string& name) {
	for (size_t i = 0; i < allNobles.size(); i++) {
		if (name == allNobles[i]->getName()){
			return allNobles[i];
		}
	}
	cerr << "Invalid search query. Noble: " << name << " not found." << endl;
	exit(1);
}

Warrior* findWarrior(vector<Warrior*>& unemployedWarriors, string& name) {
	Warrior* thisWarrior = nullptr;
	for (size_t i = 0; i < unemployedWarriors.size(); i++) {
		if (name == unemployedWarriors[i]->getName()) {
			thisWarrior = unemployedWarriors[i];
			unemployedWarriors.erase(unemployedWarriors.begin() + i); //removes warrior from unemployed list because this function is only called while hiring a warrior
			return thisWarrior;
		}
	}
	cerr << "Invalid search query. Warrior: " << name << " does not exist, or is currently employed." << endl;
	exit(1);
}

void status(vector<Noble*>& allNobles, vector<Warrior*>& unemployedWarriors) {
	cout << "Status" << endl;
	cout << "======" << endl;
	cout << "Nobles: " << endl;
	if (allNobles.size() != 0) {
		cout << allNobles;
	}
	else {
		cout << "None" << endl;
	}
	cout << "Unemployed Warriors: " << endl;
	if (unemployedWarriors.size() != 0) {
		cout << unemployedWarriors;
	}
	else {
		cout << "None" << endl;
	}
}

ostream& operator<<(ostream& os, vector<Noble*>& allNobles) {
	for (size_t i = 0; i < allNobles.size(); i++) {
		allNobles[i]->operator<<(os);
	}
	os << endl;
	return os;
}

ostream& operator<<(ostream& os, vector<Warrior*>& unemployedWarriors) {
	Warrior* thisWarrior = nullptr;
	for (size_t i = 0; i < unemployedWarriors.size(); i++) {
		unemployedWarriors[i]->operator<<(os);
	}
	os << endl;
	return os;
}