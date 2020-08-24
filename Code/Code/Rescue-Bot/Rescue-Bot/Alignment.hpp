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

int Alignment::differenceAlignment(int alignmentToAdjust)
{
	SensorController  sensCont;
	int currentalignmentOnMap = sensCont.compass();
	int difference = alignmentToAdjust - currentalignmentOnMap;
	cout << alignmentToAdjust;
	return difference;
}
void Alignment::adjustAlignment(int alignmentIsNeed)
{
	cout << "Alignment Start" << endl; 
	MotorControl engineCont;


		engineCont.rotation(differenceAlignment(alignmentIsNeed), alignmentIsNeed);
	cout << "Alignment finished" << endl;
}
