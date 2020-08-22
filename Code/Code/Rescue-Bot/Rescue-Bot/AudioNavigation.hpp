
#pragma once
#include <stdio.h>
#include <string.h>
#include "SensorController.hpp"
#include "Alignment.hpp"
class AudioNavigation
{
private:
    int audioData[4];
public:
    void Navigate();
};
#include "AudioNavigation.hpp"
void  AudioNavigation::Navigate()
{
    SensorController sensCont; Alignment ali;
    //{ 1,0,0,0}; start NACH TURM 1
    //{ 1, 0, 0, 1 }; start nach turm4
     //{ 0, 1, 0, 0 }; turm 3 nach turm 4
    //{ 0, 1, 1, 0 }; im punkt 2 ausrichtung auf turm 3
    //{ 1,0,1,0 } turm 1 nach turm 2
    size_t t = 4;
    for (size_t i = 0; i < 4; i++)
    {
        audioData[i] = sensCont.checkForAudioSignals()[i];
    }


    if (memcmp(audioData, new int[4]{ 1,0,0,0 }, t) == 0) //nord turm1
    {
        ali.adjustAlignment(0);
    }
    else if (memcmp(audioData, new int[4]{ 1, 0, 0, 1 }, t) == 0)  //
    {
        ali.adjustAlignment(90);
    }
    else if (memcmp(audioData, new int[4]{ 1, 1, 0, 0 }, t) == 0)
    {
        ali.adjustAlignment(90); // to East vom turm 1 aus liegt der turm richtung osten
    }
    else if (memcmp(audioData, new int[4]{ 0, 1, 0, 0 }, t) == 0)
    {
        ali.adjustAlignment(90);
    }
    else if (memcmp(audioData, new int[4]{ 0, 1, 1, 0 }, t) == 0)
    {
        ali.adjustAlignment(180); //to South ausrichtung auf turm 4 (hierzwischen muss irgendwo der Verletze liegen)
    }
    else if (memcmp(audioData, new int[4]{ 0, 0, 1, 0 }, t) == 0)
    {
        ali.adjustAlignment(180);
    }

}
    

