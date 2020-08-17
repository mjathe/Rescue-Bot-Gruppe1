#pragma once
#include "Sensorcontroller.h"
#include "EngineController.h"

class Alignment
{



private:
	int differenceAlignment(int alignmentToAdjust);

public:
	void adjustAlignment(int alignmentIsNeed);

	int differenceAlignment(int alignmentToAdjust)
	{
		Sensorcontroller  sensCont;
		int currentalignmentOnMap = sensCont.compass();
		int difference = alignmentToAdjust - currentalignmentOnMap;
		return difference;
	}
	void adjustAlignment(int alignmentIsNeed)
	{
		EngineController engineCont;
		engineCont.rotation(differenceAlignment(alignmentIsNeed));
	}
};
