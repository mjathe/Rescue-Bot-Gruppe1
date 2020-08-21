#include "MainControl.hpp"

void MainControl::mainloop()
{
	ObjectDetection objDec;
	int buttonOperator = false;


	if (operator == true)
	{

		activateCamera();
		displayVideo();
		//funk
		talkToPerson();
	}
}