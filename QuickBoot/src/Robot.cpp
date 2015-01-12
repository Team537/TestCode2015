#include "WPILib.h"

class Robot: public IterativeRobot
{
public:
	Robot() :
		talonTest(1),
		solenoidTest(4)
	{
	}
private:
	LiveWindow *lw;
	Talon talonTest;
	Solenoid solenoidTest;

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

			bool currentSetting = solenoidTest.Get();
			solenoidTest.Set(!currentSetting);
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
