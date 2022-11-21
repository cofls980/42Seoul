#include "easyfind.hpp"

int main(void)
{
	std::vector<int> arr;
	for (int i = 0;i<3;i++)
		arr.push_back(i);
	try
	{
		std::vector<int>::iterator iter;
		iter = easyfind(arr, 2);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator iter;
		iter = easyfind(arr, 10);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}