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

Static::Static(char *arg)
{
	this->num = std::strtod(arg, NULL);
}

double Static::getNum() const
{
	return this->num;
}

void Static::printChar()
{
	if (this->getNum() < -128 || this->getNum() > 127 || std::isnan(this->getNum()) || std::isinf(this->getNum()))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(this->getNum()) == 0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(this->getNum()) << "'" << std::endl;
}

void Static::printInt()
{
	if (std::isnan(this->getNum()) || std::isinf(this->getNum()))
		std::cout << "int: impossible" << std::endl;
	else if (this->getNum() < INT_MIN || this->getNum() > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(this->getNum()) << std::endl;

}

void Static::printFloat()
{
	if (std::isnan(this->getNum()) || std::isinf(this->getNum()))
		std::cout << "float: " << static_cast<float>(this->getNum()) << "f" << std::endl;
	else if (this->getNum() > FLT_MAX)
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << "float: " << static_cast<float>(this->getNum()) << "f" << std::endl;
	}
}

void Static::printDouble()
{
	if (std::isnan(this->getNum()) || std::isinf(this->getNum()))
		std::cout << "float: " << this->getNum() << std::endl;
	else if (this->getNum() > DBL_MAX)
	{
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << "double: " << this->getNum() << std::endl;
	}
}