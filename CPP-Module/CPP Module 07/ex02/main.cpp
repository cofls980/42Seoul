#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        std::cout << tmp.size() << std::endl;
        Array<int> test(tmp);
        std::cout << test.size() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    std::cout << "_____________________________________" << std::endl;
    const size_t s = 3;
	Array<int> a(s);
	for (unsigned int i = 0;i < s ;i++)
		std::cout << a[i] << "    ";
    std::cout << std::endl;
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
    return 0;
}