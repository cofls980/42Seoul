#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fRef)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fRef;
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
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = value << this->bit;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(value * (1 << this->bit));
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (float)(1 << this->bit));
}

int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->bit);
}

std::ostream& operator<<(std::ostream &out, const Fixed& fRef)
{
	out << fRef.toFloat();
	return (out);
}