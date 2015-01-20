#ifndef SWERVEMODULE_H
#define SWERVEMODULE_H
#include "PIDValue.h"
#include "DoublePot.h"
#include <wpilib.h>
#include <ctime>
#include <string>

class SwerveModule
{
private:
	Victor *SpeedOutput, *AngleOutput;
	Encoder *SpeedEncoder;
	DoublePot *AnglePotentiometer;
	double potfeedbackmin, potfeedbackmax;
	PIDController *PIDAngle;
	std::string Name;
	float range,MIN,MAX;
	float OldSetpoint;
public:
	SwerveModule(uint32_t SpeedPort, uint32_t AngPort, uint32_t EncPort1, uint32_t EncPort2,uint32_t PotPort, PIDValue *AnglePIDValues, std::string name, float offset)
	{
		SpeedOutput = new Victor(SpeedPort);
		SpeedEncoder = new Encoder(EncPort1,EncPort2);
		AngleOutput = new Victor(AngPort);
		AnglePotentiometer = new DoublePot(PotPort,AnglePIDValues->MINInput,AnglePIDValues->MAXInput, offset);
		Name = name;
		PIDAngle = new PIDController(AnglePIDValues->P,AnglePIDValues->I,AnglePIDValues->D,AnglePotentiometer,AngleOutput);
		PIDAngle->SetInputRange(AnglePIDValues->MINInput,AnglePIDValues->MAXInput);
		PIDAngle->SetOutputRange(AnglePIDValues->MINOutput, AnglePIDValues->MaxOutput);
		PIDAngle->SetAbsoluteTolerance(20);
		potfeedbackmin = 100;
		potfeedbackmax = 100;
		PIDAngle->SetContinuous(false);
		MIN = AnglePIDValues->MINInput;
		MAX = AnglePIDValues->MAXInput;
		toggle = true;
		lasttrigger = 0;
		range = MAX - MIN;
		OldSetpoint = 450;
		
	}
	void Initialize();
	void drive(float angle, float speed);
	void AutoDrive(float Angle);
	void PIDAdjust(float P, float I, float D);
	bool AtAngle();
	bool toggle;
	void ReadPot();
	int lasttrigger;
};
#endif
