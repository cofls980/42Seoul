#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name)
{
	std::cout << "ScavTrap constructor called with " << name << std::endl;
	this->name = _name;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "Default";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called with " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref)
{
	std::cout << "ScavTrap copy constructor called" << ref.getName() << std::endl;
	this->name = ref.getName();
	this->hitPoint = ref.getHitPoint();
	this->energyPoint = ref.getEnergyPoint();
	this->attackDamage = ref.getAttackDamage();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
	std::cout << "ScavTrap copy assignment operator called" << ref.getName() << std::endl;
	this->name = ref.getName();
	this->hitPoint = ref.getHitPoint();
	this->energyPoint = ref.getEnergyPoint();
	this->attackDamage = ref.getAttackDamage();
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoint < 1)
	{
		std::cout << "ScavTrap do not have hit points anymore." << std::endl;
		return ;
	}
	if (this->energyPoint < 1)
	{
		std::cout << "ScavTrap do not have energy points anymore." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " ";
	std::cout << "attacks " << target << ", ";
	std::cout << "causing " << this->attackDamage << " ";
	std::cout << "hit points of damage!" << std::endl;
	this->energyPoint -= 1;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}