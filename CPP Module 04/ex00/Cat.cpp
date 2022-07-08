#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = ref.getType();
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = ref.getType();
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}