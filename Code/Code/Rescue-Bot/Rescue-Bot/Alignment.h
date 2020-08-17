class Alignment
{

#include "Sensorcontroller.h"
#include "EngineController.h"
 

private:
	int differenceAlignment(int alignmentToAdjust) { return difference };
public: 
	void adjustAlignment(int alignmentIsNeed);
};
	int differenceAlignment(int alignmentToAdjust)
	{
		Sensorcontroller  sensCont;
		int currentalignmentOnMap = sensCont.compass();
		int difference = alignmentToAdjust - currentAlignmentonMap;
		return difference;
	}
	void adjustAlignment(int alignmentIsNeed)
	{
		EngineController engineCont;
		engineCont.rotation(differenceAlignment(alignmentIsNeed))
	} 
