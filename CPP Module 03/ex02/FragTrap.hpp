#pragma once
#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap& ref);
	FragTrap& operator=(const FragTrap& ref);
	virtual ~FragTrap();

	FragTrap(std::string name);
	
	void highFivesGuys(void);
};

#endif