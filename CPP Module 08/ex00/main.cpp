#include "easyfind.hpp"

int main(void)
{
	std::vector<int> arr(3);
	for (int i = 0;i<3;i++)
		arr[i] = i;
	try
	{
		unsigned int num = ::easyfind(arr, 2);
		std::cout << num << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}