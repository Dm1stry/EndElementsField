#include "geometry.h"

double distance_point_to_point(const Point& first_point, const Point& second_point)
{
	return sqrt(pow(first_point.x - second_point.x, 2) + pow(first_point.y - second_point.y, 2) + pow(first_point.z - second_point.z, 2));
}

double distance_point_to_line(const Point& point, const Point& first_line_point, const Point& second_line_point)
{
	double r1_2 = pow(first_line_point.x - point.x, 2) + pow(first_line_point.y - point.y, 2) + pow(first_line_point.z - point.z, 2);
	double r2_2 = pow(point.x - second_line_point.x, 2) + pow(point.y - second_line_point.y, 2) + pow(point.z - second_line_point.z, 2);
	double l = distance_point_to_point(first_line_point, second_line_point);
	return sqrt(abs(r2_2 - pow(((r1_2 + r2_2) / (2 * l) - l / 2), 2)));
}

double distance_point_to_line(const Point& point, const Segment& segment)
{
	return distance_point_to_line(point, segment.start, segment.end);
}

double distance_point_to_line(const Point& point, const Vector& vector)
{
	return distance_point_to_line(point, vector.point, vector.point + vector);
}

double cos_angle_line_to_line(const Vector& first_line, const Vector& second_line)
{
	double first_line_length = first_line.getLength();
	double second_line_length = second_line.getLength();
	if (first_line_length != 0 && second_line_length != 0)
		return abs(first_line.x * second_line.x + first_line.y * second_line.y + first_line.z * second_line.z) / (first_line_length * second_line_length);
	else
		return 0;
}	

double cos_angle_line_to_line(const Segment& first_line, const Segment& second_line)
{
	return cos_angle_line_to_line(first_line.toVector(), second_line.toVector());
}

double cos_angle_line_to_line(const Point& angle_point, const Point& first_line_point, const Point& second_line_point)
{
	return cos_angle_line_to_line(Segment(angle_point, first_line_point), Segment(angle_point, second_line_point));
}

double cos_angle_line_to_line(const Point& angle_point, const Segment& line)
{
	return cos_angle_line_to_line(Segment(angle_point, line.start), line);
}

