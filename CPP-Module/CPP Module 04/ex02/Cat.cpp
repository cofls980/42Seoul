#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& ref)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = ref.getType();
	this->brain = new Brain();
	*this->brain = *(ref.getBrain());
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = ref.getType();
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain();
	*(this->brain) = *(ref.getBrain());
	return *this;
}

Cat::~Cat()
{
	if (this->brain != NULL)
		delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}