#include <iostream>
#include <string>
#include "testground.cpp"
using namespace std;
char identify;
int pos[3] ={28,1};
Testground Test;
class Sensor {
    public:
        virtual int getSensor() = 0;
};
class Sensorarray {
    public:
        virtual string getSensorarray() = 0;
    void setturm(int t) {
         turm = t;
      }
        int turm;
};

class Ultraa: public Sensor {
    public:
        int getSensor(){
            //cout << "Bitte geben Sie R/G/O/W ein!" << endl;
            //cin >> identify;
            identify = Test.currendlook();
            int data = 0;
            switch(identify){
                case 'R':
                    data = 1;
                    return data;
                case 'G':
                    data = 0;
                    return data;
                case 'O':
                    data = 1;
                    return data;
                break;
                case 'W':
                    data = 0;
                    return data;
                break;
                default:
                    data = 0;
                    return data;
                break;
            }
        }
};

class Ultrab: public Sensor {
    public:
        int getSensor(){
            //cout << "Bitte geben Sie R/G/O/W ein!" << endl;
            //cin >> identify;
            identify = Test.currendlook();
            int data = 0;
            switch(identify){
                case 'R':
                    data = 1;
                    return data;
                case 'G':
                    data = 0;
                    return data;
                case 'O':
                    data = 1;
                    return data;
                break;
                case 'W':
                    data = 0;
                    return data;
                break;
                default:
                    data = 0;
                    return data;
                break;
            }
        }
};

class Wasser: public Sensor {
    public:
        int getSensor(){
            //cout << "Bitte geben Sie R/G/O/W ein!" << endl;
            //cin >> identify;
            identify = Test.currendlook();
            int data = 0;
            switch(identify){
                case 'R':
                    data = 0;
                    return data;
                case 'G':
                    data = 0;
                    return data;
                case 'O':
                    data = 0;
                    return data;
                break;
                case 'W':
                    data = 1;
                    return data;
                break;
                default:
                    data = 0;
                    return data;
                break;
            }
        }
};

class Audio: public Sensorarray {
    public:
        string getSensorarray(){
            //Testground Test;
            int *x = Test.location();
            pos[0] = x[0];
            pos[1] = x[1];
            //cout << "Bitte geben Sie die Turmnummer ein!" << endl;
            //cin >> turm;
            //cout << "Bitte geben Sie L ein!" << endl;
            //cin >> pos[0];
            //cout << "Bitte geben Sie B ein!" << endl;
            //cin >> pos[1];
            string a = "1,1,1,0,0,0,1,1,0";
            if ((pos[1] == 1 || pos[1] == 2 || pos[1] == 3) && turm == 1){
                a = "1,1,1,0,0,0,0,0,1";
                return a;
            }
            else if ((pos[0] == 1 || pos[0] == 2 || pos[0] == 3) && turm == 2){
                a = "1,1,1,0,0,0,0,1,0";
                return a;
            }
            else if ((pos[1] == 27 || pos[1] == 28 || pos[1] == 29) && turm == 3){
                a = "1,1,1,0,0,0,0,1,1";
                return a;
            }
            else if ((pos[0] == 27 || pos[0] == 28 || pos[0] == 29) && turm == 4){
                a = "1,1,1,0,0,0,1,0,0";
                return a;
            }
            else{
                return a;
            }
        }
};
/*
int main()
int main()
{
    Audio Aud;
    Ultraa Ula;
    Ultrab Ulb;
    Wasser Was;
    Aud.setturm(2);
    Test.setturn('L'); //to trun the bot 90°
    cout<<"Turmid: " << Aud.getSensorarray();
    cout<<"\nU1: " << Ula.getSensor();
    cout<<"\nU2: " << Ulb.getSensor();
    cout<<"\nW1: " << Was.getSensor();
    cout<<"\nMove: " << Test.move_east();
    return 0;
}
*/
