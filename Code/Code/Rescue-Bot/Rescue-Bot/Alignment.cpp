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
