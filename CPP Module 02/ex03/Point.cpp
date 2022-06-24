#include "Point.hpp"

Point::Point()
{
	this->x = Fixed(0);
	this->y = Fixed(0);
}

Point::Point(const float x, const float y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point(const Point& ref)
{
	*this = ref;
}

Point& Point::operator=(const Point& ref)
{
	this->x = ref.getX();
	this->y = ref.getY();
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
