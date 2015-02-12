#ifndef SRC_SWERVE_H_
#define SRC_SWERVE_H_

#include <swerve/PIDValue.h>
#include <swerve/PIDDriveValue.h>
#include <swerve/Autotune.h>
#include "WPILib.h"
#include "SwerveModule.h"

/* defines for extended board ports
#define FrontLeftSpeed
#define FrontLeftAngle
#define FrontLeftEnc1
#define FrontLeftEnc2
#define FrontLeftPot
#define FrontLeftOffSet
#define EXT6
#define EXT7
#define EXT8
#define EXT9 */

class Swerve
{
private:
	SwerveModule *FrontLeftMod, *FrontRightMod, *BackLeftMod, *BackRightMod;
	PID_ATune *automatic;
	Joystick *Controller;
	float AngleSetpoint, PChangeTest, p, i, d, NAngleSetpoint;
	Timer newtime;
	int sign;
	LiveWindow *LW;
public:
	Swerve(Joystick *controller)
	{
		Controller = controller;
		LW = LiveWindow::GetInstance();
			//
		PIDValue *FrontLeftAngleValues  = new PIDValue(.021,0.000250,.0425, 15, 345, -1,1);
		PIDValue *FrontRightAngleValues = new PIDValue(.014,0.000320,0.035, 15, 345, -1, 1);
		PIDValue *BackLeftAngleValues   = new PIDValue(.020,0.00017, 0.0401,15,345,-1,1);
		PIDValue *BackRightAngleValues  = new PIDValue(.020,0.000210,0.0335,15,345,-1,1);
		PIDDriveValue *FrontLeftDriveValues  = new PIDDriveValue(.004, 0, 0,0,0);
		PIDDriveValue *FrontRightDriveValues = new PIDDriveValue(.004, 0, 0,0,0);
		PIDDriveValue *BackLeftDriveValues   = new PIDDriveValue(.004, 0, 0,0,0);
		PIDDriveValue *BackRightDriveValues  = new PIDDriveValue(.004, 0, 0,0,0);
		automatic = new PID_ATune();
		///                            (speed,angle,encoder1,encoder2,pot,pidAngle,PIDDrive,name,offset, Max Encoder rate, setpointoffset)
		FrontLeftMod  = new SwerveModule(11,15,16,17,5, FrontLeftAngleValues, FrontLeftDriveValues,"FrontLeft", 0,10,0);
		FrontRightMod = new SwerveModule(10,14,14,15,4,FrontRightAngleValues,FrontRightDriveValues,"FrontRight", 0,10,0);
		BackLeftMod   = new SwerveModule(13,17,24,25,7,BackLeftAngleValues, BackLeftDriveValues,"BackLeft", -29.941,10,0);
		BackRightMod  = new SwerveModule(12,16,22,23,6,BackRightAngleValues, BackRightDriveValues,"BackRight", 0,10,0);

		sign = 0;
		NAngleSetpoint = 0;
		AngleSetpoint = 90;
		PChangeTest = 0;
		p = .016;
		i = 0;
		d = 0;
	}
	void Initialize();
	void Run();
	void TestMode();
};
#endif
