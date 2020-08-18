#include <iostream>
#include <string>
using namespace std;
char identify = 'R';
int pos[3] ={28,3};
int turm = 1;
class Sensor {
    public:
        virtual int getSensor() = 0;
};
class Sensorarray {
    public:
        virtual string getSensorarray() = 0;
};

class Ultraa: public Sensor {
    public:
        int getSensor(){
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
            string a = "1,1,1,0,0,0,1,1,0";
            if ((pos[0] == 2 || pos[0] == 3 || pos[0] == 4) && trum == 1){
                a = "1,1,1,0,0,0,0,0,1";
                return a;
            }
            if ((pos[1] == 2 || pos[1] == 3 || pos[1] == 4) && trum == 2){
                a = "1,1,1,0,0,0,0,1,0";
                return a;
            }
            if ((pos[0] == 27 || pos[0] == 28 || pos[0] == 29) && trum == 3){
                a = "1,1,1,0,0,0,0,1,1";
                return a;
            }
            if ((pos[1] == 27 || pos[1] == 28 || pos[1] == 29) && trum == 4){
                a = "1,1,1,0,0,0,1,0,0";
                return a;
            }
            else{
                return a;
            }
        }
};
int main(void)
{
    Ultraa Ula;
    Ultrab Ulb;
    Wasser Was;
    Audio Aud;
    cout << "U0 " << Ula.getSensor();
    cout << "\nU1 " << Ulb.getSensor();
    cout << "\nW0 " << Was.getSensor();
    cout << "\nA " << Aud.getSensorarray();
}
