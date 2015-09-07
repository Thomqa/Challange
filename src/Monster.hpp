/*
 * Monster.hpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#ifndef MONSTER_HPP_
#define MONSTER_HPP_

#include <string>

class Monster
{
public:
	Monster(std::string aName, long aHitpoints);
	Monster(const Monster& aMonster);
	virtual ~Monster();

	unsigned long attack(unsigned long damage);
	bool isDead();

	Monster& operator=(const Monster& aMonster);
	const std::string& getName() const;

private:
	Monster();

	std::string name;
	long hitpoints;
};

#endif /* MONSTER_HPP_ */
