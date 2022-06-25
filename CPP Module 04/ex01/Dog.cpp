#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->idea = new Brain();
	this->idea->setIdeas();
}

Dog::Dog(const Dog& ref) : Animal(ref)
{
	this->type = ref.type;
}

Dog& Dog::operator=(const Dog& ref)
{
	this->type = ref.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->idea;
}

std::string Dog::getType() const
{
	return this->type;
}

void Dog::makeSound() const
{
	std::cout << "BOWWOW!" << std::endl;
}