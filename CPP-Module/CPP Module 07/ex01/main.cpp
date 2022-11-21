#include "iter.hpp"

int main(void)
{
	int arr1[5] = {10, 20, 30, 40, 50};
	iter(arr1, 5, print);

	char arr2[3] = {'d', 'r', 't'};
	iter(arr2, 3, print);

	std::string arr3[4] = {"hi", "hello", "nice", "to"};
	iter(arr3, 4, print);

	return (0);
}