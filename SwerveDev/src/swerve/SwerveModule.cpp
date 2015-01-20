#include "..\Schematic.h"
#include "SwerveModule.h"
#include "cmath"

void SwerveModule::Initialize()
{
	//SmartDashboard::PutData("Angle PID", PIDAngle);
	PIDAngle->Reset();
}

void SwerveModule::drive(float angle, float speed)
{
	if (fabs(angle) < JOYDEADBAND)
	{
		angle = 0;
	}

	if (fabs(speed) < JOYDEADBAND)
	{
		speed = 0;
	}
	
	//AngleOutput->Set(angle);

	
	SpeedOutput->Set(.5*speed);
	double potfeedback = AnglePotentiometer->PIDGet();
		if (potfeedback >= potfeedbackmax){
			potfeedbackmax = potfeedback;
			}
		if (potfeedback <= potfeedbackmin){
			potfeedbackmin = potfeedback;
			}
	SmartDashboard::PutNumber("max pot", potfeedbackmax);
	SmartDashboard::PutNumber("min pot", potfeedbackmin);
	SmartDashboard::PutNumber(Name + "Potval", potfeedback);
	SmartDashboard::PutNumber("Encoder", SpeedEncoder->GetRate());
	SmartDashboard::PutNumber("Potentiometer", AnglePotentiometer->Get());
	SmartDashboard::PutNumber("Angle IO",angle);
	SmartDashboard::PutNumber("Speed IO",speed);
}

void SwerveModule::AutoDrive(float Angle)
{
	Angle = (Angle*range+MIN);
	if (Angle < 300)
		Angle =300;
	if (Angle > 600)
		Angle = 600;
	PIDAngle->Enable();
	PIDAngle->SetSetpoint(Angle);
	SmartDashboard::PutNumber(Name+ "PotReading", AnglePotentiometer->PIDGet());
	SmartDashboard::PutNumber(Name+ "Angle Error", PIDAngle->GetError());
	SmartDashboard::PutNumber(Name+ "Angle Setpoint", PIDAngle->GetSetpoint());
	SmartDashboard::PutBoolean(Name+ "Angle Target", PIDAngle->OnTarget());
	SmartDashboard::PutNumber(Name+ "Angle Error2", PIDAngle->GetError());
	SmartDashboard::PutNumber(Name+ "Angle Error3", PIDAngle->GetError());
}

void SwerveModule::PIDAdjust(float P, float I, float D)
{
	SmartDashboard::PutNumber(Name+ "P", PIDAngle->GetP()*1000);
	SmartDashboard::PutNumber(Name+ "I", ((PIDAngle->GetI())*1000));
	SmartDashboard::PutNumber(Name+ "D", PIDAngle->GetD()*1000);
	PIDAngle->SetPID(P, I, D);
}

bool SwerveModule::AtAngle()
{
	return PIDAngle->OnTarget();
}
void SwerveModule::ReadPot(){
	SmartDashboard::PutNumber(Name+ " Initial Pot Reading", AnglePotentiometer->PIDGet());
	
}


