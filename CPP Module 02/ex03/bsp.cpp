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
https://medium.com/@joongi1978/algorithm-3-%EC%84%B8-%EC%A0%90%EC%9D%84-%EC%95%8C-%EB%95%8C-%EC%82%BC%EA%B0%81%ED%98%95%EC%9D%98-%EB%84%93%EC%9D%B4%EB%A5%BC-%EA%B5%AC%ED%95%98%EB%8A%94-%EB%B0%A9%EB%B2%95-%EC%82%AC%EC%84%A0-%EC%8B%A0%EB%B0%9C%EB%81%88-%EA%B3%B5%EC%8B%9D-232ed0dc94d8
신발끈 공식
a.x b.x c.x a.x
a.y b.y c.y a.y
*/