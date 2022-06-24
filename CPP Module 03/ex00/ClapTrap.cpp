#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "";
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called with " << name << std::endl;
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->name = ref.name;
	this->hitPoint = ref.hitPoint;
	this->energyPoint = ref.energyPoint;
	this->attackDamage = ref.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->hitPoint = ref.hitPoint;
	this->energyPoint = ref.energyPoint;
	this->attackDamage = ref.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoint > 0)
	{
		std::cout << "ClapTrap " << this->name << " ";
		std::cout << "attacks " << target << ", ";
		std::cout << "causing " << this->attackDamage << " ";
		std::cout << "points of damage!" << std::endl;
		this->energyPoint -= 1;
	}
	else
	{
		std::cout << "ClapTrap do not have energy point.." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap takes damage so lose " << amount << "point!" << std::endl;
	if (this->hitPoint < amount)
		this->hitPoint = 0;
	else
		this->hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint > 0)
	{
		std::cout << "ClapTrap repairs itself so get " << amount << "point!" << std::endl;
		this->hitPoint += amount;
		this->energyPoint -= 1;
	}
	else
	{
		std::cout << "ClapTrap do not have energy point.." << std::endl;
	}
}