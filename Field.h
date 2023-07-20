#pragma once
#ifndef FIELD
#define FIELD

#include <vector>
#include <array>
#include <string>
#include <fstream>

#ifdef _DEBUG
#include <iostream>
#endif

#include "Vector.h"


class Field {

	friend class Experiment;

public:
	Field(Point center, double cube_side, size_t discretization_side);
	std::vector<Vector> getFieldValues();
	bool writeToMatlabFormat(std::string filename);

private:
	std::vector<Vector> field;
	Vector field_place;  //Represents sizes and replacement of calulating part of field
	std::array<size_t, 3> discretization;  //Discretization of field in each dimension 0 - x, 1 - y, 2 - z
};

#endif