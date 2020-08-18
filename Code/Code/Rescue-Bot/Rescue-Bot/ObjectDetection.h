#pragma once
#include "SensorController.h"
#include "DriveMode.h"
#include "ObjectRecognition.h"
#include "EngineController.h"
#include "AudioNavigation.h"
class ObjectDetection
{
private:
	void recognizedPerson();
		void recognizedBranch();


public:
	void detectObject();
};

	void ObjectDetection::detectObject()
	{
		SensorController senContr;
		DriveMode drvMode;
		AudioNavigation audiNav;

		if (senContr.checkWater() == 1)
		{
			drvMode.startWaterMode();
		}
		else if (senContr.checkWater() != 1)
		{
			drvMode.startLandMode();
		}

		if (senContr.checkUltrasonicSensors()[0] == 1 || senContr.checkUltrasonicSensors()[1] == 1)
		{
			ObjectRecognition objRec;
			switch (objRec.recognized())
			{
			case 'b': recognizedBranch();
				break;
			case 'p': recognizedPerson();
				break;
			case 'n': audiNav.Navigate();
			default:
				break;
			}
		}

	}
	void ObjectDetection::recognizedBranch()
	{
		//callOperator
	}
	void ObjectDetection::recognizedPerson()
	{
		//callOperator
	}

