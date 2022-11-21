#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& ref)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = ref.getType();
	this->brain = new Brain();
	*this->brain = *(ref.getBrain());
}

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = ref.getType();
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain();
	*(this->brain) = *(ref.getBrain());
	return *this;
}

Dog::~Dog()
{
	if (this->brain != NULL)
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