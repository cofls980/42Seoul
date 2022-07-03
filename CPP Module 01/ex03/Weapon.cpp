#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()
{
	const std::string &ref = this->type;
	return ref;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}