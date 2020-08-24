#pragma once
#include <Windows.h>
#include "../Interface_Sensors.cpp"
class MotorControl
{
#define enginePin1  3
#define enginePin2  4
#define directionPin1  5
#define directionPin2  6
#define degreePerSecond  3

#define delay  
#define analogWrite 

public:
	void acclerator(int direction);
	void rotation(int angle, int orientation);
	MotorControl(DriveMode _drvMode);
	MotorControl();
private:
	void engine(int engine1, int engine2);
	DriveMode drvMode;
	Move Mov;

};
MotorControl::MotorControl()
{
}
MotorControl::MotorControl(DriveMode _drvMode)
{
	drvMode = _drvMode;
}
	
#include "MotorControl.hpp"
void MotorControl::engine(int engine1, int engine2)		//Engine1 = right Engine2 = left
{
	if (engine1 == 100)
	{
		Mov.movestraight(enginePin1,255, 255);

	}
	else if (engine1 == 0)
	{

		Mov.movestraight(enginePin1,255, 0);
		

	}
	else if (engine1 == 200)
	{
		Mov.movestraight(enginePin1,0, 255);

	}

	{
		if (engine2 == 100)
		{
			Mov.movestraight(enginePin2,255, 255);

		}
		else if (engine2 == 0)
		{
			Mov.movestraight(enginePin2,255, 0);
		}
		else if (engine2 == 200)
		{
			Mov.movestraight(enginePin2,0, 255);
		}
	}
	cout << "EN1/R(";
	cout << engine1;
	cout << ")";
	cout << "EN2/L(";
	cout << engine2;
	cout << ")";
	cout  << endl;
}
void MotorControl::acclerator(int direction)
{
	switch (direction)
	{

	case 0: 	if (drvMode.getDriveMode() == 0) //0 = water
	{
		engine(0, 0);
	}
		  else
	{
		engine(50, 50);
		Sleep(100);
	}
		  break;
	case 1: engine(100, 100);
		break;
	case 2: engine(200, 200);
		break;
	default:
		if (drvMode.getDriveMode() == 0) //0 = water
		{
			engine(0, 0);
		}
		else
		{
			engine(50, 50);
			Sleep(100);
		}
		break;
	}
}
void setOrientation(int orientation)
{
	SetOrientation SOR;
	switch (orientation)
	{
	case 0:SOR.setori('N');
		break;
	case 90: SOR.setori('E');
		break;
	case 180:SOR.setori('S');
		break;
	case 270:SOR.setori('W');
		break;
	}
}
void MotorControl::rotation(int angle, int orientation)
{	


	setOrientation(orientation);
	int absangle = abs(angle);
	if (absangle <= 180 || angle > 0)
	{
		int secondsToRotate = absangle / degreePerSecond;
		size_t i = secondsToRotate;
		for (i; i > 0; i--)
		{

			//engine(200, 100);
			delay(1000);    //spezifisch für arduino 
		}
		//engine(0, 0);
	}
	else if (absangle > 180 || angle < 0)
	{
		int secondsToRotate = (360 - absangle) / degreePerSecond;
		for (size_t i = secondsToRotate; i > 0; i--)
		{
			//engine(100, 200);
			delay(1000);    //spezifisch für arduino 
		}
		//engine(0, 0);
	}

}
