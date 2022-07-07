#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

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
};

#endif