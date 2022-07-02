#include <iostream>
#include <stdint.h>

struct Data
{
	unsigned int test;
};


uintptr_t serialize(Data* ptr)
{
	return uintptr_t(ptr);
}

Data* deserialize(uintptr_t raw) //reinterpret_cast
{
	Data* test = reinterpret_cast<Data *>(raw);
	return test;
}

int main(void)
{
	Data test;

	std::cout << serialize(&test) << std::endl;
	std::cout << deserialize(serialize(&test)) << std::endl;
	std::cout << &test << std::endl;
}