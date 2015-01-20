#include "Swerve.h"
#include "SwerveModule.h"

void Swerve::Initialize()
{
	newtime.Start();

	FrontLeftMod->Initialize();
	FrontRightMod->Initialize();
	BackLeftMod->Initialize();
	BackRightMod->Initialize();
	AngleSetpoint = .5;
}

void Swerve::Run()
{
	//testing.Set(0.25);
				//compress.checkCompressor();
				//SpdSet.Setspeed(Controller.GetRawAxis(2), Controller.GetRawAxis(4), Controller.GetRawButton(1), Controller.GetRawButton(2), Controller.GetRawButton(6));
				//FrontLeftMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
				//FrontRightMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
				//BackRightMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
				//BackLeftMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));

			/*	if (Controller->GetRawButton(1) == 1){
					AngleSetpoint = 650;
				}
				else {
					AngleSetpoint = 445;
				}*/
				if (Controller->GetMagnitude() >= .15)
				{
					NAngleSetpoint = Controller->GetDirectionDegrees();
					SmartDashboard::PutNumber("RawDegrees", Controller->GetRawAxis(2));

					if (Controller->GetRawAxis(2) < 0)
					{
						NAngleSetpoint += 90;
						sign = 1;
					}
					else if (NAngleSetpoint > 0)
					{
						sign = -1;
						NAngleSetpoint -= 90;

					}
					else
					{
						sign = -1;
						NAngleSetpoint += 270;
					}

					SmartDashboard::PutNumber("NAngleSetpoint", NAngleSetpoint);
					AngleSetpoint = NAngleSetpoint/180;
				}
					SmartDashboard::PutNumber("Magnitude", Controller->GetMagnitude());
					FrontRightMod->AutoDrive(AngleSetpoint);
					BackLeftMod->AutoDrive(AngleSetpoint);
					BackRightMod->AutoDrive(AngleSetpoint);
					FrontLeftMod->AutoDrive(AngleSetpoint);
					if (FrontRightMod->AtAngle() && BackRightMod->AtAngle() && FrontLeftMod->AtAngle() && BackLeftMod->AtAngle())
					{
						FrontLeftMod->drive(Controller->GetRawAxis(1),-1*sign*Controller->GetMagnitude());
						FrontRightMod->drive(Controller->GetRawAxis(1),-1*sign*Controller->GetMagnitude());
						BackRightMod->drive(Controller->GetRawAxis(1),sign* Controller->GetMagnitude());
						BackLeftMod->drive(Controller->GetRawAxis(1), -1*sign*Controller->GetMagnitude());
					}
					else
					{
						FrontLeftMod->drive(0,0);
						FrontRightMod->drive(0,0);
						BackRightMod->drive(0,0);
						BackLeftMod->drive(0,0);
					}

			/*	AngleSetpoint = Controller->GetDirectionDegrees();
				if (AngleSetpoint < 0)
					AngleSetpoint += 360;

				NAngleSetpoint = (AngleSetpoint / 360) * 889 + 40;*/
				SmartDashboard::PutNumber("Angle Setpoint", AngleSetpoint);
				SmartDashboard::PutNumber("N Angle Setpoint", NAngleSetpoint);
				//FrontRightMod->AutoDrive((AngleSetpoint / 360) *901 + 36);
				//BackLeftMod->AutoDrive((AngleSetpoint / 360) * 889 + 36);
				//BackRightMod->AutoDrive((AngleSetpoint / 360) * 889 + 36);
				//FrontLeftMod->AutoDrive((AngleSetpoint / 360) * 885 + 40);

	 	/*	if(newtime.Get() >= .25)
				{
					if (Controller->GetRawButton(7)==1)
					{
						p-=.0001;
					}
					if (Controller->GetRawButton(8)==1)
					{
						p+=.0001;
					}
					if (Controller->GetRawButton(9)==1)
					{
						i-=.00001;
					}
					if (Controller->GetRawButton(10)==1)
					{
						i+=.00001;
					}
					if (Controller->GetRawButton(11)==1)
					{
						d-=.0001;
					}
					if (Controller->GetRawButton(12)==1)
					{
						d+=.0001;
					}
				SmartDashboard::PutNumber("P Change Test", PChangeTest);
					newtime.Stop();
					newtime.Reset();
					newtime.Start();
					//FrontLeftMod->PIDAdjust(p,i,d);
					}*/
}
