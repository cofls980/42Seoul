#include "Array.hpp"

int main(void)
{
	const size_t s = 3;
	Array<int> a(s);

	for (unsigned int i = 0;i < s;i++)
	{
		a[i] = i;
	}
	for (unsigned int i = 0;i < s;i++)
	{
		std::cout << a[i] << "    ";
	}
	std::cout << std::endl;
	Array<int> b;
	b = a;
	std::cout << "size: " << b.size() << std::endl;
	try
	{
		b[10] = 1;
		std::cout << "num: " << b[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b[1] = 100;
		std::cout << "num: " << b[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}