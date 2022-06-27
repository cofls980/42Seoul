#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	this->type = "NOTHING";
}

AMateria::AMateria(const AMateria& ref)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	this->type = ref.type;
}

AMateria& AMateria::operator=(const AMateria& ref)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	this->type = ref.type;
	return (*this);
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria constructor called with " << type << std::endl;
	this->type = type;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	//std::cout << "type: " << type << ", target: " << target << std::endl;
}