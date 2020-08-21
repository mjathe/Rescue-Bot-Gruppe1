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

	
