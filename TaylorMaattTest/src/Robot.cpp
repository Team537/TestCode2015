#include "WPILib.h"

class Robot: public IterativeRobot
{
public:
	Robot()
	{
	}

private:
	Talon *testtalon;
	Solenoid *testpiston;
	Joystick *controller;


private:
	LiveWindow *lw;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
		testtalon = new Talon(0);
		testpiston = new Solenoid(4);
		controller = new Joystick(0);
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		testtalon->Set(controller->GetRawAxis(1));
		if (controller->GetRawButton(1))
		{
			testpiston->Set(1);
		}
		if (controller->GetRawButton(2))		{
			testpiston->Set(0);
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
