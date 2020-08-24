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

		AudioNavigation audiNav;

		cout << "\nObject Detection: ";
		char objects[2];
		memcpy((char*)senContr.checkForObjects(), (char*)objects, 2);
 		if (objects[0] == 1 || objects[1] == 1)
		{
			ObstacleDetection objRec;
			switch (objRec.recognized())
			{
			case 'b': cout << "\n\nknown obect found: branch"; recognizedBranch();
				break;
			case 'p':cout << "\n\nknown obect found: person"; recognizedPerson();
				break;
			case 'n':cout << "\n\nno known obect found";  audiNav.Navigate();
			default:
				break;
			}
			cout << "\nobject recognition with positive result\n\n";
			return true;
		}
		else
		{
			cout << "\nobject recognition with negative result\n\n";
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

