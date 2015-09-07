/*
 * Rogue.hpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#ifndef ROGUE_HPP_
#define ROGUE_HPP_

#define WEAPON_COUNT 2

#include "Fighter.hpp"

class Rogue: public Fighter
{
public:
	Rogue();
	Rogue(const Rogue& aRogue);
	virtual ~Rogue();

	void attack(Monster& monster);
	void rest();

	Rogue& operator=(const Rogue& aRogue);

private:
	static const unsigned short cooldown[WEAPON_COUNT];
	static const unsigned short hitpoints[WEAPON_COUNT];

	unsigned long nextAttackTime[WEAPON_COUNT];
};

#endif /* ROGUE_HPP_ */
