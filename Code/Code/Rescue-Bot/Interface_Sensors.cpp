
#include <iostream>

using namespace std;

class Sensor {
    public:
        virtual int getSensor() = 0;

};

class Ultraa: public Sensor {
    public:
        int getSensor(){
            int data = 1;
            return data;
        }
};

class Ultrab: public Sensor {
    public:
        int getSensor(){
            int data = 1;
            return data;
        }
};

class Wasser: public Sensor {
    public:
        int getSensor(){
            int data = 1;
            return data;
        }
};

class AudioMain: public Sensor {
    public:
        int getSensor(){
            int data = 0011;
            return data;
        }
};
class ObjectId: public Sensor {
    public:
        int getSensor(){
            int data = 0;
            return data;
        }
};


int main(void)
{
    Ultraa Ula;
    Ultrab Ulb;
    Wasser Was;
    AudioMain Audm;
    ObjectId OID;
    cout << "U0 " << Ula.getSensor();
    cout << "\nU1 " << Ulb.getSensor();
    cout << "\nW0 " << Was.getSensor();
    cout << "\nA0 " << Audm.getSensor();
    cout << "\nObjectID " << OID.getSensor();
}
