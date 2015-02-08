#include "WPILib.h"
#include "Autotune.h"

class Robot: public IterativeRobot {
private:
	LiveWindow *lw;
	Victor *AngleVictor;
	AnalogPotentiometer *AnglePot;
	PID_ATune *Autotune;
	Joystick *controller;
	bool tuning;
	int lastpressed;
	int cpressed;

	void RobotInit() {
		lw = LiveWindow::GetInstance();
		AngleVictor = new Victor(17);
		AnglePot = new AnalogPotentiometer(7, 360, 0);
		Autotune = new PID_ATune(AnglePot, AngleVictor);
		controller = new Joystick(0);
		lastpressed = 0;
		cpressed = 0;
		tuning = false;
	}

	void AutonomousInit() {

	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {

		Autotune->SetControlType(1);
		Autotune->SetOutputStep(.33);
		Autotune->SetNoiseBand(2);

	}

	void TeleopPeriodic() {
		 cpressed = controller->GetRawButton(1);
		if (lastpressed == 1 && cpressed == 0)
		{
			tuning = true;
			Autotune->InitializeRuntime(0);
		}
		if (tuning) {
			int val = (Autotune->Runtime());
			if (val != 0) {
				tuning = false;
			}
		} else { //we're done, set the tuning parameters
			float kp = Autotune->GetKp();
			float ki = Autotune->GetKi();
			float kd = Autotune->GetKd();
			SmartDashboard::PutNumber("KP", kp * 1000000);
			SmartDashboard::PutNumber("KI", ki * 1000000);
			SmartDashboard::PutNumber("KD", kd * 1000000);
			SmartDashboard::PutBoolean("tuning", tuning);
		}
		SmartDashboard::PutNumber("Pot PID", AnglePot->PIDGet());
		SmartDashboard::PutNumber("Victor Output", AngleVictor->Get());
		lastpressed = cpressed;
	}

	void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
