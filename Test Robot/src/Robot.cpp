#include "WPILib.h"
#include "Schematic.h"

class Robot: public IterativeRobot
{
public:
	Robot() :
	solenoid(1),
	button(6)
{
}
private:

	Solenoid solenoid;

	LiveWindow *lw;

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

	}

	void TeleopPeriodic()
	{
		while (IsEnabled())
		{
			solenoid.Set(1);
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
