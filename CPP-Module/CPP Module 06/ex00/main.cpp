#include "Static.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Static test(argv[1]);
		test.printChar();
		test.printInt();
		test.printFloat();
		test.printDouble();
	}
	return (0);
}