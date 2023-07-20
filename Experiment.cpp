#include "Experiment.h"

Experiment::Experiment(const Field& field, std::list<Coil> coils, std::list<double> I) : field(field), field_is_calculated(false)  
{
	if (coils.size() == I.size())
	{
		this->Is = I;
		this->coils = coils;
	}
}

Experiment::Experiment(const Field& field, const Coil& coil, const double& I) : field(field), field_is_calculated(false), coils({ coil }), Is({ I }) {}

void Experiment::setCoils(std::list<Coil> new_coils, std::list<double> new_I)
{
	if (new_coils.size() == new_I.size())
	{
		coils = new_coils;
		Is = new_I;
	}
}

void Experiment::addCoil(Coil additional_coil, double I)
{
	coils.push_back(additional_coil);
	Is.push_back(I);
}

void Experiment::addCoils(std::list<Coil> additional_coils, std::list<double> Is)
{
	if (Is.size() == additional_coils.size())
	{
		std::list<double>::iterator I = Is.begin();
		for (auto additional_coil : additional_coils)
		{
			this->addCoil(additional_coil, *(I++));
		}
	}
	else
	{
		//there must be an exception
	}
}

void Experiment::setField(Field new_field)
{
	//Possibly there could be implemented some copy from old field to keep old calculated data
	field = new_field;
}

Field Experiment::getField()
{
	if (!field_is_calculated)
	{
		constexpr double C = 1e-7 / std::numbers::pi;
		std::list<double>::iterator I = Is.begin();
		for (auto& current_coil : coils)
		{
			for (auto field_point = field.field.begin(); field_point < field.field.end(); ++field_point)
			{
				bool coil_ended = false;
				current_coil.resetSegmentIterator();
				while (!coil_ended)
				{
					Segment current_segment = current_coil.getCurrentSegment(coil_ended);
					Vector segment_field_orth((*field_point).point, 
											current_segment.start.y * current_segment.end.z - current_segment.start.z * current_segment.end.y, 
											current_segment.start.x * current_segment.end.z - current_segment.start.z * current_segment.end.x,
											current_segment.start.x * current_segment.end.y - current_segment.start.y * current_segment.end.x);
					segment_field_orth.toOrth();

					(*field_point) += segment_field_orth * C * (*I) * (cos_angle_line_to_line((*field_point).point, current_segment)
																		+ cos_angle_line_to_line(current_segment.end, (*field_point).point, current_segment.start));
				}
			}
			I++;
		}
	}
	return field;
}

