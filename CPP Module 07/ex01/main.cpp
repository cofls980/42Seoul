#include "iter.hpp"

template <typename T>
void print(T a)
{
	std::cout << a << std::endl;
}

template <typename T, typename Func>
void iter(T *a, int b, Func func)
{
	for (int i = 0;i < b;i++)
	{
		func(a[i]);
	}
}

int main(void)
{
	int arr1[5] = {10, 20, 30, 40, 50};
	::iter(arr1, 5, ::print<int>);

	char arr2[3] = {'d', 'r', 't'};
	::iter(arr2, 3, ::print<char>);

	std::string arr3[4] = {"hi", "hello", "nice", "to"};
	::iter(arr3, 4, ::print<std::string>);

	return (0);
}