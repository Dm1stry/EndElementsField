#pragma once
#ifndef COIL
#define COIL

#include <filesystem>
#include <list>
#include <iterator>
#include <fstream>
#include <exception>

#ifdef _DEBUG
#include <iostream>
#endif

#include "Segment.h"

class Coil {
public:
	Coil();
	Coil(std::filesystem::path coil_file_path);

	Segment getCurrentSegment(bool& end);
	void resetSegmentIterator();
private:
	std::list<Point> points;
	std::list<Point>::iterator current_start_point;  //points to start point of segment to read (that coulg be gotten with getCurrentSegment()), default 2-nd point in a list
};

#endif