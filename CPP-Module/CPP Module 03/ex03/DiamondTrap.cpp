#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "Default";
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap constructor called with " << name << std::endl;
	this->name = name;
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref)
{
	std::cout << "DiamondTrap copy constructor called with " << ref.getName() << std::endl;
	this->name = ref.getName();
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoint = ref.getHitPoint();
	this->energyPoint = ref.getEnergyPoint();
	this->attackDamage = ref.getAttackDamage();
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref)
{
	std::cout << "DiamondTrap copy assignment operator called with " << ref.getName() << std::endl;
	this->name = ref.getName();
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoint = ref.getHitPoint();
	this->energyPoint = ref.getEnergyPoint();
	this->attackDamage = ref.getAttackDamage();
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called with " << this->getName() << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->getName() << " in DiamondTrap and ";
	std::cout << ClapTrap::name << " in ClapTrap." << std::endl;
}

std::string DiamondTrap::getName() const
{
	return this->name;
}