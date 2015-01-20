#include "WPILib.h"

//  this is a test 123

class Robot: public IterativeRobot
{
public:
	Robot() :
		talonTest(12),
		solenoidTest(4),
		controller(0)
	{
	}
private:
	LiveWindow *lw;
	Talon talonTest;
	Solenoid solenoidTest; //have to initialize solenoid in port 0 to start compressor

	Joystick controller;

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
			/*this is a test
			Wait(6.0);
			counter++;
			bool currentSetting = solenoidTest.Get();
			solenoidTest.Set(!currentSetting);*/


			talonTest.Set(0.25);
			//solenoidTest.Set(controller.GetRawButton(6));
			//talonTest.Set(controller.GetRawAxis(1));

		}

	}
	/* void TestPeriodic()
	{
		lw->Run();
	} */
};

START_ROBOT_CLASS(Robot);
