#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name), weapon(NULL)
{}

void	HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}

HumanB::~HumanB()
{}