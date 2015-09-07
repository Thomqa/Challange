/*
 * Warrior.hpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Fighter.hpp"

class Warrior: public Fighter
{
public:
	Warrior();
	Warrior(const Warrior& aWarrior);
	virtual ~Warrior();

	void attack(Monster& monster);
	void rest();

	Warrior& operator=(const Warrior& aWarrior);
private:
	static const unsigned long cooldown;
	static const unsigned long damage;

	long latestAttackTime;
};

#endif /* WARRIOR_HPP_ */
