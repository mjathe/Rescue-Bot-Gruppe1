#pragma once
#include <iostream>
#include "../Interface_Sensors.cpp"

using namespace std;

class SensorController
{

#define ultrasonicPin1 29
#define ultrasonicPin2 27
#define ultrasonicPin3 25
#define ultrasonicPin4 23
#define pinMicrofone 22

#define watersens 20
#define sleep

private:
	float x1, y1, z1;	//Gyroscope
	float x2, y2, z2;	//compass
	float x3, y3, z3;	//acceleration
	float orientationToNorth;
	float orientation;
	int ultrasonicVL; int ultrasonicVR;
	int freqTow = 0; //frequenz für türme

	
	int audioData[4];
	bool water;
	int obstacle[2];

public:
	int* checkForAudioSignals();
	float compass();
	float gyroscope();
	float acceleration();
	int* checkForObjects();
	int checkWater();
	char cameraMeasurement();

};
