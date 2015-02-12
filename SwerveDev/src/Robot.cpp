#include "WPILib.h"
#include "swerve/Swerve.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	Joystick *controller;
	Swerve *swerve;
	CameraServer *camera;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
		camera = CameraServer::GetInstance();
		camera->StartAutomaticCapture("cam0");
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
