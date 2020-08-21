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
	if (angle <= 180)
	{
		int secondsToRotate = angle / degreePerSecond;
		for (size_t i = secondsToRotate; i > 0; i--)
		{
			engine(100, 0);
			delay(1000);    //spezifisch für arduino 
		}
		engine(0, 0);
	}
	else if (angle > 180)
	{
		int secondsToRotate = (360 - angle) / degreePerSecond;
		for (size_t i = secondsToRotate; i > 0; i--)
		{
			engine(0, 100);
			delay(1000);    //spezifisch für arduino 
		}
		engine(0, 0);
	}

}
