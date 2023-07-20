#include "Coil.h"

Coil::Coil() : points({}), current_start_point(points.begin()) {}

Coil::Coil(std::filesystem::path coil_file_path) : points({})
{
	if (std::filesystem::exists(coil_file_path))
	{
		std::ifstream coil_file_stream(coil_file_path);
		if (coil_file_stream.is_open())
		{
			double x, y, z;
			bool more_then_one_point = false;
			while (coil_file_stream >> x >> y >> z)
			{
				points.push_back(Point(x, y, z));
				if (!more_then_one_point && points.size() == 2)
				{
					more_then_one_point = true;
				}
			}
			if (more_then_one_point)
			{
				current_start_point = points.begin();
			}
			else
			{
				std::cerr << "\nWrong Coil file format\n";
			}
			coil_file_stream.close();
		}
		else
		{
			std::cerr << "\nOpening file error\n";
			//There must be an error_of_opening_file throwing code
		}
	}
	else
	{
		std::cerr << "\nFinding file error\n";
		//There must be an error_of_finding_file throwing code
		//throw new std::FileNotFoundException("I couldn't find your file!");
	}

}

Segment Coil::getCurrentSegment(bool& end)
{
	//static size_t segment_num = 0;
	auto preend = std::prev(points.end());
	if (current_start_point != preend)
	{
		std::list<Point>::iterator segment_start(current_start_point++);

		if (current_start_point == preend)
			end = true;

		//end = segment_num++ < points.size() - 2;
		//std::cerr << "Start: " << (*segment_start).x << " " << (*segment_start).y << " " << (*segment_start).z << '\n'
		//	<< "End: " << (*current_start_point).x << " " << (*current_start_point).y << " " << (*current_start_point).z << "\n\n";
		return Segment(*segment_start, *current_start_point);
	}
	else
	{
		return Segment(Point(0, 0, 0), Point(0, 0, 0));
	}
}

void Coil::resetSegmentIterator()
{
	current_start_point = points.begin();
}
