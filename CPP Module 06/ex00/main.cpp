#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char **argv) //static_cast
{
	if (argc == 2)
	{
		double value = 0.0;
		value = std::strtod(argv[1], NULL);
		if (0 <= value && value <= 31)
			std::cout << "char: Non displayable" << std::endl;
		else if (char(value) == 0 || value > 255 || value < 0)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: '" << char(value) << "'" << std::endl;
		if (-2147483648 <= value && value <= 2147483647)
			std::cout << "int: " << int(value) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << "float: " << float(value) << "f" << std::endl;
		std::cout << "double: " << double(value) << std::endl;
	}
	return (0);
}