#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap();
	FragTrap(const FragTrap& ref);
	FragTrap& operator=(const FragTrap& ref);
	~FragTrap();
	
	void highFivesGuys(void);
};

#endif