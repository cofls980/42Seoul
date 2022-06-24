#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	unsigned int hitPoint;
	unsigned int energyPoint;
	unsigned int attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& ref);
	ClapTrap& operator=(const ClapTrap& ref);
	virtual ~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName();
	unsigned int getHitPoint();
	unsigned int getEnergyPoint();
	unsigned int getAttackDamage();

	void setName(std::string name);
	void setHitPoint(unsigned int hitPoint);
	void setEnergyPoint(unsigned int energyPoint);
	void setAttackDamage(unsigned int attackDamage);
};

#endif