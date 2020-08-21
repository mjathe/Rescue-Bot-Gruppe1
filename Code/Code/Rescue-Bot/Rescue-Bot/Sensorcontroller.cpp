#include "Sensorcontroller.hpp"
char* readSensorsAudio(int freqTow)
{
	Audio Aud;
	char temp[9];
	memcpy((char*)Aud.getSensorarray(/*freqTow*/).c_str(), (char*)temp, 9);
	/*for (size_t i = 0; i < 9; i++) // problem
	{
		temp[i] = Aud.getSensorarray()[i];
	}*/


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
float readMagneticField(float wert1, float wert2, float wert3)
{
	return wert1, wert2, wert3;
}
float readGyroscope(float wert1, float wert2, float wert3)
{
	return wert1, wert2, wert3;
}
int* SensorController::checkForAudioSignals()
{
	//AudioOne{1,1,1,0,0,0,0,0,1} northwest
	//AudioTwo{1,1,1,0,0,0,0,1,0}northeast
	//AudioThree{1,1,1,0,0,0,0,1,1} northeast
	//Audiofour{1,1,1,0,0,0,1,0,0} Southeast shortway
	char audioSignals[9];
	for (size_t i = 0; i < 4; i++)
	{
		memcpy(readSensorsAudio(freqTow), audioSignals, 9);
		/* for (size_t i = 0; i < 9; i++)
		 {
			 audioSignals[i] = readSensors(freqTow)[i];
		 }
		 */
		if (memcmp(audioSignals, new char[9]{ '1', '1', '1', '0', '0', '0', '0', '0', '1' }, 9) == 0)
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
		else if (memcmp(audioSignals, new char[9]{ '1', '1', '1', '0', '0', '0', '1', '0', '0' }, 9) == 0)
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


int* SensorController::checkForObjects()
{
	int ultrasonicVL = readUltrasonic(ultrasonicPin1);
	int ultrasonicVR = readUltrasonic(ultrasonicPin2);

	return new int[2]{ ultrasonicVL,ultrasonicVR };
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
