/*Isaiah Garnett
hw06, Separate Compilaiton
Using namespace WarriorCraft*/



#include <iostream>
#include <vector>
#include <string>
using namespace std;




class Noble;
class Warrior;


//class Warrior {
//	friend ostream& operator<<(ostream& os, const Warrior& warrior);
//
//public:
//	Warrior(const string& name, int strength);
//	string getName() const;
//	void setStrength(int newStrength);
//	int getStrength();
//	Noble* getLord() const;
//	void setLord(Noble* newLord);
//	void runaway();
//
//	
//private:
//	const string name;
//	int strength;
//	Noble* lord;
//};


//class Noble {
//	friend ostream& operator<<(ostream& os, const Noble& noble);
//
//public:
//	Noble(const string& name);
//	int getArmyStrength() const;
//	string getName() const;
//	void defeated();
//	bool checkAlive() const;
//	void updateArmyStrength(const double ratio);
//	void hire(Warrior& thisWarrior);
//	void fire(const string& warriorName, bool ranaway = false);
//	void battle(Noble& adversary);
//	size_t findWarrior(const string& warriorName);
//	~Noble();
//	
//
//private:
//	const string name;
//	int armyStrength;
//	vector<Warrior*> army;
//	bool alive;
//};




//Warrior method definitions
//ostream& operator<<(ostream& os, const Warrior& warrior) {
//	os << warrior.name << ": " << warrior.strength << endl;
//	return os;
//}
//Warrior::Warrior(const string& name, int strength) : name(name), strength(strength) {}
//string Warrior::getName() const { return name; }
//void Warrior::setStrength(int newStrength) {
//	strength = newStrength;
//}
//int Warrior::getStrength() { return strength; }
//Noble* Warrior::getLord() const { return lord; }
//void Warrior::setLord(Noble* newLord) { lord = newLord; }
//void Warrior::runaway() {
//	lord->fire(name, true);
//	lord = nullptr;
//}
//Warrior method definitions


//Noble method definitions
//ostream& operator<<(ostream& os, const Noble& noble) {
//	os << noble.name << " has an army of " << noble.army.size() << endl;
//	for (size_t i = 0; i < noble.army.size(); i++) {
//		&noble.army[i];
//	}
//	return os;
//
//}
//Noble::Noble(const string& name) : name(name) { int armyStrength(0); bool alive(true); }
//int Noble::getArmyStrength() const { return armyStrength; }
//string Noble::getName() const { return name; };
//void Noble::defeated() {
//	armyStrength = 0;
//	for (Warrior*& thisWarrior : army) {
//		thisWarrior->setStrength(0);
//	}
//	alive = false;
//}
//bool Noble::checkAlive() const {
//	return alive;
//}
//void Noble::updateArmyStrength(const double ratio) {
//	int lostStrength;
//	for (Warrior* thisPoorSod : army) {
//		lostStrength = thisPoorSod->getStrength()*ratio;
//		thisPoorSod->setStrength(thisPoorSod->getStrength() - lostStrength);
//	}
//}
//void Noble::hire(Warrior& thisWarrior) {
//	if (thisWarrior.getStrength() != 0) {
//		thisWarrior.setLord(this);
//		Warrior* newWarrior;
//		newWarrior = &thisWarrior;
//		army.push_back(newWarrior);
//		armyStrength += thisWarrior.getStrength();
//	}
//	else {
//		cout << name << " failed to hire " << thisWarrior.getName() << ". He's dead " << name << endl;
//	}
//}
//void Noble::fire(const string& warriorName, bool ranaway) {
//	int i = 0;
//	size_t origArmySize = army.size();
//	Warrior* thisWarrior = nullptr;
//	size_t warrInd = findWarrior(warriorName);
//	if (warrInd != army.size()) {
//		if (ranaway) {
//			cout << army[warrInd]->getName() << ", you're fired! --" << this->name << endl;
//		}
//		else {
//			cout << warriorName << " fless in terror, abandoning his lord, " << name << endl;
//		}
//		army.erase(army.begin() + i);
//	}
//}
//void Noble::battle(Noble& adversary) {
//	cout << this->name << " battles " << adversary.getName() << endl;
//	if ((this->armyStrength != 0) && (adversary.getArmyStrength() != 0)) {
//		if (this->armyStrength > adversary.getArmyStrength()) {
//			cout << this->name << " defeats " << adversary.getName() << endl;
//			this->updateArmyStrength(adversary.getArmyStrength() / this->armyStrength);
//			adversary.defeated();
//		}
//		else if (adversary.getArmyStrength() > this->armyStrength) {
//			cout << adversary.getName() << " defeasts " << this->name << endl;
//			adversary.updateArmyStrength(this->armyStrength / adversary.getArmyStrength());
//			this->defeated();
//		}
//		else if (adversary.getArmyStrength() == this->armyStrength) {
//			cout << "Mutual Annihilation: " << this->name << " and " << adversary.getName()
//				<< " die at each other's hands" << endl;
//			this->defeated();
//			adversary.defeated();
//		}
//	}
//	else if ((this->armyStrength == 0) && (adversary.getArmyStrength() != 0)) {
//		cout << "He's dead " << adversary.getName() << endl;
//	}
//	else if ((this->armyStrength != 0) && adversary.getArmyStrength() == 0) {
//		cout << "He's dead " << this->name << endl;
//	}
//	else {
//		cout << "Oh, NO! They're both dead! Yuck!" << endl;
//	}
//}
//size_t Noble::findWarrior(const string& warriorName) {
//	for (size_t i = 0; i < army.size(); i++) {
//		if (army[i]->getName() == warriorName) {
//			return i;
//		}
//	}
//	return army.size();
//}
//Noble::~Noble() {
//	for (size_t i = 0; i < army.size(); i++) {
//		delete army[i];
//	}
//}

//Noble method definitions





//int main() {
//	Noble art("King Arthur");
//	Noble lance("Lancelot du Lac");
//	Noble jim("Jim");
//	Noble linus("Linus Torvalds");
//	Noble billie("Bill Gates");
//
//	Warrior cheetah("Tarzan", 10);
//	Warrior wizard("Merlin", 15);
//	Warrior theGovernator("Conan", 12);
//	Warrior nimoy("Spock", 15);
//	Warrior lawless("Xena", 20);
//	Warrior mrGreen("Hulk", 8);
//	Warrior dylan("Hercules", 3);
//
//	jim.hire(nimoy);
//	lance.hire(theGovernator);
//	art.hire(wizard);
//	lance.hire(dylan);
//	linus.hire(lawless);
//	billie.hire(mrGreen);
//	art.hire(cheetah);
//
//	cout << jim << endl;
//	cout << lance << endl;
//	cout << art << endl;
//	cout << linus << endl;
//	cout << billie << endl;
//
//	cheetah.runaway();
//	cout << art << endl;
//
//	art.battle(lance);
//	jim.battle(lance);
//	linus.battle(billie);
//	billie.battle(lance);
//}