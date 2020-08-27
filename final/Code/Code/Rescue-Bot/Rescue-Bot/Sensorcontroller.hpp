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

	

	bool water;
	int obstacle[2];

	int readWater(int);
	int readUltrasonic(int);
	float readMagneticField(float , float , float );
	float readGyroscope(float, float, float);

	Ultraa Ula;
	Ultrab Ulb;
	Compass cmp;

public:
	char* checkForAudioSignals();
	float compass();
	float gyroscope();
	float acceleration();
	int* checkForObjects();
	int checkWater();
	char cameraMeasurement();

};
#include "Sensorcontroller.hpp"
int SensorController::readWater(int wert)
{
	return wert;
}
int SensorController::readUltrasonic(int wert)
{

	int temp = 0;
	switch (wert)
	{
	case 29:  return Ula.getSensor();
		break;
	case 27: return Ulb.getSensor();
		break;
	default: return 0;
		break;
	}
}
float SensorController::readMagneticField(float wert1, float wert2, float wert3)
{
	return wert1, wert2, wert3;
}
float SensorController::readGyroscope(float wert1, float wert2, float wert3)
{
	return wert1, wert2, wert3;
}
char* SensorController::checkForAudioSignals()
{
	Audio Aud;
	char audioData[4] = { '0','0','0','0' };
	//AudioOne{1,1,1,0,0,0,0,0,1} northwest
	//AudioTwo{1,1,1,0,0,0,0,1,0}northeast
	//AudioThree{1,1,1,0,0,0,0,1,1} northeast
	//Audiofour{1,1,1,0,0,0,1,0,0} Southeast shortway
	for (size_t i = 1; i < 5; i++)
	{	
		Aud.setturm(i);
		string audioSigna = "";
		 audioSigna = Aud.getSensorarray().c_str();
		//cout << audioSigna;	

		if (memcmp(audioSigna.c_str(), "1,1,1,0,0,0,0,0,1", 15) == 0)
		{
			audioData[0] = '1';
		}
		else if (memcmp (audioSigna.c_str(), "1,1,1,0,0,0,0,1,0", 15) == 0)
		{
			audioData[1] = '1';
		}
		else if (memcmp(audioSigna.c_str(), "1,1,1,0,0,0,0,1,1", 15) == 0)
		{
			audioData[2] = '1';
		}
		else if (memcmp(audioSigna.c_str(),"1,1,1,0,0,0,1,0,0", 15) == 0)
		{
			audioData[3] = '1';
		}
		else if (memcmp(audioSigna.c_str(), "1,1,1,0,0,0,1,1,0", 15) == 0)
		{
			//cout << "fehler: Keine Audio Codierung empfangen!";

		}
		else
		{
			//cout << "Allgemeiner fehler in der AudioNavigation!";
		}
	}
	/*
	if (audioSignals{1, 1, 1, 0, 0, 0, 0, 0, 1} || audioSignals{1, 1, 1, 0, 0, 0, 0, 1, 0} || audioSignals{1, 1, 1, 0, 0, 0, 0, 1, 1} || audioSignals{1, 1, 1, 0, 0, 0, 1, 0, 0})
	{
		switch (audioSignals)
		{
		case {1, 1, 1, 0, 0, 0, 0, 0, 1}: audioData[0] = true;
			break;
		case {1, 1, 1, 0, 0, 0, 0, 1, 0}: audioData[1] = true;
			break;
		case {1, 1, 1, 0, 0, 0, 0, 1, 1}: audioData[2] = true;
			break;
		case {1, 1, 1, 0, 0, 0, 1, 0, 0}: audioData[3] = true;
			break;

	}}*/

	cout << "\n";
	cout << audioData << endl;
	return audioData;
}

float SensorController::gyroscope()
{
	orientation = readGyroscope(x1, y1, z1);

	return orientation;
}

float SensorController::compass()
{
	orientationToNorth = cmp.getCompass();

	return orientationToNorth;
}


int* SensorController::checkForObjects()
{
	int temp[2] = { 0, 0};
	 temp[0] = readUltrasonic(ultrasonicPin1);
	 temp[1] = readUltrasonic(ultrasonicPin2);
	
	 return temp;
}

int SensorController::checkWater()
{
	Wasser water;
	int waterdata = water.getSensor();

	return waterdata;
}

char SensorController::cameraMeasurement()
{
	char msg = 'n';
	return msg;
}
