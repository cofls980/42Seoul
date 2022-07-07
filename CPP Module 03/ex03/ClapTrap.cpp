#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called with " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
	std::cout << "ClapTrap copy constructor called with " << ref.getName() << std::endl;
	this->name = ref.getName();
	this->hitPoint = ref.getHitPoint();
	this->energyPoint = ref.getEnergyPoint();
	this->attackDamage = ref.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
	std::cout << "ClapTrap copy assignment operator called with " << ref.getName() << std::endl;
	this->name = ref.getName();
	this->hitPoint = ref.getHitPoint();
	this->energyPoint = ref.getEnergyPoint();
	this->attackDamage = ref.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called with " << this->getName() << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoint < 1)
	{
		std::cout << "ClapTrap named " << this->getName() << " do not have hit points anymore. It was dead" << std::endl;
		return ;
	}
	if (this->energyPoint < 1)
	{
		std::cout << "ClapTrap named " << this->getName() << " do not have energy points anymore." << std::endl;
		return ;
	}
	std::cout << "ClapTrap named " << this->getName() << " ";
	std::cout << "attacks " << target << ", ";
	std::cout << "causing " << this->attackDamage << " ";
	std::cout << "hit points of damage!" << std::endl;
	this->energyPoint -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint < 1)
	{
		std::cout << "ClapTrap named " << this->getName() << " do not have hit points anymore. It was dead" << std::endl;
		return ;
	}
	if (this->hitPoint <= amount)
	{
		std::cout << "ClapTrap named " << this->getName() << " takes damage and loses all hit points.. and now it is dead" << std::endl;
		this->hitPoint = 0;
	}
	else
	{
		std::cout << "ClapTrap named " << this->getName() << " takes damage so lose " << amount << " hit points.." << std::endl;
		this->hitPoint -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint < 1)
	{
		std::cout << "ClapTrap named " << this->getName() << " do not have hit points anymore. It was dead" << std::endl;
		return ;
	}
	if (this->energyPoint < 1)
	{
		std::cout << "ClapTrap named " << this->getName() << " do not have energy points anymore." << std::endl;
		return ;
	}
	if (this->hitPoint == 100)
	{
		std::cout << "ClapTrap named " << this->getName() << " has full hit points." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap named " << this->getName() << " repairs itself so get " << amount << " hit points!";
		if (this->hitPoint + amount >= 100)
		{
			std::cout << " And now it has full hit points." << std::endl;
			this->hitPoint = 100;
		}
		else
		{
			std::cout << std::endl;
			this->hitPoint += amount;
		}
		this->energyPoint -= 1;
	}
}

std::string ClapTrap::getName() const
{
	return this->name;
}

unsigned int ClapTrap::getHitPoint() const
{
	return this->hitPoint;
}

unsigned int ClapTrap::getEnergyPoint() const
{
	return this->energyPoint;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}