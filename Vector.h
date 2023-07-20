#pragma once
#ifndef VECTOR
#define VECTOR

#include <cmath>

#ifdef _DEBUG
#include <iostream>
#endif

#include "Point.h"

struct Vector {
	Vector(const Point& point = Point(0, 0, 0), double x = 0, double y = 0, double z = 0);
	double getLength() const;
	Vector toOrth();

	Vector operator *(const double& number);
	Vector operator/=(const double& number);
	Vector operator +=(const Vector& vector);

	Point point;
	double x;
	double y;
	double z;
};

Vector operator-(const Point& start_point, const Point& end_point);

Point operator+(const Point& point, const Vector& vector);
#endif