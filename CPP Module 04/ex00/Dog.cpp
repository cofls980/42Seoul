#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& ref)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = ref.getType();
}

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = ref.getType();
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "BOWWOW!" << std::endl;
}