/*
 * Rogue.cpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#include "Rogue.hpp"
#define WEAPON_COUNT 2

/*static*/ const unsigned short Rogue::cooldown[WEAPON_COUNT] = {4, 3};
/*static*/ const unsigned short Rogue::hitpoints[WEAPON_COUNT] = {30, 20};

Rogue::Rogue() :
		Fighter("Rogue")
{
	for (unsigned int i = 0; i < WEAPON_COUNT; ++i)
	{
		nextAttackTime[i] = 0;
	}

}

Rogue::Rogue(const Rogue& aRogue) :
		Fighter(aRogue)
{
	for (unsigned int i = 0; i < WEAPON_COUNT; ++i)
	{
		nextAttackTime[i] = aRogue.nextAttackTime[i];
	}
}

Rogue::~Rogue()
{
	// TODO Auto-generated destructor stub
}

void Rogue::attack(Monster& monster)
{
	if (!monster.isDead())
	{
		for (unsigned short w = 0; w < WEAPON_COUNT; ++w)
		{
			if (nextAttackTime[w] <= Fighter::getSeconds())
			{
				Fighter::attack(monster, hitpoints[w]);
				nextAttackTime[w] = Fighter::getSeconds() + cooldown[w];
			}
		}
	}
}

void Rogue::rest()
{
	for (unsigned int i = 0; i < WEAPON_COUNT; ++i)
	{
		nextAttackTime[i] = 0;
	}
}

Rogue& Rogue::operator =(const Rogue& aRogue)
{
	Fighter::operator =(aRogue);
	for (unsigned int i = 0; i < WEAPON_COUNT; ++i)
	{
		nextAttackTime[i] = aRogue.nextAttackTime[i];
	}
	return *this;
}
