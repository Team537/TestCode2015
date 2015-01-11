#include "WPILib.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	int counter;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		counter = 0;
	}

	void TeleopPeriodic()
	{
		while(IsEnabled())
		{
			// this is a test
			Wait(2.0);
			counter++;

		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
