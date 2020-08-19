#pragma once
#include "ObjectDetection.h"
#include <Windows.h>
class AutoMode
{

public: 
	void startAutoMode();

	
};
void startAutoMode()
{
	ObjectDetection objDec;

	objDec.detectObject();
}