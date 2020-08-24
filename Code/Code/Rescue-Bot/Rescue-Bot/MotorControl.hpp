#pragma once
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
	void rotation(int angle);

private:
	void engine(int engine1, int engine2);
};

	
#include "MotorControl.hpp"
void MotorControl::engine(int engine1, int engine2)		//Engine1 = right Engine2 = left
{
	if (engine1 == 100)
	{
		analogWrite(directionPin1, 255);
		analogWrite(enginePin1, 255);
	}
	else if (engine1 == 0)
	{
		analogWrite(enginePin1, 255);
	}
	else if (engine1 == 200)
	{
		analogWrite(directionPin1, 0);
		analogWrite(enginePin1, 255);
	}

	{
		if (engine2 == 100)
		{
			analogWrite(directionPin2, 255);
			analogWrite(enginePin2, 255);

		}
		else if (engine2 == 0)
		{
			analogWrite(enginePin2, 255);
		}
		else if (engine2 == 200)
		{
			analogWrite(directionPin2, 0);
			analogWrite(enginePin2, 255);
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

	case 0: engine(0, 0);
		break;
	case 1: engine(100, 100);
		break;
	case 2: engine(200, 200);
		break;
	default: engine(0, 0);
		break;
	}
}

void MotorControl::rotation(int angle)
{
	int absangle = abs(angle);
	if (absangle <= 180 || angle > 0)
	{
		int secondsToRotate = absangle / degreePerSecond;
		size_t i = secondsToRotate;
		for (i; i > 0; i--)
		{

			engine(200, 100);
			delay(1000);    //spezifisch für arduino 
		}
		engine(0, 0);
	}
	else if (absangle > 180 || angle < 0)
	{
		int secondsToRotate = (360 - absangle) / degreePerSecond;
		for (size_t i = secondsToRotate; i > 0; i--)
		{
			engine(100, 200);
			delay(1000);    //spezifisch für arduino 
		}
		engine(0, 0);
	}

}
