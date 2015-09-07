/*
 * Monster.cpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#include "Monster.hpp"
#include <cstdlib>
#include <iostream>

Monster::Monster(std::string aName, long aHitpoints) :
		name(aName), hitpoints(aHitpoints)
{
}

Monster::Monster(const Monster& aMonster) :
		name(aMonster.name), hitpoints(aMonster.hitpoints)
{
}

/**
 * Returns overkill when death. Else 0.
 */
unsigned long Monster::attack(unsigned long damage)
{
	if (!isDead())
	{
		hitpoints -= damage;
		if (hitpoints <= 0) {
			std::cout << "lost " << damage - abs(hitpoints) << " hp, 0 hp left. KILLED (overkill: " << abs(hitpoints) << " hp)" << std::endl;
			return abs(hitpoints);
		}
		std::cout << "lost " << damage << " hp, " << hitpoints << " hp left." << std::endl;
	}
	else
	{
		std::cout << "Oops, monster is already death..." << std::endl;
	}
	return 0;
}

bool Monster::isDead()
{
	return (hitpoints <= 0);
}

Monster& Monster::operator =(const Monster& aMonster)
{
	name = aMonster.name;
	hitpoints = aMonster.hitpoints;
	return *this;
}

Monster::Monster()
{
	//No non-defined monsters allowed.
}

Monster::~Monster()
{
	// TODO Auto-generated destructor stub
}

const std::string& Monster::getName() const
{
	return name;
}
