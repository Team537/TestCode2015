#include "WPILib.h"
#include "swerve/Swerve.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	Joystick *controller;
	Swerve *swerve;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
		controller = new Joystick(1);
		swerve = new Swerve(controller);
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		swerve->Initialize();
	}

	void TeleopPeriodic()
	{
		swerve->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
