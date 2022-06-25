#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& ref) : Animal(ref)
{
	*this = ref;
}

Dog& Dog::operator=(const Dog& ref)
{
	this->type = ref.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}

void Dog::makeSound() const
{
	std::cout << "BOWWOW!" << std::endl;
}