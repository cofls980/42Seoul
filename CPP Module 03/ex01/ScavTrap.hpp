#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap();
	ScavTrap(const ScavTrap& ref);
	ScavTrap& operator=(const ScavTrap& ref);
	~ScavTrap();
	
	void attack(const std::string& target);
	void guardGate();
};

#endif