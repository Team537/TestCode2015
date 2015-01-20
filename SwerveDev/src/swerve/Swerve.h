#ifndef SRC_SWERVE_H_
#define SRC_SWERVE_H_

#include "WPILib.h"
#include "SwerveModule.h"
#include "PIDValue.h"

class Swerve
{
private:
	SwerveModule *FrontLeftMod, *FrontRightMod, *BackLeftMod, *BackRightMod;
	Joystick *Controller;
	float AngleSetpoint, PChangeTest, p, i, d, NAngleSetpoint;
	Timer newtime;
	int sign;
public:
	Swerve(Joystick *controller)
	{
		Controller = controller;

		PIDValue *FrontLeftAngleValues = new PIDValue(.0034,0.0004,.0003, 40, 925, -.5,.5);
		PIDValue *FrontRightAngleValues = new PIDValue(.0018,0.0001,0.0012, 36, 937, -.5, .5);
		PIDValue *BackLeftAngleValues = new PIDValue(.0036,0.0004,0.0005,36,925,-.5,.5);
		PIDValue *BackRightAngleValues = new PIDValue(-.004,-0.0001,0.0014,36,925,-.5,.5);

		FrontLeftMod = new SwerveModule(1,2,5,6,4, FrontLeftAngleValues, "FrontLeft",0);
		FrontRightMod = new SwerveModule(8,6,1,2,7,FrontRightAngleValues,"FrontRight",0);
		BackLeftMod = new SwerveModule(4,5,7,8,5,BackLeftAngleValues, "BackLeft",0);
		BackRightMod = new SwerveModule(7,3,3,4,6,BackRightAngleValues, "BackRight", -10);

		sign = 0;
		NAngleSetpoint = 1;
		AngleSetpoint = 0;
		PChangeTest = 0;
		p = .004;
		i = 0;
		d = 0;
	}
	void Initialize();
	void Run();
};
#endif
