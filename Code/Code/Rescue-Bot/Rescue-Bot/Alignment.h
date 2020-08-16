class Alignment
{

#include "Sensorcontroller.h"

#include "EngineController.h"
private:
	int differenceAlignment(int alignmentToAdjust);
public : 
	void adjustAlignment(int alignmentIsNeed);

	int differenceAlignment(int alignmentToAdjust)
	{
		int currentalignmentOnMap = Sensorcontroller.compass();
		int difference = alignmentToAdjust - currentAlignmentonMap;
		return difference;
	}
	void adjustAlignment(int alignmentIsNeed)
	{
		EngineController.rotation(differenceAlignment(alignmentIsNeed))
	} 
};