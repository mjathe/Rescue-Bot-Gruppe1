#pragma once
#include "SensorController.h"
#include "MotorControl.h"

class Alignment
{
private:
	int differenceAlignment(int alignmentToAdjust);
public:
	void adjustAlignment(int alignmentIsNeed);
};
	int Alignment::differenceAlignment(int alignmentToAdjust)
	{
		SensorController  sensCont;
		int currentalignmentOnMap = sensCont.compass();
		int difference = alignmentToAdjust - currentalignmentOnMap;
		return difference;
	}
	void Alignment::adjustAlignment(int alignmentIsNeed)
	{
		MotorControl engineCont;
		engineCont.rotation(differenceAlignment(alignmentIsNeed));
	}

