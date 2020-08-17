#include <iostream>

using namespace std;

class Sensorcontroller
{

	#define ultrasonicPin1 = 29;
	#define ultrasonicPin2 = 27;
	#define ultrasonicPin3 = 25;
	#define ultrasonicPin4 = 23;

	#define watersens = 20;

	float x1, y1, z1;	//Gyroscope
	float x2, y2, z2;	//compass
	float x3, y3, z3;	//acceleration
	float orientationToNorth;
	float orientation;
	int ultrasonicVL, ultrasonicVR, ultrasonicHL, ultrasonicHR;


	bool[] audioSignals[9];
	bool[] audiData[4];
	bool water;
	bool[] obstacle[4];



	public bool[] readAudioSensors()
	{
	//AudioOne{1,1,1,0,0,0,0,0,1} northwest
	//AudioTwo{1,1,1,0,0,0,0,1,0}northeast
	//AudioThree{1,1,1,0,0,0,0,1,1} northeast
	//Audiofour{1,1,1,0,0,0,1,0,0} Southeast shortway
    		for ( i=0; i< 9; i++)
    		{
      			audioSignals[i] = readSensor(microfone)
      			sleep(100) // zeit zwischen den bits
    		}
    		for(i= 0; i<3;i++)
    		{
      			if(audioSignals.subArray[0,5] == new {1,1,1,0,0,0})
        	{
         	switch(audioSignals.subArray[6,8]);
         		case {001}: audioData[0]  = true;
        			break;
        		case {010}: audiData[1] = true;
         			break;
         		case {011}: audioData[2]  = true;
        			break;
         		case {100}: audiData[3] = true;
         			break;
        	}

        		else
        		{
         			exeption"fehlerhaftes Signal";
        		}
        		return audiData;
      	}

	public float gyroscope(orientation, x1, y1, z1)
	{

		float orientation = readGyroscope(x1, y1, z1);
		return orientation;

	}

	public float compass(orientationToNorth, x2, y2, z2)
	{

    		float orientationToNorth = readMagneticField(x2, y2, z2);
    		return orientationToNorth;

	}

	public float acceleration(speed, x3, y3, z3)
	{

		float speed = readAcceleration(x3, y3, z3);
		return speed;

	}


	public int checkUltrasonicsensors(ultrasonicVL, ultrasonicVR) 
	{


		int ultrasonicVL = readDigitalValue(ultrasonicPin1);
		int ultrasonicVR = readDigitalValue(ultrasonicPin2);
		int ultrasonicHL = readDigitalValue(ultrasonicPin3);
		int ultrasonicHR = readDigitalValue(ultrasonicPin4);


		return {SensorRead(ultrasonicVL),SensorRead(ultrasonicVR)};
	}

	public int checkwater(water) 
	{
		int water = readWater(watersens);
		return water;
	}
}
