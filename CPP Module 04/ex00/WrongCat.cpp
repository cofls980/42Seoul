#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = ref.getType();
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->type = ref.getType();
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WRONG MEOW!" << std::endl;
}