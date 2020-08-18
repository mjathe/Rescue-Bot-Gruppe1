#pragma once
#include "SensorController.h"
#include "EngineController.h"

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
		EngineController engineCont;
		engineCont.rotation(differenceAlignment(alignmentIsNeed));
	}

