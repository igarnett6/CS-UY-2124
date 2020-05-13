#pragma once
#include <string>
#include <iostream>
#include "Noble.h"

namespace WarriorCraft {
	class Noble;

	class Warrior {
		friend std::ostream& operator<<(std::ostream& os, const Warrior& warrior);

	public:
		Warrior(const std::string& name, int strength);
		std::string getName() const;
		void setStrength(int newStrength);
		int getStrength();
		Noble* getLord() const;
		void setLord(Noble* newLord);
		void runaway();

	private:
		const std::string name;
		int strength;
		Noble* lord;
	};
}
