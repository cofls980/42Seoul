#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"

class HumanB {

private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack();
	~HumanB();
};

#endif