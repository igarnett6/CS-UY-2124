//
//
//
//
//class Noble {
//public:
//	Noble(const string& name, int strength = -1) {}
//private:
//	string name;
//	int strength;
//};
//class Protector {
//public:
//	Protector(const string& name, int strength) : name(name), strength(strength) {}
//	string getName() const { return name; }
//	int getStrength() const { return strength; }
//private:
//	const string name;
//	int strength;
//};
//
//class Lord {
//public:
//	Lord(const string& name) : name(name) { int armyStrength(0); bool alive(true); }
//	int getArmyStrength() const { return armyStrength; }
//
//	string getName() const { return name; };
//
//	void defeated() {
//		armyStrength = 0;
//		for (Protector*& thisProtector : army) {
//			thisProtector->setStrength(0);
//		}
//		alive = false;
//	}
//
//	bool checkAlive() const {
//		return alive;
//	}
//
//	void display() {
//		cout << name << " has an army of " << army.size() << endl;
//		for (Protector* thisProtector : army) {
//			cout << thisProtector->getName() << ": " << thisProtector->getStrength() << endl;
//		}
//	}
//
//	void updateArmyStrength(const double ratio) {
//		int lostStrength;
//		for (Protector* thisPoorSod : army) {
//			lostStrength = thisPoorSod->getStrength() * ratio;
//			thisPoorSod->setStrength(thisPoorSod->getStrength() - lostStrength);
//		}
//	}
//
//	bool hire(Protector & thisProtector) {
//		if (thisProtector.getStrength() != 0) {
//			if (thisProtector.getLord()) {
//				cout << this->name << " failed to hire " << thisProtector.getName() << ". They have sworn fealty to Lord "
//					<< thisProtector.getLord()->getName() << endl;
//				return false;
//			}
//			else {
//				thisProtector.setLord(this);
//				army.push_back(&thisProtector);
//				armyStrength += thisProtector.getStrength();
//				return true;
//			}
//		}
//		else {
//			cout << this->name << " failed to hire " << thisProtector.getName() << ". He's dead " << this->name << endl;
//			return false;
//		}
//	}
//
//	void fire(Protector & thisProtector) {
//		int i = 0;
//		for (Protector*& soughtProtector : army) {
//			if (&thisProtector == soughtProtector) {
//				army.erase(army.begin() + i);
//			}
//			i++;
//		}
//		cout << thisProtector.getName() << ", you're fired! --" << this->name << endl;
//	}
//
//	void battle(Lord & adversary) {
//		cout << this->name << " battles " << adversary.getName() << endl;
//		if ((this->armyStrength != 0) && (adversary.getArmyStrength() != 0)) {
//			if (this->armyStrength > adversary.getArmyStrength()) {
//				cout << this->name << " defeats " << adversary.getName() << endl;
//				this->updateArmyStrength(adversary.getArmyStrength() / this->armyStrength);
//				adversary.defeated();
//			}
//			else if (adversary.getArmyStrength() > this->armyStrength) {
//				cout << adversary.getName() << " defeasts " << this->name << endl;
//				adversary.updateArmyStrength(this->armyStrength / adversary.getArmyStrength());
//				this->defeated();
//			}
//			else if (adversary.getArmyStrength() == this->armyStrength) {
//				cout << "Mutual Annihilation: " << this->name << " and " << adversary.getName()
//					<< " die at each other's hands" << endl;
//				this->defeated();
//				adversary.defeated();
//			}
//		}
//		else if ((this->armyStrength == 0) && (adversary.getArmyStrength() != 0)) {
//			cout << "He's dead " << adversary.getName() << endl;
//		}
//		else if ((this->armyStrength != 0) && adversary.getArmyStrength() == 0) {
//			cout << "He's dead " << this->name << endl;
//		}
//		else {
//			cout << "Oh, NO! They're both dead! Yuck!" << endl;
//		}
//	}
//
//private:
//	const string name;
//	int armyStrength;
//	vector<Protector*> army;
//	bool alive;
//};
