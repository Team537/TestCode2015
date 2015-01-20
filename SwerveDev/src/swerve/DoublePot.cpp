#include "DoublePot.h"
#include "WPILib.h"
#include "cmath"

DoublePot::DoublePot(int channel, float min, float max, float Offset) : AnalogPotentiometer(channel) {
	Min = min;
	Max = max;
	OFFSet = Offset;
	counter = 0;
	lastval = 0;
	lastdeltasign = false;
	accum = 0;
	alternater = false;
};

double DoublePot::PIDGet()
{
	double originalreading = AnalogPotentiometer::PIDGet();
	double delta = originalreading - lastval;
	double range = Max - Min;
	double tmpIntPart, tmpAccum;
	bool deltaIsPositive = delta > 0;
	
	if (originalreading > Max || originalreading <Min)
	{
		return lastval;
	}
	lastval = originalreading;
	originalreading -= OFFSet;
	if (originalreading < Min)
		originalreading += range;
	return originalreading;
	
	SmartDashboard::PutBoolean("Alternater", alternater);
	SmartDashboard::PutNumber("originalreading", originalreading);
	SmartDashboard::PutNumber("accum", accum);

	// Update the accumulator with the current change in angle
	//accum += delta;

	// If we've seen a big jump in angle (half range or more)
	// adjust the accumulator for the sawtooth step
/*	if(fabs(delta) > range/2)
	{
		if (deltaIsPositive)
			accum -= range;
		else
			accum += range;
	}
	
	lastdeltasign = deltaIsPositive;
	lastval = originalreading;*/
	
	// At this point the accumulator could be a very large absolute value
	// Use a modulus operation to get back to the expected range of values
	// Note that we divide by (range*2) to compensate for 2:1 pot to motor ratio
	// then we multiply the fractional part by the range to get back to the
	// expected range of values.
	//tmpAccum = modf(accum/(range*2), &tmpIntPart) * range;
	
	// We want to always return positive values, so if we're currently negative,
	// add the range value to the output value before returning.
	/*if (tmpAccum < 0)
		tmpAccum += range;
	tmpAccum += Min;
	tmpAccum -= OFFSet;
	if(tmpAccum < Min)
		tmpAccum +=range;

	return(tmpAccum);*/
	

}
