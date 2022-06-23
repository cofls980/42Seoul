#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fRef)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = fRef.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fRef)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fRef.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}