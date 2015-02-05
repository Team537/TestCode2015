#include "WPILib.h"
#include "Autotune.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	Victor *AngleVictor;
	AnalogPotentiometer *AnglePot;
	PID_ATune *Autotune;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
		AngleVictor = new Victor (15);
		AnglePot = new AnalogPotentiometer(5);
		Autotune = new PID_ATune(AnglePot, AngleVictor);
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

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
