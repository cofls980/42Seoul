#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
	int value;
	const static int bit = 8;

public:
	Fixed();
	Fixed(const Fixed& fRef);//복사 생성자(Copy constructor)
	Fixed& operator=(const Fixed& fRef);//복사 대입 연산자(Copy assignment operator)
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	Fixed(const int value);
	Fixed(const float value);
	float toFloat(void) const;
	int toInt(void) const;
	//std::ostream& operator<<(std::ostream &out, const Fixed& fRef);
	//std::ostream& operator << (std::ostream &out, const Fixed& fRef);
};

std::ostream& operator<<(std::ostream &out, const Fixed& fRef);

#endif