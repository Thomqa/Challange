/*
 * fibonacci.cpp
 *
 *  Created on: 1 sep. 2015
 *      Author: thoma
 */

#include <iostream>
#include <vector>

#include "Monster.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Rogue.hpp"

int main(int argc, char **argv) {
	std::vector<Monster> dungeonMonsters {Monster("Monster 1", 300),
		Monster("Monster 2", 600), Monster("Monster 3", 850),
		Monster("Monster 4", 900), Monster("Monster 5", 1100),
		Monster("Bossman", 3500)};
	std::vector<Fighter*> heroes {(new Warrior()),
		(new Mage()), new Rogue()};

	for (Monster m : dungeonMonsters)
	{
		std::cout << "\n\rLooking for new monster..." << std::endl;
		while (!m.isDead())
		{
			for (Fighter* f : heroes)
			{
				f->attack(m);
			}
			Fighter::incrementTime();
		}
		// Our heroes take a rest after each fight.
		for (Fighter* f : heroes)
		{
			f->rest();
		}
	}

	std::cout << std::endl << "Dungeon cleared!" << std::endl;
	for (Fighter* f : heroes)
	{
		std::cout << f->getType() << "'s overkill = " << f->getOverkillHitpoints() << std::endl;
	}

	return 0;
}
