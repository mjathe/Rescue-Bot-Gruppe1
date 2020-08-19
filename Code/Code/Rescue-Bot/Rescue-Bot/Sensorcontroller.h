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
	int* readAudioSensors();
	float compass();
	float gyroscope();
	float acceleration();
	int* checkUltrasonicSensors();
	int checkWater();
	char cameraMeasurement();

};
char* readSensors(int freqTow)
{	
	Audio Aud;
	char temp[9] = {};
	for (size_t i = 0; i < 9; i++)
	{
		temp[i] = Aud.getSensorarray()[i];
	}


	return 	temp;
}
int readWater(int wert)
{
	return wert;
}
int readUltrasonic(int wert)
{
	Ultraa Ula;
	Ultrab Ulb;
	int temp = 0; 
	switch (wert)
	{
	case 29:  temp = Ula.getSensor();
		break;
	case 27: temp = Ulb.getSensor();
		break;
	default: temp = 0;
		break;
	}

	return  temp;
}
float readMagneticField(float wert1,float wert2,float wert3)
{
	return wert1,wert2,wert3;
}
float readGyroscope(float wert1, float wert2, float wert3)
{
	return wert1, wert2, wert3;
}
	 int* SensorController::readAudioSensors()
	{
	//AudioOne{1,1,1,0,0,0,0,0,1} northwest
	//AudioTwo{1,1,1,0,0,0,0,1,0}northeast
	//AudioThree{1,1,1,0,0,0,0,1,1} northeast
	//Audiofour{1,1,1,0,0,0,1,0,0} Southeast shortway
			 char audioSignals[9];
			 for (size_t i = 0; i < 4; i++)
			 {
				 for (size_t i = 0; i < 9; i++)
				 {
					 audioSignals[i] = readSensors(freqTow)[i];
				 }

				 if (memcmp(audioSignals,new char[9] { '1', '1', '1', '0', '0', '0', '0', '0', '1' }, 9) == 0)
				 {
					 audioData[0] = true;
				 }
				 else if (memcmp(audioSignals, new char[9]{ '1', '1', '1', '0', '0', '0', '0','1', '0' }, 9) == 0)
				 {
					 audioData[1] = true;
				 }
				 else if (memcmp(audioSignals, new char[9]{ '1', '1', '1', '0', '0', '0', '0', '1', '1' }, 9) == 0)
				 {
					 audioData[2] = true;
				 }
				 else if (memcmp(audioSignals,new char[9] { '1', '1', '1', '0', '0', '0', '1', '0', '0' }, 9) == 0)
				 {
					 audioData[3] = true;
				 }
				 else if (memcmp(audioSignals, new char[9]{ '1', '1', '1', '0', '0', '0', '1', '1', '0' }, 9) == 0)
				 {
					 //no signal 

				 }
				 else
				 {
					 //auch fehler
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
			
 
        		return audioData;
      	}

	 float SensorController::gyroscope()
	{
		orientation = readGyroscope(x1, y1, z1);

		return orientation;
	}

	 float SensorController::compass()
	{
    		orientationToNorth = readMagneticField(x2, y2, z2);
		
    		return orientationToNorth;
	}
		

	int* SensorController::checkUltrasonicSensors()
	{		
		int ultrasonicVL = readUltrasonic(ultrasonicPin1);
		int ultrasonicVR = readUltrasonic(ultrasonicPin2);
		
		return new int[]{ultrasonicVL,ultrasonicVR};
	}
		
	 int SensorController::checkWater() 
	{
		int water = readWater(watersens);
		
		return water;
	}

	 char SensorController::cameraMeasurement()
	 {
		 char msg = 'n';
		 return msg;
	}
