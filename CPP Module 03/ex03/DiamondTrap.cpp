#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "";
	ClapTrap::name = name + "_clap_name";
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called with " << name << std::endl;
	this->name = name;
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref) : ClapTrap(ref), ScavTrap(ref), FragTrap(ref)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = ref;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->hitPoint = ref.hitPoint;
	this->energyPoint = ref.energyPoint;
	this->attackDamage = ref.attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << " in DiamondTrap and ";
	std::cout << ClapTrap::name << " in ClapTrap." << std::endl;
}