#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type)
{}

const std::string &Weapon::getType()
{
	const std::string &ref = this->type;
	return ref;
}

void	Weapon::setType(std::string _type)
{
	this->type = _type;
}

Weapon::~Weapon()
{}