#include "Array.hpp"

int main(void)
{
	Array<int> a(3);

	for (unsigned int i = 0;i < 3;i++)
	{
		std::cout << a[i] << ", ";
	}
	std::cout << std::endl;
	for (unsigned int i = 0;i < 3;i++)
	{
		a[i] = i;
	}
	for (unsigned int i = 0;i < 3;i++)
	{
		std::cout << a[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << "size: " << a.size() << std::endl;
	try
	{
		a[10] = 1;
		std::cout << "num: " << a[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}