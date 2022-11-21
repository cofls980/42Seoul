#include "Data.hpp"

int main(void)
{
	Data test;

	std::cout << "get number: " << test.getNum() << std::endl;
	std::cout << "data address: " << &test << std::endl;
	uintptr_t tmp1 = serialize(&test);
	std::cout << "serialized address: " << tmp1 << std::endl;
	Data *tmp2 = deserialize(tmp1);
	std::cout << "deserialized address: " << tmp2 << std::endl;
	std::cout << "again get number: " << tmp2->getNum() << std::endl;

	return (0);
}