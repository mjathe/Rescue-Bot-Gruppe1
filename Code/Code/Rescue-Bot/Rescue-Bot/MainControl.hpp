#pragma once
#include "ObjectDetection.hpp"
#include <Windows.h>
#include <conio.h>
class MainControl
{
public:
	void mainloop();

};

#include "MainControl.hpp"
void MainControl::mainloop()
{
	ObjectDetection objDec;
	int buttonOperator = false;
	while (_getch() != 32)
	{
		objDec.detectObject();
	}
}