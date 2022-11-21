#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "Wrongnothing";
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = ref.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->type = ref.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WRONG NOTHING!" << std::endl;
}