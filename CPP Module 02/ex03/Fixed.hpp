#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixedPointValue;
	const static int bit;

public:
	Fixed();
	Fixed(const Fixed& fRef);
	Fixed& operator=(const Fixed& fRef);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	Fixed(const int value);
	Fixed(const float value);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed& fRef) const;
	bool operator<(const Fixed& fRef) const;
	bool operator>=(const Fixed& fRef) const;
	bool operator<=(const Fixed& fRef) const;
	bool operator==(const Fixed& fRef) const;
	bool operator!=(const Fixed& fRef) const;

	Fixed operator+(const Fixed& fRef) const;
	Fixed operator-(const Fixed& fRef) const;
	Fixed operator*(const Fixed& fRef) const;
	Fixed operator/(const Fixed& fRef) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream &out, const Fixed& fRef);

#endif