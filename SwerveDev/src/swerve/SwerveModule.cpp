#include "..\Schematic.h"
#include "SwerveModule.h"
#include "cmath"

void SwerveModule::Initialize()
{
	//SmartDashboard::PutData("Angle PID", PIDAngle);
	PIDAngle->Disable();
	PIDAngle->Reset();
	PIDAngle->Disable();
	firsttime = true;
	SpeedEncoder->Reset();
}

void SwerveModule::drive(float angle, float speed)
{
	SmartDashboard::PutBoolean("firsttime", firsttime);
	SmartDashboard::PutBoolean("toggle", toggle);
	SmartDashboard::PutNumber("watch", watch.Get());
	if (fabs(angle) < JOYDEADBAND)
	{
		angle = 0;
	}

	if (fabs(speed) < JOYDEADBAND)
	{
		speed = 0;
	}
	double crate = SpeedEncoder->GetRate();
	if (crate >= maxencrate)
	{
		maxencrate = crate;
	}
	SmartDashboard::PutNumber(Name + "crate", crate);
	SmartDashboard::PutNumber(Name + "max encoder rate", maxencrate);
	//AngleOutput->Set(angle);
	PIDDrive->SetSetpoint(.5*speed*MaxRate);
	SmartDashboard::PutNumber("Encoder", SpeedEncoder->GetRate());
	SmartDashboard::PutNumber(Name +"Potentiometer", AnglePotentiometer->Get());
	SmartDashboard::PutNumber("Angle IO",angle);
	SmartDashboard::PutNumber("Speed IO",speed);
}

void SwerveModule::AutoDrive(float Angle)
{
	Angle = (Angle/360)*330 + 15;
	//SmartDashboard::PutNumber(Name+"actual I",((PIDAngle->GetI())*1000));
	Angle += Offset;
	Angle += range;
	if (Angle > MAX)
		Angle -= range;
	if (Angle < MIN)
		Angle += range;
	SmartDashboard::PutNumber(Name+ "Angle Setpoint pre cap", Angle);
/*	if(Angle > 300)
		Angle = 300;
	if (Angle < 90)
		Angle = 90;*/
	PIDAngle->Enable();
	PIDAngle->SetSetpoint(Angle);
	if(AngleOutput->Get() > 0)
	{
		PIDAngle->SetSetpoint(Angle - offSet);
	}
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
	SmartDashboard::PutNumber(Name+ "setpoint offset", offSet);
	PIDAngle->SetPID(P, I, D);
}

bool SwerveModule::AtAngle()
{
	return PIDAngle->OnTarget();
}
float SwerveModule::ReadPot(){
	SmartDashboard::PutNumber(Name+ " Initial Pot Reading", AnglePotentiometer->PIDGet());
	return AnglePotentiometer->PIDGet();
	
}
void SwerveModule::Reset()
{
	PIDAngle->Reset();
}

void SwerveModule::DisablePID()
{
	PIDAngle->Disable();
}
void SwerveModule::offSetAdjust(int a, int b){
	if (a)
	{
		offSet += 1;
	}
	if (b)
	{
		offSet -= 1;
	}
}
PIDController* SwerveModule::GetAnglePID()
{
	return PIDAngle;
}
void SwerveModule::PIDAuto(float distance)
{
	SpeedEncoder->SetPIDSourceParameter(PIDSource::kDistance);
	PIDDriveDistance->Disable();
	PIDDriveDistance->SetSetpoint(distance);
}
bool SwerveModule::GetDistancePID()
{
	SmartDashboard::PutBoolean("Distance on Target", PIDDriveDistance->OnTarget());
	return PIDDriveDistance->OnTarget();
}

void SwerveModule::DistancePIDDisable()
{
	PIDDriveDistance->Disable();
}

