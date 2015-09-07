/*
 * Fighter.cpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#include "Fighter.hpp"
#include <iostream>

/*static*/ unsigned long Fighter::seconds = 0;

Fighter::Fighter(std::string aType) :
		type(aType), overkillHitpoints(0)
{
}

Fighter::Fighter(const Fighter& aFighter) :
		type(aFighter.type), overkillHitpoints(aFighter.overkillHitpoints)
{
}

Fighter::~Fighter()
{
	// TODO Auto-generated destructor stub
}

void Fighter::attack(Monster& monster, unsigned long damage)
{
	std::cout << type << " attacks " << monster.getName() << ": ";
	overkillHitpoints += monster.attack(damage);
}

Fighter& Fighter::operator =(const Fighter& aFighter)
{
	type = aFighter.type;
	overkillHitpoints = aFighter.overkillHitpoints;
	return *this;
}

/*static*/ void Fighter::incrementTime()
{
	++seconds;
}

/*static*/ unsigned long Fighter::getSeconds()
{
	return seconds;
}

unsigned long Fighter::getOverkillHitpoints() const
{
	return overkillHitpoints;
}

const std::string& Fighter::getType() const
{
	return type;
}
