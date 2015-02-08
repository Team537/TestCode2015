#include "Swerve.h"
#include "SwerveModule.h"

void Swerve::Initialize()
{
	newtime.Start();
	AngleSetpoint = 90;
	FrontLeftMod->Initialize();
	FrontRightMod->Initialize();
	BackLeftMod->Initialize();
	BackRightMod->Initialize();
	AngleSetpoint = .5;
	SmartDashboard::PutNumber("538test", 538);

}

void Swerve::Run()
{
	//testing.Set(0.25);
				//compress.checkCompressor();
				//SpdSet.Setspeed(Controller.GetRawAxis(2), Controller.GetRawAxis(4), Controller.GetRawButton(1), Controller.GetRawButton(2), Controller.GetRawButton(6));
				//SmartDashboard::PutNumber("537test", 537);*/
				/*FrontLeftMod->drive(Controller->GetRawAxis(0),Controller->GetRawAxis(1));
				FrontRightMod->drive(Controller->GetRawAxis(0),Controller->GetRawAxis(1));
				BackRightMod->drive(Controller->GetRawAxis(0),Controller->GetRawAxis(1));
				BackLeftMod->drive(Controller->GetRawAxis(0),Controller->GetRawAxis(1));
				/*if (Controller->GetRawButton(1) == 1){
					AngleSetpoint = 250;
				}
				else {
					AngleSetpoint = 165;
				}
			//	BackRightMod->AutoDrive(AngleSetpoint);*/
				/*if (Controller->GetMagnitude() >= .15)
				{
					NAngleSetpoint = Controller->GetDirectionDegrees();
					SmartDashboard::PutNumber("RawDegrees", Controller->GetDirectionDegrees());

					if (Controller->GetRawAxis(1) < 0)
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
					AngleSetpoint = AngleSetpoint*330;
					AngleSetpoint += 15;
				}*/


				/*AngleSetpoint = Controller->GetDirectionDegrees();
				if (AngleSetpoint < 0)
					AngleSetpoint += 360;

				NAngleSetpoint = (AngleSetpoint / 360) * 889 + 40;
				SmartDashboard::PutNumber("Angle Setpoint", AngleSetpoint);
				//SmartDashboard::PutNumber("N Angle Setpoint", NAngleSetpoint);
				//FrontRightMod->AutoDrive((AngleSetpoint / 360) *901 + 36);
				//BackLeftMod->AutoDrive((AngleSetpoint / 360) * 889 + 36);
				//BackRightMod->AutoDrive((AngleSetpoint / 360) * 889 + 36);
				//FrontLeftMod->AutoDrive((AngleSetpoint / 360) * 885 + 40);*/

	 		/*if(newtime.Get() >= .25)
				{
					if (Controller->GetRawButton(7)==1)
					{
						p-=.0001;
						BackRightMod->Reset();
					}
					if (Controller->GetRawButton(8)==1)
					{
						p+=.0001;
						BackRightMod->Reset();
					}
					if (Controller->GetRawButton(9)==1)
					{
						i-=.000001;
						BackRightMod->Reset();
					}
					if (Controller->GetRawButton(10)==1)
					{
						i+=.000001;
						BackRightMod->Reset();
					}
					if (Controller->GetRawButton(3)==1)
					{
						i-=.00001;
						BackRightMod->Reset();
					}
					if (Controller->GetRawButton(5)==1)
					{
						i+=.00001;
						BackRightMod->Reset();
					}
					if (Controller->GetRawButton(11)==1)
					{
						d-=.0001;
						BackRightMod->Reset();
					}
					if (Controller->GetRawButton(12)==1)
					{
						d+=.0001;
						BackRightMod->Reset();
					}
					FrontRightMod->offSetAdjust(Controller->GetRawButton(4),Controller->GetRawButton(6));
				SmartDashboard::PutNumber("P Change Test", PChangeTest);
					newtime.Stop();
					newtime.Reset();
					newtime.Start();
					BackRightMod->PIDAdjust(p,i,d);
					}*/
					if (Controller->GetRawButton(3) || Controller->GetRawButton(4))
					{
						FrontLeftMod->AutoDrive(329.3);
						FrontRightMod->AutoDrive(30.7);
						BackLeftMod->AutoDrive(30.7);
						BackRightMod->AutoDrive(329.3);
						if (FrontRightMod->AtAngle() && BackRightMod->AtAngle() && FrontLeftMod->AtAngle() && BackLeftMod->AtAngle() && Controller->GetRawButton(3))
						{
							FrontLeftMod->drive(0,1);
							FrontRightMod->drive(0,1);
							BackRightMod->drive(0, 1);
							BackLeftMod->drive(0,1);
						}
						if (FrontRightMod->AtAngle() && BackRightMod->AtAngle() && FrontLeftMod->AtAngle() && BackLeftMod->AtAngle() && Controller->GetRawButton(4))
						{
							FrontLeftMod->drive(0,-1);
							FrontRightMod->drive(0,-1);
							BackRightMod->drive(0, -1);
							BackLeftMod->drive(0,-1);
						}
					}
					else
					{
						NAngleSetpoint = Controller->GetDirectionDegrees();
						NAngleSetpoint += 180;
						AngleSetpoint = (NAngleSetpoint);
						SmartDashboard::PutNumber("Magnitude", Controller->GetMagnitude());
						SmartDashboard::PutNumber("Angle Setpoint", AngleSetpoint);
						if(AngleSetpoint > 315)
						{
							sign = -1;
							AngleSetpoint -= 180;
						}
						else if (AngleSetpoint < 45)
						{
							sign = -1;
							AngleSetpoint += 180;
						}
						else{
							sign = 1;
						}
						FrontRightMod->AutoDrive(AngleSetpoint);
						BackLeftMod->AutoDrive(AngleSetpoint);
						BackRightMod->AutoDrive(AngleSetpoint);
						FrontLeftMod->AutoDrive(AngleSetpoint);
						if (FrontRightMod->AtAngle() && BackRightMod->AtAngle() && FrontLeftMod->AtAngle() && BackLeftMod->AtAngle())
						{
							FrontLeftMod->drive(Controller->GetRawAxis(0),-1*sign*Controller->GetMagnitude());
							FrontRightMod->drive(Controller->GetRawAxis(0),sign*Controller->GetMagnitude());
							BackRightMod->drive(Controller->GetRawAxis(0), sign*Controller->GetMagnitude());
							BackLeftMod->drive(Controller->GetRawAxis(0),-1*sign*Controller->GetMagnitude());
						}
						else
						{
							FrontLeftMod->drive(0,0);
							FrontRightMod->drive(0,0);

							BackRightMod->drive(0,0);
							BackLeftMod->drive(0,0);
						}
					}

}

void Swerve::TestMode()
{
	LW->AddActuator("Left Front", "Angle", FrontLeftMod->GetAnglePID());
}
