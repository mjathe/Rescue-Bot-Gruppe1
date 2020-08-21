#pragma once
#include "SensorController.h"
#include "DriveMode.h"
#include "ObstacleDetection.h"
#include "MotorControl.h"
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
			drvMode.botDrivesOverWater();
		}
		else if (senContr.checkWater() != 1)
		{
			drvMode.botDrivesOverLand();
		}

		if (senContr.checkForObjects()[0] == 1 || senContr.checkForObjects()[1] == 1)
		{
			ObstacleDetection objRec;
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

