#ifndef SRC_SWERVE_H_
#define SRC_SWERVE_H_

#include <swerve/PIDValue.h>
#include <swerve/PIDDriveValue.h>
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
		PIDValue *FrontLeftAngleValues  = new PIDValue(.0065,0.000065,.0014, 15, 345, -1,1);
		PIDValue *FrontRightAngleValues = new PIDValue(.0066,0.000506,0.0062, 15, 345, -1, 1);
		PIDValue *BackLeftAngleValues   = new PIDValue(.0066,0.00034, 0.006,15,345,-1,1);
		PIDValue *BackRightAngleValues  = new PIDValue(.0079,0.000238,0.0033,15,345,-1,1);
		PIDDriveValue *FrontLeftDriveValues  = new PIDDriveValue(.004, 0, 0,0,0);
		PIDDriveValue *FrontRightDriveValues = new PIDDriveValue(.004, 0, 0,0,0);
		PIDDriveValue *BackLeftDriveValues   = new PIDDriveValue(.004, 0, 0,0,0);
		PIDDriveValue *BackRightDriveValues  = new PIDDriveValue(.004, 0, 0,0,0);
		///                            (speed,angle,encoder1,encoder2,pot,pidAngle,PIDDrive,name,offset, Max Encoder rate, setpointoffset)
		FrontLeftMod  = new SwerveModule(11,15,5,6,5, FrontLeftAngleValues, FrontLeftDriveValues,"FrontLeft", 0,10,0);
		FrontRightMod = new SwerveModule(10,14,1,2,4,FrontRightAngleValues,FrontRightDriveValues,"FrontRight", 0,10,0);
		BackLeftMod   = new SwerveModule(13,17,7,8,7,BackLeftAngleValues, BackLeftDriveValues,"BackLeft", 0,10,0);
		BackRightMod  = new SwerveModule(12,16,3,4,6,BackRightAngleValues, BackRightDriveValues,"BackRight", 0,10,0);

		sign = 0;
		NAngleSetpoint = 0;
		AngleSetpoint = 90;
		PChangeTest = 0;
		p = .004;
		i = 0;
		d = 0;
	}
	void Initialize();
	void Run();
	void TestMode();
};
#endif
