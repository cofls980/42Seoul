#ifndef STATIC_HPP
#define STATIC_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Static
{
private:
	double num;

public:
	Static();
	Static(const Static& ref);
	Static& operator=(const Static& ref);
	~Static();

	Static(std::string p);

	double getNum() const;

	void printChar();
	void printInt();
	void printFloat();
	void printDouble();
};

#endif