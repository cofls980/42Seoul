#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(const float _x, const float _y) : x(_x), y(_y)
{}

Point::Point(const Point& ref) : x(ref.getX()), y(ref.getY())
{}

Point& Point::operator=(const Point& ref)
{
	ref.getX();
	return *this;
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}

Point::~Point()
{}
