#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fRef)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = fRef.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fRef)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointValue = fRef.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}