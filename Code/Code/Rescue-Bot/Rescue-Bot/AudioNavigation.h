#pragma once
class AudioNavigation
{
#include "Sensorcontroller.h"
#include "Alignment.h"
#define int[4] audioData;

	 AudioNavigation()
	{
		 audioData = Sensorcontroller.readAudioSensors();
		 if (audioData == {1, 0, 0, 0})
		 {
			 Alingment.adjustAlignment(0);
		 }
		 else if (audioData == {1, 0, 0, 1})
		 {
			 Alignment.adjustAlignment(90);
		 }
         else if (audioData == {1, 1, 0, 0})
         {
             Alignment.adjustAlignment(90) // to East vom turm 1 aus liegt der turm richtung osten
         }
         else if (audioData == {0, 1, 0, 0})
         {
             Alignment.adjustAlignment(90) 
         }
         elseif(audioData == {0, 1, 1, 0})
         {
             Alignment.adjustAlignment(180) //to South ausrichtung auf turm 4 (hierzwischen muss irgendwo der Verletze liegen)
         }
         else if (audioData == {0, 0, 1, 0})
         {
             Alignment.adjustAlignment(180)
         }

	}
};
