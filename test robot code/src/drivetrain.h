#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "WPILib.h"
#include "Schematic.h"

class drivetrain
{
	float motorleft;
	float motorright;


public:

	drivetrain ():
		newleft(MOTORLEFT),
		newright(MOTORRIGHT),
		shiftdrivetrain(BUTTONSHIFT)
{

}
void rundrivetrain(
float rightspeed2,
float leftspeed2,
float buttonhigh2,
float buttonlow2
);

private:
	Talon *newleft;
	Talon *newright;
	shiftdrivetrain = new Solenoid(BUTTONSHIFT);
	float clamp (float Speed);
	float deadband (float controller1);
	void ramp (float rightspeed, float leftspeed);
	void motorspeed ();
	void shift (float buttonhigh, float buttonlow);

};

#endif
