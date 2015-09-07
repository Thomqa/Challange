/*
 * Fighter.hpp
 *
 *  Created on: 7 sep. 2015
 *      Author: thoma
 */

#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_
#include "Monster.hpp"
#include <string>

class Fighter
{
public:
	Fighter(std::string aType);
	Fighter(const Fighter& aFighter);
	virtual ~Fighter();

	virtual void attack(Monster& monster) = 0;
	virtual void rest() = 0;
	virtual Fighter& operator=(const Fighter& aFighter);

	static void incrementTime();
	static unsigned long getSeconds();
	unsigned long getOverkillHitpoints() const;
	const std::string& getType() const;

protected:
	void attack(Monster& monster, unsigned long damage);

	static unsigned long seconds;

private:
	std::string type;
	unsigned long overkillHitpoints;
};

#endif /* FIGHTER_HPP_ */
