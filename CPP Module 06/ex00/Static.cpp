#include "Static.hpp"

Static::Static() : num(0.0)
{}

Static::Static(const Static& ref) : num(ref.getNum())
{}

Static& Static::operator=(const Static& ref)
{
	this->num = ref.getNum();
	return (*this);
}

Static::~Static()
{}

Static::Static(std::string p)
{
	//this->num = atof(p.c_str());
	this->num = std::strtod(p.c_str(), NULL);
}

double Static::getNum() const
{
	return this->num;
}

void Static::printChar()
{
	if (0 <= value && value <= 31)
		std::cout << "char: Non displayable" << std::endl;
	else if (char(value) == 0 || value > 255 || value < 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << char(value) << "'" << std::endl;
}

void Static::printInt()
{
	int value = static_cast<int>(this->getNum());
	if (-2147483648 <= value && value <= 2147483647)
		std::cout << "int: " << value << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void Static::printFloat()
{}

void Static::printDouble()
{}