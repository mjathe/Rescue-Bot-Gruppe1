#pragma once
#include "Sensorcontroller.h"
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

	ObjectDetection()
	{
		Sensorcontroller senContr;
		DriveMode drvMode;
		AudioNavigation audiNav;

		if (senContr.checkWater() == true)
		{
			drvMode.startWaterMode();
		}
		else if (senContr.checkWater() != true)
		{
			drvMode.startLandMode();
		}

		if (senContr.checkUltrasonicSensors() == true)
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

	void recognizedBranch()
	{
		//callOperator
	}
	void recognizedPerson()
	{
		//callOperator
	}
};
