#include "Field.h"

Field::Field(Point center, double cube_side, size_t discretization_side) : discretization({discretization_side, discretization_side, discretization_side})
{
	const double half_cube_side = cube_side / 2;
	field_place.point.x = center.x - half_cube_side;
	field_place.point.y = center.y - half_cube_side;
	field_place.point.z = center.z - half_cube_side;
	field_place.x = field_place.y = field_place.z = cube_side;
	field = std::vector<Vector>(discretization_side * discretization_side * discretization_side, Vector(Point(0, 0, 0)));
	const double step = cube_side / (discretization_side - 1);
	size_t current_element = 0;
	for (double x = field_place.point.x; x <= field_place.point.x + field_place.x; x += step)
	{
		for (double y = field_place.point.y; y <= field_place.point.y + field_place.y; y += step)
		{
			for (double z = field_place.point.z; z <= field_place.point.z + field_place.z; z += step, ++current_element)
			{
				field[current_element] = Vector(Point(x, y, z));
			}
		}
	}
}

std::vector<Vector> Field::getFieldValues()
{
	return field;
}

bool Field::writeToMatlabFormat(std::string filename)
{
	std::ofstream field_file_stream(filename, std::ofstream::out);
	if (field_file_stream.is_open())
	{
		for (auto vector_in_point : field)
		{
			field_file_stream << vector_in_point.point.x << "\t" << vector_in_point.point.y << "\t" << vector_in_point.point.z << "\t" <<
				vector_in_point.x << "\t" << vector_in_point.y << "\t" << vector_in_point.z << "\n";
		}
		field_file_stream.close();
	}
	else
	{
		std::cerr << "Error of file opening\n";
	}
	return false;
}
