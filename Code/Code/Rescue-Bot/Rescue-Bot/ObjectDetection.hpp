#pragma once
#include "SensorController.hpp"
#include "DriveMode.hpp"
#include "ObstacleDetection.hpp" //konvention c++ header
#include "MotorControl.hpp"
#include "AudioNavigation.hpp"
class ObjectDetection
{
private:
	void recognizedPerson();
		void recognizedBranch();


public:
	bool detectObject();
};

	bool ObjectDetection::detectObject()
	{
		SensorController senContr;
		DriveMode drvMode;
		AudioNavigation audiNav;
		cout << "checkWater";
		if (senContr.checkWater() == 1)
		{
			drvMode.botDrivesOverWater();
		}
		else if (senContr.checkWater() != 1)
		{
			drvMode.botDrivesOverLand();
		}
		cout << "\nObject Detection";
		char objects[2];
		memcpy((char*)senContr.checkForObjects(), (char*)objects, 2);
 		if (objects[0] == 1 || objects[1] == 1)
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
			return true;
		}
		else
		{
			return false;
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

