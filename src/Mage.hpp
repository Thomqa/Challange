/*
 * Mage.hpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Fighter.hpp"

enum MageState {MAGE_IDLE, MAGE_CASTING, MAGE_ATTACKING};

class Mage: public Fighter
{
public:
	Mage();
	Mage(const Mage& aMage);
	virtual ~Mage();

	void attack(Monster& monster);
	void rest();

	Mage& operator=(const Mage& aMage);

private:
	static const unsigned short CASTING_TIME;
	static const unsigned short ATTACK_INTERVAL;
	static const unsigned short DAMAGE;

	MageState ms;
	unsigned long nextStateTime;
};

#endif /* MAGE_HPP_ */
