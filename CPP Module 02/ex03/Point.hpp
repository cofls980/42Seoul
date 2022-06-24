#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Fixed.hpp"

class Point
{

private:
	Fixed x;
	Fixed y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point& ref);
	Point& operator=(const Point& ref);
	Fixed getX() const;
	Fixed getY() const;
	~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif