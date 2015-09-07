/*
 * Warrior.cpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#include "Warrior.hpp"

/*static*/ const unsigned long Warrior::cooldown = 4;
/*static*/ const unsigned long Warrior::damage = 35;

Warrior::Warrior() :
		Fighter("Warrior"), latestAttackTime(-1)
{
	// TODO Auto-generated constructor stub

}

Warrior::Warrior(const Warrior& aWarrior) :
		Fighter(aWarrior), latestAttackTime(aWarrior.latestAttackTime)
{
}

Warrior::~Warrior()
{
	// TODO Auto-generated destructor stub
}

/**
 * Attack monster, monster can't be dead.
 */
void Warrior::attack(Monster& monster)
{
	if (latestAttackTime < 0 ||
		latestAttackTime + cooldown <= Fighter::getSeconds())
	{
		Fighter::attack(monster, damage);
		latestAttackTime = Fighter::getSeconds();
	}
}

void Warrior::rest()
{
	latestAttackTime = -1;
}

Warrior& Warrior::operator =(const Warrior& aWarrior)
{
	Fighter::operator =(aWarrior);
	latestAttackTime = aWarrior.latestAttackTime;
	return *this;
}
