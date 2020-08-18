#pragma once
#pragma once
#include "SensorController.h"
class ObjectRecognition
{


public:
	char recognized();
};
	char ObjectRecognition::recognized()
	{
		SensorController sensCont;
		switch (sensCont.cameraMeasurement())
		{
		case 0: return 'b';
			break;
		case 1: return 'p';
			break;
		default: return 'n';
			break;
		}
	}



