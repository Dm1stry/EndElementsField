#pragma once
#ifndef GEOMETRY
#define GEOMETRY
#include <cmath>
#define _USE_MATH_DEFINES

#include "Point.h"
#include "Vector.h"
#include "Segment.h"

double distance_point_to_point(const Point& first_point, const Point& second_point);


double distance_point_to_line(const Point& point, const Point& first_line_point, const Point& second_line_point);

double distance_point_to_line(const Point& point, const Segment& segment);

double distance_point_to_line(const Point& point, const Vector& vector);


double cos_angle_line_to_line(const Vector& first_line, const Vector& second_line);

double cos_angle_line_to_line(const Segment& first_line, const Segment& second_line);

double cos_angle_line_to_line(const Point& angle_point, const Point& first_line_point, const Point& second_line_point);

double cos_angle_line_to_line(const Point& angle_point, const Segment& line);
#endif