#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called with " << name << std::endl;
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->name = ref.name;
	this->hitPoint = ref.hitPoint;
	this->energyPoint = ref.energyPoint;
	this->attackDamage = ref.attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& ref)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->hitPoint = ref.hitPoint;
	this->energyPoint = ref.energyPoint;
	this->attackDamage = ref.attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap highFivesGuys." << std::endl;
}