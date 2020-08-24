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
		system("cls");
		cout << "checkWater";
		if (senContr.checkWater() == 1)
		{
			drvMode.botDrivesOverWater();
			cout endl << "water" << endl;
		}
		else if (senContr.checkWater() != 1)
		{
			drvMode.botDrivesOverLand();
			cout endl<< "land" << endl;
		}
		
		bool object = false;
		object = objDec.detectObject();
		 if (object == true)
			{
				moCo.acclerator(0);
				ali.adjustAlignment(senContr.compass() - 90);
			/*	if (object[0] == '\x1' && object[1] == '\x1')
				{
					ali.adjustAlignment(senContr.compass() - 90);
					moCo.acclerator(1);
					Sleep(1000);
					ali.adjustAlignment(senContr.compass() + 90);
				}*/
				moCo.acclerator(1);
				Sleep(1000);
				ali.adjustAlignment(senContr.compass() + 90);
				moCo.acclerator(0);


			}

		if(object == false)
		{
			auNav.Navigate();
			cout << "drive: ";
			moCo.acclerator(1);
		}
	}
	cout << " Manual Modus";
	cin;
}
