#include "Noble.h"
using namespace std;
namespace WarriorCraft {
	ostream& operator<<(ostream& os, const Noble& noble) {
		os << noble.name << " has an army of " << noble.army.size() << endl;
		for (size_t i = 0; i < noble.army.size(); i++) {
			operator<<(os, *noble.army[i]);
		}
		return os;

	}
	Noble::Noble(const string& name) : name(name) { int armyStrength(0); bool alive(true); }
	int Noble::getArmyStrength() const { return armyStrength; }
	string Noble::getName() const { return name; };
	void Noble::defeated() {
		armyStrength = 0;
		for (Warrior*& thisWarrior : army) {
			thisWarrior->setStrength(0);
		}
		alive = false;
	}
	bool Noble::checkAlive() const {
		return alive;
	}
	void Noble::updateArmyStrength(const double ratio) {
		int lostStrength;
		for (Warrior* thisPoorSod : army) {
			lostStrength = thisPoorSod->getStrength()*ratio;
			thisPoorSod->setStrength(thisPoorSod->getStrength() - lostStrength);
		}
	}
	void Noble::hire(Warrior& thisWarrior) {
		if (thisWarrior.getStrength() != 0) {
			thisWarrior.setLord(this);
			Warrior* newWarrior;
			newWarrior = &thisWarrior;
			army.push_back(newWarrior);
			armyStrength += thisWarrior.getStrength();
		}
		else {
			cout << name << " failed to hire " << thisWarrior.getName() << ". He's dead " << name << endl;
		}
	}
	void Noble::fire(const string& warriorName, bool ranaway) {
		int i = 0;
		size_t origArmySize = army.size();
		Warrior* thisWarrior = nullptr;
		size_t warrInd = findWarrior(warriorName);
		if (warrInd != army.size()) {
			if (ranaway) {
				cout << army[warrInd]->getName() << ", you're fired! --" << this->name << endl;
			}
			else {
				cout << warriorName << " fless in terror, abandoning his lord, " << name << endl;
			}
			unemployed.push_back(army[i]);
			army.erase(army.begin() + i);
		}
	}
	void Noble::battle(Noble& adversary) {
		cout << this->name << " battles " << adversary.getName() << endl;
		if ((this->armyStrength != 0) && (adversary.getArmyStrength() != 0)) {
			if (this->armyStrength > adversary.getArmyStrength()) {
				cout << this->name << " defeats " << adversary.getName() << endl;
				this->updateArmyStrength(adversary.getArmyStrength() / this->armyStrength);
				adversary.defeated();
			}
			else if (adversary.getArmyStrength() > this->armyStrength) {
				cout << adversary.getName() << " defeats " << this->name << endl;
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
	size_t Noble::findWarrior(const string& warriorName) {
		for (size_t i = 0; i < army.size(); i++) {
			if (army[i]->getName() == warriorName) {
				return i;
			}
		}
		return army.size();
	}
}

