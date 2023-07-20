#pragma once
#ifndef SEGMENT
#define SEGMENT

#include "Vector.h"

struct Segment {
	Segment(const Point& start = Point(0, 0, 0), const Point& end = Point(0, 0, 0));

	Vector toVector() const;
	double getLength() const;

	Point start;
	Point end;
};

#endif