#pragma once
#include "Warrior.h"
#include <vector>

namespace WarriorCraft {
	class Warrior;


	class Noble {
		friend std::ostream& operator<<(std::ostream& os, const Noble& noble);

	public:
		Noble(const std::string& name);
		int getArmyStrength() const;
		std::string getName() const;
		void defeated();
		bool checkAlive() const;
		void updateArmyStrength(const double ratio);
		void hire(Warrior& thisWarrior);
		void fire(const std::string& warriorName, bool ranaway = false);
		void battle(Noble& adversary);
		size_t findWarrior(const std::string& warriorName);



	private:
		const std::string name;
		int armyStrength;
		std::vector<Warrior*> army;
		std::vector<Warrior*> unemployed;
		bool alive;
	};
}
