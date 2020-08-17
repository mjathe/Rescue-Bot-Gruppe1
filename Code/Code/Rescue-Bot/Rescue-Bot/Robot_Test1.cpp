#include <iostream>
#include <Adafruit_PWMServoDriver.h>

using namespace std;
#define MrPin1 = D3;
#define MrPin2 = D4;
#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

uint16_t Mr, M1, M2, M3; //Servos
uint8_t m0 = 0;
uint8_t m1 = 1;
uint8_t m2 = 2;
uint8_t m3 = 3;
float nump7, nump9, nump4, nump6, nump2, nump8, nump1, nump3; //Key inputs
int main()
{
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
    Mrotate = 0;    //Set servos to start position
    M1 = 4;
    M2 = 4;
    M3 = 4;
    uint16_t pulselen = SERVOMIN
    
   while(1){ //Loop forever || or remove loop and call this
       if(nump7 != 0 && nump9 != 0){
           if(nump7 != 0 && nump9 == 0 && Mr >= 2){
               Mr = Mr - pulselen;
               pwm.setPWM(m0, 0, Mr);
           }
           if(nump7 == 0 && nump9 != 0 && Mr <= 178){
               Mr = Mr +pulselen;
               pwm.setPWM(m0, 0, Mr);
           }
       }
       if(nump4 != 0 && nump6 != 0){
           if(nump4 != 0 && nump6 == 0 && M1 >= 10){
               M1 = M1 -pulselen;
               pwm.setPWM(m1, 0, Mr);
           }
           if(nump4 == 0 && nump6 != 0 && M1 <= 170){
               M1 = M1 +pulselen;
               pwm.setPWM(m1, 0, Mr);
           }
       }
       if(nump2 != 0 && nump8 != 0){
           if(nump2 != 0 && nump8 == 0 && M2 >= 10){
               M2 = M2 -pulselen;
               pwm.setPWM(m2, 0, Mr);
           }
           if(nump2 == 0 && nump8 != 0 && M2 <= 170){
               M2 = M2 +pulselen;
               pwm.setPWM(m3, 0, Mr);
           }
       }
       if(nump1 != 0 && nump3 != 0){
           if(nump7 != 0 && nump9 == 0 && M3 >= 10){
               M3 = M3 -pulselen;
               pwm.setPWM(m3, 0, Mr);
           }
           if(nump1 == 0 && nump3 != 0 && M3 <= 170){
               M3 = M3 +pulselen;
               pwm.setPWM(m3, 0, Mr);
           }
       }
   }
   
   return 0;
}
