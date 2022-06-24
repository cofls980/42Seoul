#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const Fixed& fRef)
{
	*this = fRef;
}

Fixed& Fixed::operator=(const Fixed& fRef)
{
	this->value = fRef.getRawBits();
	return *this;
}

Fixed::~Fixed()
{}

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
	this->value = value * (1 << this->bit);
}

Fixed::Fixed(const float value)
{
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

bool Fixed::operator>(const Fixed& fRef) const
{
	if (this->getRawBits() > fRef.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& fRef) const
{
	if (this->getRawBits() < fRef.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& fRef) const
{
	if (this->getRawBits() >= fRef.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& fRef) const
{
	if (this->getRawBits() <= fRef.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& fRef) const
{
	if (this->getRawBits() == fRef.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& fRef) const
{
	if (this->getRawBits() != fRef.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& fRef) const
{
	return Fixed(this->toFloat() + fRef.toFloat());
}

Fixed Fixed::operator-(const Fixed& fRef) const
{
	return Fixed(this->toFloat() - fRef.toFloat());
}

Fixed Fixed::operator*(const Fixed& fRef) const
{
	return Fixed(this->toFloat() * fRef.toFloat());
}

Fixed Fixed::operator/(const Fixed& fRef) const
{
	return Fixed(this->toFloat() / fRef.toFloat());
}
//전위 증가
Fixed& Fixed::operator++()
{
	this->value += 1;
	return *this;
}
//후위 증가
Fixed Fixed::operator++(int)
{
	Fixed fix;
	fix.setRawBits(this->value);
	this->value += 1;
	return fix;
}

Fixed& Fixed::operator--()
{
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed fix;
	fix.setRawBits(this->value);
	this->value -= 1;
	return fix;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 <= f2)
		return f1;
	return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 <= f2)
		return f1;
	return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 >= f2)
		return f1;
	return f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 >= f2)
		return f1;
	return f2;
}