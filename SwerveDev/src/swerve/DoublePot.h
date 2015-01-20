#ifndef DOUBLEPOT_H
#define DOUBLEPOT_H

#include "Schematic.h"
#include "WPILib.h"

class DoublePot : public AnalogPotentiometer
{
public:
	explicit DoublePot(int channel, float min, float max, float Offset);
	double PIDGet();
private:
	bool alternater;
	bool lastdeltasign;
	double lastval;
	float Min;
	float Max;
	int counter;
	double accum;
	double OFFSet;
};
#endif
