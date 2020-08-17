#include <iostream>
#include <new>

using namespace std;

class Sensorcontroller
{

	#define ultrasonicPin1 29;
	#define ultrasonicPin2 27;
	#define ultrasonicPin3 25;
	#define ultrasonicPin4  23;

	#define watersens  20;


private:
	float x1, y1, z1;	//Gyroscope
	float x2, y2, z2;	//compass
	float x3, y3, z3;	//acceleration
	float orientationToNorth;
	float orientation;
	int ultrasonicVL; ultrasonicVR;


	int audioSignals[9];
	int audiData[4];
	bool water;
	int obstacle[2];

public:
	int[] readAudioSensors();
	float compass();
	float gyroscope();
	float acceleration();
	int[] checkUltraSonicSensors();
	int checkWater();


	 int[] readAudioSensors()
	{
	//AudioOne{1,1,1,0,0,0,0,0,1} northwest
	//AudioTwo{1,1,1,0,0,0,0,1,0}northeast
	//AudioThree{1,1,1,0,0,0,0,1,1} northeast
	//Audiofour{1,1,1,0,0,0,1,0,0} Southeast shortway
    		for ( i=0; i< 9; i++)
    		{
				audioSignals[i] = readSensor(microfone);
				sleep(100); // zeit zwischen den bits
    		}
			for (i = 0; i < 3; i++)
			{
				if (audioSignals.subArray[0, 5] == new {1, 1, 1, 0, 0, 0})
				{
					switch (audioSignals.subArray[6, 8])
					{
					case {001}: audioData[0] = true;
						break;
					case {010}: audiData[1] = true;
						break;
					case {011}: audioData[2] = true;
						break;
					case {100}: audiData[3] = true;
						break;
					}
				}
			}

        		else
        		{
         			cout <<"fehlerhaftes Signal"<<;
        		}
        		return audiData;
      	}

	 float gyroscope()
	{
		orientation = readGyroscope(x1, y1, z1);

		return orientation;
	}

	 float compass()
	{
    		orientationToNorth = readMagneticField(x2, y2, z2);
		
    		return orientationToNorth;
	}
		

	 float acceleration()
	{
		speed = readAcceleration(x3, y3, z3);
		
		return speed;
	}

	int[] checkUltraSonicSensors() 
	{		
		ultrasonicVL = readDigitalValue(ultrasonicPin1);
		ultrasonicVR = readDigitalValue(ultrasonicPin2);
		
		return new int[]{ultrasonicVL,ultrasonicVR};
	}
		
	 int checkWater() 
	{
		int water = readWater(watersens);
		
		return water;
	}
}
