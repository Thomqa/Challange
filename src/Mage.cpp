/*
 * Mage.cpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#include "Mage.hpp"

/*static*/ const unsigned short Mage::CASTING_TIME = 2;
/*static*/ const unsigned short Mage::ATTACK_INTERVAL = 8;
/*static*/ const unsigned short Mage::DAMAGE = 80;

Mage::Mage() :
	Fighter("Mage"), ms(MAGE_IDLE), nextStateTime(0)
{
	// TODO Auto-generated constructor stub

}

Mage::Mage(const Mage& aMage) :
	Fighter(aMage), ms(aMage.ms), nextStateTime(aMage.nextStateTime)
{
}

Mage::~Mage()
{
	// TODO Auto-generated destructor stub
}

void Mage::attack(Monster& monster)
{
	if (!monster.isDead())
	{
		switch(ms)
		{
		case MAGE_IDLE:
			ms = MAGE_CASTING;
			nextStateTime = Fighter::getSeconds() + CASTING_TIME;
			break;
		case MAGE_CASTING:
			if (nextStateTime <= Fighter::getSeconds())
			{
				ms = MAGE_ATTACKING;
				//Don't break.
			}
			else
			{
				break;
			}
		case MAGE_ATTACKING:
			if (nextStateTime <= Fighter::getSeconds())
			{
				Fighter::attack(monster, DAMAGE);
				nextStateTime = Fighter::getSeconds() + ATTACK_INTERVAL;
			}
			break;
		default:
			ms = MAGE_IDLE;
			break;
		}
	}
}

void Mage::rest()
{
	ms = MAGE_IDLE;
	nextStateTime = 0;
}

Mage& Mage::operator =(const Mage& aMage)
{
	Fighter::operator =(aMage);
	ms = aMage.ms;
	nextStateTime = aMage.nextStateTime;
	return *this;
}










