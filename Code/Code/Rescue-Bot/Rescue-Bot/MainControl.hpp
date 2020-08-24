#pragma once
#include "ObjectDetection.hpp"
#include "AudioNavigation.hpp"
#include "MotorControl.hpp"
#include <Windows.h>
#include <conio.h>
#include "Sensorcontroller.hpp"
class MainControl
{
private: 
	AudioNavigation auNav;
	DriveMode drvMode;
	//MotorControl moCo();
	SensorController senContr;
public:
	void mainloop();

};

#include "MainControl.hpp"
void MainControl::mainloop()
{
	MotorControl moCo(drvMode);
	ObjectDetection objDec;
	int buttonOperator = false;
	while (GetAsyncKeyState(0x60) == 0)
	 {
		Sleep(1000);
		system("cls");
		cout << "checkWater";
		if (senContr.checkWater() == 1)
		{
			drvMode.botDrivesOverWater();
		}
		else if (senContr.checkWater() != 1)
		{
			drvMode.botDrivesOverLand();
		}
		if (objDec.detectObject() == true)
		{
			moCo.acclerator(0);
		}
		else
		{
			auNav.Navigate();
			cout << "drive: ";
			moCo.acclerator(1);
		}
	}
	cout << " Manual Modus";
	cin;
}