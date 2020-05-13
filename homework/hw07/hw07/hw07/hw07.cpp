/*Isaiah Garnett
hw 07, Inheritance*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Protector;

/*  Your classes go here */
class Noble { 
public:
	Noble(const string& name, int strength = 0) : name(name), strength(strength), alive(true) {}
	virtual void defeated() {}
	virtual void fighting() {}
	virtual void updateStrength(int num, int denom = 1) {}
	int getStrength() const { return strength; }
	void setStrength(int newStrength) { strength = newStrength; }
	string getName() const { return name; }
	void kill() { alive = false; }
	bool checkAlive() const {
		return alive;
	}
	void battle(Noble& adversary) {
		cout << name  << " battles " << adversary.name << endl;
		if (alive && adversary.alive) {
			fighting();
			adversary.fighting();
			if (strength > adversary.strength) {
				cout << name << " defeats " << adversary.name << endl;
				adversary.defeated();
				updateStrength(adversary.strength, strength);
			}
			else if (adversary.strength > strength) {
				cout << adversary.name << " defeats " << name << endl;
				defeated();
				adversary.updateStrength(strength, adversary.strength);
			}
			else if (strength == adversary.strength) {
				cout << "Mutual Annihilation: " << name << " and " << adversary.name
					<< " die at each other's hands" << endl;
				defeated();
				adversary.defeated();
			}
		}
		else if (!alive && adversary.alive) {
			cout << "He's dead, " << adversary.name << endl;
		}
		else if (alive && !adversary.alive) {
			cout << "He's dead " << name << endl;
		}
		else {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
	}

private:
	const string name;
	int strength;
	bool alive;
};

class PersonWithStrengthToFight : public Noble {
public:
	PersonWithStrengthToFight(const string& name, int strength) : Noble(name, strength) {}
	void fighting() { return; }
	void defeated() override {
		Noble::kill();
	}
private:
};

class Protector {
public:
	Protector(const string& name, int strength) : name(name), strength(strength) {}
	string getName() const { return name; }
	void setStrength(int newStrength) {
		strength = newStrength;
	}
	int getStrength() const { return strength; }
	Noble* getLord() const { return lord; }
	void setLord(Noble* newLord) { lord = newLord; }
	virtual void defend() = 0;
private:
	const string name;
	int strength;
	Noble* lord;
};

class Lord : public Noble {
public:
	Lord(const string& name) : Noble(name), army() {}
	void defeated() override { Noble::kill(); }
	void updateStrength(int num, int denom) override {
		unsigned lostStrength;
		for (Protector* thisProtector : army) {
			lostStrength = thisProtector->getStrength() * (num/denom);
			thisProtector->setStrength(thisProtector->getStrength() - lostStrength);
		}
	}
	void fighting() {
		for (Protector* thisProtector : army) {
			thisProtector->defend();
		}
	}
	bool hires(Protector& thisProtector) {
		if (Noble::checkAlive()) {
			if (thisProtector.getStrength() != 0) {
				if (thisProtector.getLord()) {
					cout << Noble::getName() << " failed to hire "
						<< thisProtector.getName() << endl;
					return false;
				}
				else {
					thisProtector.setLord(this);
					Noble::setStrength(Noble::getStrength() + thisProtector.getStrength());
					army.push_back(&thisProtector);
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
		
	}
private:
	vector<Protector*> army;
};

class Wizard : public Protector {
public:
	Wizard(const string& name, int strength) : Protector(name, strength) {}
	void defend() override {
		cout << "POOF! " << endl;
	}
private:
};
class Warrior : public Protector {
public:
	Warrior(const string& name, int strength) : Protector(name, strength) {}
	void defend() override {
		cout << Protector::getName() << " says: Take that in the name of my lord, " 
			<< Protector::getLord()->getName() << endl;
	}
private:

};
class Archer : public Warrior {
public:
	Archer(const string& name, int strength) : Warrior(name, strength) {}
	void defend() override {
		cout << "TWANG! ";
		Warrior::defend();
	}
private:

};
class Swordsman : public Warrior {
public:
	Swordsman(const string& name, int strength) : Warrior(name, strength) {}
	void defend() override {
		cout << "CLANG! ";
		Warrior::defend();
	}
private:
};

int main() {
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
}