#pragma once
#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;

public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& ref);
	DiamondTrap& operator=(const DiamondTrap& ref);
	virtual ~DiamondTrap();

	DiamondTrap(std::string name);

	void whoAmI();
	void attack(const std::string& target);

	std::string getName() const;
};

#endif
