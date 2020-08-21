#pragma once
#include "SensorController.hpp"
#include "MotorControl.hpp"

class Alignment
{
private:
	int differenceAlignment(int alignmentToAdjust);
public:
	void adjustAlignment(int alignmentIsNeed);
};

