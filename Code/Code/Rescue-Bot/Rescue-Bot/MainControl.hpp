#pragma once
#include "ObjectDetection.hpp"
#include "AudioNavigation.hpp"
#include "MotorControl.hpp"
#include <Windows.h>
#include <conio.h>
#include "Alignment.hpp"
#include "Sensorcontroller.hpp"
class MainControl
{
private: 
	AudioNavigation auNav;
	DriveMode drvMode;
	//MotorControl moCo();
	SensorController senContr;
	Alignment ali;
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
		//system("cls");
		cout << "checkWater";
		if (senContr.checkWater() == 1)
		{
			drvMode.botDrivesOverWater();
		}
		else if (senContr.checkWater() != 1)
		{
			drvMode.botDrivesOverLand();
		}
		char object[2] = {'0','0'};
		memcpy(objDec.detectObject(), object, 2);
		if (object[0] == '1')
		{
			moCo.acclerator(0);
			ali.adjustAlignment(270);
			moCo.acclerator(1);
			Sleep(1000);
			moCo.acclerator(0);
			ali.adjustAlignment(90);

			
		}
		else if (object[0] == '1')
		{
			moCo.acclerator(0);
			ali.adjustAlignment(90);
			moCo.acclerator(1);
			Sleep(1000);
			moCo.acclerator(0);
			ali.adjustAlignment(270);
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