/*Isaiah Garnett
hw04, pointer basics
knights and nobles...*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Warrior;
class Noble;


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

	void display() {
		cout << name << " has an army of " << army.size() << endl;
		for (Warrior* thisWarrior : army) {
			cout << thisWarrior->getName() << ": " << thisWarrior->getStrength() << endl;
		}
	}

	void updateArmyStrength(const double ratio) {
		int lostStrength;
		for (Warrior* thisPoorSod : army) {
			lostStrength = thisPoorSod->getStrength()*ratio;
			thisPoorSod->setStrength(thisPoorSod->getStrength()-lostStrength);
		}
	}

	bool hire(Warrior& thisWarrior) {
		if (thisWarrior.getStrength() != 0) {
			if (thisWarrior.getLord()) {
				cout << this->name << " failed to hire " << thisWarrior.getName() << ". They have sworn fealty to Lord "
					<< thisWarrior.getLord()->getName() << endl;
				return false;
			}
			else {
				thisWarrior.setLord(this);
				army.push_back(&thisWarrior);
				armyStrength += thisWarrior.getStrength();
				return true;
			}
		}
		else {
			cout << this->name << " failed to hire " << thisWarrior.getName() << ". He's dead " << this->name << endl;
			return false;
		}
	}

	void fire(Warrior& thisWarrior) {
		int i = 0;
		for (Warrior*& soughtWarrior : army) {
			if (&thisWarrior == soughtWarrior) {
				army.erase(army.begin() + i);
			}
			i++;
		}
		cout << thisWarrior.getName() << ", you're fired! --" << this->name << endl;
	}

	void battle(Noble& adversary) {
		cout << this->name << " battles " << adversary.getName() << endl;
		if ((this->armyStrength!=0) && (adversary.getArmyStrength()!=0)) {
			if (this->armyStrength > adversary.getArmyStrength()) {
				cout << this->name << " defeats " << adversary.getName() << endl;
				this->updateArmyStrength(adversary.getArmyStrength() / this->armyStrength);
				adversary.defeated();
			}
			else if (adversary.getArmyStrength() > this->armyStrength) {
				cout << adversary.getName() << " defeasts " << this->name << endl;
				adversary.updateArmyStrength(this->armyStrength/adversary.getArmyStrength());
				this->defeated();
			}
			else if (adversary.getArmyStrength() == this->armyStrength) {
				cout << "Mutual Annihilation: " << this->name << " and " << adversary.getName()
					<< " die at each other's hands" << endl;
				this->defeated();
				adversary.defeated();
			}
		}
		else if ((this->armyStrength == 0)&&(adversary.getArmyStrength()!=0)){
			cout << "He's dead " << adversary.getName() << endl;
		}
		else if ((this->armyStrength!=0)&&adversary.getArmyStrength()==0) {
			cout << "He's dead " << this->name << endl;
		}
		else {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
	}

private:
	const string name;
	int armyStrength;
	vector<Warrior*> army;
	bool alive;
};



int main() {

	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);


	// NEW OUTPUT CODE
	cout << "==========\n"
		<< "Status after all battles, etc.\n";
	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

}
