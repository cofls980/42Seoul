#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& ref) : Animal(ref)
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
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "BOWWOW!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->brain;
}

void Dog::setBrain(Brain &brain)
{
	*(this->brain) = brain;
	//this->brain = &brain;
}