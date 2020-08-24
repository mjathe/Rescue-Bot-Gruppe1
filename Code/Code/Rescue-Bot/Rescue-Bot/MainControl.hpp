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
	while (GetAsyncKeyState(0x60) == 0)
	 {
		Sleep(1000);
		system("cls");
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