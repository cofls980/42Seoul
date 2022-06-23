#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed& fRef)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fRef;
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
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bit;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bit));
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->bit));
}

int Fixed::toInt(void) const
{
	return (this->value >> this->bit);
}

std::ostream& operator<<(std::ostream &out, const Fixed& fRef)
{
	out << fRef.toFloat();
	return (out);
}