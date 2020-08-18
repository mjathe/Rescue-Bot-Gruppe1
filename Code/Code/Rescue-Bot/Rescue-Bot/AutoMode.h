#include "ObjectDetection.h"
#include <Windows.h>
class AutoMode
{
	AutoMode()
	{
		char c = 'C';
		ObjectDetection objDec;
		int buttonOperator = false;
		while (buttonOperator != true)
		{
			if (c  == 'c')
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