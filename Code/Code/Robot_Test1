#include <iostream>

using namespace std;

float Mrotate, M1, M2, M3; //Servos
float Mrs, M1s, M2s, M3s; //Servosensor
float nump7, nump9, nump4, nump6, nump2, nump8, nump1, nump3; //Key inputs
int main()
{
    Mrotate = 0;    //Set servos to start position
    M1 = 4;
    M2 = 4;
    M3 = 4;
    
   while(1){ //Loop forever || or remove loop and call this
       if(nump7 != 0 && nump9 != 0){
           if(nump7 != 0 && nump9 == 0 && Mrs >= 2){
               Mrotate = Mrs -2;
           }
           if(nump7 == 0 && nump9 != 0 && Mrs <= 178){
               Mrotate = Mrs +2;
           }
       }
       if(nump4 != 0 && nump6 != 0){
           if(nump4 != 0 && nump6 == 0 && M1s >= 10){
               Mrotate = M1s -2;
           }
           if(nump4 == 0 && nump6 != 0 && M1s <= 170){
               Mrotate = M1s +2;
           }
       }
       if(nump2 != 0 && nump8 != 0){
           if(nump2 != 0 && nump8 == 0 && M2s >= 10){
               Mrotate = M2s -2;
           }
           if(nump2 == 0 && nump8 != 0 && M2s <= 170){
               Mrotate = M2s +2;
           }
       }
       if(nump1 != 0 && nump3 != 0){
           if(nump7 != 0 && nump9 == 0 && M3s >= 10){
               Mrotate = M3s -2;
           }
           if(nump1 == 0 && nump3 != 0 && M3s <= 170){
               Mrotate = M3s +2;
           }
       }
   }
   
   return 0;
}
