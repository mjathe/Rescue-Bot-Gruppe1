#pragma once
#include "ObjectDetection.hpp"
#include "AudioNavigation.hpp"
#include "MotorControl.hpp"
#include <Windows.h>
#include <conio.h>
class MainControl
{
private: 
	AudioNavigation auNav;
	MotorControl moCo;
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
		if (objDec.detectObject() == true)
		{

		}
		else
		{
			auNav.Navigate();
			cout<<"drive: ";
			moCo.acclerator(1);
		}
	}
}