
class EngineController
{


#define enginePin1 = D3;
#define enginePin2 = D4;
#define directionPin1 = D5;
#define directionPin2 = D6;
#define degreePerSecond  3;

#define delay;
#define digitalWrite();

public:
	void acclerator(int direction);
	void rotation(int angle);

private:
	void engine(int engine1, int engine2);


	void engine(int engine1, int engine2)		//Engine1 = right Engine2 = left
	{
		if (engine1 == 100)
		{
			digitalWrite(directionPin1, 255);
			digitalWrite(enginePin1, 255);
		}
		else if (engine1 == 0)
		{
			digitalWrite(enginePin1, 255);
		}
		else if (engine1 == 200)
		{
			digitalWrite(directionPin1, 0);
			digitalWrite(enginePin1, 255);
		}

		{
			if (engine2 == 100)
			{
				digitalWrite(directionPin2, 255);
				digitalWrite(enginePin2, 255);

			}
			else if (engine2 == 0)
			{
				digitalWrite(enginePin2, 255);
			}
			else if (engine2 == 200)
			{
				digitalWrite(directionPin2, 0);
				digitalWrite(enginePin2, 255);
			}
		}
	}
	void acclerator(int direction)
	{
		switch (direction)
		{

		case 0: engine(0, 0);
			break;
		case 1: engine(100, 100);
			break;
		case 2: engine(200, 200);
			break;
		default: engine(0, 0);
			break;
		};
	}
	void rotation(int angle)
	{
		if (angle <= 180 )
		{
			int secondsToRotate = angle / degreePerSecond;
			for (size_t i = secondsToRotate ; i > 0 ; i--)
			{
				engine(100, 0);
				delay(1000);    //spezifisch für arduino 
			}
			engine(0, 0);
		}
		else if (angle > 180)
		{
			int secondsToRotate = (360 - angle) / degreePerSecond;
			for (size_t i = secondsToRotate; i > 0; i--)
			{
				engine(0, 100);
				delay(1000);    //spezifisch für arduino 
			}
			engine(0, 0);
		}
		
	}

};