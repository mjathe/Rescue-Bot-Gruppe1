
#pragma once
#include "SensorController.hpp"
class ObstacleDetection
{


public:
	char recognized();
};
char ObstacleDetection::recognized()
{
	SensorController sensCont;
	char temp = sensCont.cameraMeasurement();
	switch (temp)
	{
	case 0: return 'b';
		break;
	case 1: return 'p';
		break;
	default: return 'n';
		break;
	}
}



