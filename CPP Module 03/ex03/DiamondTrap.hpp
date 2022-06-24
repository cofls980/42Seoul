#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& ref);
	DiamondTrap& operator=(const DiamondTrap& ref);
	~DiamondTrap();

	void whoAmI();
	void attack(const std::string& target);
};

#endif
