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
		controller = new Joystick(0);
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
		swerve->TestMode();
	}
};

START_ROBOT_CLASS(Robot);
