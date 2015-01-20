#include "WPILib.h"
#include "Schematic.h"
#include "drivetrain.h"

class Robot: public IterativeRobot
{
	drivetrain drive;


public:

		Robot():

	{

	}
		void Autonomous() {

		}

		void OperatorControl() {
			while (IsOperatorControl()) {
				drive.rundrivetrain(joystick1.GetRawAxis(LEFTJOYSTICK), joystick1.GetRawAxis(RIGHTJOYSTICK), joystick1.GetRawButton(SHIFTHIGH), joystick1.GetRawButton(SHIFTLOW));
			}
		}
		void Test(){

		}
};
private:
	LiveWindow *lw;
	Joystick *joystick1;
	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
		joystick1(STICK);
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
