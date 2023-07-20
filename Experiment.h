#pragma once
#ifndef EXPERIMENT
#define EXPERIMENT

#include <numbers>

#include "Coil.h"
#include "Field.h"
#include "geometry.h"

class Experiment {
public:
	Experiment(const Field& field, const Coil& coils, const double& I);
	Experiment(const Field& field, std::list<Coil> coils = {}, std::list<double> I = {});

	void setCoils(std::list<Coil> new_coils, std::list<double> new_I);
	void addCoil(Coil additional_coil, double I);
	void addCoils(std::list<Coil> additional_coils, std::list<double> Is);

	void setField(Field new_field);
	Field getField();
private:
	Field field;
	bool field_is_calculated;
	std::list<Coil> coils;
	std::list<double> Is;
};

#endif