#pragma once
#include "Sensorcontroller.h"
#include "DriveMode.h"
class ObjectDetection
{


private:

public:

	 ObjectDetection()
	{
		 


		if (Sensorcontroller.checkWater() == true)
		{
			DriveMode.startWaterMode()
		}
		else if (Sensorcontroller.checkWater() != true)
		{
			DriveMode.startLandMode()
		}

		if (Sensorcontroller.checkUltrasonicSensors() == true)
		{

		}
	}
};
