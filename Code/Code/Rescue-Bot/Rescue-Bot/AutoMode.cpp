#include "ObjectDetection.h"
#include <Windows.h>
class AutoMode
{
	AutoMode()
	{
		ObjectDetection objDec;
		int buttonOperator = false;
		while (buttonOperator != true)
		{
			if (getAsyncKeyState() == 'c')
			{
				buttonOperator = true;
			}
			else
			{
				objDec.detectObject();
			}
		}
	}
};