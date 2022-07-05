#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"

class HumanB {

private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(std::string _name);
	void setWeapon(Weapon &_weapon);
	void attack();
	~HumanB();
};

#endif