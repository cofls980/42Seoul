#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "nothing";
}

/*Animal::Animal(std::string type)
{
	std::cout << "Animal constructor called with type " << type << std::endl;
	this->type = type;
}*/

Animal::Animal(const Animal& ref)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = ref;
}

Animal& Animal::operator=(const Animal& ref)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = ref.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "NOTHING!" << std::endl;
}