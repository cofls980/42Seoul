#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called with " << name << std::endl;
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "Default";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called with " << this->getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref)
{
	std::cout << "FragTrap copy constructor called with " << ref.getName() << std::endl;
	this->name = ref.getName();
	this->hitPoint = ref.getHitPoint();
	this->energyPoint = ref.getEnergyPoint();
	this->attackDamage = ref.getAttackDamage();
}

FragTrap& FragTrap::operator=(const FragTrap& ref)
{
	std::cout << "FragTrap copy assignment operator called with " << ref.getName() << std::endl;
	this->name = ref.getName();
	this->hitPoint = ref.getHitPoint();
	this->energyPoint = ref.getEnergyPoint();
	this->attackDamage = ref.getAttackDamage();
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " HIGH FIVES!" << std::endl;
}