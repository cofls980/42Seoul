#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void)
{
	Base * p;
	char c;

	srand((unsigned int)time(NULL));
	int num = rand() % 3;
	if (num == 0)
	{
		c = 'A';
		p = new A;
	}
	else if (num == 1)
	{
		c = 'B';
		p = new B;
	}
	else if (num == 2)
	{
		c = 'C';
		p = new C;
	}
	std::cout << c << " is generated" << std::endl;
	return (p);
}

void identify(Base* p)
{
	A * a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "A";
	B * b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B";
	C * c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C";
	std::cout << " is identified(pointer)" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "A";
	}
	catch(const std::exception& e)
	{}
	try
	{
		B b = dynamic_cast<B &>(p);
		std::cout << "B";
	}
	catch(const std::exception& e)
	{}
	try
	{
		C c = dynamic_cast<C &>(p);
		std::cout << "C";
	}
	catch(const std::exception& e)
	{}
	std::cout << " is identified(reference)" << std::endl;
}

int main()
{
	Base * base = generate();
	identify(base);
	identify(*base);
}