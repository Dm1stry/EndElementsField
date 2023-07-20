#include "Segment.h"

Segment::Segment(const Point& start, const Point& end) : start(start), end(end) {}

Vector Segment::toVector() const
{
	return Vector(start, end.x - start.x, end.y - start.y, end.z - start.z);
}

double Segment::getLength() const
{
	return sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2) + pow(start.z - end.z, 2));
}
