#include "Experiment.h"
#include "Coil.h"
#include "Field.h"

#include <string>

int main()
{
	//Coil coil("debug_src/coil.txt");
	std::list<Coil> coils;
	for (int i = 1; i <= 4; ++i)
	{
		coils.push_back(Coil("debug_src/coil" + std::to_string(i) + ".txt"));
	}
	Field field(Point(0, 0, 0), 80, 5);
	const double I = 10;
	std::list<double> Is = { I, I, -I, -I};
	Experiment experiment(field, coils, Is);
	field = experiment.getField();
	field.writeToMatlabFormat("debug_src/field.txt");
}