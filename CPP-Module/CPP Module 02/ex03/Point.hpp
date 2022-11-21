#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const Point& ref);
	Point& operator=(const Point& ref);
	~Point();
	
	Point(const float _x, const float _y);
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif