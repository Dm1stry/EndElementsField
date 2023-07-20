#include "Vector.h"

Vector::Vector(const Point& point, double x, double y, double z) : point(point), x(x), y(y), z(z) {}

double Vector::getLength() const
{
	return sqrt(x*x + y*y + z*z);
}

Vector Vector::toOrth()
{
	return *this /= this->getLength();
}

Vector Vector::operator*(const double& number)
{
	Vector new_vector = *this;
	new_vector.x *= number;
	new_vector.y *= number;
	new_vector.z *= number;
	return new_vector;
}

Vector Vector::operator/=(const double& number)
{
	if (number != 0)
	{
		this->x /= number;
		this->y /= number;
		this->z /= number;
	}
	else
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	return (*this);
}

Vector Vector::operator+=(const Vector& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
	return (*this);
}

Vector operator-(const Point& end_point, const Point& start_point)
{
	return Vector(start_point, end_point.x - start_point.x, end_point.y - start_point.y, end_point.z - start_point.z);
}

Point operator+(const Point& point, const Vector& vector)
{
	return Point(point.x + vector.x, point.y + vector.y, point.z + vector.z);
}
