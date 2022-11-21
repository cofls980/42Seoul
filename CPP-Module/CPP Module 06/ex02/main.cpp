#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	Base * p;

	srand(time(NULL));
	int num = rand() % 3;
	if (num == 0)
	{
		p = new A;
		std::cout << "A is generated" << std::endl;
	}
	else if (num == 1)
	{
		p = new B;
		std::cout << "B is generated" << std::endl;
	}
	else if (num == 2)
	{
		p = new C;
		std::cout << "C is generated" << std::endl;
	}
	else
	{
		p = NULL;
		std::cout << "Nothing generated" << std::endl;
	}
	return (p);
}

void identify(Base* p)
{
	A * a = dynamic_cast<A *>(p);
	if (a != NULL)
		std::cout << "A is identified(pointer)" << std::endl;
	B * b = dynamic_cast<B *>(p);
	if (b != NULL)
		std::cout << "B is identified(pointer)" << std::endl;
	C * c = dynamic_cast<C *>(p);
	if (c != NULL)
		std::cout << "C is identified(pointer)" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A is identified(reference)" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B is identified(reference)" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C is identified(reference)" << std::endl;
	}
	catch(const std::exception& e)
	{}
}

int main()
{
	Base * base = generate();
	identify(base);
	identify(*base);
	if (base)
		delete base;
	return (0);
}