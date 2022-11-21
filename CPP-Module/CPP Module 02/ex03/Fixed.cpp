#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed() : fixedPointValue(0)
{}

Fixed::Fixed(const Fixed& fRef)
{
	this->fixedPointValue = fRef.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fRef)
{
	this->fixedPointValue = fRef.getRawBits();
	return *this;
}

Fixed::~Fixed()
{}

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
	this->fixedPointValue = value << this->bit;
}

Fixed::Fixed(const float value)
{
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
	if (fRef.toFloat() == 0.0)
	{
		std::cout << "Zero is not valid" << std::endl;
		std::exit(1);
	}
	return Fixed(this->toFloat() / fRef.toFloat());
}

Fixed& Fixed::operator++()
{
	this->fixedPointValue += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed fix;
	fix.setRawBits(this->fixedPointValue);
	this->fixedPointValue += 1;
	return fix;
}

Fixed& Fixed::operator--()
{
	this->fixedPointValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed fix;
	fix.setRawBits(this->fixedPointValue);
	this->fixedPointValue -= 1;
	return fix;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}