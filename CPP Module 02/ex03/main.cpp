#include "Point.hpp"

int main( void ) {
	
	Point const a(1.0, 1.0);
	Point const b(1.0, 5.0);
	Point const c(5.0, 1.0);
	Point const point(5.0, 5.0);
	
	if (bsp(a, b, c, point))
	{
		std::cout << "TRUE" << std::endl;
	}
	else
	{
		std::cout << "FALSE" << std::endl;
	}
	return 0;
}