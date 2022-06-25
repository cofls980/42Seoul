#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->idea = new Brain();
	this->idea->setIdeas();
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	this->type = ref.type;
}

Cat& Cat::operator=(const Cat& ref)
{
	this->type = ref.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->idea;
}

std::string Cat::getType() const
{
	return this->type;
}

void Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}