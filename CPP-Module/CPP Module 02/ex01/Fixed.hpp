#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

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
};

std::ostream& operator<<(std::ostream &out, const Fixed& fRef);

#endif