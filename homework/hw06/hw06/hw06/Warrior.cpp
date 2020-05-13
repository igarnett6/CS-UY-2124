#include "Warrior.h"
using namespace std;

namespace WarriorCraft {
	ostream& operator<<(ostream& os, const Warrior& warrior) {
		os << warrior.name << ": " << warrior.strength << endl;
		return os;
	}
	Warrior::Warrior(const string& name, int strength) : name(name), strength(strength) {}
	string Warrior::getName() const { return name; }
	void Warrior::setStrength(int newStrength) {
		strength = newStrength;
	}
	int Warrior::getStrength() { return strength; }
	Noble* Warrior::getLord() const { return lord; }
	void Warrior::setLord(Noble* newLord) { lord = newLord; }
	void Warrior::runaway() {
		lord->fire(name, true);
		lord = nullptr;
	}
	
}
