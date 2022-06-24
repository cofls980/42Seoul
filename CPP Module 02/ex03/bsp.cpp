#include "Point.hpp"

Fixed getTriangle(Point const a, Point const b, Point const c)
{
	Fixed first = (a.getX() * b.getY()) + (b.getX() * c.getY()) + (c.getX() * a.getY());
	Fixed second = (b.getX() * a.getY()) + (c.getX() * b.getY()) + (a.getX() * c.getY());
	Fixed res = first - second;
	if (res.getRawBits() < 0)
		res.setRawBits(-1 * res.getRawBits());
	return res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed t1 = getTriangle(a, b, c);
	Fixed t2 = getTriangle(a, b, point);
	Fixed t3 = getTriangle(a, c, point);
	Fixed t4 = getTriangle(b, c, point);
	
	std::cout << t1.toFloat() << std::endl;
	std::cout << t2.toFloat() << std::endl;
	std::cout << t3.toFloat() << std::endl;
	std::cout << t4.toFloat() << std::endl;
	return (t1 == (t2 + t3 + t4));
}
/*
a.x b.x c.x a.x
a.y b.y c.y a.y
*/