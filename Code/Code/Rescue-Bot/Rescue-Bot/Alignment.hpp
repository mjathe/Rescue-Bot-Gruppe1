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

#include "Alignment.hpp"
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
