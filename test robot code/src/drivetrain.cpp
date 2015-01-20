#include "drivetrain.h"
#include "Schematic.h"
#include <cmath>

float drivetrain::clamp(float Speed)
{
	if (Speed > MAXSPEED)
	{
		Speed = MAXSPEED;
	}

	if (Speed < MINSPEED)
	{
		Speed = MINSPEED;
	}
	return Speed;

}
float drivetrain::deadband(float controller1)
{
	if (fabs(controller1) <= DEADBAND)
	{
		controller1 = 0;
	}
	return controller1;
}
void drivetrain::ramp(float rightspeed, float leftspeed)
{
	if ((rightspeed - motorright) > RAMPSPEED)
	{
		rightspeed = motorright + RAMPSPEED;
	}
	if ((rightspeed - motorright) < -1 * RAMPSPEED)
	{
		rightspeed = motorright - RAMPSPEED;
	}
	if ((leftspeed - motorleft) > RAMPSPEED)
	{
		leftspeed = motorleft + RAMPSPEED;
	}
	if ((leftspeed - motorleft) < -1 * RAMPSPEED)
	{
		leftspeed = motorleft - RAMPSPEED;
	}
	motorright = rightspeed;
	motorleft = leftspeed;
}
void drivetrain::motorspeed()
{
	newleft->Set(motorleft);
	newright->Set(motorright);
}
void drivetrain::shift(float buttonhigh, float buttonlow)
{
	if (buttonhigh == 1)
	{
		shiftdrivetrain.Set(1);
	}
	if (buttonlow == 1)
	{
		shiftdrivetrain.Set(0);
	}
}
void drivetrain::rundrivetrain(float rightspeed2, float leftspeed2, float buttonhigh2, float buttonlow2)
{
	ramp(clamp(deadband(rightspeed2)), clamp(deadband(leftspeed2)));
	motorspeed();
	shift(buttonhigh2, buttonlow2);
}
