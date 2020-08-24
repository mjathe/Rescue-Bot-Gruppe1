
#pragma once
class DriveMode
{
private:
	int currentDriveMode;
public:
	void botDrivesOverLand();
	void botDrivesOverWater();
	int getDriveMode();
};

#include"DriveMode.hpp"
void DriveMode::botDrivesOverWater()
{
	currentDriveMode = 0;
}
void DriveMode::botDrivesOverLand()
{
	currentDriveMode = 1;
}
int DriveMode::getDriveMode()
{
	return currentDriveMode;
}