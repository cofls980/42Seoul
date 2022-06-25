#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	*this = ref;
}

Cat& Cat::operator=(const Cat& ref)
{
	this->type = ref.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}

void Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}