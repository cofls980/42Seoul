#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called with " << name << std::endl;
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->name = ref.name;
	this->hitPoint = ref.hitPoint;
	this->energyPoint = ref.energyPoint;
	this->attackDamage = ref.attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->hitPoint = ref.hitPoint;
	this->energyPoint = ref.energyPoint;
	this->attackDamage = ref.attackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoint > 0)
	{
		std::cout << "ScavTrap " << this->name << " ";
		std::cout << "attacks " << target << ", ";
		std::cout << "causing " << this->attackDamage << " ";
		std::cout << "points of damage!" << std::endl;
		this->energyPoint -= 1;
	}
	else
	{
		std::cout << "ScavTrap do not have energy point.." << std::endl;
	}
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}