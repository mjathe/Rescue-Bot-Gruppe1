#pragma once
#include "Sensorcontroller.h"
#include "DriveMode.h"
class ObjectDetection
{


private:

public:

	 ObjectDetection()
	{
		 Sensorcontroller senContr;
		 DriveMode drvMode;

		if (senContr.checkWater() == true)
		{
			 drvMode.startWaterMode()
		}
		else if (senContr.checkWater() != true)
		{
			drvMode.startLandMode()
		}

		if (senContr.checkUltrasonicSensors() == true)
		{

		}
	}
};
